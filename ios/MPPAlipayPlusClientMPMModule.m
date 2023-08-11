//
//  MPPAlipayPlusClientMPMModule.m
//  react-native-mppalipayplusclient
//
//  Created by yihan on 2023/6/8.
//

#import "MPPAlipayPlusClientMPMModule.h"
#import <MPPAlipayPlusClientMPM/MPPAlipayPlusClient+MPM.h>
#import "MPPAlipayPlusClientRNLogger.h"

@interface MPPAlipayPlusClientMPMModule ()
@property (nonatomic, copy) void (^ payCompletionHandler)(MPPDecodeServiceResult * _Nullable, NSError * _Nullable);
@end

@implementation MPPAlipayPlusClientMPMModule

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(rn_launch:(NSDictionary *)params
                  callback:(RCTResponseSenderBlock)callback) {
    
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_launch" params:params];
    
    MPPLaunchParams *launchParams = [MPPLaunchParams new];
    launchParams.url = params[@"url"];
    launchParams.userAgent = params[@"userAgent"];
    [[MPPAlipayPlusClient shared] launch:launchParams completionHandler:^(MPPLaunchResult * _Nullable result, NSError * _Nullable error) {
        if (!error) {
            callback(@[[NSNull null], [NSNull null]]);
        } else {
            NSDictionary *errorDict = @{@"code": @(error.code),
                                        @"message": error.localizedDescription};
            callback(@[[NSNull null], errorDict]);
        }
    }];
}

RCT_EXPORT_METHOD(rn_registerMPMService) {
    [MPPAlipayPlusClient shared].mpmService = self;
}

RCT_EXPORT_METHOD(rn_sendEventCallback:(NSDictionary *)params
                  error:(NSDictionary *)rn_error) {
    
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_sendEventCallback" params:params];
    
    if (!rn_error) {
        MPPDecodeServiceResult *result = [MPPDecodeServiceResult new];
        self.payCompletionHandler(result, nil);
    } else {
        NSInteger errorCode = 1000;
        NSNumber *errorCodeNumber = [rn_error objectForKey:@"code"];
        if (errorCodeNumber && [errorCodeNumber isKindOfClass:NSNumber.class]) {
            errorCode = [errorCodeNumber integerValue];
        }
        NSError *error = [[NSError alloc] initWithDomain:@"MPPAlipayPlusClient_RN_SPI_ErrorDomain" code:errorCode userInfo:@{NSLocalizedDescriptionKey: rn_error[@"message"]}];
        self.payCompletionHandler(nil, error);
    }
}

- (NSArray<NSString *> *)supportedEvents {
    return @[@"rn_mpp_service_decode"];
}

- (void)decode:(nonnull MPPDecodeServiceParams *)params payCompletionHandler:(nonnull void (^)(MPPDecodeServiceResult * _Nullable, NSError * _Nullable))payCompletionHandler {
    _payCompletionHandler = payCompletionHandler;
    
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_service_decode_call" params:@{@"codeValue": params.codeValue}];
    [self sendEventWithName:@"rn_mpp_service_decode" body:@{@"codeValue": params.codeValue}];
}

@end
