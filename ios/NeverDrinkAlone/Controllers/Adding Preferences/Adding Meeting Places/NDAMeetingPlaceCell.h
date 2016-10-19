//
//  NDAMeetingPlaceCell.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 6/20/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAPreferencesObjectCell.h"

@interface NDAMeetingPlaceCell : NDAPreferencesObjectCell

/**
 *  Label with the name of the meeting place.
 */
@property (nonatomic) UILabel *nameLabel;
/**
 *  Label with the address of the meeting place.
 */
@property (nonatomic) UILabel *addressLabel;

@end
