//
//  MPPCommonOAuthServiceResult.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPCommonOAuthServiceResult : NSObject
@property (nonatomic, copy) NSString *authCode;
@property (nonatomic, copy, nullable) NSArray<NSString *> *authSuccessScopes;
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *authErrorScopes;
@end

NS_ASSUME_NONNULL_END
