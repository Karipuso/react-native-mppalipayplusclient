import MPPAlipayPlusClientLoggerModule,{registerLoggerEmitter} from '../modules/MPPAlipayPlusClientLoggerModule'
import { ILoggerService, MPPLog } from "../types";


export class MPPAlipayPlusClientLogger {
    static iLoggerService : ILoggerService;

	static registerLoggerService(service:ILoggerService) {
		MPPAlipayPlusClientLogger.iLoggerService = service;

		// 注册logspi，打开日志采集开关
		MPPAlipayPlusClientLoggerModule.rn_startLog();

		registerLoggerEmitter((params: MPPLog) => {
			MPPAlipayPlusClientLogger.iLoggerService.log(params);
		});
	}
}