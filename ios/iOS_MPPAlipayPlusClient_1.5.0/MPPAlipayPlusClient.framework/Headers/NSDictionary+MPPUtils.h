//
//  NSDictionary+MPPUtils.h
//  AlipayPlusClient
//
//  Created by assuner on 2022/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (MPPUtils)
- (BOOL)mppu_boolForKey:(NSString *)key;
- (nullable NSString *)mppu_stringForKey:(NSString *)key;
- (NSInteger)mppu_integerForKey:(NSString *)key;
- (nullable NSArray *)mppu_arrayForKey:(NSString *)key;
- (nullable NSDictionary *)mppu_dictionaryForKey:(NSString *)key;
@end


NS_ASSUME_NONNULL_END
