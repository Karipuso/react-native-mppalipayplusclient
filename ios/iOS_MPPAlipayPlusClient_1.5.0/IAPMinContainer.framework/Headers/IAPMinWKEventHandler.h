//
//  IAPMinWKEventHandler.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/10/2.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>
@class IAPMinWKEvent;
NS_ASSUME_NONNULL_BEGIN
/**
 *  A protocol which defines the interface to handle the event.
*/
@protocol IAPMinWKEventHandler <NSObject>
@required
/**
 * Handles the event with the `IAPMinWKEvent` parameter.When a `IAPMinWKEvent` event occurs,the ACEventHandler registered the event will be called this method.You can cancel or stop to propagate eht event.
 * @param event A IAPMinWKEvent value.
*/
- (void)handleEvent:(IAPMinWKEvent *)event;

/**
 * Sets the event hander name
 * @return A String value.
 *
*/
- (NSString *)name;
@end

NS_ASSUME_NONNULL_END
