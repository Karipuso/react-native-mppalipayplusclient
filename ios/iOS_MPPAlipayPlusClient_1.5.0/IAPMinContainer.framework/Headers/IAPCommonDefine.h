//
//  IAPCommonDefine.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/10/2.
//  Copyright © 2019 iap.connect. All rights reserved.
//

#ifndef IAPCommonDefine_h
#define IAPCommonDefine_h

//************************  Start Pramameters ************************//
/**
 * A const string value to define the `url` key in the `viewControllerWithParameter:` method
*/
#define kMinWKCreate_Param_URL      @"url"

/**
 * A const string value to define the `userAgentSuffix` key in the `viewControllerWithParameter:` method.It's used to add some suffix string in the webcontainer useragent.
*/
#define kMinWKCreate_Param_UserAgentSuffix     @"userAgentSuffix"

/**
 * A const string value to define the `appId` key in the `viewControllerWithParameter:` method
*/
#define kMinWKCreate_Param_AppId      @"appId"

/**
 * A const string value to define a NSURLRequest value in the `viewControllerWithParameter:` method
*/
#define kMinWKCreate_Param_Request      @"request"

/**
 * A const string value to define a NSURLRequest method in the `viewControllerWithParameter:` method
*/
#define kMinWKCreate_Param_Method      @"method"

/**
 * A const string value to define a NSURLRequest post paramters in the `viewControllerWithParameter:` method
*/
#define kMinWKCreate_Param_PostParamters     @"postParamters"


/**
 * A const string value to define the `isSyncCookieWhenLogin` key in the `viewControllerWithParameter:` method
*/
#define kMinWKCreate_Param_IsSyncCookieWhenLogin      @"isSyncCookieWhenLogin"

//************************  JSAPI Event ************************//
/**
 * A const string value to define the jsapi event when webcontainer starts to call a jsapi
*/
#define kMinWKEvent_JSAPI_Invode                @"invocation.invoke"

//************************  Web Event ************************//

/**
 * A const string value to define the web event when the webcontainer load a request.
*/
#define kMinWKEvent_WK_load_request       @"navigation.load.request"

/**
 * A const string value to define the web event when the webcontainer starts to should load a request.You can cancel the event to stop the current webview to load a url
*/
#define kMinWKEvent_WK_Start        @"navigation.start"

/**
 * A const string value to define the web event when the webcontainer starts to load a request completely.
*/
#define kMinWKEvent_WK_DidStart     @"navigation.start.complete"

/**
 * A const string value to define the web event when the webcontainer finish load a request successfully.
*/
#define kMinWKEvent_WK_Complete     @"navigation.complete"

/**
 * A const string value to define the web event when the webcontainer is failed to load a request
*/
#define kMinWKEvent_WK_Error        @"navigation.error"

//************************  ViewController Event ************************//

/**
 * A const string value to define the viewController event when the webcontainer to create a viewcontroller
*/
#define kMinWKEvent_VC_Create       @"scene.create"

/**
 * A const string value to define the viewController event when the webcontainer to load a viewcontroller before appearing.It's like `- (void)viewWillAppear:(BOOL)animated`
*/
#define kMinWKEvent_VC_AppearBefore     @"scene.appear.before"

/**
 * A const string value to define the viewController event when the webcontainer to load a viewcontroller after appearing.It's like `- (void)viewDidAppear:(BOOL)animated`
*/
#define kMinWKEvent_VC_AppearAfter      @"scene.appear.after"

/**
 * A const string value to define the viewController event when the webcontainer to load a viewcontroller when didload.It's like `-(void)viewDidLoad:(BOOL)animated`
*/
#define kMinWKEvent_VC_Didload      @"scene.didload"

/**
 * A const string value to define the viewController event when the webcontainer to load a viewcontroller before disappearing.It's like `-(void)viewWillDisappear:(BOOL)animated`
*/
#define kMinWKEvent_VC_DisappearBefore      @"scene.disappear.before"

/**
 * A const string value to define the viewController event when the webcontainer to load a viewcontroller after disappearing.It's like `-(void)viewDidDisappear:(BOOL)animated`
*/
#define kMinWKEvent_VC_DisappearAfter       @"scene.disappear.after"

/**
 * A const string value to define the viewController event when the webcontainer to destroy a viewcontroller.It's like `- (void)dealloc`
*/
#define kMinWKEvent_VC_Destroy      @"scene.destroy"


//************************  Monitor Key ************************//
/**
 * A PV of a web page.It's added in the IAPMinWKWebViewController viewDidAppear event.
*/
#define IAPMinWKLog_pv @"mix_appcontainer_pv"

