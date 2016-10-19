//
//  NDAOutcomingMessage.h
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 11/28/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import <JSQMessagesViewController/JSQMessages.h>

@interface NDAOutcomingMessage : NSObject

- (instancetype)initWithChatId:(NSString *)chatId;
- (void)sendWithText:(NSString *)text;

@end
