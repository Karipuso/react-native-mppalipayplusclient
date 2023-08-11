//
//  IAPTinyLoggerAPI.h
//  IAPTinyLogger
//
//  Created by assuner on 2022/6/13.
//

#import <Foundation/Foundation.h>
#import <IAPTinyLogger/IAPTinyLog.h>
#import <IAPTinyLogger/IAPTinyLogObserverProtocol.h>

NS_ASSUME_NONNULL_BEGIN



@interface IAPTinyLogger : NSObject

#pragma mark - static

/**
 * @return 所有监听者
 */
+ (NSArray<id<IAPTinyLogObserverProtocol>> *)observers;

/**
 * 添加日志监听者
 *
 * @param observer 实现了IAPTinyLogObserverProtocol协议的监听者
 */
+ (void)addObserver:(id<IAPTinyLogObserverProtocol>)observer;

/**
 * 移除指定日志监听者
 *
 * @param observer 实现了IAPTinyLogObserverProtocol协议的监听者
 */
+ (void)removeObserver:(id<IAPTinyLogObserverProtocol>)observer;

/**
 * 移除所有监听者
 */
+ (void)removeAllObservers;

/**
 * 查看是否开启日志的记录
 *
 * @param type 日志类型，见IAPTinyLogType
 * @return 是否可用,  默认所有类型对应值为NO
 */
+ (BOOL)logEnabledForType:(IAPTinyLogType)type;


/**
 * 设置是否开启日志的记录
 *
 * @param enabled 表示是否开启
 * @param type 日志类型，见IAPTinyLogType
 */
+ (void)setLogEnabled:(BOOL)enabled forType:(IAPTinyLogType)type;


/**
 * @return 默认参数，公共参数会被加到每一条日志的扩展参数中
 */
+ (NSDictionary<NSString *, NSString *> *)defautParameters;

/**
 * 修改公共参数
 *
 * @param value 公共参数的值
 * @param key 公共参数的key
 */
+ (void)setDefaultParameterWithValue:(nullable NSString *)value forKey:(NSString *)key;

#pragma mark - instance


// 可用于标记是哪个宿主App
@property (nonatomic, copy, readonly) NSString *productId;

// 可用于标记是哪个业务方
@property (nonatomic, copy, readonly) NSString *bizName;

/**
 * 实例初始化方法
 *
 * @param productId 可用于标记是哪个宿主App
 * @param bizName 可用于标记是哪个业务方
 * @return logger实例
 */
- (nullable instancetype)initWithProductId:(NSString *)productId bizName:(NSString *)bizName;


/**
 * 记录事件日志
 *
 * @param log 具体的log信息
 */
- (void)log:(IAPTinyLog *)log;


@end

NS_ASSUME_NONNULL_END
