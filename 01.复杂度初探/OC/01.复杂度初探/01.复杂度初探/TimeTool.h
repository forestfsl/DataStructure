//
//  TimeTool.h
//  01.复杂度初探
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^FuncBlock)(void);

@interface TimeTool : NSObject


+ (void)check:(NSString *)title completion:(FuncBlock)functionBlock;

@end

NS_ASSUME_NONNULL_END
