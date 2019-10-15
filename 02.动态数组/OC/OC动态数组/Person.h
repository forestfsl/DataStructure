//
//  Person.h
//  OC动态数组
//
//  Created by songlin on 2019/10/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

- (instancetype)initPersonWithAge:(int)age name:(NSString *)name;
@property (nonatomic, assign) int age;
@property (nonatomic, copy) NSString *name;
@end

NS_ASSUME_NONNULL_END
