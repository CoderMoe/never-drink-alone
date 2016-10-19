//
//  GLMenuListViewCell.h
//  Galileo
//
//  Created by Ayan Yenbekbay on 10/11/15.
//  Copyright © 2015 Ayan Yenbekbay. All rights reserved.
//

@interface GLMenuListViewCell : UITableViewCell

@property (nonatomic) UILabel *titleLabel;
@property (nonatomic) UIImageView *iconImageView;
@property (nonatomic, getter=isAnimating) BOOL animating;

@end