/**
 * Load a request successfully.It's added in the IAPMinWKWebView didFinishNavigation event.
*/
#define IAPMinWKLog_load_success @"mix_appcontainer_load_success"

/**
 * Load a request failed.It's added in the IAPMinWKWebView didFailNavigation&didFailProvisionalNavigation event.
*/
#define IAPMinWKLog_load_failed @"mix_appcontainer_load_failed"

/**
 * A jsApi call event.
*/
#define IAPMinWKLog_jsapi_call @"mix_appcontainer_jsapi_call"

/**
 * An event when some local js files is inserted into the wkwebview instance.
*/
#define IAPMinWKLog_insert_js @"mix_appcontainer_insert_js"

/**
 * An event when a jspai call is rejected
*/
#define IAPMinWKLog_reject_jsapi_call @"mix_appcontainer_reject_jsapi_call"

/**
 * An event when a request loaded is rejected
*/
#define IAPMinWKLog_reject_load_url @"mix_appcontainer_reject_load_url"

/**
 * Starting the IAPMinContainer event
*/
#define IAPMinWKLog_start @"mix_appcontainer_start"

/**
 * An event when the local js files is loaded failed
*/
#define IAPMinWKLog_load_js_failed @"mix_appcontainer_load_js_failed"


/**
 * An event when creating a wkwebview with some invalid params
*/
#define IAPMinWKLog_invalid_param @"mix_appcontainer_invalid_param"

/**
 * A setting customer UA failed event
*/
#define IAPMinWKLog_set_UA_failed @"mix_appcontainer_set_UA_failed"

/**
 * An event when the event loop is interupted by a `IAPMinWKEvent` instance
*/
#define IAPMinWKLog_stop_event_loop @"mix_appcontainer_stop_event_loop"

/**
 * An event when a `IAPMinWKEvent` instance is canceled.
*/
#define IAPMinWKLog_cancel_event @"mix_appcontainer_cancel_event"

/**
 * An event when native sides sync cookies to wkwebview.
*/
#define IAPMinWKLog_app2wk_sync_cookie @"mix_appcontainer_app2wk_sync_cookie"

/**
 * An event when wkwebview sync cookies to native sides.
*/
#define IAPMinWKLog_wk2app_sync_cookie @"mix_appcontainer_wk2app_sync_cookie"

/**
 * An event when some local jsmessage.js files is inserted into the wkwebview instance.
*/
#define IAPMinWKLog_insert_cookie_js @"mix_appcontainer_insert_cookie_js"

//************************  Error Code  ************************//
typedef NS_ENUM(NSUInteger, IAPMinWKErrorCode){
    IAPMinWK_UNKNOWN_ERROR                = 1099, //Unknown error
    IAPMinWK_LOCAL_FILE_LOAD_FAILED            = 1002, //The local js is loaded failed.
    IAPMinWK_LOCAL_JS_INJECT_CANCEL = 1003,  //The local js is canceled.
    IAPMinWK_INVALID_PARAMETER    = 1004, //The parameter is invalid
    IAPMinWK_WEBVIEW_SET_UA_FAIL          = 1005, //Set the UA to a WKView failed
    IAPMinWK_LOCAL_JS_INJECT_FAIL       = 1006, //Inject the js to a WKView failed
    IAPMinWK_WEBVIEW_LOAD_FAIL          = 1007, //WKWebview load a request failed
    IAPMinWK_JSBRIDGE_CALL_NOT_FOUND            = 1008, //A native jsapi implement is not found
    IAPMinWK_JSBRIDGE_DECODE_DATA_FAIL        = 1009, //Decode the data failed in jsapi call process
    IAPMinWK_JSBRIDGE_ENCODE_DATA_FAIL          = 1010, //Encode the data failed in jsapi call process
    IAPMinWK_JSBRIDGE_PERMISSION_FAIL          = 1011, //A jsapi call is rejected by the premission
    IAPMinWK_JSBRIDGE_RUN_FAIL          = 1012, //Callback to the h5 sides failed in a jspai process
    IAPMinWK_WEBVIEW_LOAD_PERMISSION_FAIL          = 1013, //A request load is rejected by the premission
    IAPMinWK_EVENT_BUBBLE_INTERUPTED          = 1014, //An event loop is interupted
    IAPMinWK_EVENT_CANCELED          = 1015, //An event is canceld
    IAPMinWK_COOKIE_SYNC_ERROR       = 1016, //Syncing Cookies is failed from native to h5
    IAPMinWK_COOKIE_H5_MESSAGES_ERROR     = 1017, //Syncing Cookies is failed from h5 to native
    IAPMinWK_COOKIE_LOCALJS_INJECT_FAIL     = 1018, //Inject the cookie js to a WKView failed

};

#endif /* IAPCommonDefine_h */
