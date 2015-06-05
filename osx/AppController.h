
#import "cocos2d.h"
#import "EAGLView.h"
#import "PTPWindow.h"

@interface AppController : NSObject <NSApplicationDelegate> {
    NSWindow *window;
    EAGLView *glView;
    
    NSRect _originalWinRect;
    cocos2d::CCSize _originalFrameSize;
}
@property (nonatomic, assign) IBOutlet NSWindow* window;
@property (nonatomic, assign) IBOutlet EAGLView* glView;

-(void)setFullscreen:(BOOL)value;
-(NSRect)screenResolution;
-(void)loadingDidComplete;
-(void)adjustWindowForFullscreen:(BOOL)fullscreen;
@end

