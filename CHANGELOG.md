# CHANGE LOG  
  
## Initial Release  
### Version 0.0.1  
#### Supported Devices:  
AMAZON (Eclipse IDE) [Broken]  
ANDROID (Eclipse IDE) [Broken]  
IOS (XCODE IDE) [Broken]  
OSX - MAC OS X (XCODE IDE)  
WIN32 - WINDOWS 32 bit System (Visual Studio 2012)

### Version 0.0.2  
#### Supported Devices:  
AMAZON (Eclipse IDE)  
ANDROID (Eclipse IDE)  
IOS (XCODE IDE)  
OSX - MAC OS X (XCODE IDE)  
WIN32 - WINDOWS 32 bit System (Visual Studio 2013)  
WINRT - WINDOWS METRO (Visual Studio 2013)
#### Changes:  
Added: WINRT - WINDOWS METRO (Visual Studio 2013)  
Added: Touch Screen Support (Both Mobile Devices and Desktop support)  
Added: Accelerometer  
Added: Joystick buttons  
Updated: applovin sdk  
Updated: admob sdk  
Updated: rebmob sdk  
Updated: improved support for winrt, win32, exe  
Updated: Visual Studio 2012 to Visual Studio 2013
Fixed: applying banner on top of screen  
Fixed: game play sounds in file not playing  
Fixed: OSX game in full screen keyboard does not work  
Fixed: one way collision  
Fixed: do not background music is it already in play  
Fixed: mute music/sound when displaying a video ad (Vungle)  
Fixed: Connected Enemy Objects Disappear when destroyed with Bullet but still collide and kill character  
Fixed: do not stop death sound after death animation end  
Fixed: Crashing intermittently on device after death  
Fixed: Flat on flat collision with character walking will stick eventually  
Fixed: Downward bounce pre-set is broken  
Fixed: admob and iAd banner issues  
Fixed: chart-boost (and leadbolt) issue, game freezes  
Fixed: game crashing at game over screen when pressing restart  
Fixed: font size for Windows  
Fixed: APK crashes on game over when not entering leader board ID  
Fixed: reset on OS X does not reset progress  
Fixed: character and background layering issues  
Fixed: Pause Menu Back to Main Menu to Start Game x2 Crashes on Device  
Fixed: Coin Shop functions differently when accessed from Main Menu  
Fixed: Kill All Enemies Not Destroying Spawned Enemies  
Fixed: sound for object/enemy does not play completely after second appearance of object  
Fixed: Start/End sounds not working correctly with coins, play sound on Game Over Screen  
Fixed: review button crashes when using “market://” URL on Google Play  
Fixed: Label off alignment issue and add couple new scripts for building CORE lib  
Fixed: stop idle sound after Start Sound activated  
Fixed: Power Up Sound Not Working (IDLE and END)  
Fixed: Trail Effect Connected to Character Does Not Disappear When Character Dies  
Fixed: Back to Main Menu with Accelerometer causes crash  
Fixed: OS X 10.10 bug with dialogue windows  
Fixed: scroll bar for OSX 10.10 (auto hide scroll bar)  
Fixed: object idle sound is not working  
Fixed: score is not getting reported to leader board on game end scene (only game over screen)  
Fixed: Buttons from Main Menu can still be pressed in Shop despite not being visible  
Fixed: Power Up Sound Not Working (IDLE and END)  
Fixed: added IDLE sound increase while character is closer to object  
  
### Version 0.0.3  
#### Supported Devices:  
AMAZON (Eclipse IDE)  
ANDROID (Eclipse IDE)  
IOS (XCODE IDE)  
OSX - MAC OS X (XCODE IDE)  
WIN32 - WINDOWS 32 bit System (Visual Studio 2013)  
WINRT - WINDOWS METRO (Visual Studio 2013)
#### Changes:  
Updated: iOS Admob SDK to 7.2.2  
Fixed: text/label misalign (old files need to refresh font)  
Fixed: joystick/accelerometer  
Fixed: game over delay  
Fixed: various crashes  
Fixed: various issues with sound not playing  

