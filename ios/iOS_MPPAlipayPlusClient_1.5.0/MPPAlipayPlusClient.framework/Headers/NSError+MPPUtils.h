//
//  NSError+MPPUtils.h
//  AlipayPlusClient
//
//  Created by assuner on 2022/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (MPPUtils)
+ (instancetype)mppu_paramsIllegalErrorWithExtraMessage:(nullable NSString *)extraMessage;
+ (instancetype)mppu_invalidNetworkErrorWithExtraMessage:(nullable NSString *)extraMessage;
+ (instancetype)mppu_systemErrorWithExtraMessage:(nullable NSString *)extraMessage;
+ (instancetype)mppu_userCancelWithExtraMessage:(nullable NSString *)extraMessage;
@end

NS_ASSUME_NONNULL_END
