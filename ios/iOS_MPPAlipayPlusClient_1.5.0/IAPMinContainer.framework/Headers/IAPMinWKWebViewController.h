//
//  IAPMinWKWebViewController.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/8/14.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IAPMinWKWebView.h"

NS_ASSUME_NONNULL_BEGIN
/**
 * A class to provider the webcontainer viewcontroller
*/
@interface IAPMinWKWebViewController : UIViewController

/**
 The webView instance in the viewcontroller.
*/
@property (nonatomic, strong, readonly) IAPMinWKWebView *webView;

/**
 The `IAPMinWKSession` instance in the IAPMinWKWebView instance.
*/
@property (nonatomic, readonly) IAPMinWKSession *session;

/**
 The initialization parameters
*/
@property (nonatomic, strong, readonly) NSDictionary *parameters;

/**
 The initialization url in the initialization parameters
*/
@property (nonatomic, copy, readonly) NSString *url;

/**
 *  Creats a UIViewController instance from IAPMinWKWeb SDK with some `NSDictionary` parameters
 *
 *  @param parameters Some `NSDictionary` parameters.Basically it need to contains the `url` and `userAgentSuffix` values.The `url` will be used to load a request.The `userAgentSuffix` will be used to add some suffix string in the webcontainer useragent.
 *
 *   @return A UIViewContainer instance which owns jsapi and eventplugin capability
*/
+ (IAPMinWKWebViewController *)viewControllerWithParameters:(NSDictionary <NSString *,id> * _Nullable)parameters;
@end

NS_ASSUME_NONNULL_END
