//
//  IAPMinWKEvent.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/10/2.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPMinWKEventContext.h"

NS_ASSUME_NONNULL_BEGIN
/**
* The IAPMinWKContainer Event module to define an event.
*/
@interface IAPMinWKEvent : NSObject
/**
  A BOOL value whether the event can be bubbled.
*/
@property(nonatomic, readonly) BOOL bubbles;

/**
  A BOOL value whether the event can be canceled.
*/
@property(nonatomic, readonly) BOOL cancelable;

/**
  The timeStamp when the event occurs
*/
@property(nonatomic, readonly) NSTimeInterval timeStamp;

/**
  The event name
*/
@property(nonatomic, readonly, copy) NSString *eventType;

/**
  The current context
*/
@property(nonatomic, strong) IAPMinWKEventContext *context;
/**
  The current request of webcontainer
*/
@property(nonatomic, strong) NSURLRequest *request;

/**
  The current url of webcontainer
*/
@property(nonatomic, copy) NSString *url;

/**
  A occuring error in the event
*/
@property(nonatomic, strong) NSError  *error;

/**
  A BOOL value whether the event has be canceled.
*/
@property(nonatomic, readonly) BOOL isCancelled;

/**
  A BOOL value whether the event has be stop.
*/
@property(nonatomic, readonly) BOOL isStoped;

/**
 *  Creats a ACContainerEvent instance with event name ,canBubble,cancelable
 *
 *  @param eventType The event name
 *  @param canBubble A BOOL value whether the event can be bubbled.
 *  @param cancelable A BOOL value whether the event can be canceled.
 *
 *  @return A ACContainerEvent instance
*/
- (instancetype)initWithEventType:(NSString *)eventType canBubble:(BOOL)canBubble cancelable:(BOOL)cancelable;

/**
 *  Stops to propagate the current event
*/
- (void)stopPropagation;

/**
 *  Cancels the current event
*/
- (void)preventDefault;
@end

NS_ASSUME_NONNULL_END
