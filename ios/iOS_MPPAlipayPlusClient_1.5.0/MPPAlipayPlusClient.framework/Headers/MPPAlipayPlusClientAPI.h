/**
 *   Legal Disclaimer
 *   Source Code or Sample Code not belongs to Alipay technological assets, partners agree to take full responsibility for any activities or actions under its use.
 *   Partners are authorised to use for Approved Purposes.
 *   "Approved Purpose" means, subject to any restrictions set out in the Participation Documents, (i) in relation to a Partner, as is necessary in order to facilitate that Partner’s participation in Alipay+ Core; and (ii) in relation to Alipay+, as is necessary in order to facilitate the provision of the Services (including the exercise of rights and performance of obligations under Participation Documents, managing AML/Fraud Risk, resolving any Disputes or facilitating the provision of Partner Products by other Partners).
 *   You should check our NDA for detail Legal T&C.
 */
//
//  MPPAlipayPlusClientAPI.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/20.
//

#import <Foundation/Foundation.h>
#import <MPPAlipayPlusClient/MPPConfiguration.h>
#import <MPPAlipayPlusClient/MPPAlipayPlusClientCommonOAuthProtocol.h>
#import <MPPAlipayPlusClient/MPPInquireQuoteResult.h>
#import <MPPAlipayPlusClient/MPPInquireQuoteParams.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPAlipayPlusClient : NSObject

@property (nonatomic, strong) MPPConfiguration *configuration;
@property (nonatomic, strong) id<MPPAlipayPlusClientCommonOAuthProtocol> commonOAuthService;

+ (instancetype)shared;
- (void)inquireQuote:(MPPInquireQuoteParams *)params
   completionHandler:(void(^)(MPPInquireQuoteResult * _Nullable result, NSError *  _Nullable error))completionHandler;
@end

NS_ASSUME_NONNULL_END
