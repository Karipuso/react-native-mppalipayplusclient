//
//  IAPTinyLogObserverProtocol.h
//  IAPTinyLogger
//
//  Created by assuner on 2022/6/13.
//

#ifndef IAPTinyLogObserverProtocol_h
#define IAPTinyLogObserverProtocol_h

@class IAPTinyLogger;
@class IAPTinyLog;

// 宿主App可以实现协议并且监听日志
@protocol IAPTinyLogObserverProtocol <NSObject>
@required
/**
 * event日志记录时候的通知
 *
 * @param logger 写日志的logger，包含productId和bizType信息，可以知道是哪个业务方写的日志
 * @param log 日志
 */
- (void)logger:(IAPTinyLogger *)logger didCollectLog:(IAPTinyLog *)log;
@end


#endif /* IAPTinyLogObserverProtocol_h */
