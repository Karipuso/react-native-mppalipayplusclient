//
//  MPPRemoteConfiguration.h
//  MPPAlipayPlusClient
//
//  Created by yihan on 2023/6/5.
//

#import <Foundation/Foundation.h>
#import "MPPResponseModelProtocol.h"

#define CodingImplementation \
- (void)encodeWithCoder:(NSCoder *)encoder { \
    unsigned int outCount = 0; \
    Ivar *ivars = class_copyIvarList([self class], &outCount); \
    for (int i = 0; i < outCount; i++) { \
        Ivar ivar = ivars[i]; \
        NSString *key = [NSString stringWithUTF8String:ivar_getName(ivar)]; \
        [encoder encodeObject:[self valueForKey:key] forKey:key]; \
    } \
    free(ivars); \
} \
- (instancetype)initWithCoder:(NSCoder *)decoder { \
    self = [super init]; \
    if (self) { \
        unsigned int outCount = 0; \
        Ivar *ivars = class_copyIvarList([self class], &outCount); \
        for (int i = 0; i < outCount; i++) { \
            Ivar ivar = ivars[i]; \
            NSString *key = [NSString stringWithUTF8String:ivar_getName(ivar)]; \
            id value = [decoder decodeObjectForKey:key]; \
            if (value) { \
                [self setValue:value forKey:key]; \
            } \
        } \
        free(ivars); \
    } \
    return self; \
}

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MPPAcceptanceMarkLogo
@interface MPPAcceptanceMarkLogo : NSObject <MPPResponseModelProtocol, NSCoding>

@property (nonatomic, copy, nullable) NSString *logoName;
@property (nonatomic, copy) NSString *logoUrl;

@end

#pragma mark - MPPRegionAcceptanceMark
@interface MPPRegionAcceptanceMark : NSObject <MPPResponseModelProtocol, NSCoding>

@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSArray<MPPAcceptanceMarkLogo *> *mpmLogos;
@property (nonatomic, copy) NSArray<MPPAcceptanceMarkLogo *> *upmLogos;

@end

#pragma mark - MPPRemoteBasicConfig
@interface MPPRemoteBasicConfig : NSObject <MPPResponseModelProtocol, NSCoding>

@property (nonatomic, copy) NSString *regionDecidingFactor;
@property (nonatomic, copy) NSArray<MPPRegionAcceptanceMark *> *regionAcceptanceMarks;
@property (nonatomic, copy) NSArray<NSString *> *pspRegions;
@property (nonatomic, copy) NSArray<NSString *> *availableRegions;

@end


#pragma mark - MPPRemoteConfiguration
@interface MPPRemoteConfiguration : NSObject

+ (instancetype)shared;
- (void)updateConfig;
- (nullable MPPRemoteBasicConfig *)getConfig;

@end



NS_ASSUME_NONNULL_END


