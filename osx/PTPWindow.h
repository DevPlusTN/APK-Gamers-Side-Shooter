//
//  PTPWindow.h
//  PTPlayer
//
//  Created by Nik Rudenko on 9/25/14.
//
//

#import <Cocoa/Cocoa.h>

@interface PTPWindow : NSWindow{
    
}
- (void)keyDown:(NSEvent *)theEvent;
- (void)keyUp:(NSEvent *)theEvent;
- (int)mapKeys:(unsigned short)key;
@end
