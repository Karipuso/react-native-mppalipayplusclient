//
//  MPPAlipayPlusClientRNLogger.m
//  react-native-mppalipayplusclient
//
//  Created by yihan on 2023/6/13.
//

#import "MPPAlipayPlusClientRNLogger.h"
#import <IAPTinyLogger/IAPTinyLogger.h>

@interface MPPAlipayPlusClientRNLogger ()
@property (nonatomic, strong) IAPTinyLogger *logger;
@end

@implementation MPPAlipayPlusClientRNLogger

+ (instancetype)shared {
    static MPPAlipayPlusClientRNLogger *client = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        client = [self new];
    });
    return client;
}

- (instancetype)init {
    if (self = [super init]) {
        self.logger = [[IAPTinyLogger alloc] initWithProductId:@"MPPAlipayPlusClient_RN_iOS" bizName:@"payment"];
    }
    return self;
}

- (void)logEventWithName:(NSString *)name params:(nullable NSDictionary *)params {
    IAPTinyLog *log = [IAPTinyLog new];
    log.type = IAPTinyLogTypeEvent;
    log.name = name;
    log.parameters = params;
    [self.logger log:log];
}


@end
