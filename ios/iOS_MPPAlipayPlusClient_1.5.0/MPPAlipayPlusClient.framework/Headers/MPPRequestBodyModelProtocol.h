//
//  MPPRequestModelProtocol.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/25.
//

#import <Foundation/Foundation.h>

#ifndef MPPRequestBodyModelProtocol_h
#define MPPRequestBodyModelProtocol_h

NS_ASSUME_NONNULL_BEGIN
@protocol MPPRequestBodyModelProtocol <NSObject>
@required
- (NSDictionary *)bodyParamsDictionary;
@end
NS_ASSUME_NONNULL_END
#endif /* MPPRequestModelProtocol_h */
