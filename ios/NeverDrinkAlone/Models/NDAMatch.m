//
//  NDAMatch.m
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 7/7/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAMatch.h"

@implementation NDAMatch

@dynamic firstUser;
@dynamic secondUser;
@dynamic interests;

#pragma mark Initialization

- (instancetype)initWithFirstUser:(PFUser *)firstUser secondUser:(PFUser *)secondUser interests:(NSArray *)interests {
  self = [super init];
  if (!self) {
    return nil;
  }

  self.firstUser = firstUser;
  self.secondUser = secondUser;
  self.interests = interests;

  return self;
}

#pragma mark PFSubclassing

+ (void)load {
  [self registerSubclass];
}

+ (NSString *)parseClassName {
  return @"Match";
}

@end
