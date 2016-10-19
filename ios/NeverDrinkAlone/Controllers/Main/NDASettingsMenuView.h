//
//  NDASettingsMenuView.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 10/10/15.
//  Copyright © 2015 Ayan Yenbekbay. All rights reserved.
//

@class NDASettingsMenuView;

@protocol NDASettingsMenuViewDelegate <NSObject>
@required
- (void)menuView:(NDASettingsMenuView *)menuView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
@end

@interface NDASettingsMenuView : UIView

#pragma mark Properties

@property (weak, nonatomic) id<NDASettingsMenuViewDelegate> delegate;
@property (nonatomic) UITableView *tableView;

#pragma mark Methods

- (instancetype)initWithFrame:(CGRect)frame images:(NSArray *)images titles:(NSArray *)titles;

@end
