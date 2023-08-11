//
//  IAPMinWKCookieManager.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/11/5.
//  Copyright © 2019 chris.ym. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
The type to synchronize cookies

- IAPMinWKCookieBidirectionalSync: The default type.It's contains the IAPMinWKCookieNativeToWKOnly and IAPMinWKCookieNativeToWKOnly
- IAPMinWKCookieNativeToWKOnly: It will only sync the cookies from the native to h5.
- IAPMinWKCookieWKToNativeOnly: It will only sync the cookies from the h5 to native.
- IAPMinWKCookieNOSYNC: It will no sync the cookiew between native and h5.
*/
typedef NS_ENUM(NSInteger, IAPMinWKCookieSyncType) {
    IAPMinWKCookieBidirectionalSync = 1,
    IAPMinWKCookieNativeToWKOnly = 1 << 1,
    IAPMinWKCookieWKToNativeOnly = 1 << 2,
    IAPMinWKCookieNOSYNC = 1 << 3,
};

/*
 * A Singleton EventManager which provides the synchronous cookies capability between native and h5
 * Noted:if the system version < iOS 11，it will't sync the cookies which the cookie.name or cookie.value contains the `'` value.
 *
 */
@interface IAPMinWKCookieManager : NSObject

/**
  A current cookieSyncType how to sync cookies between native and h5.
*/
@property (nonatomic,assign)IAPMinWKCookieSyncType cookieSyncType;


/**
 Singleton of IAPMinWKCookieManager.

 @return return the singleon instance
*/
+ (instancetype)sharedInstance;

/**
 *  Adds a `NSHTTPCookie` value which need to be synced between native and h5.
 *
 *  @param syncCookie A NSHTTPCookie instance
 *  @return A Bool value whether the add-operation is successful
*/
- (BOOL)addSyncCookie:(NSHTTPCookie *)syncCookie;

/**
 *  Removes a `NSHTTPCookie` value which need to be synced between native and h5.
 *
 *  @param syncCookie A NSHTTPCookie instance
 *  @return A Bool value whether the remove-operation is successful
*/
- (BOOL)removeSyncCookie:(NSHTTPCookie *)syncCookie;

/**
 *  Adds a list `NSHTTPCookie` values which need to be synced between native and h5.
 *
 *  @param syncCookies A NSArray of cookies
 *  @return A Bool value whether the add-operation is successful
*/
- (BOOL)addSyncCookieList:(NSArray <NSHTTPCookie *> *)syncCookies;

/**
 *  Removes a list `NSHTTPCookie` values which need to be synced between native and h5.
 *
 *  @param syncCookies A NSArray of cookies
 *  @return A Bool value whether the remove-operation is successful
*/
- (BOOL)removeSyncCookieList:(NSArray <NSHTTPCookie *> *)syncCookies;

/**
 *  Gets whether the IAPMinWKCookieManager contains a `NSHTTPCookie` instance.
 *
 *  @param syncCookie A NSHTTPCookie instance
 *  @return A Bool value whether syncCookie is existed
*/
- (BOOL)isCookieExisted:(NSHTTPCookie *)syncCookie;

/**
 *  Gets a NSHTTPCookie instance in the IAPMinWKCookieManager needSyncCookieList.
 *
 *  @param name A NSHTTPCookie name
 *  @param domain A NSHTTPCookie domain
 *  @return A NSHTTPCookie instance in the IAPMinWKCookieManager needSyncCookieList
*/
- (NSHTTPCookie *)cookie:(NSString *)name domain:(NSString *)domain;

/**
 *  Clear all of the needSyncCookieList.
 *
*/
- (void)clearAllSyncCookies;

/**
 *  Gets all of the NSHTTPCookie instances in the IAPMinWKCookieManager needSyncCookieList.
 *
 *  @return A Array list contains some NSHTTPCookie in the IAPMinWKCookieManager needSyncCookieList
*/
- (NSArray <NSHTTPCookie *> *)allSyncCookies;

/**
 *  Be enable to sync cookies from app to h5 with a WKWebview instance.
 *
 *  @param webView A WKWebView instance
 *  @return A Bool value whether the operation is sucessful
*/
- (BOOL)enableSyncCookieFromWKtoNative:(WKWebView *)webView;

/**
 *  Syncs cookies from app to h5.
 *
 *  @param webView A WKWebView instance
 *  @param request The current request that the webview is loading
 *  @param isMainRequest A Bool value whether the request is first one
 *  @return A Bool value whether the operation is sucessful
*/
- (BOOL)syncCookieFromNativetoWK:(WKWebView *)webView request:(NSMutableURLRequest *)request isMainRequest:(BOOL)isMainRequest;

/**
 *  Syncs cookies from h5 to native.
 *
 *  @param cookie A string value contains the cookie data to add
 *  @param url The current url
 *  @param domainUrl The URL of the main HTML document for the top-level frame, if known. The value can be nil. This URL is used to determine whether the cookie should be accepted if the cookie accept policy is NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain.
 *  @param webView A WKWebView instance
*/
- (void)syncCookieFromWKtoNative:(NSString *)cookie url:(NSURL *)url domainUrl:(NSURL *)domainUrl webview:(WKWebView *)webView;

@end

NS_ASSUME_NONNULL_END
