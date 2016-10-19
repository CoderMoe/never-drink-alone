//
//  UIColor+NDAHelpers.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 2/17/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

@interface UIColor (NDAHelpers)

- (instancetype)darkerColor:(CGFloat)decrement;
- (instancetype)lighterColor:(CGFloat)increment;

@end
