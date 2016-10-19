//
//  NDADashboardViewController.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 7/5/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import <AMPopTip/AMPopTip.h>

@protocol NDADashboardViewControllerDelegate <NSObject>
@required
- (UINavigationController *)navigationController;
- (UINavigationItem *)navigationItem;
- (void)switchView;
@end

@interface NDADashboardViewController : UIViewController

/**
 * To access the parent page controller's propeties and methods.
 */
@property (assign, nonatomic) id<NDADashboardViewControllerDelegate> delegate;

@end
