//
//  NSThread+MPPUtils.h
//  MPPAlipayPlusClient
//
//  Created by assuner on 2022/7/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef mppu_weakify
#define mppu_weakify(obj) \
autoreleasepool {}\
__weak typeof(obj) __mppu__weak_##obj = obj;
#endif

#ifndef mppu_strongify
#define mppu_strongify(obj) \
autoreleasepool {}\
__strong typeof(__mppu__weak_##obj) obj = __mppu__weak_##obj;
#endif

@interface NSThread (MPPUtils)
+ (void)mppu_syncExecuteInMainThread:(dispatch_block_t)block;
@end

NS_ASSUME_NONNULL_END
