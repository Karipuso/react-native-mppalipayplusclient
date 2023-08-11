//
//  MPPAlipayPlusClientRNLogger.h
//  react-native-mppalipayplusclient
//
//  Created by yihan on 2023/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPAlipayPlusClientRNLogger : NSObject

+ (instancetype)shared;
- (void)logEventWithName:(NSString *)name params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
