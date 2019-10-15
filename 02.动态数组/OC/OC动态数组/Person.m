//
//  Person.m
//  OC动态数组
//
//  Created by songlin on 2019/10/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#import "Person.h"

@interface Person ()

@end

@implementation Person
- (instancetype)initPersonWithAge:(int)age name:(NSString *)name{
    if (self = [super init]) {
        self.age = age;
        self.name = name;
    }
    return self;
}
- (NSString *)description{
    NSString *string = @"Person [age= ";
    string = [string stringByAppendingString:[NSString stringWithFormat:@"%d",self.age]];
    string = [string stringByAppendingString:@",name="];
    string = [string stringByAppendingString:self.name];
    string = [string stringByAppendingString:@"]"];
    string = [string stringByAppendingString:[NSString stringWithFormat:@"<%@: %p>",[self class],self]];
    return string;
}
//-(NSString*)description{
//    return [NSString stringWithFormat:@"<%@: %p> {name: %@ ,age: %@}",[self class],self,self.name,self.age];
//}

- (void)dealloc{
    NSLog(@"Person%@ 销毁了",self);
}

- (BOOL)isEqual:(id)object{
    if (object == nil) {
        return  false;
    }
    if ([object isKindOfClass:[Person class]]) {
        Person *person = (Person *)object;
        return self.age = person.age;
    }
    return false;
}

@end
