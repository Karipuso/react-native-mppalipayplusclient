import MPPAlipayPlusClientModule, { registerCommonOAuthEventEmitter } from '../modules/MPPAlipayPlusClientModule'
import { MPPConfiguration, MPPInquireQuoteParams, InquireQuoteCallback, ICommonOAuthService, MPPCommonOAuthServiceParams, CommonOAuthServiceCallback, MPPAcceptanceMarkLogo } from '../types';
export class MPPAlipayPlusClient {
	static iCommonOAuthService: ICommonOAuthService;

	static registerCommonOAuthService(service: ICommonOAuthService) {
		MPPAlipayPlusClient.iCommonOAuthService = service;

		//去原生处注册自己的spi
		MPPAlipayPlusClientModule.rn_registerCommonOAuthService();

		//注册spi后开始监听原生向js发送事件		
		registerCommonOAuthEventEmitter((params: MPPCommonOAuthServiceParams, callback: CommonOAuthServiceCallback) => {
			MPPAlipayPlusClient.iCommonOAuthService.getAuthCode(params, callback);
		});
	}

	static setConfiguration(configuration: MPPConfiguration) {
		MPPAlipayPlusClientModule.rn_setConfiguration(configuration);
	}

	static inquireQuote(params: MPPInquireQuoteParams, callback: InquireQuoteCallback) {
		return MPPAlipayPlusClientModule.rn_inquireQuote(params, callback);
	}

	static getCurrentRegion(): String {
		return MPPAlipayPlusClientModule.rn_getCurrentRegion();
	}

	static isAlipayPlusSupportedRegion(region?: String): Boolean {
		return MPPAlipayPlusClientModule.rn_isAlipayPlusSupportedRegion(region);
	}

	static getAcceptanceMarkLogos(scenario: String, region?: String): MPPAcceptanceMarkLogo[] {
		return MPPAlipayPlusClientModule.rn_getAcceptanceMarkLogos(scenario, region);
	}

}
