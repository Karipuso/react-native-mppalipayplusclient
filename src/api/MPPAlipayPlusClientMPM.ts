import MPPAlipayPlusClientMPMModule, { registerDecodeEventEmitter } from "../modules/MPPAlipayPlusClientMPMModule";
import { LaunchCallback, MPPLaunchParams, IMPMService, MPPDecodeServiceParams, DecodeServiceCallback } from "../types";


export class MPPAlipayPlusClientMPM {
	static iMPMService: IMPMService;

	static registerMPMDecodeService(service: IMPMService) {
		MPPAlipayPlusClientMPM.iMPMService = service;

		//去原生处注册自己的spi
		MPPAlipayPlusClientMPMModule.rn_registerMPMService();

		//注册spi后开始监听原生向js发送事件		
		registerDecodeEventEmitter((params: MPPDecodeServiceParams, callback: DecodeServiceCallback) => {
			MPPAlipayPlusClientMPM.iMPMService.decode(params, callback);
		});
	}

	static launch(params: MPPLaunchParams, callback: LaunchCallback) {
		MPPAlipayPlusClientMPMModule.rn_launch(params, callback);
	}
}
