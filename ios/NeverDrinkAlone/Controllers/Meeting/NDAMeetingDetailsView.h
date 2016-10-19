//
//  NDAMeetingDetailsView.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 6/27/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAMeeting.h"
#import "NDAMeetingViewController.h"

@interface NDAMeetingDetailsView : UIScrollView

#pragma mark Properties

@property (weak, nonatomic) NDAMeeting *meeting;
@property (nonatomic) id<NDAMeetingViewControllerDelegate> meetingDelegate;

#pragma mark Methods

- (void)setUserStatuses;

@end
