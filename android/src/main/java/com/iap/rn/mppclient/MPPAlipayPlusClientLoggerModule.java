package com.iap.rn.mppclient;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.iap.android.iaptinylog.IAPTinyLogger;
import com.iap.android.iaptinylog.data.IAPTinyLogType;
import com.iap.rn.mppclient.log.RNLogObserverImpl;

public class MPPAlipayPlusClientLoggerModule extends BaseModule {

    public MPPAlipayPlusClientLoggerModule(ReactApplicationContext context) {
        super(context);
    }

    @Override
    public void rn_sendEventCallback(ReadableMap map, ReadableMap mapError) {

    }

    @NonNull
    @Override
    public String getName() {
        return "MPPAlipayPlusClientLoggerModule";
    }

    @ReactMethod
    public void addListener(String eventName) {
        // Set up any upstream listeners or background tasks as necessary
    }

    @ReactMethod
    public void removeListeners(Integer count) {
        // Remove upstream listeners, stop unnecessary background tasks
    }

    @ReactMethod
    public void rn_startLog() {
        IAPTinyLogger.setLogEnabledByType(true, IAPTinyLogType.LOG_TYPE_EVENT);
        IAPTinyLogger.setLogEnabledByType(true, IAPTinyLogType.LOG_TYPE_DIAGNOSE);
        IAPTinyLogger.setLogEnabledByType(true, IAPTinyLogType.LOG_TYPE_EXCEPTION);

        IAPTinyLogger.addObserver(new RNLogObserverImpl());
    }
}
