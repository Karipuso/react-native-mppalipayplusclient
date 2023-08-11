//
//  IAPMinWKJsApi.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/8/15.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPMinWKJSAPIHandler.h"
@class IAPMinWKEventContext;

/**
 *  A block to handle the jsapi event with some js data,the native context and a callback to js.
 *
 *  @param data It's some data from js.It could be nil.
 *  @param context  It contains some native context information.It could be nil.
 *  @param responseCallbackBlock  The block to callback some data to js
*/
typedef void (^IAPMinWKJsApiHandlerBlock)(NSDictionary * _Nullable data,id _Nullable context,IAPMinWKJsApiResponseCallbackBlock _Nullable responseCallbackBlock);


NS_ASSUME_NONNULL_BEGIN
/**
 *  The webcontainer JSAPI which contains the JsApi name and className or handlerblock to handler the jsapi call.
*/
@interface IAPMinWKJsApi : NSObject

/**
 The JsApi name to identify a JSAPI.
*/
@property(nonatomic, readonly, copy) NSString  *name; // JsApi名称

/**
 A ACJSAPIHandlerBlock instance;
*/
@property(nonatomic, readonly, copy) IAPMinWKJsApiHandlerBlock _Nullable handler;

/**
 The JsApi class which implements the `IAPMinWKJSAPIHandler`
*/
@property(nonatomic, readonly, weak) Class _Nullable handlerClass;

/**
 *  Creats a ACContainerJSAPI instance with jsapi name and `IAPMinWKJsApiHandlerBlock` block
 *
 *  @param name The JsApi name
 *  @param handler  The ACJSAPIHandlerBlock hander
 *
 *  @return A ACContainerJSAPI instance with a jsapi name and a IAPMinWKJsApiHandlerBlock` block
*/
+ (instancetype)jsApi:(NSString *)name
              handler:(IAPMinWKJsApiHandlerBlock _Nullable)handler;

/**
 *  Creats a IAPMinWKJsApi instance with jsapi name and a class
 *
 *  @param name The JsApi name
 *  @param handlerClass  The JsApi class which implements the `IAPMinWKJSAPIHandler`
 *
 *  @return A IAPMinWKJsApi instance with a jsapi name and a class
*/
+ (instancetype)jsApi:(NSString *)name
         handlerClass:(Class _Nullable)handlerClass;

/**
 *  Handles the jsapi call.Translate it to the handlerClass or handler of a `IAPMinWKJsApi` instance to handle it.The handler has a higher prority.
 *
 *  @param data It's some data from js.It could be nil.
 *  @param context  It contains some native context information.It could be nil.
 *  @param callback  The block to callback some data to js
*/
- (void)handler:(NSDictionary * _Nullable)data context:(IAPMinWKEventContext * _Nullable)context callback:(IAPMinWKJsApiResponseCallbackBlock _Nullable)callback;


@end
NS_ASSUME_NONNULL_END
