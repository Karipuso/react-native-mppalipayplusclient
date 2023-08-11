//
//  MPPInquireQuoteResult.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPInquireQuoteResult : NSObject
@property (nonatomic, copy) NSString *quoteId;
@property (nonatomic, copy) NSString *quoteCurrencyPair;
@property (nonatomic, copy) NSString *quotePrice;
@end

NS_ASSUME_NONNULL_END
