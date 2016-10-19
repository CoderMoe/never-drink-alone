//
//  CLLocation+NDAHelpers.m
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 10/31/15.
//  Copyright © 2015 Ayan Yenbekbay. All rights reserved.
//

#import "CLLocation+NDAHelpers.h"

static NSTimeInterval const kRecentLocationMaximumElapsedTimeInterval = 5;

@implementation CLLocation (NDAHelpers)

- (BOOL)isStale {
  return [self elapsedTimeInterval] > kRecentLocationMaximumElapsedTimeInterval;
}

- (NSTimeInterval)elapsedTimeInterval {
  return [[NSDate date] timeIntervalSinceDate:self.timestamp];
}

@end
