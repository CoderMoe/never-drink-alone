//
//  UILabel+NDAHelpers.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 2/27/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

@interface UILabel (NDAHelpers)

- (void)setFrameToFitWithHeightLimit:(CGFloat)heightLimit;
- (CGSize)sizeToFitWithHeightLimit:(CGFloat)heightLimit;

@end
