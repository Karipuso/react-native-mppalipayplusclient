import { NativeModules, NativeEventEmitter } from 'react-native';
import { MPPCommonOAuthServiceParams } from '../types';

export default NativeModules.MPPAlipayPlusClientModule;

const eventEmitter = new NativeEventEmitter(NativeModules.MPPAlipayPlusClientModule);

export function registerCommonOAuthEventEmitter(emitterCallback) {
	eventEmitter.addListener('rn_mpp_service_getAuthCode', (event) => {
		var commonOAuthServiceParams = new MPPCommonOAuthServiceParams();
		commonOAuthServiceParams.authClientId = event.authClientId;
		commonOAuthServiceParams.scopes = event.scopes;

		var commonOAuthServiceCallback = (commonOAuthServiceResult, error) => {
			NativeModules.MPPAlipayPlusClientModule.rn_sendEventCallback(commonOAuthServiceResult, error);
		}
		emitterCallback(commonOAuthServiceParams, commonOAuthServiceCallback);
	});
}

export function unRegisteAutoDebitEventEmitter() {
	eventEmitter.removeAllListeners('rn_mpp_service_getAuthCode');
}