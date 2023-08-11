//
//  MPPConstant.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define kMPPAlipayPlusClientVersionString @"1.5.0"


#pragma mark - env

typedef NSString *MPPEnv;
extern MPPEnv const kMPPEnvPROD;

#pragma mark - error
extern NSString * const MPPErrorDomain;
extern NSInteger const MPPErrorParamIllegal;
extern NSInteger const MPPErrorInvalidNetwork;
extern NSInteger const MPPErrorSystemError;
extern NSInteger const MPPErrorUserCancel;
extern NSInteger const MPPErrorPayFail;
extern NSInteger const MPPErrorH5JSBridgeCallNotFound;


NS_ASSUME_NONNULL_END
