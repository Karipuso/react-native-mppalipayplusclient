package com.iap.rn.mppclient.log;

import android.util.Log;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.bridge.WritableNativeMap;
import com.iap.android.iaptinylog.IAPTinyLogger;
import com.iap.android.iaptinylog.data.IAPTinyLog;
import com.iap.android.iaptinylog.observer.ILogObserver;
import com.iap.rn.mppclient.MPPAlipayPlusClientLoggerModule;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

public class RNLogObserverImpl implements ILogObserver {
    private final String TAG = RNLogObserverImpl.class.getSimpleName();

    @Override
    public void logger(IAPTinyLogger iapTinyLogger, IAPTinyLog iapTinyLog) {
        WritableMap writableMap = Arguments.createMap();
        writableMap.putString("name", iapTinyLog.name);
        writableMap.putString("type", iapTinyLog.type.name());

        HashMap<String, String> params = new HashMap<>();
        if (iapTinyLog.parameters != null) {
            params.putAll(iapTinyLog.parameters);
        }
        JSONObject paramsJson = new JSONObject(params);
        writableMap.putString("parameters", paramsJson.toString());
        MPPAlipayPlusClientLoggerModule.sendEvent("rn_mpp_service_showLog", writableMap);
    }
}
