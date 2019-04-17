//
//  TimeTool.m
//  01.复杂度初探
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#import "TimeTool.h"

@implementation TimeTool


+(NSString*)getCurrentTimes{
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    
    // ----------设置你想要的格式,hh与HH的区别:分别表示12小时制,24小时制
    
    [formatter setDateFormat:@"YYYY-MM-dd HH:mm:ss"];
    
    //现在时间,你可以输出来看下是什么格式
    
    NSDate *datenow = [NSDate date];
    
    //----------将nsdate按formatter格式转成nsstring
    
    NSString *currentTimeString = [formatter stringFromDate:datenow];
    
//    NSLog(@"currentTimeString =  %@",currentTimeString);
    
    return currentTimeString;
    
}

+ (void)check:(NSString *)title completion:(FuncBlock)functionBlock{
    if (!functionBlock) {
        return;
    }
//    NSDate* start = [NSDate dateWithTimeIntervalSinceNow:0];
//    NSTimeInterval a=[start timeIntervalSince1970] * 1000;
//    NSString *beginString = [NSString stringWithFormat:@"%.0f", a];
    
    NSString *beginString = [self getCurrentTimes];
    
    NSLog(@"title:%@",title);
    NSLog(@"开始时间%@:",beginString);
    if (functionBlock) {
        functionBlock();
    }
    
//    NSDate* end = [NSDate dateWithTimeIntervalSinceNow:0];
//    NSTimeInterval b=[end timeIntervalSince1970] * 1000;
//    NSString *endString = [NSString stringWithFormat:@"%.0f", b];
//    NSLog(@"耗时:%f",[endString floatValue] - [beginString floatValue]);
    
     NSString *endString = [self getCurrentTimes];
    NSLog(@"结束时间%@:",endString);
    
    
}

/*
 *
 终端输出：测试的时候我用了45来测试，发现64fib(1)几年都出不来
 2019-04-17 17:00:43.257515+0800 01.复杂度初探[16529:16380213] title:fib1
 2019-04-17 17:00:43.257592+0800 01.复杂度初探[16529:16380213] 开始时间2019-04-17 17:02:43:
 2019-04-17 17:02:13.830494+0800 01.复杂度初探[16513:16378278] title:fib2
 2019-04-17 17:02:13.830581+0800 01.复杂度初探[16513:16378278] 开始时间2019-04-17 17:02:13:
 2019-04-17 17:02:13.830846+0800 01.复杂度初探[16513:16378278] 结束时间2019-04-17 17:02:13:
 */

@end
