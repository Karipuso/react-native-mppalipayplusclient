//
//  IAPMinWKService.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/10/2.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPMinWKGlobalConfiguration.h"
@class IAPMinWKWebView;
@class IAPMinWKWebViewController;
NS_ASSUME_NONNULL_BEGIN
/**
 * Lite version of webContainer service
*/
@interface IAPMinWKService : NSObject

/**
  Some global configurations to control the webcontainer.
*/
@property (nonatomic, strong) IAPMinWKGlobalConfiguration *configuration;

/**
 Singleton of IAPMinWKService.

 @return return the singleon instance
*/
+ (instancetype)sharedInstance;

/**
 Starts the IAPMinWKService service.It should be called before any other APIs.
*/
- (void)startService;

/**
 *  Creats a UIViewController instance from IAPMinWKWeb SDK with some `NSDictionary` parameters
 *
 *  @param parameters Some `NSDictionary` parameters.Basically it need to contains the `url` and `userAgentSuffix` values.The `url` will be used to load a request.The `userAgentSuffix` will be used to add some suffix string in the webcontainer useragent.
 *
 *   @return A UIViewContainer instance which owns jsapi and eventplugin capability
*/
- (IAPMinWKWebViewController * _Nullable)viewControllerWithParameter:(NSDictionary <NSString *,id> * _Nullable)parameters;

/**
 *  Creats a IAPMinWKWebView instance from webContainer SDK with some `NSDictionary` parameters.It's basic component of the SDK.
 *
 *  @param parameters Some `NSDictionary` parameters.Basically it need to contains the `url` and `userAgentSuffix` values.The `url` will be used to load a request.The `userAgentSuffix` will be used to add some suffix string in the webcontainer useragent.
 *
 *   @return A IAPMinWKWebView instance which owns jsapi and eventplugin capability.
*/
- (IAPMinWKWebView * _Nullable)webView:(CGRect)frame parameters:(NSDictionary <NSString *,id> * _Nullable)parameters;
@end

NS_ASSUME_NONNULL_END
