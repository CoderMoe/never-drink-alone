//
//  NSDate+NDAHelpers.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 7/9/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

@interface NSDate (NDAHelpers)

- (NSInteger)daysFromToday;
- (NSString *)weekdayString;
- (NSString *)dayString;
- (NSString *)dateString;
- (NSString *)fullDate;
- (NSString *)birthdayDate;
- (NSInteger)ageFromDate;
- (NSTimeInterval)timeLeftToDate;
- (NSString *)formattedTimeLeftToDate;
+ (NSInteger)currentHour;
+ (instancetype)dateForHour:(NSInteger)hour;
- (NSString *)messageString;
+ (instancetype)dateFromMessageString:(NSString *)messageString;
- (NSString *)timeAgo;

@end
