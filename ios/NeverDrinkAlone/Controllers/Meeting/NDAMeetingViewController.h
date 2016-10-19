//
//  NDAMeetingViewController.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 6/27/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAMeeting.h"

@protocol NDAMeetingViewControllerDelegate <NSObject>
@required
- (void)displayImageForImageView:(UIImageView *)imageView;
- (void)shrinkUserInfoView;
- (void)expandUserInfoView;
- (void)userInfoViewChangedHeight:(CGFloat)heightDiff;
@end

@interface NDAMeetingViewController : UIViewController <NDAMeetingViewControllerDelegate>

#pragma mark Properties

@property (nonatomic, readonly) NDAMeeting *meeting;

#pragma mark Methods

- (instancetype)initWithMeeting:(NDAMeeting *)meeting;

@end
