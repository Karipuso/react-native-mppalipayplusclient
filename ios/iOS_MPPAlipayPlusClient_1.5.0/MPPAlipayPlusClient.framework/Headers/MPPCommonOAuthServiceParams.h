//
//  MPPCommonOAuthServiceParams.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPCommonOAuthServiceParams : NSObject
@property (nonatomic, copy) NSString *authClientId;
@property (nonatomic, copy) NSArray<NSString *> *scopes;
@end

NS_ASSUME_NONNULL_END
