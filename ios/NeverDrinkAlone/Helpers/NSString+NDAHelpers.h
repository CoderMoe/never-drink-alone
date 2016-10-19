//
//  NSString+NDAHelpers.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 6/21/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

@interface NSString (NDAHelpers)

- (CGSize)sizeWithFont:(UIFont *)font width:(CGFloat)width;
+ (NSString *)getNumEnding:(NSInteger)number endings:(NSArray *)endings;

@end
