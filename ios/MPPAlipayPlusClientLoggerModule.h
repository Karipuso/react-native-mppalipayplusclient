//
//  MPPAlipayPlusClientLoggerModule.h
//  react-native-mppalipayplusclient
//
//  Created by yihan on 2023/6/12.
//

#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>
#import <IAPTinyLogger/IAPTinyLogger.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPAlipayPlusClientLoggerModule : RCTEventEmitter <RCTBridgeModule, IAPTinyLogObserverProtocol>

@end

NS_ASSUME_NONNULL_END
