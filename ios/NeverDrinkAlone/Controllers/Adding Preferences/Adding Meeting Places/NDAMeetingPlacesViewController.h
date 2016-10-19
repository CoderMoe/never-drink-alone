//
//  NDAMeetingPlacesViewController.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 6/19/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDASearchablePreferencesViewController.h"

@interface NDAMeetingPlacesViewController : NDASearchablePreferencesViewController

/**
 *  Trigerred by a notification, loads NDArby venues through Foursquare.
 */
- (void)locationLoaded;

@end
