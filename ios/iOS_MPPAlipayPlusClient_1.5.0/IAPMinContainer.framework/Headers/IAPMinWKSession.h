//
//  IAPMinWKSession.h
//  IAPMinContainer
//
//  Created by chris.ym on 2019/12/9.
//  Copyright © 2019 chris.ym. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPMinWKSessionContext.h"
NS_ASSUME_NONNULL_BEGIN

/**
 *  A class which defines the business IAPMinWKWebView.
*/
@interface IAPMinWKSession : NSObject
/**
 *  A `IAPMinWKSessionContext` instance contains a id ,url and some parameters
*/
@property(nonatomic, readonly, strong) IAPMinWKSessionContext *context;

/**
 *  Initials a IAPMinWKSession instance  with a `IAPMinWKSessionContext` instance.
 *
 *  @param context  A IAPMinWKSessionContext instance.
 *
 *  @return A IAPMinWKSession instance .
*/
- (instancetype)initWithContext:(IAPMinWKSessionContext *)context;
@end

NS_ASSUME_NONNULL_END
