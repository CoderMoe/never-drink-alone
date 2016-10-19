//
//  AYFeedback.h
//  AYToolbox
//
//  Created by Ayan Yenbekbay on 7/7/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

@interface AYFeedback : NSObject

@property (nonatomic) NSString *subject;
@property (nonatomic, readonly) NSString *deviceModel;
@property (nonatomic, readonly) NSString *operatingSystemVersion;
@property (nonatomic, readonly) NSString *appVersion;
@property (nonatomic, readonly) NSString *appName;
@property (nonatomic, readonly) NSString *messageWithMetaData;

@end
