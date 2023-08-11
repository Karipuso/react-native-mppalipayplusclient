//
//  MPPRequestParams.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/20.
//

#import <Foundation/Foundation.h>
#import <MPPAlipayPlusClient/MPPResponseModelProtocol.h>
#import <MPPAlipayPlusClient/MPPRequestBodyModelProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPRequestParams : NSObject
@property (nonatomic, copy, nullable) NSString *path;
@property (nonatomic, copy, nullable) NSURL *URL;
@property (nonatomic, copy) NSString *method; // GET/POST/.., default is POST
@property (nonatomic, assign) NSTimeInterval timeoutInterval; // if timeoutInterval <= 0. default value is 5s;
@property (nonatomic, assign) BOOL callbackInMainQueue; // default value is NO;

@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *extraHeaders;
@property (nonatomic, copy, nullable) NSDictionary *extraBodyParams;
@property (nonatomic, strong) id<MPPRequestBodyModelProtocol> extraBodyModel;

@property (nonatomic, strong) Class<MPPResponseModelProtocol> responseCls;

- (NSDictionary *)finalExtraBodyParams;
- (BOOL)valid;
@end

NS_ASSUME_NONNULL_END
