//
//  MPPAlipayPlusClient.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/20.
//

//Public
#import <Foundation/Foundation.h>
#import <MPPAlipayPlusClient/MPPConfiguration.h>
#import <MPPAlipayPlusClient/MPPConstant.h>
#import <MPPAlipayPlusClient/MPPAlipayPlusClientAPI.h>
#import <MPPAlipayPlusClient/MPPCommonOAuthServiceParams.h>
#import <MPPAlipayPlusClient/MPPCommonOAuthServiceResult.h>
#import <MPPAlipayPlusClient/MPPAlipayPlusClientCommonOAuthProtocol.h>
#import <MPPAlipayPlusClient/MPPInquireQuoteResult.h>
#import <MPPAlipayPlusClient/MPPInquireQuoteParams.h>
#import <MPPAlipayPlusClient/MPPRemoteConfiguration.h>
#import <MPPAlipayPlusClient/MPPAlipayPlusClient+AcceptanceHelper.h>

//Common Foundation
#import <MPPAlipayPlusClient/MPPRequestParams.h>
#import <MPPAlipayPlusClient/MPPRequestSponsor.h>
#import <MPPAlipayPlusClient/MPPResponseModelProtocol.h>
#import <MPPAlipayPlusClient/MPPRequestBodyModelProtocol.h>
#import <MPPAlipayPlusClient/MPPJSONUtils.h>
#import <MPPAlipayPlusClient/NSDictionary+MPPUtils.h>
#import <MPPAlipayPlusClient/NSError+MPPUtils.h>
#import <MPPAlipayPlusClient/NSThread+MPPUtils.h>


//! Project version number for MPPAlipayPlusClient.
FOUNDATION_EXPORT double MPPAlipayPlusClientVersionNumber;

//! Project version string for MPPAlipayPlusClient.
FOUNDATION_EXPORT const unsigned char MPPAlipayPlusClientVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MPPAlipayPlusClient/PublicHeader.h>


#define MPPAlipayPlusClientVersion @"1.5.0"
