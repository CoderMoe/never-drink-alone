//
//  NDALoadingImageView.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 6/24/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

@interface NDALoadingImageView : UIImageView

#pragma mark Properties

@property (nonatomic, readonly) UIActivityIndicatorView *spinner;
@property (nonatomic) UIActivityIndicatorViewStyle spinnerStyle;

#pragma mark Methods

/**
 *  Start animating the activity indicator.
 */
- (void)startSpinning;
/**
 *  Stop animating the activity indicator.
 */
- (void)stopSpinning;

@end
