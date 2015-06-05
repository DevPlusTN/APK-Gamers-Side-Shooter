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

#include "PTPConfig.h"
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
#ifdef USE_STEAM
#include "steam_api.h"
#endif

using namespace OIS;

USING_NS_CC;

const char *g_DeviceType[6] = { "OISUnknown", "OISKeyboard", "OISMouse", "OISJoyStick",
"OISTablet", "OISOther" };

InputManager *g_InputManager = 0;	//Our Input System
Keyboard *g_kb = 0;				//Keyboard Device

HWND hWnd = 0;

std::map<int, int> _keysMap = {
	{41, 96},// `
	{2, 49},// 1
	{3, 50},// 2
	{4, 51},// 3
	{5, 52},// 4
	{6, 53},// 5
	{7, 54},// 6
	{8, 55},// 7
	{9, 56},// 8
	{10, 57},// 9
	{11, 48},// 0
	{12, 45},// -
	{13, 61},// =
	{16, 81},// Q
	{17, 87},// W
	{18, 69},// E
	{19, 82},// R
	{20, 84},// T
	{21, 89},// Y
	{22, 85},// U 
	{23, 73},// I
	{24, 79},// O
	{25, 80},// P
	{26, 91},// [
	{27, 93},// ]
	{43, 92},// "\"
	{30, 65},// A
	{31, 83},// S
	{32, 68},// D
	{33, 70},// F 
	{34, 71},// G
	{35, 72},// H
	{36, 74},// J
	{37, 75},// K
	{38, 76},// L
	{39, 59},// ;
	{40, 39},// ' 
	{44, 90},// Z
	{45, 88},// X
	{46, 67},// C 
	{47, 86},// V
	{48, 66},// B
	{49, 78},// N
	{50, 77},// M
	{51, 44},// ,
	{52, 46},// .
	{53, 47},// /
	{203, 16777234},// Left
	{208, 16777237},// Down
	{205, 16777236},// Right 
	{200, 16777235},// Up
	{1, 16777216},// Esc
	{59, 16777264},// F1
	{60, 16777265},// F2
	{61, 16777266},// F3
	{62, 16777267},// F4
	{63, 16777268},// F5
	{64, 16777269},// F6
	{65, 16777270},// F7
	{66, 16777271},// F8 
	{67, 16777272},// F9
	{68, 16777273},// F10
	{87, 16777274},// F11
	{88, 16777275},// F12
	{199, 16777232},// Home
	{207, 16777233},// End
	{210, 16777222},// Insert
	{211, 16777223},// Delete
	{15, 16777217},// Tab
	{58, 16777252},// Caps Lock
	{42, 16777248},// Shift
	{29, 16777249},// Ctrl 
	{56, 16777251},// Alt  
	{57, 32},// Space 
	{181, 47},// Num / 
	{55, 42},// *
	{74, 45},// -
	{78, 43},// +
	{156, 16777221},// Num Enter
};

