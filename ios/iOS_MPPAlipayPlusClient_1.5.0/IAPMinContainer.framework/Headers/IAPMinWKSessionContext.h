//
//  IAPMinWKSessionContext.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/12/9.
//  Copyright © 2019 chris.ym. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *  A class which contains some context data for a IAPMinWKWebView instance.
*/
@interface IAPMinWKSessionContext : NSObject

/**
 *  A String value to identify a IAPMinWKWebView instance.The name is to be compatible with the last container.
*/
@property(nonatomic, copy) NSString                     *nbl_id;

/**
 *  A current url
*/
@property(nonatomic, copy) NSString                     *url;

/**
 *  The initialization parameters of a IAPMinWKWebView instance
*/
@property(nonatomic, strong) NSDictionary               *params;

/**
  whether sync the cookie automatically when users login or logout.The default value is YES.
*/
@property (nonatomic,assign)BOOL syncCookieWhenLoginStatusChanged;

/**
 *  Initials a IAPMinWKSessionContext instance  with some `NSDictionary` parameters.
 *
 *  @param parameters Some `NSDictionary` parameters.Basically it need to contains the `url` and 'appId'.
 *   The `url` value is for the `url` property;the `appid` value is for the `nbl_id` property;the `isSyncCookieWhenLogin` is for the `syncCookieWhenLoginStatusChanged` property.Andt the parameters itself is set to the `params` property.
 *
 *   @return A IAPMinWKSessionContext instance .
*/
- (id)initWithParam:(NSDictionary *)parameters;
@end

NS_ASSUME_NONNULL_END
