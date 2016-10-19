//
//  NDAKarmaCard.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 10/23/15.
//  Copyright © 2015 Ayan Yenbekbay. All rights reserved.
//

#import <ReactiveCocoa/ReactiveCocoa.h>

@interface NDAKarmaCard : UIButton

- (RACSignal *)updateKarma;

@end
