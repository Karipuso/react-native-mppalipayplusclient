package com.iap.rn.mppclient.impl;

import android.util.Log;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.WritableMap;
import com.iap.android.mppclient.basic.callback.Callback;
import com.iap.android.mppclient.basic.model.DecodeServiceParams;
import com.iap.android.mppclient.basic.model.DecodeServiceResult;
import com.iap.android.mppclient.mpm.service.MPMService;
import com.iap.rn.mppclient.BaseModule;
import com.iap.rn.mppclient.MPPAlipayPlusClientMPMModule;

public class MPMServiceImpl implements MPMService {
    private final String TAG = MPMServiceImpl.class.getSimpleName();
    private static Callback<DecodeServiceResult> sCallback;

    public static void sendFailedCallback(String errorCode, String errorMessage) {
        if (sCallback != null) {
            sCallback.onFailure(errorCode, errorMessage);
        }
    }

    public static void sendSuccessCallback(DecodeServiceResult result) {
        if (sCallback != null) {
            sCallback.onSuccess(result);
        }
    }

    @Override
    public void decode(DecodeServiceParams params, Callback<DecodeServiceResult> callback) {
        sCallback = callback;
        WritableMap writableMap = Arguments.createMap();
        writableMap.putString("codeValue", params.codeValue);
        MPPAlipayPlusClientMPMModule.sendEvent("rn_mpp_service_decode", writableMap);
    }
}
