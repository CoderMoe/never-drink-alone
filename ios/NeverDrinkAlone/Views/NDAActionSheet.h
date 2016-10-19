//
//  NDAActionSheet.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 03/13/15
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAConstants.h"

@interface NDAActionSheet : UIView

#pragma mark Properties

@property (copy, nonatomic) NDADismissHandler dismissHandler;
@property (copy, nonatomic) NSString *cancelButtonTitle;
@property (copy, nonatomic) NSString *title;
@property (nonatomic) BOOL automaticallyTintButtonImages;
// Boxed boolean value. Useful when adding buttons without images. Disabled by default
@property (nonatomic, getter = isButtonTextCenteringEnabled) BOOL buttonTextCenteringEnabled;
// Boxed boolean value. Enables/disables control hiding with pan gesture. Enabled by default
@property (nonatomic) BOOL cancelOnPanGestureEnabled;
@property (nonatomic) CGFloat buttonHeight;
@property (nonatomic) NSDictionary *buttonTextAttributes;
@property (nonatomic) NSDictionary *titleTextAttributes;
@property (nonatomic) NSTimeInterval animationDuration;
@property (nonatomic) NSUInteger activeIndex;
@property (nonatomic) NSUInteger staticIndex;
// If set, a small shadow (a gradient layer) will be drawn above the cancel button to separate it visually from the
// other buttons
@property (nonatomic) UIColor *cancelButtonShadowColor;
// Background color of the button when it's tapped (internally it's a UITableViewCell)
@property (nonatomic) UIColor *selectedBackgroundColor;
@property (nonatomic) UIColor *separatorColor;
// View to display above the buttons (only if the title isn't set)
@property (nonatomic) UIView *headerView;

#pragma mark Methods

- (instancetype)initWithTitle:(NSString *)title;
- (void)addButtonWithTitle:(NSString *)title handler:(NDADismissHandler)handler;
- (void)addButtonWithTitle:(NSString *)title image:(UIImage *)image handler:(NDADismissHandler)handler;
- (void)addView:(UIView *)view;
- (void)show;
- (void)dismissAnimated:(BOOL)animated;

@end
