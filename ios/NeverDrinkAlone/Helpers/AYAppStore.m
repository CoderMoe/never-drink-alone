//
//  AYAppStore.m
//  AYToolbox
//
//  Created by Ayan Yenbekbay on 18/06/2014.
//  Copyright (c) 2014 Ayan Yenbekbay. All rights reserved.
//

#import "AYAppStore.h"

@implementation AYAppStore

+ (void)openAppStoreReviewForApp:(NSString *)appId {
  if ([[[UIDevice currentDevice] systemVersion] compare:@"7.1" options:NSNumericSearch] != NSOrderedAscending) {
    // Since 7.1 we can throw to the review tab
    NSString *url = [NSString stringWithFormat:@"http://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?id=%@&pageNumber=0&sortOrdering=2&type=Purple+Software&mt=8", appId];
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
  } else {
    [self openAppStoreForApp:appId];
  }
}

+ (void)openAppStoreForApp:(NSString *)appId {
  NSString *url = [NSString stringWithFormat:@"https://itunes.apple.com/kz/app/app/id%@?mt=8", appId];
  [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
}

@end
