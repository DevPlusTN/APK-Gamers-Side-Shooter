#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <iostream>
#include <vector>
#include <sstream>

// Windows Header Files:
#include <windows.h>
#include <tchar.h>

// C RunTime Header Files
#include "CCStdC.h"

#include "CCEGLView.h"
#include "CCDirector.h"
#include "CCScheduler.h"

#include "models/PTModelController.h"
#include "screens/PTPScreenGameField.h"
#include "PTPAppDelegate.h"
#include "PTPInputController.h"

//////////////////////////////// OS Nuetral Headers ////////////////
#include "OISInputManager.h"
#include "OISException.h"
#include "OISKeyboard.h"
#include "OISMouse.h"
#include "OISJoyStick.h"
#include "OISEvents.h"


//Advanced Usage
#include "OISForceFeedback.h"

// Steam API include
#include "steam_api.h"

using namespace OIS;

USING_NS_CC;

const char *g_DeviceType[6] = { "OISUnknown", "OISKeyboard", "OISMouse", "OISJoyStick",
"OISTablet", "OISOther" };

InputManager *g_InputManager = 0;	//Our Input System
Keyboard *g_kb = 0;				//Keyboard Device

HWND hWnd = 0;

//////////// Common Event handler class ////////
class EventHandler : public KeyListener
{
public:
	EventHandler() {}
	~EventHandler() {}
	bool keyPressed(const KeyEvent &arg) {
		CCLOG(" KeyPressed {%d, %s} Character (%c)",
			arg.key, ((Keyboard*)(arg.device))->getAsString(arg.key).c_str(), (char)arg.text);
		PTPScreenGameField *gf = PTPScreenGameField::shared();
		if (gf) {
			if (arg.key == 203)
				gf->inputController()->keyPressed(PTPInputControllerKeyLeft);
			if (arg.key == 205)
				gf->inputController()->keyPressed(PTPInputControllerKeyRight);
			if (arg.key == 200)
				gf->inputController()->keyPressed(PTPInputControllerKeyUp);
			if (arg.key == 208)
				gf->inputController()->keyPressed(PTPInputControllerKeyDown);
			if (arg.key == 36)
				gf->inputController()->keyPressed(PTPInputControllerKeyJump);
			if (arg.key == 57)
				gf->inputController()->keyPressed(PTPInputControllerKeyShoot);
			if (arg.key == 45)
				gf->inputController()->keyPressed(PTPInputControllerKeyMotorCW);
			if (arg.key == 44)
				gf->inputController()->keyPressed(PTPInputControllerKeyMotorCCW);
			if (arg.key == 51)
				gf->inputController()->keyPressed(PTPInputControllerKeyRotateLeft);
			if (arg.key == 52)
				gf->inputController()->keyPressed(PTPInputControllerKeyRotateRight);
		}
		return true;
	}
	bool keyReleased(const KeyEvent &arg) {
		CCLOG("KeyReleased {%s}",
			((Keyboard*)(arg.device))->getAsString(arg.key).c_str());
		PTPScreenGameField *gf = PTPScreenGameField::shared();
		if (gf) {
			if (arg.key == 203)
				gf->inputController()->keyReleased(PTPInputControllerKeyLeft);
			if (arg.key == 205)
				gf->inputController()->keyReleased(PTPInputControllerKeyRight);
			if (arg.key == 200)
				gf->inputController()->keyReleased(PTPInputControllerKeyUp);
			if (arg.key == 208)
				gf->inputController()->keyReleased(PTPInputControllerKeyDown);
			if (arg.key == 36)
				gf->inputController()->keyReleased(PTPInputControllerKeyJump);
			if (arg.key == 57)
				gf->inputController()->keyReleased(PTPInputControllerKeyShoot);
			if (arg.key == 45)
				gf->inputController()->keyReleased(PTPInputControllerKeyMotorCW);
			if (arg.key == 44)
				gf->inputController()->keyReleased(PTPInputControllerKeyMotorCCW);
			if (arg.key == 51)
				gf->inputController()->keyReleased(PTPInputControllerKeyRotateLeft);
			if (arg.key == 52)
				gf->inputController()->keyReleased(PTPInputControllerKeyRotateRight);
		}
		return true;
	}
};

//Create a global instance
EventHandler handler;

// cocos2d application instance
static PTPAppDelegate s_sharedApplication;

class CaptureObject : public CCObject {
public:
	CaptureObject() : CCObject() {}

	virtual void update(float) { 
		if (g_kb)
		{
			g_kb->capture();
			if (!g_kb->buffered()) {
				if (g_kb->isModifierDown(Keyboard::Shift))
					CCLOG("Shift is down..\n");
				if (g_kb->isModifierDown(Keyboard::Alt))
					CCLOG("Alt is down..\n");
				if (g_kb->isModifierDown(Keyboard::Ctrl))
					CCLOG("Ctrl is down..\n");
			}
		}
	};
};

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	PTModelController *mc = PTModelController::shared();
	mc->clean();
	mc->loadDataForClass(CCString::create("data/PTModelGeneralSettings.0.xml"));
	mc->loadDataForClass(CCString::create("data/PTModelFont.0.xml"));

    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("Player");
	eglView->setFrameSize(1134, 640);
	eglView->setFrameZoomFactor(1.0f);

	// disabled Steam Initialization
	//bool steamStarted = SteamAPI_Init();
	//std::cout << "Steam Started: %b" << steamStarted;

	ParamList pl;
	hWnd = eglView->getHWnd();	
	std::ostringstream wnd;
	wnd << (size_t)hWnd;
	pl.insert(std::make_pair(std::string("WINDOW"), wnd.str()));

	//Default mode is foreground exclusive..but, we want to show mouse - so nonexclusive
	//	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
	//	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));

	//This never returns null.. it will raise an exception on errors
	g_InputManager = InputManager::createInputSystem(pl);

	//Lets enable all addons that were compiled in:
	g_InputManager->enableAddOnFactory(InputManager::AddOn_All);

	//Print debugging information
	unsigned int v = g_InputManager->getVersionNumber();
	CCLOG("OIS Version: %i.%i.%i",
		(v >> 16),
		((v >> 8) & 0x000000FF),
		(v & 0x000000FF));
	CCLOG("Release Name: %s", g_InputManager->getVersionName().c_str());
	CCLOG("Manager: %s", g_InputManager->inputSystemName().c_str());
	CCLOG("Total Keyboards: %i", g_InputManager->getNumberOfDevices(OISKeyboard));
	CCLOG("Total Mice: %i", g_InputManager->getNumberOfDevices(OISMouse));
	CCLOG("Total JoySticks: %i", g_InputManager->getNumberOfDevices(OISJoyStick));

	//List all devices
	DeviceList list = g_InputManager->listFreeDevices();
	for (DeviceList::iterator i = list.begin(); i != list.end(); ++i)
		CCLOG("\tDevice: %s  Vendor: %s", g_DeviceType[i->first], i->second.c_str());

	g_kb = (Keyboard*)g_InputManager->createInputObject(OISKeyboard, true);
	g_kb->setEventCallback(&handler);

	// connect the listener to the scheduler of the director
	CaptureObject ccobjectTarget;

	CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(&ccobjectTarget, 0, false);

    return CCApplication::sharedApplication()->run();
}
