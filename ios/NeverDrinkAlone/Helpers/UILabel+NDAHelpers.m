//
//  UILabel+NDAHelpers.m
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 2/27/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "UILabel+NDAHelpers.h"

#import "UIView+AYUtils.h"

@implementation UILabel (NDAHelpers)

- (void)setFrameToFitWithHeightLimit:(CGFloat)heightLimit {
  self.height = [self sizeToFitWithHeightLimit:heightLimit].height;
}

- (CGSize)sizeToFitWithHeightLimit:(CGFloat)heightLimit {
  NSMutableParagraphStyle *paragraphStyle = [NSMutableParagraphStyle new];

  paragraphStyle.lineBreakMode = NSLineBreakByWordWrapping;
  return ([self.text boundingRectWithSize:CGSizeMake(self.width, heightLimit) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{
             NSParagraphStyleAttributeName : paragraphStyle.copy,
             NSFontAttributeName : self.font
           } context:nil]).size;
}

@end
