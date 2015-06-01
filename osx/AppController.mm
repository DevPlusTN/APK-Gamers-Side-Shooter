

#import "AppController.h"
#import "PTPAppDelegate.h"

#import "models/PTModelController.h"
#import "models/PTModelGeneralSettings.h"

@implementation AppController
    @synthesize window, glView;

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static PTPAppDelegate s_sharedApplication;

-(void) applicationDidFinishLaunching:(NSNotification *)aNotification{
    
    PTModelController *mc = PTModelController::shared();
    mc->clean();
    mc->loadDataForClass( CCString::create("data/PTModelGeneralSettings.0.xml") );
    mc->loadDataForClass( CCString::create("data/PTModelFont.0.xml") );
    mc->loadDataForClass( CCString::create("data/PTModelScreen.0.xml") );
    mc->loadDataForClass( CCString::create("data/PTModelObjectLabel.0.xml") );
    mc->loadConnectionsForClass(CCString::create("data/PTModelScreen.0.xml"));
    
    
    
    NSRect rect = [self screenResolution];
    window = [[PTPWindow alloc] initWithContentRect:rect
        styleMask:( NSClosableWindowMask | NSTitledWindowMask )
        backing:NSBackingStoreBuffered
        defer:YES];
    
    [window setOpaque:true];
    [window setHidesOnDeactivate:YES];
    
    glView = [[EAGLView alloc] initWithFrame:rect];

    [window becomeFirstResponder];
    [window setContentView:glView];
    NSString *gameName = [NSString stringWithUTF8String:PTModelGeneralSettings::shared()->applicationName->getCString()];
    [window setTitle:gameName];
    [window makeKeyAndOrderFront:self];
    [window setAcceptsMouseMovedEvents:NO];

    [glView setFrameZoomFactor:0.6];

    printf("GL_VENDOR:     %s\n", glGetString(GL_VENDOR));
    printf("GL_RENDERER:   %s\n", glGetString(GL_RENDERER));
    printf("GL_VERSION:    %s\n", glGetString(GL_VERSION));

    cocos2d::CCApplication::sharedApplication()->run();
    //clean up main model controller before starting loading Objects form XML files
    mc->clean();
}

-(NSRect)screenResolution{
    NSScreen *screen = [NSScreen mainScreen];
    return [screen frame];
}

-(BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication
{
    return YES;
}

-(void) dealloc{
    cocos2d::CCDirector::sharedDirector()->end();
    [super dealloc];
}

-(void)setFullscreen:(BOOL)value{
    EAGLView* pView = [EAGLView sharedEGLView];
    if(value == YES){
       [glView setFrameZoomFactor:1.0];
    }
    else{
       [glView setFrameZoomFactor:0.6];
    }
    [pView setFullScreen:value];
}

-(void)loadingDidComplete{

}

@end

