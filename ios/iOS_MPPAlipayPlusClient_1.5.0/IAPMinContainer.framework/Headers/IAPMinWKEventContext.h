//
//  IAPMinWKEventContext.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/10/10.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPMinWKWebViewController.h"
#import "IAPMinWKWebView.h"
#import "IAPMinWKSession.h"
@class IAPMinWKEvent;

NS_ASSUME_NONNULL_BEGIN

@interface IAPMinWKEventContextParams: NSObject
/**
   A `NSDictionary` instance.Basically it need to contains the `url` , `userAgentSuffix` and 'appId' values.It always comes from the `- (UIViewController * _Nullable)viewControllerWithParameter:(NSDictionary <NSString *,id> * _Nullable)parameters;` in the `IAPMinWKService`
*/
@property(nonatomic, copy) NSDictionary * _Nullable expandParams;
@end

/**
 *  A class which defines the capability of the event and japis context.
*/
@interface IAPMinWKEventContext : NSObject

/**
 *  The current UIViewcontroller when the event occured;
*/
@property (nonatomic,weak)IAPMinWKWebViewController * currentViewController;

/**
 *  The current webview when the event occured;
*/
@property (nonatomic,weak)IAPMinWKWebView * currentWebView;

/**
 *  The current event in the context;
*/
@property(nonatomic, weak) IAPMinWKEvent *event;

/**
 *  The current session when the event occured;
*/
@property(nonatomic,weak)  IAPMinWKSession *currentSession;

/**
 *  The current extra params when the event occured;  designed for ac SPI
*/
@property (nonatomic, strong, readonly) IAPMinWKEventContextParams *params;

@end

NS_ASSUME_NONNULL_END
