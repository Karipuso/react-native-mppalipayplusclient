package com.iap.rn.mppclient;

import android.text.TextUtils;
import android.util.Log;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.modules.core.DeviceEventManagerModule;
import com.iap.android.mppclient.basic.log.ACLogEvent;
import com.iap.rn.mppclient.log.RNLogConstants;

import java.util.HashMap;
import java.util.Map;

public abstract class BaseModule extends ReactContextBaseJavaModule {
    protected final String TAG = getClass().getSimpleName();

    protected static ReactApplicationContext reactContext;

    public BaseModule(ReactApplicationContext context) {
        super(context);
        reactContext = context;
    }

    @ReactMethod
    public abstract void rn_sendEventCallback(ReadableMap map, ReadableMap mapError);

    public static void sendEvent(String eventName, WritableMap params) {
        if (params != null && !TextUtils.equals(eventName,"rn_mpp_service_showLog")) {
            //此处必须把rn_mpp_service_showLog给过滤掉，防止死循环程序直接崩溃
            ACLogEvent acLogEvent = ACLogEvent.newLogger(RNLogConstants.bizCode, RNLogConstants.LOG_RN_SERVICE_CALL);
            acLogEvent.addParams("eventName", eventName);
            HashMap<String, Object> hashParams = params.toHashMap();
            for (Map.Entry<String, Object> entry : hashParams.entrySet()) {
                acLogEvent = acLogEvent.addParams(entry.getKey(), String.valueOf(entry.getValue()));
            }
            acLogEvent.event();
        }

        if (reactContext != null) {
            reactContext
                    .getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter.class)
                    .emit(eventName, params);
        }
    }
}
