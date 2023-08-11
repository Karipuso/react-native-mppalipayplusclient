//
//  MPPAlipayPlusClient+AcceptanceHelper.h
//  MPPAlipayPlusClient
//
//  Created by yihan on 2023/6/5.
//

#import <Foundation/Foundation.h>
#import <MPPAlipayPlusClient/MPPRemoteConfiguration.h>
#import <MPPAlipayPlusClient/MPPAlipayPlusClientAPI.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MPPPaymentScenario
typedef NSString *MPPPaymentScenario;
FOUNDATION_EXPORT MPPPaymentScenario const UPMPaymentScenario;
FOUNDATION_EXPORT MPPPaymentScenario const MPMPaymentScenario;

#pragma mark - MPPAlipayPlusClient
@interface MPPAlipayPlusClient (AcceptanceHelper)

- (nullable NSArray<MPPAcceptanceMarkLogo *> *)getAcceptanceMarkLogos:(MPPPaymentScenario)scenario withRegion:(nullable NSString *)region;
- (BOOL)isAlipayPlusSupportedRegion:(nullable NSString *)region;
- (nullable NSString *)getCurrentRegion;

@end



NS_ASSUME_NONNULL_END
