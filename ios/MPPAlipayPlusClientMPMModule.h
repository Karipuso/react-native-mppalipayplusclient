//
//  MPPAlipayPlusClientMPMModule.h
//  react-native-mppalipayplusclient
//
//  Created by yihan on 2023/6/8.
//

#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>
#import <MPPAlipayPlusClientMPM/MPPAlipayPlusClient+MPM.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPAlipayPlusClientMPMModule : RCTEventEmitter <RCTBridgeModule, MPPAlipayPlusClientMPMProtocol>

@end

NS_ASSUME_NONNULL_END