### Version 0.0.4  
#### Supported Devices:  
AMAZON (Eclipse IDE)  
ANDROID (Eclipse IDE)  
IOS (XCODE IDE)  
OSX - MAC OS X (XCODE IDE)  
WIN32 - WINDOWS 32 bit System (Visual Studio 2013)  
WINRT - WINDOWS METRO (Visual Studio 2013)  
#### Changes:  
Updated: AdMob information  
Added: More scenes with enemies more spread out  
Fixed: Minor changes and bug fixes for AdMob placement  
Removed: Clean-up of unused assets  

### Version 0.0.5  
#### Supported Devices:  
AMAZON (Eclipse IDE)  
ANDROID (Eclipse IDE)  
IOS (XCODE IDE)  
OSX - MAC OS X (XCODE IDE)  
WIN32 - WINDOWS 32 bit System (Visual Studio 2013)  
WINRT - WINDOWS METRO (Visual Studio 2013)  
#### Changes:  
Fixed: Missing sound files that gotten deleted by mistake when cleaning up unused resources  
Fixed: Misc changes and bug fixes  
  
### Version 0.0.6  
#### Supported Devices:  
AMAZON (Eclipse IDE)  
ANDROID (Eclipse IDE)  
IOS (XCODE IDE)  
OSX - MAC OS X (XCODE IDE)  
WIN32 - WINDOWS 32 bit System (Visual Studio 2013)  
WINRT - WINDOWS METRO (Visual Studio 2013)  
#### Changes:  
Added: New Scoring System for distance travelled.  
Added: Missing Version 0.0.5 changes to the Change log  
Added: Increased Scenes Count to the game with more enemies.  
Fixed: Missing Package name in AndroidManifest.xml for AMAZON  
Fixed: Missing Package name in AndroidManifest.xml for ANDROID  
Fixed: Missing Bundle ID for IOS  
Fixed: Missing Bundle ID for OSX  
Fixed: Missing Bundle ID for WIN32  
Fixed: Missing Bundle ID for WINRT  
Modified: Now if you go to close to the Ocean you will now crash into it and die  
Modified: Increased Population of enemies in each scene.  
  
### Version 0.0.7  
#### Supported Devices:  
AMAZON (Eclipse IDE)  
ANDROID (Eclipse IDE)  
IOS (XCODE IDE)  
OSX - MAC OS X (XCODE IDE)  
WIN32 - WINDOWS 32 bit System (Visual Studio 2013)  
WINRT - WINDOWS METRO (Visual Studio 2013)  
#### Changes: 
Added: New Graphic for the Joystick  
Added: New Graphic for the Fire Button.  
Added: New Graphic for the Pause button 
Modified: New Package name in AndroidManifest.xml for AMAZON  
Modified: New Package name in AndroidManifest.xml for ANDROID  
Modified: New Bundle ID for IOS  
Modified: New Bundle ID for OSX  
Modified: New Bundle ID for WIN32  
Modified: New Bundle ID for WINRT 
Modified: Joystick for the touch-screen support to look for cleaner and crisp.  
Modified: Fire button to look like a actual fire button instead of a green blob.  
Modified: Length of level from 20 scenes to 100 scenes.  
Removed: Clean up of unused images to reduce size of the game from all platforms  
Removed: Clean up of unused objects to reduce size of the game from all platforms  
Removed: Clean up of unused code to reduce size of the game from all platforms  
Removed: Clean up of unused Advertisement SDKs from all platforms  
  
### Version 0.0.8  
#### Supported Devices:  
AMAZON (Eclipse IDE)  
ANDROID (Eclipse IDE)  
IOS (XCODE IDE)  
OSX - MAC OS X (XCODE IDE)  
WIN32 - WINDOWS 32 bit System (Visual Studio 2013)  
WINRT - WINDOWS METRO (Visual Studio 2013)  
#### Changes:  
Added: NEW Checkpoint Graphic  
Added: NEW Stage Complete Graphic  
Added: Checkpoints every 5 scenes  
Modified: Scene Size from 1200 to 1400 for all scenes  
Modified: Fixed some issues with continue from checkpoint was nearly impossible continue by spacing the enemies further away after each check point.
  
