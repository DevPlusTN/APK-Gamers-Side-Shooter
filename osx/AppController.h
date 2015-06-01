
#import "cocos2d.h"
#import "EAGLView.h"
#import "PTPWindow.h"

@interface AppController : NSObject <NSApplicationDelegate> {
    PTPWindow *window;
    EAGLView *glView;
}
@property (nonatomic, assign) IBOutlet NSWindow* window;
@property (nonatomic, assign) IBOutlet EAGLView* glView;

-(void)setFullscreen:(BOOL)value;
-(NSRect)screenResolution;
-(void)loadingDidComplete;

@end

