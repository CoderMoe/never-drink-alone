//
//  UIImage+NDAHelpers.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 6/16/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (NDAHelpers)

+ (instancetype)imageWithColor:(UIColor *)color;
- (instancetype)crop:(CGRect)rect;
- (instancetype)getRoundedRectImage;
+ (instancetype)convertViewToImage:(UIView *)view;

@end
