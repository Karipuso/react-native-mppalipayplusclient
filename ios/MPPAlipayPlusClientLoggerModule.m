//
//  MPPAlipayPlusClientLoggerModule.m
//  react-native-mppalipayplusclient
//
//  Created by yihan on 2023/6/12.
//

#import "MPPAlipayPlusClientLoggerModule.h"
#import "MPPAlipayPlusClientRNLogger.h"

@implementation MPPAlipayPlusClientLoggerModule

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(rn_startLog) {
    
    [[MPPAlipayPlusClientRNLogger shared] logEventWithName:@"mpp_rn_startLog" params:@{}];
    
    [IAPTinyLogger addObserver:self];
    [IAPTinyLogger setLogEnabled:true forType:IAPTinyLogTypeEvent];
    [IAPTinyLogger setLogEnabled:true forType:IAPTinyLogTypeException];
    [IAPTinyLogger setLogEnabled:true forType:IAPTinyLogTypeDiagnose];

}

- (NSArray<NSString *> *)supportedEvents {
    return @[@"rn_mpp_service_showLog"];
}

- (void)logger:(IAPTinyLogger *)logger didCollectLog:(IAPTinyLog *)log {
    NSString *type = @"";
    if (log.type == IAPTinyLogTypeEvent) {
        type = @"event";
    } else if (log.type == IAPTinyLogTypeException) {
        type = @"exception";
    } else if (log.type == IAPTinyLogTypeDiagnose) {
        type = @"diagnose";
    }
    
    NSError *error;
    NSData *parametersData = [NSJSONSerialization dataWithJSONObject:log.parameters options:0 error:&error];
    NSString *parametersString = [[NSString alloc] initWithData:parametersData encoding:NSUTF8StringEncoding];

    if (!error) {
        [self sendEventWithName:@"rn_mpp_service_showLog" body:@{@"name":log.name,
                                                     @"type":type,
                                                     @"parameters":parametersString,
                                                   }];
    } else {
        [self sendEventWithName:@"rn_mpp_service_showLog" body:@{@"name":log.name,
                                                     @"type":type,
                                                     @"parameters":@"",
                                                   }];
    }
    
}



@end
