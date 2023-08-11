import { NativeModules, NativeEventEmitter } from 'react-native';
import { MPPLog } from '../types';

export default NativeModules.MPPAlipayPlusClientLoggerModule;

const eventEmitter = new NativeEventEmitter(NativeModules.MPPAlipayPlusClientLoggerModule);

export function registerLoggerEmitter(loggerCallback) {
	eventEmitter.addListener('rn_mpp_service_showLog', (event) => {
		loggerCallback(event);
	});
}

export function unRegisterLogger() {
	eventEmitter.removeAllListeners('rn_mpp_service_showLog');
}