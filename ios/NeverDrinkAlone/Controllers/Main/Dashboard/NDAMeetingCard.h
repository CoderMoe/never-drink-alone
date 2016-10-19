//
//  NDAMeetingCard.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 10/23/15.
//  Copyright © 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAMeeting.h"
#import <ReactiveCocoa/ReactiveCocoa.h>

@interface NDAMeetingCard : UIButton

#pragma mark Properties

@property (weak, nonatomic) NDAMeeting *meeting;

#pragma mark Methods

- (RACSignal *)show;
- (RACSignal *)hide;

@end
