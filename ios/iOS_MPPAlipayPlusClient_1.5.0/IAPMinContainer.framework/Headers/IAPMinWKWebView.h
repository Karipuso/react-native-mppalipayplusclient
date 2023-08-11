//
//  IAPWKWebView.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/8/14.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "IAPMinWKSession.h"
NS_ASSUME_NONNULL_BEGIN

@class IAPMinWKWebViewController;
/**
 * A class to provider the wkwebview instance.It's basic component of the SDK.
*/
@interface IAPMinWKWebView : NSObject

/**
 The `WKWebView` instance in the IAPMinWKWebView instance.
*/
@property (nonatomic, strong, readonly) WKWebView *  webView;

/**
 The `WKWebView` instance in the IAPMinWKWebView instance.
*/
@property (nonatomic, weak) IAPMinWKWebViewController * webViewContainer;

/**
 The `IAPMinWKSession` instance in the IAPMinWKWebView instance.
*/
@property (nonatomic, strong) IAPMinWKSession * session;

/**
 The initialization parameters
*/
@property (nonatomic, strong, readonly) NSDictionary *parameters;

/**
 The initialization url in the initialization parameters
*/
@property (nonatomic, copy, readonly) NSString *url;

/**
 The current useragent
*/
@property (nonatomic, copy, readonly) NSString *useAgent;


/**
 *  Creats a IAPMinWKWebView instance from webContainer SDK with some `NSDictionary` parameters.It's basic component of the SDK.
 *
 *  @param parameters Some `NSDictionary` parameters.Basically it need to contains the `url` and `userAgentSuffix` values.The `url` will be used to load a request.The `userAgentSuffix` will be used to add some suffix string in the webcontainer useragent.
 *
 *   @return A IAPMinWKWebView instance which owns jsapi and eventplugin capability.
*/
+ (IAPMinWKWebView *_Nullable)webView:(CGRect)frame  parameters:(NSDictionary <NSString *,id> * _Nullable)parameters;

/**
 *  Starts to load a url in property by the WKWebview.
*/
- (void)startLoadRequest;

/**
 *  Starts to load a request by the WKWebview.
 *
 *  @param request A NSURLRequest parameters.It will repalce the url in property.
*/
- (void)loadRequest:(NSURLRequest * _Nullable)request;


@end
NS_ASSUME_NONNULL_END

