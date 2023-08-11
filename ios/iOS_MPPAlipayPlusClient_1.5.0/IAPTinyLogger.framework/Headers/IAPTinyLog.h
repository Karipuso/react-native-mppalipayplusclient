//
//  IAPTinyLog.h
//  IAPTinyLogger
//
//  Created by assuner on 2022/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, IAPTinyLogType) {
    IAPTinyLogTypeEvent,
    IAPTinyLogTypeException,
    IAPTinyLogTypeDiagnose
};

typedef NSString * IAPTinyLogTypeParameterKey;
typedef NSString * IAPTinyLogDiagnoseLevel;

extern IAPTinyLogTypeParameterKey const IAPTinyLogParameterDiagnoseMessage;
extern IAPTinyLogTypeParameterKey const IAPTinyLogParameterDiagnoseLevel;

extern IAPTinyLogDiagnoseLevel const IAPTinyLogDiagnoseLevelInfo;
extern IAPTinyLogDiagnoseLevel const IAPTinyLogDiagnoseLevelWarn;
extern IAPTinyLogDiagnoseLevel const IAPTinyLogDiagnoseLevelDebug;
extern IAPTinyLogDiagnoseLevel const IAPTinyLogDiagnoseLevelError;

@interface IAPTinyLog : NSObject
// 日志类型
@property (nonatomic, assign) IAPTinyLogType type;

//@property (nonatomic, assign) IAPTinyLogDiagnoseLevel diagnoseLevel;

// 日志名
@property (nonatomic, copy) NSString *name;

// 扩展参数
@property (nonatomic, copy, nullable) NSDictionary *parameters;

// 日志的tag，可用于搜索, 可用于分类
@property (nonatomic, copy, nullable) NSString *tag;

+ (instancetype)diagnoseLogWithName:(NSString *)name
                            message:(NSString *)message
                              level:(IAPTinyLogDiagnoseLevel)level;

@end

NS_ASSUME_NONNULL_END
