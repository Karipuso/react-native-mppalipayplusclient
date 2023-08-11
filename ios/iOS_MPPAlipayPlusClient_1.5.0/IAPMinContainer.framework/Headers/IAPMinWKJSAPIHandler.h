//
//  JSAPIHandler.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/8/15.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPMinWKEventContext.h"
/**
 *  A block to pass datas from native to the js when the jsapi call.
 *
 *  @param responseData It will be passed from native to the js.
*/
typedef void (^IAPMinWKJsApiResponseCallbackBlock)(id _Nullable responseData);

@protocol IAPMinWKJSAPIHandler <NSObject>

@required
/**
 *  A method to handle the jsapi event with some js data ,the native context and a callback to js.
 *
 *  @param data It's some data from js.It could be nil.
 *  @param context  It contains some native context information.It could be nil.
 *  @param callback  The block to callback some data to js
*/
- (void)handler:(NSDictionary * _Nullable)data context:(IAPMinWKEventContext * _Nullable)context callback:(IAPMinWKJsApiResponseCallbackBlock _Nullable)callback;
@end

