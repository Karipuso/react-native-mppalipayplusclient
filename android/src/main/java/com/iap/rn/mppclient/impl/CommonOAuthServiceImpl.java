package com.iap.rn.mppclient.impl;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableMap;
import com.iap.android.mppclient.basic.callback.Callback;
import com.iap.android.mppclient.basic.model.CommonOAuthServiceParams;
import com.iap.android.mppclient.basic.model.CommonOAuthServiceResult;
import com.iap.android.mppclient.basic.service.CommonOAuthService;
import com.iap.rn.mppclient.MPPAlipayPlusClientModule;


public class CommonOAuthServiceImpl implements CommonOAuthService {
    private final static String TAG = CommonOAuthServiceImpl.class.getSimpleName();

    private static Callback sCallback;

    public static void sendFailedCallback(String errorCode, String errorMessage) {
        if (sCallback != null) {
            sCallback.onFailure(errorCode, errorMessage);
        }
    }

    public static void sendSuccessCallback(CommonOAuthServiceResult result) {
        if (sCallback != null) {
            sCallback.onSuccess(result);
        }
    }

    @Override
    public void getAuthCode(CommonOAuthServiceParams params, Callback<CommonOAuthServiceResult> callback) {
        sCallback = callback;
        WritableMap writableMap = Arguments.createMap();
        WritableArray writableArray = Arguments.fromJavaArgs(params.scopes.toArray());
        writableMap.putString("authUrl", params.authClientId);
        writableMap.putArray("scopes",writableArray);
        MPPAlipayPlusClientModule.sendEvent("rn_mpp_service_getAuthCode", writableMap);
    }
}
