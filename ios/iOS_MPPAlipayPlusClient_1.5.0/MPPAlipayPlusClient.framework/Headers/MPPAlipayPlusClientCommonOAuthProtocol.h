//
//  MPPAlipayPlusClientCommonOAuthProtocol.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/20.
//

#import <MPPAlipayPlusClient/MPPCommonOAuthServiceParams.h>
#import <MPPAlipayPlusClient/MPPCommonOAuthServiceResult.h>
#import <MPPAlipayPlusClient/MPPConstant.h>

#ifndef MPPAlipayPlusClientCommonOAuthProtocol_h
#define MPPAlipayPlusClientCommonOAuthProtocol_h

NS_ASSUME_NONNULL_BEGIN

@protocol MPPAlipayPlusClientCommonOAuthProtocol <NSObject>

- (void)getAuthCode:(MPPCommonOAuthServiceParams *)params
            completionHandler:(void(^)(MPPCommonOAuthServiceResult *_Nullable result, NSError *_Nullable error))completionHandler;

@end
NS_ASSUME_NONNULL_END


#endif /* MPPAlipayPlusClientCommonOAuthProtocol_h */
