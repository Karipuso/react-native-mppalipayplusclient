package com.iap.rn.mppclient;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;
import com.iap.android.mppclient.basic.callback.Callback;
import com.iap.android.mppclient.basic.log.ACLogEvent;
import com.iap.android.mppclient.basic.model.DecodeServiceResult;
import com.iap.android.mppclient.mpm.AlipayPlusClientMPM;
import com.iap.android.mppclient.mpm.model.LaunchParams;
import com.iap.android.mppclient.mpm.model.LaunchResult;
import com.iap.rn.mppclient.impl.MPMServiceImpl;
import com.iap.rn.mppclient.log.RNLogConstants;

import java.util.HashMap;
import java.util.Map;

public class MPPAlipayPlusClientMPMModule extends BaseModule {
    public MPPAlipayPlusClientMPMModule(ReactApplicationContext context) {
        super(context);
    }

    @NonNull
    @Override
    public String getName() {
        return "MPPAlipayPlusClientMPMModule";
    }

    @ReactMethod
    public void rn_launch(ReadableMap map, final com.facebook.react.bridge.Callback callback) {
        HashMap<String, Object> params = new HashMap<>();
        if (map != null) {
            params = map.toHashMap();

            ACLogEvent acLogEvent = ACLogEvent.newLogger(RNLogConstants.bizCode, RNLogConstants.LOG_RN_LAUNCH);
            for (Map.Entry<String, Object> entry : params.entrySet()) {
                acLogEvent = acLogEvent.addParams(entry.getKey(), String.valueOf(entry.getValue()));
            }
            acLogEvent.event();
        }
        LaunchParams launchParams = new LaunchParams();
        launchParams.url = String.valueOf(params.get("url"));
        launchParams.userAgent = String.valueOf(params.get("userAgent"));
        Log.d(TAG, String.format("url = %s, userAgent = %s", launchParams.url, launchParams.userAgent));

        final boolean[] hasInvoke = {false};
        AlipayPlusClientMPM.getInstance().launch(reactContext, launchParams, new Callback<LaunchResult>() {
            @Override
            public void onSuccess(LaunchResult launchResult) {
                WritableMap map = Arguments.createMap();
                if (!hasInvoke[0]) {
                    hasInvoke[0] = true;
                    callback.invoke(map, null);
                }
            }

            @Override
            public void onFailure(String s, String s1) {
                WritableMap map = Arguments.createMap();
                map.putString("code", s);
                map.putString("message", s1);
                if (!hasInvoke[0]) {
                    hasInvoke[0] = true;
                    callback.invoke(null, map);

                }
            }
        });
    }

    @ReactMethod
    public void rn_registerMPMService() {
        AlipayPlusClientMPM.getInstance().mpmService = new MPMServiceImpl();
        Log.e(TAG, "registerMPMSuccessfully");
    }

    @ReactMethod
    @Override
    public void rn_sendEventCallback(ReadableMap map, ReadableMap mapError) {
        Log.e(TAG, "sendEventCallback");
        if (map != null) {
            DecodeServiceResult decodeServiceResult = new DecodeServiceResult();
            MPMServiceImpl.sendSuccessCallback(decodeServiceResult);
        } else {
            HashMap<String, Object> params = mapError.toHashMap();
            String errorCode = String.valueOf(params.get("code"));
            String errorMessage = String.valueOf(params.get("message"));
            Log.e(TAG, String.format("errorCode = %s, errorMessage = %s", errorCode, errorMessage));
            MPMServiceImpl.sendFailedCallback(errorCode, errorMessage);
        }
    }

    @ReactMethod
    public void addListener(String eventName) {
        // Set up any upstream listeners or background tasks as necessary
    }

    @ReactMethod
    public void removeListeners(Integer count) {
        // Remove upstream listeners, stop unnecessary background tasks
    }
}
