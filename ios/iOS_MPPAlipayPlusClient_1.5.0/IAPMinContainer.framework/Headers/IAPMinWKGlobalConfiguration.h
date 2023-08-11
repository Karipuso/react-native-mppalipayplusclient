//
//  IAPMinWKWebContext.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/8/16.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface IAPMinWKGlobalConfiguration : NSObject
/**
 *  The domain whiteList for loading url.When the webcontainer begins to load a url,the webcontainer will reject the url when the domin of url is not in the domain whiteList.If the value is nil or empty,the webcontainer will allow all of the urls.
*/
@property (nonatomic, strong) NSArray <NSString *> * domainWhiteList;

/**
 *  The domain blackList for loading url.When the webcontainer begins to load a url,the webcontainer will reject the url when the domin of url is  in the domainBlackList.If the value is nil or empty,the webcontainer will allow all of the urls.It has a higher prority than the domainWhiteList.
*/
@property (nonatomic, strong) NSArray <NSString *> * domainBlackList;

/**
 *  The scheme whiteList for loading url.When the webcontainer begins to load a url,the webcontainer will reject the url when the scheme of url is not in the domain whiteList.
*/
@property (nonatomic, strong) NSArray <NSString *> * schemeWhiteList;

/**
 *  The domain JSAPIPermission for jsapi permission.When the webcontainer get a jspai calling,the webcontainer will reject the jsapi calling when the domin of url is not in the domainOnJSAPIPermission.If the value is nil or empty,the webcontainer will allow all of the jsapi.
*/
@property (nonatomic, strong) NSDictionary <NSString *, NSArray *> * domainOnJSAPIPermission;

/**
 *  The scheme for jsapi permission.When the webcontainer get a jspai calling,the webcontainer will reject the jsapi calling when the scheme of url is not in the schemeOnJSAPIPermission.If the value is nil or empty,the webcontainer will allow all of the jsapi.
*/
@property (nonatomic, strong) NSArray <NSString *> * schemeOnJSAPIPermission;

/**
 *  If it's true,the webcontainer will reject all of the jsapi.The default value is NO
*/
@property (nonatomic, assign) BOOL forbiddenAllJSAPI;

/**
 *  If it's false,the webcontainer will not inject any local js.The default value is YES
*/
@property (nonatomic, assign) BOOL enableInjectLocalJS;

@end

