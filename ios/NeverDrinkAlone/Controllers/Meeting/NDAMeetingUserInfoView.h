//
//  NDAMeetingUserInfoView.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 6/27/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAMeetingViewController.h"
#import <Parse/Parse.h>

@interface NDAMeetingUserInfoView : UIView

#pragma mark Properties

@property (weak, nonatomic) PFUser *user;
@property (nonatomic) id<NDAMeetingViewControllerDelegate> meetingDelegate;

#pragma mark Methods

- (void)shrink;
- (void)expand;

@end
