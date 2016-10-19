//
//  NDAEditBiographyViewController.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 11/16/15.
//  Copyright © 2015 Ayan Yenbekbay. All rights reserved.
//

@protocol NDAEditBiographyViewControllerDelegate <NSObject>
@required
- (void)didFinishEditingBiographyWithText:(NSString *)text;
@end

@interface NDAEditBiographyViewController : UIViewController

#pragma mark Properties

@property (weak, nonatomic) id<NDAEditBiographyViewControllerDelegate> delegate;

#pragma mark Methods

+ (CGSize)viewSize;

@end
