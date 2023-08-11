import { NativeModules, NativeEventEmitter } from 'react-native';
import { MPPDecodeServiceParams } from '../types'


export default NativeModules.MPPAlipayPlusClientMPMModule;

const eventEmitter = new NativeEventEmitter(NativeModules.MPPAlipayPlusClientMPMModule);

export function registerDecodeEventEmitter(emitterCallback) {
	eventEmitter.addListener('rn_mpp_service_decode', (event) => {
		var decodeParams = new MPPDecodeServiceParams();
		decodeParams.codeValue = event.codeValue;
		var decodeServiceCallback = (decodeServiceResult, error) => {
			NativeModules.MPPAlipayPlusClientMPMModule.rn_sendEventCallback(decodeServiceResult, error);
		};
		emitterCallback(decodeParams, decodeServiceCallback);
	});
}

export function unRegisterDecodeEventEmitter() {
	eventEmitter.removeAllListeners('rn_mpp_service_decode');
}