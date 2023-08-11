//
//  IAPMinWKJsApiManager.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/8/15.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IAPMinWKJsApi;

NS_ASSUME_NONNULL_BEGIN
/**
 *  A Singleton JsApiManager provides the webContainer JSAPI capability
*/
@interface IAPMinWKJsApiManager : NSObject
/**
 Singleton of IAPMinWKJsApiManager.

 @return return the singleon instance
*/
+ (instancetype)sharedInstance;

/**
 *  Registers a `IAPMinWKJsApi` instance
 *
 *  @param jsApi A IAPMinWKJsApi instance
*/
- (void)registerJsApi:(IAPMinWKJsApi *)jsApi;

/**
 *  UnRegisters a `IAPMinWKJsApi` instance.It only compares the jspai name.
 *
 *  @param jsApi A IAPMinWKJsApi instance
*/
- (void)unRegisterJsApi:(IAPMinWKJsApi *)jsApi;

/**
 *  Gets whether the IAPMinWKJsApiManager contains a jsapi name.
 *
 *  @param apiName A jsapi name
 *  @return A Bool value
*/
- (BOOL)isExitJsApi:(NSString *)apiName;

/**
 *  Gets a `IAPMinWKJsApi` instance with a jsapi name.
 *
 *  @param apiName A jsapi name
 *  @return A `IAPMinWKJsApi` instance
*/
- (IAPMinWKJsApi * _Nullable)jsApi:(NSString *)apiName;

/**
 *  Gets all of the jsapis registered.
 *
 *  @return A NSArray which contains all of the jsapis registered
*/
- (NSArray <IAPMinWKJsApi *> * _Nullable)jsApis;

@end
NS_ASSUME_NONNULL_END
