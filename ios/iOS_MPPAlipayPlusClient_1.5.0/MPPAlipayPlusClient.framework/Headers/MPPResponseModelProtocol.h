//
//  MPPResponseModelProtocol.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/21.
//
#import <Foundation/Foundation.h>

#ifndef MPPResponseModelProtocol_h
#define MPPResponseModelProtocol_h

NS_ASSUME_NONNULL_BEGIN
@protocol MPPResponseModelProtocol <NSObject>
@required
+ (nullable instancetype)modelFromJSONDictionary:(NSDictionary *)json;
@end
NS_ASSUME_NONNULL_END

#endif /* MPPResponseModelProtocol_h */