//////////// Common Event handler class ////////
class EventHandler : public KeyListener
{
public:
	EventHandler() {}
	~EventHandler() {}
	bool keyPressed(const KeyEvent &arg) {
		
		PTLog(" KeyPressed {%d, %s} Character (%c)",
			arg.key, ((Keyboard*)(arg.device))->getAsString(arg.key).c_str(), (char)arg.text);
		PTPScreenGameField *gf = PTPScreenGameField::shared();
		if (gf) {
			PTPInputController *inputController = gf->inputController();
			PTModelGeneralSettings *settsModel = (PTModelGeneralSettings *)PTModelController::shared()->getModel("PTModelGeneralSettings");
			int key = _keysMap[ arg.key ];

			PTPScreen *screenLayer = PTPScreen::getTopScreen();
			if (inputController->handleKeyPressOnScreen(key, screenLayer)) {
				return true;
			}

			if (settsModel->moveUpKey == key) {
				inputController->buttonMoveUpPressed();
				return true;
			}
			if (settsModel->moveDownKey == key) {
				inputController->buttonMoveDownPressed();
				return true;
			}
			if (settsModel->moveLeftKey == key) {
				inputController->buttonMoveLeftPressed();
				return true;
			}
			if (settsModel->moveRightKey == key) {
				inputController->buttonMoveRightPressed();
				return true;
			}
			if (settsModel->motorCWKey == key) {
				inputController->buttonMotorCWPressed();
				return true;
			}
			if (settsModel->motorCCWKey == key) {
				inputController->buttonMotorCCWPressed();
				return true;
			}
			if (settsModel->rotateLeftKey == key) {
				inputController->buttonRotateLeftPressed();
				return true;
			}
			if (settsModel->rotateRightKey == key) {
				inputController->buttonRotateRightPressed();
				return true;
			}
			if (settsModel->shootKey == key) {
				inputController->buttonShootPressed();
				return true;
			}
			if (settsModel->jumpKey == key) {
				inputController->buttonJumpPressed();
				return true;
			}

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
		PTLog("KeyReleased {%s}",
			((Keyboard*)(arg.device))->getAsString(arg.key).c_str());
		PTPScreenGameField *gf = PTPScreenGameField::shared();
		if (gf) {
			PTPInputController *inputController = gf->inputController();
			PTModelGeneralSettings *settsModel = (PTModelGeneralSettings *)PTModelController::shared()->getModel("PTModelGeneralSettings");
			int key = _keysMap[arg.key];

			PTPScreen *screenLayer = PTPScreen::getTopScreen();
			if (inputController->handleKeyReleaseOnScreen(key, screenLayer)) {
				return true;
			}

			if (settsModel->moveUpKey == key) {
				inputController->buttonMoveUpReleased();
				return true;
			}
			if (settsModel->moveDownKey == key) {
				inputController->buttonMoveDownReleased();
				return true;
			}
			if (settsModel->moveLeftKey == key) {
				inputController->buttonMoveLeftReleased();
				return true;
			}
			if (settsModel->moveRightKey == key) {
				inputController->buttonMoveRightReleased();
				return true;
			}
			if (settsModel->motorCWKey == key) {
				inputController->buttonMotorCWReleased();
				return true;
			}
			if (settsModel->motorCCWKey == key) {
				inputController->buttonMotorCCWReleased();
				return true;
			}
			if (settsModel->rotateLeftKey == key) {
				inputController->buttonRotateLeftReleased();
				return true;
			}
			if (settsModel->rotateRightKey == key) {
				inputController->buttonRotateRightReleased();
				return true;
			}
			if (settsModel->shootKey == key) {
				inputController->buttonShootReleased();
				return true;
			}
			if (settsModel->jumpKey == key) {
				inputController->buttonJumpReleased();
				return true;
			}

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
					PTLog("Shift is down..\n");
				if (g_kb->isModifierDown(Keyboard::Alt))
					PTLog("Alt is down..\n");
				if (g_kb->isModifierDown(Keyboard::Ctrl))
					PTLog("Ctrl is down..\n");
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
    mc->loadDataForClass( CCString::create("data/PTModelGeneralSettings.0.attributes.xml"), PTModelControllerDataTypeAttributes );
    mc->loadDataForClass( CCString::create("data/PTModelFont.0.attributes.xml"), PTModelControllerDataTypeAttributes );     
    mc->loadDataForClass( CCString::create("data/PTModelScreen.0.attributes.xml"), PTModelControllerDataTypeAttributes );
    mc->loadDataForClass( CCString::create("data/PTModelObjectLabel.0.attributes.xml"), PTModelControllerDataTypeAttributes );
    mc->loadDataForClass( CCString::create("data/PTModelScreen.0.connections.xml"), PTModelControllerDataTypeConnections );

    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("Player");
	eglView->setFrameSize(1134, 640);
	eglView->setFrameZoomFactor(1.0f);

#ifdef USE_STEAM
    bool steamStarted = SteamAPI_Init();
    std::cout << "Steam Started: %b" << steamStarted;
#endif

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

	mc->clean();
    return CCApplication::sharedApplication()->run();
}
