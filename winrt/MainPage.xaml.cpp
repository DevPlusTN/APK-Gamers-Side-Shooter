/****************************************************************************
Copyright (c) 2010-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
//
// MainPage.xaml.cpp
// Implementation of the MainPage.xaml class.
//

#include "pch.h"
#include "MainPage.xaml.h"

#include "CCApplication.h"
#include "CCEGLView.h"

#include "screens/PTPScreenGameField.h"
#include "models/PTModelController.h"
#include "PTPInputController.h"
#include "PTPConfig.h"

USING_NS_CC;

using namespace HelloCpp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::Input;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::System;

std::map<int, int> _keysMap = {
		{ 192, 96 },// `
		{ 49, 49 },// 1
		{ 50, 50 },// 2
		{ 51, 51 },// 3
		{ 52, 52 },// 4
		{ 53, 53 },// 5
		{ 54, 54 },// 6
		{ 55, 55 },// 7
		{ 56, 56 },// 8
		{ 57, 57 },// 9
		{ 48, 48 },// 0
		{ 189, 45 },// -
		{ 187, 61 },// =
		{ 81, 81 },// Q
		{ 87, 87 },// W
		{ 69, 69 },// E
		{ 82, 82 },// R
		{ 84, 84 },// T
		{ 89, 89 },// Y
		{ 85, 85 },// U 
		{ 73, 73 },// I
		{ 79, 79 },// O
		{ 80, 80 },// P
		{ 219, 91 },// [
		{ 221, 93 },// ]
		{ 220, 92 },// "\"
		{ 65, 65 },// A
		{ 83, 83 },// S
		{ 68, 68 },// D
		{ 70, 70 },// F 
		{ 71, 71 },// G
		{ 72, 72 },// H
		{ 74, 74 },// J
		{ 75, 75 },// K
		{ 76, 76 },// L
		{ 186, 59 },// ;
		{ 222, 39 },// ' 
		{ 90, 90 },// Z
		{ 88, 88 },// X
		{ 67, 67 },// C 
		{ 86, 86 },// V
		{ 66, 66 },// B
		{ 78, 78 },// N
		{ 77, 77 },// M
		{ 188, 44 },// ,
		{ 190, 46 },// .
		{ 191, 47 },// /

		{ 37, 16777234 },// Left
		{ 40, 16777237 },// Down
		{ 39, 16777236 },// Right 
		{ 38, 16777235 },// Up

		{ 27, 16777216 },// Esc
		{ 112, 16777264 },// F1
		{ 113, 16777265 },// F2
		{ 114, 16777266 },// F3
		{ 115, 16777267 },// F4
		{ 116, 16777268 },// F5
		{ 117, 16777269 },// F6
		{ 118, 16777270 },// F7
		{ 119, 16777271 },// F8 
		{ 120, 16777272 },// F9
		{ 121, 16777273 },// F10
		{ 122, 16777274 },// F11
		{ 123, 16777275 },// F12

		{ 36, 16777232 },// Home
		{ 35, 16777233 },// End
		{ 45, 16777222 },// Insert
		{ 46, 16777223 },// Delete

		{ 9, 16777217 },// Tab
		{ 20, 16777252 },// Caps Lock
		{ 16, 16777248 },// Shift
		{ 17, 16777249 },// Ctrl 
		{ 18, 16777251 },// Alt  
		{ 32, 32 },// Space 

		{ 111, 47 },// Num / 
		{ 106, 42 },// *
		{ 109, 45 },// -
		{ 107, 43 },// +
		{ 156, 16777221 },// Num Enter
};

MainPage::MainPage()
{
	InitializeComponent();

	PTModelController *mc = PTModelController::shared();
	mc->clean();

    mc->loadDataForClass( CCString::create("data/PTModelGeneralSettings.0.attributes.xml"), PTModelControllerDataTypeAttributes );
    mc->loadDataForClass( CCString::create("data/PTModelFont.0.attributes.xml"), PTModelControllerDataTypeAttributes );     
    mc->loadDataForClass( CCString::create("data/PTModelScreen.0.attributes.xml"), PTModelControllerDataTypeAttributes );
    mc->loadDataForClass( CCString::create("data/PTModelObjectLabel.0.attributes.xml"), PTModelControllerDataTypeAttributes );
    mc->loadDataForClass( CCString::create("data/PTModelScreen.0.connections.xml"), PTModelControllerDataTypeConnections );

	std::vector<std::string> searchPath;
	searchPath.push_back("data");
	searchPath.push_back("data/atlases");
	searchPath.push_back("data/fonts");
	searchPath.push_back("data/images");
	searchPath.push_back("data/sounds");
	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

	CCEGLView* eglView = new CCEGLView();
	eglView->Create(Window::Current->CoreWindow, SwapChainPanel);
	eglView->setViewName("Player");

	mc->clean();
    CCApplication::sharedApplication()->run();

	KeyUp += ref new Windows::UI::Xaml::Input::KeyEventHandler(this, &MainPage::OnKeyUp);
	KeyDown += ref new Windows::UI::Xaml::Input::KeyEventHandler(this, &MainPage::OnKeyDown);
}

void MainPage::OnPreviousPressed(Object^ sender, RoutedEventArgs^ args)
{
}

void MainPage::OnNextPressed(Object^ sender, RoutedEventArgs^ args)
{
}

void MainPage::SaveInternalState(IPropertySet^ state)
{
    CCEGLView::sharedOpenGLView()->OnSuspending();
}

void MainPage::LoadInternalState(IPropertySet^ state)
{
	//m_renderer->LoadInternalState(state);
}

void MainPage::OnKeyUp(Platform::Object ^sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs ^e)
{
	PTLog("Button Up %s %i", e->ToString(), e->Key);
	
	PTPScreenGameField *gf = PTPScreenGameField::shared();
	if (gf) {
		PTPInputController *inputController = gf->inputController();
		PTModelGeneralSettings *settsModel = (PTModelGeneralSettings *)PTModelController::shared()->getModel("PTModelGeneralSettings");
		int key = _keysMap[(int)e->Key];

		PTPScreen *screenLayer = PTPScreen::getTopScreen();
		if (inputController->handleKeyReleaseOnScreen(key, screenLayer)) {
			return;
		}

		if (settsModel->moveUpKey == key) {
			inputController->buttonMoveUpReleased();
			return;
		}
		if (settsModel->moveDownKey == key) {
			inputController->buttonMoveDownReleased();
			return;
		}
		if (settsModel->moveLeftKey == key) {
			inputController->buttonMoveLeftReleased();
			return;
		}
		if (settsModel->moveRightKey == key) {
			inputController->buttonMoveRightReleased();
			return;
		}
		if (settsModel->motorCWKey == key) {
			inputController->buttonMotorCWReleased();
			return;
		}
		if (settsModel->motorCCWKey == key) {
			inputController->buttonMotorCCWReleased();
			return;
		}
		if (settsModel->rotateLeftKey == key) {
			inputController->buttonRotateLeftReleased();
			return;
		}
		if (settsModel->rotateRightKey == key) {
			inputController->buttonRotateRightReleased();
			return;
		}
		if (settsModel->shootKey == key) {
			inputController->buttonShootReleased();
			return;
		}
		if (settsModel->jumpKey == key) {
			inputController->buttonJumpReleased();
			return;
		}

		if (e->Key == VirtualKey::Left) // 37
			gf->inputController()->keyReleased(PTPInputControllerKeyLeft);
		if (e->Key == VirtualKey::Right) // 39
			gf->inputController()->keyReleased(PTPInputControllerKeyRight);
		if (e->Key == VirtualKey::Up) // 38
			gf->inputController()->keyReleased(PTPInputControllerKeyUp);
		if (e->Key == VirtualKey::Down) // 40
			gf->inputController()->keyReleased(PTPInputControllerKeyDown);
		if (e->Key == VirtualKey::J) // 74
			gf->inputController()->keyReleased(PTPInputControllerKeyJump);
		if (e->Key == VirtualKey::Space) // 32
			gf->inputController()->keyReleased(PTPInputControllerKeyShoot);
		if (e->Key == VirtualKey::X) // 88
			gf->inputController()->keyReleased(PTPInputControllerKeyMotorCW);
		if (e->Key == VirtualKey::Z) // 90
			gf->inputController()->keyReleased(PTPInputControllerKeyMotorCCW);
		if (int(e->Key) == 188) // 188
			gf->inputController()->keyReleased(PTPInputControllerKeyRotateLeft);
		if (int(e->Key) == 190) // 190
			gf->inputController()->keyReleased(PTPInputControllerKeyRotateRight);
	}

}

void MainPage::OnKeyDown(Platform::Object ^sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs ^e)
{
	PTLog("Button Down %s %i", e->ToString(), e->Key);
	
	PTPScreenGameField *gf = PTPScreenGameField::shared();
	if (gf) {
		PTPInputController *inputController = gf->inputController();
		PTModelGeneralSettings *settsModel = (PTModelGeneralSettings *)PTModelController::shared()->getModel("PTModelGeneralSettings");
		int key = _keysMap[(int)e->Key];

		PTPScreen *screenLayer = PTPScreen::getTopScreen();
		if (inputController->handleKeyPressOnScreen(key, screenLayer)) {
			return;
		}

		if (settsModel->moveUpKey == key) {
			inputController->buttonMoveUpPressed();
			return;
		}
		if (settsModel->moveDownKey == key) {
			inputController->buttonMoveDownPressed();
			return;
		}
		if (settsModel->moveLeftKey == key) {
			inputController->buttonMoveLeftPressed();
			return;
		}
		if (settsModel->moveRightKey == key) {
			inputController->buttonMoveRightPressed();
			return;
		}
		if (settsModel->motorCWKey == key) {
			inputController->buttonMotorCWPressed();
			return;
		}
		if (settsModel->motorCCWKey == key) {
			inputController->buttonMotorCCWPressed();
			return;
		}
		if (settsModel->rotateLeftKey == key) {
			inputController->buttonRotateLeftPressed();
			return;
		}
		if (settsModel->rotateRightKey == key) {
			inputController->buttonRotateRightPressed();
			return;
		}
		if (settsModel->shootKey == key) {
			inputController->buttonShootPressed();
			return;
		}
		if (settsModel->jumpKey == key) {
			inputController->buttonJumpPressed();
			return;
		}

		if (e->Key == VirtualKey::Left) // 37
			gf->inputController()->keyPressed(PTPInputControllerKeyLeft);
		if (e->Key == VirtualKey::Right) // 39
			gf->inputController()->keyPressed(PTPInputControllerKeyRight);
		if (e->Key == VirtualKey::Up) // 38
			gf->inputController()->keyPressed(PTPInputControllerKeyUp);
		if (e->Key == VirtualKey::Down) // 40
			gf->inputController()->keyPressed(PTPInputControllerKeyDown);
		if (e->Key == VirtualKey::J) // 74
			gf->inputController()->keyPressed(PTPInputControllerKeyJump);
		if (e->Key == VirtualKey::Space) // 32
			gf->inputController()->keyPressed(PTPInputControllerKeyShoot);
		if (e->Key == VirtualKey::X) // 88
			gf->inputController()->keyPressed(PTPInputControllerKeyMotorCW);
		if (e->Key == VirtualKey::Z) // 90
			gf->inputController()->keyPressed(PTPInputControllerKeyMotorCCW);
		if (int(e->Key) == 188) // 188
			gf->inputController()->keyPressed(PTPInputControllerKeyRotateLeft);
		if (int(e->Key) == 190) // 190
			gf->inputController()->keyPressed(PTPInputControllerKeyRotateRight);
	}
}