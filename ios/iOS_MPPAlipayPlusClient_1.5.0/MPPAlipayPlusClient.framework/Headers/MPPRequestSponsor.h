//
//  MPPRequestSponsor.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/20.
//

#import <Foundation/Foundation.h>
#import <MPPAlipayPlusClient/MPPRequestParams.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPRequestSponsor : NSObject
+ (instancetype)shared;
@property (nonatomic, strong) NSDictionary *extraEnvHostMap;

- (void)asyncSendRequestWithParams:(MPPRequestParams *)params
                 completionHandler:(void(^)(id<MPPResponseModelProtocol> _Nullable responseModel, NSDictionary * _Nullable responseJSON, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;
@end

NS_ASSUME_NONNULL_END
