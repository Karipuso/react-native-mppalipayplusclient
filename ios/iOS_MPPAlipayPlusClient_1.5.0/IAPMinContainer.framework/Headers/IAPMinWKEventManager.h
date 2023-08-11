//
//  IAPMinWKEventManager.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/10/2.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPMinWKEventHandler.h"
#import "IAPMinWKEvent.h"
NS_ASSUME_NONNULL_BEGIN
/**
 *  A Singleton EventManager which provides the webContainer event capability
*/
@interface IAPMinWKEventManager : NSObject

/**
 Singleton of IAPMinWKEventManager.

 @return return the singleon instance
*/
+ (instancetype)sharedInstance;

/**
 *  Adds an event observer which an event name and an event handle observer.
 *  The observer must implement the `IAPMinWKEventHandler` protocol
 *
 *  @param eventName The eventName.
 *  @param eventListener The observer must implement the `IAPMinWKEventHandler` protocol
*/
- (void)addEventListener:(NSString *)eventName withListener:(id<IAPMinWKEventHandler>)eventListener;

/**
 *  Removes an event observer which an event name and an event handle observer.
 *  The observer must implement the `IAPMinWKEventHandler` protocol
 *
 *  @param eventName The eventName.It can't be nil or empty
 *  @param eventListener The observer must implement the `IAPMinWKEventHandler` protocol
*/
- (void)removeEventListener:(NSString *)eventName withListener:(id<IAPMinWKEventHandler>)eventListener;

/**
 *  Gets all of the events
 *
 *  @return A NSDictionary value contains all of the event handlers.The type of key in NSDictionary is NSString,the type of value is `NSArray<id<IAPMinWKEventHandler>> *`
*/
- (NSDictionary<NSString *, NSArray<id<IAPMinWKEventHandler>> *> *)eventListenersForAll;

/**
 *  Gets the events of an eventName
 *
 *  @return A NSArray value contains some event handlers wieh an event name.
*/
- (NSArray<id<IAPMinWKEventHandler>> *)listenersForEventName:(NSString *)eventName;

/**
 *  Dispatchs an event.When it occurs,the observeres registered will be called the `handleEvent:`method.
 *
 *  @param event The IAPMinWKEvent instance.
*/
- (BOOL)dispatchEvent:(IAPMinWKEvent *)event;

@end

NS_ASSUME_NONNULL_END
