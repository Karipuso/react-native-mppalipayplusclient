//
//  MPPAlipayPlusClientModule.m
//  react-native-mppalipayplusclient
//
//  Created by yihan on 2023/6/8.
//

#import "MPPAlipayPlusClientModule.h"
#import "MPPAlipayPlusClientRNLogger.h"


@interface MPPAlipayPlusClientModule ()
@property (nonatomic, copy) void (^ completionHandler)(MPPCommonOAuthServiceResult * _Nullable, NSError * _Nullable);
@end

@implementation MPPAlipayPlusClientModule

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(rn_setConfiguration:(NSDictionary *)params) {
    
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_setConfiguration" params:params];
    
    MPPConfiguration *config = [MPPConfiguration new];
    config.clientId = params[@"clientId"];
    config.envType = params[@"envType"];
    [MPPAlipayPlusClient shared].configuration = config;
}

RCT_EXPORT_METHOD(rn_inquireQuote:(NSDictionary *)params
                  callback:(RCTResponseSenderBlock)callback) {
    
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_inquireQuote" params:params];
    
    MPPInquireQuoteParams *inquireQuoteParams = [MPPInquireQuoteParams new];
    inquireQuoteParams.buyCurrency = params[@"buyCurrency"];
    inquireQuoteParams.sellCurrency = params[@"sellCurrency"];
    [[MPPAlipayPlusClient shared] inquireQuote:inquireQuoteParams completionHandler:^(MPPInquireQuoteResult * _Nullable result, NSError * _Nullable error) {
      if (!error) {
          NSDictionary *resultDict = @{@"quoteId": result.quoteId,
                                       @"quoteCurrencyPair": result.quoteCurrencyPair,
                                       @"quotePrice": result.quotePrice};
          callback(@[resultDict, [NSNull null]]);
      } else {
          NSDictionary *errorDict = @{@"code": @(error.code),
                                      @"message": error.localizedDescription};
          callback(@[[NSNull null], errorDict]);
      }
    }];
}

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(rn_getCurrentRegion) {
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_getCurrentRegion" params:nil];
    return [[MPPAlipayPlusClient shared] getCurrentRegion];
}

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(rn_isAlipayPlusSupportedRegion:(NSString *)region) {
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_isAlipayPlusSupportedRegion" params:@{@"region":region}];
    return @([[MPPAlipayPlusClient shared] isAlipayPlusSupportedRegion:region]);
}

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(rn_getAcceptanceMarkLogos:(NSString *)scenario withRegion:(NSString *)region) {
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_getAcceptanceMarkLogos" params:@{@"scenario":scenario, @"region":region}];
    
    if (!scenario || !scenario.length) { return nil; }

    NSArray<MPPAcceptanceMarkLogo *> *logos = [[MPPAlipayPlusClient shared] getAcceptanceMarkLogos:scenario withRegion:region];
    NSMutableArray *result = [NSMutableArray array];
    [logos enumerateObjectsUsingBlock:^(MPPAcceptanceMarkLogo * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [result addObject:@{
            @"logoName": obj.logoName ?: [NSNull null],
            @"logoUrl": obj.logoUrl
        }];
    }];
    
    return result;
}


RCT_EXPORT_METHOD(rn_registerCommonOAuthService) {
    [MPPAlipayPlusClient shared].commonOAuthService = self;
}

RCT_EXPORT_METHOD(rn_sendEventCallback:(NSDictionary *)params
                  error:(NSDictionary *)rn_error) {
    
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_sendEventCallback" params:params];
    
    if (!rn_error) {
        MPPCommonOAuthServiceResult *result = [MPPCommonOAuthServiceResult new];
        result.authCode = params[@"authCode"];
        result.authErrorScopes = params[@"authErrorScopes"];
        result.authSuccessScopes = params[@"authSuccessScopes"];
        self.completionHandler(result, nil);
    } else {
        NSInteger errorCode = 1000;
        NSNumber *errorCodeNumber = [rn_error objectForKey:@"code"];
        if (errorCodeNumber && [errorCodeNumber isKindOfClass:NSNumber.class]) {
            errorCode = [errorCodeNumber integerValue];
        }
        NSError *error = [[NSError alloc] initWithDomain:@"MPPAlipayPlusClient_RN_SPI_ErrorDomain" code:errorCode userInfo:@{NSLocalizedDescriptionKey: rn_error[@"message"]}];
        self.completionHandler(nil, error);
    }
}

- (NSArray<NSString *> *)supportedEvents {
    return @[@"rn_mpp_service_getAuthCode"];
}

- (void)getAuthCode:(nonnull MPPCommonOAuthServiceParams *)params completionHandler:(nonnull void (^)(MPPCommonOAuthServiceResult * _Nullable, NSError * _Nullable))completionHandler {
    _completionHandler = completionHandler;
    
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_service_getAuthCode_call" params:@{@"authClientId": params.authClientId, @"scopes": params.scopes}];
    [self sendEventWithName:@"rn_mpp_service_getAuthCode" body:@{@"authClientId": params.authClientId, @"scopes": params.scopes}];
}

@end
