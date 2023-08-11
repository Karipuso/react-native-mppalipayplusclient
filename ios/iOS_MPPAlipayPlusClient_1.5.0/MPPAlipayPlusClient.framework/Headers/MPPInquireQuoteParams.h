//
//  MPPInquireQuoteParams.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPInquireQuoteParams : NSObject
@property (nonatomic, copy) NSString *buyCurrency;
@property (nonatomic, copy) NSString *sellCurrency;
@end

NS_ASSUME_NONNULL_END
