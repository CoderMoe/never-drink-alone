//
//  NDAProgressView.h
//  Never Drink Alone
//
//  Created by kishikawa katsumi on 12/13/2014. (Modified by Ayan Yenbekbay on 3/1/2015)
//  Copyright (c) 2014 kishikawa katsumi. All rights reserved.
//

@interface NDAProgressView : UIView

#pragma mark Properties

@property (nonatomic) CGFloat lineWidth;
@property (nonatomic) CGFloat progress;
@property (nonatomic) CGFloat radius;
@property (nonatomic) CGFloat spinnerHeight;
@property (nonatomic) UIColor *tintColor;
@property (nonatomic) UIView *backgroundView;
@property (nonatomic, getter = isIndeterminate) BOOL indeterminate;

#pragma mark Methods

/**
 *  Setter for the value of the progress arc in the view.
 *
 *  @param progress The value to set for the progress.
 *  @param animated Whether or not to animate the change.
 */
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;
/**
 *  Animate the progress view disappearing and remove it from its superview.
 */
- (void)performFinishAnimation;

@end
