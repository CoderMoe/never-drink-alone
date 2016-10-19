//
//  NDAEmailAuthorizationViewController.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 7/5/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAAlertManager.h"

@interface NDAEmailAuthorizationViewController : UIViewController

#pragma mark Properties

@property (nonatomic) UITextField *emailTextField;
@property (nonatomic) UITextField *passwordTextField;
@property (nonatomic) UITextField *firstNameTextField;
@property (nonatomic) UITextField *lastNameTextField;
/**
 *  String representing the action this view controller serves (login or sign up).
 */
@property (nonatomic) NSString *action;
/**
 *  Used to display notifications and alerts.
 */
@property (nonatomic) NDAAlertManager *alertManager;

#pragma mark Methods

- (void)actionButtonTapped;
- (NSString *)stringForError:(NSError *)error;
- (void)continueRegistration;
- (void)goToDashboard;

@end
