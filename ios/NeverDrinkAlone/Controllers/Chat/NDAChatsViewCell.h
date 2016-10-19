//
//  NDAChatsViewCell.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 10/29/15.
//  Copyright © 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAMatch.h"

@interface NDAChatsViewCell : UITableViewCell

@property (nonatomic) NSDictionary *recent;
@property (nonatomic, readonly) NDAMatch *match;

@end
