package com.iap.rn.mppclient;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableMap;
import com.iap.android.mppclient.basic.AlipayPlusClient;
import com.iap.android.mppclient.basic.callback.Callback;
import com.iap.android.mppclient.basic.log.ACLogEvent;
import com.iap.android.mppclient.basic.model.CommonOAuthServiceResult;
import com.iap.android.mppclient.basic.model.Configuration;
import com.iap.android.mppclient.basic.model.InquireQuoteParams;
import com.iap.android.mppclient.basic.model.InquireQuoteResult;
import com.iap.android.mppclient.basic.model.MPPAcceptanceMarkLogo;
import com.iap.rn.mppclient.impl.CommonOAuthServiceImpl;
import com.iap.rn.mppclient.log.RNLogConstants;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MPPAlipayPlusClientModule extends BaseModule {
    public MPPAlipayPlusClientModule(ReactApplicationContext context) {
        super(context);
    }


    @NonNull
    @Override
    public String getName() {
        return "MPPAlipayPlusClientModule";
    }

    @ReactMethod
    public void rn_setConfiguration(ReadableMap map) {
        HashMap<String, Object> params = new HashMap<>();
        if (map != null) {
            params = map.toHashMap();

            ACLogEvent acLogEvent = ACLogEvent.newLogger(RNLogConstants.bizCode, RNLogConstants.LOG_RN_SET_CONFIGURATION);
            for (Map.Entry<String, Object> entry : params.entrySet()) {
                acLogEvent = acLogEvent.addParams(entry.getKey(), String.valueOf(entry.getValue()));
            }
            acLogEvent.event();
        }
        Configuration configuration = new Configuration();
        configuration.clientId = String.valueOf(params.get("clientId"));
        configuration.envType = String.valueOf(params.get("envType"));
        Log.e(TAG, String.format("clientId = %s, envType = %s", configuration.clientId, configuration.envType));
        AlipayPlusClient.getInstance().setConfiguration(configuration);
    }

    @ReactMethod
    public void rn_inquireQuote(ReadableMap map, final com.facebook.react.bridge.Callback callback) {
        HashMap<String, Object> params = new HashMap<>();
        if (map != null) {
            params = map.toHashMap();

            ACLogEvent acLogEvent = ACLogEvent.newLogger(RNLogConstants.bizCode, RNLogConstants.LOG_RN_INQUIRY_QUOTE);
            for (Map.Entry<String, Object> entry : params.entrySet()) {
                acLogEvent = acLogEvent.addParams(entry.getKey(), String.valueOf(entry.getValue()));
            }
            acLogEvent.event();
        }

        InquireQuoteParams inquireQuoteParams = new InquireQuoteParams();
        inquireQuoteParams.buyCurrency = String.valueOf(params.get("buyCurrency"));
        inquireQuoteParams.sellCurrency = String.valueOf(params.get("sellCurrency"));
        Log.d(TAG, String.format("buyCurrency = %s, sellCurrency = %s", inquireQuoteParams.buyCurrency, inquireQuoteParams.sellCurrency));

        final boolean[] hasInvoke = {false};
        AlipayPlusClient.getInstance().inquireQuote(inquireQuoteParams, new Callback<InquireQuoteResult>() {
            @Override
            public void onSuccess(InquireQuoteResult inquireQuoteResult) {
                Log.e(TAG, "onSuccess: enter inquireQuote callback");
                if (callback != null) {
                    WritableMap map = Arguments.createMap();
                    map.putString("quoteId", inquireQuoteResult.quoteId);
                    map.putString("quoteCurrencyPair", inquireQuoteResult.quoteCurrencyPair);
                    map.putString("quotePrice", inquireQuoteResult.quotePrice);
                    if (!hasInvoke[0]) {
                        hasInvoke[0] = true;
                        callback.invoke(map, null);
                    }
                }
            }

            @Override
            public void onFailure(String s, String s1) {
                Log.e(TAG, "onFailure: enter inquireQuote callback");
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
    public void rn_registerCommonOAuthService() {
        AlipayPlusClient.getInstance().commonOAuthService = new CommonOAuthServiceImpl();
        Log.e(TAG, "registerCommonOAuthService Successfully");
    }

    @ReactMethod
    @Override
    public void rn_sendEventCallback(ReadableMap map, ReadableMap mapError) {
        if (map != null) {
            HashMap<String, Object> params = map.toHashMap();
            CommonOAuthServiceResult commonOAuthServiceResult = new CommonOAuthServiceResult();
            commonOAuthServiceResult.authCode = String.valueOf(params.get("authCode"));
            CommonOAuthServiceImpl.sendSuccessCallback(commonOAuthServiceResult);
        } else {
            HashMap<String, Object> params = mapError.toHashMap();
            String errorCode = String.valueOf(params.get("code"));
            String errorMessage = String.valueOf(params.get("message"));
            Log.e(TAG, String.format("errorCode = %s, errorMessage = %s", errorCode, errorMessage));
            CommonOAuthServiceImpl.sendFailedCallback(errorCode, errorMessage);
        }
    }

    @ReactMethod(isBlockingSynchronousMethod = true)
    public String rn_getCurrentRegion() {
        ACLogEvent.newLogger(RNLogConstants.bizCode, RNLogConstants.LOG_RN_GET_CURRENT_REGION).event();

        return AlipayPlusClient.getInstance().getCurrentRegion(reactContext);
    }

    @ReactMethod(isBlockingSynchronousMethod = true)
    public boolean rn_isAlipayPlusSupportedRegion(String region) {
        ACLogEvent.newLogger(RNLogConstants.bizCode, RNLogConstants.LOG_RN_IS_ALIPAYPLUS_SUPPORTED_REGION)
                .addParams("region", region)
                .event();

        return AlipayPlusClient.getInstance().isAlipayPlusSupportedRegion(reactContext, region);
    }

    @ReactMethod(isBlockingSynchronousMethod = true)
    public WritableArray rn_getAcceptanceMarkLogos(String scenario, String region) {
        ACLogEvent.newLogger(RNLogConstants.bizCode, RNLogConstants.LOG_RN_GET_ACCEPTANCE_MARK_LOGOS)
                .addParams("scenario", scenario)
                .addParams("region", region)
                .event();

        List<MPPAcceptanceMarkLogo> mppAcceptanceMarkLogos = AlipayPlusClient.getInstance().getAcceptanceMarkLogos(reactContext, scenario, region);

        WritableArray writableArray = null;
        if (mppAcceptanceMarkLogos != null && !mppAcceptanceMarkLogos.isEmpty()) {
            writableArray = Arguments.createArray();
            for (MPPAcceptanceMarkLogo logo : mppAcceptanceMarkLogos) {
                WritableMap writableMap = Arguments.createMap();
                writableMap.putString("logoUrl", logo.logoUrl);
                writableMap.putString("logoName", logo.logoName);
                writableArray.pushMap(writableMap);
            }
        }

        return writableArray;
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
