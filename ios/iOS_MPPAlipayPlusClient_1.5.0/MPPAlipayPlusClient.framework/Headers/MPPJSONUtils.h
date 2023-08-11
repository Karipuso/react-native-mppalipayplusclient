//
//  MPPJSONUtils.h
//  AlipayPlusClient
//
//  Created by assuner on 2022/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define MPPSetVarFromJSONVarName(self, varName) self.varName = [json mppu_stringForKey:NSStringFromSelector(@selector(varName))]

#define MPPJSONKeyValueFromVarName(varName)  NSStringFromSelector(@selector(varName)): self.varName ?: @""

@interface MPPJSONUtils : NSObject
+ (nullable id)JSONObjectFromData:(NSData *)data;
+ (nullable id)JSONObjectFromString:(NSString *)string;
+ (nullable NSString *)jsonStringFromDictionary:(NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
