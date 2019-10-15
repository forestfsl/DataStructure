//
//  main.m
//  OC动态数组
//
//  Created by songlin on 2019/10/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSArrayList.h"
#import "Person.h"

void testGeneric(){
    NSArrayList *arrayList = [NSArrayList new];
    [arrayList addElement:@(10)];
    [arrayList addElement:[[Person alloc]initPersonWithAge:10 name:@"songlin"]];
    [arrayList addElement:@(20)];
    int index = [arrayList indexOfElement:[[Person alloc]initPersonWithAge:10 name:@"songlin"]];
    NSLog(@"index = %d 1：代表包含;-1:代表不包含",index);
    for (int i = 0; i < arrayList.countOfElement; i++) {
        NSLog(@"打印数组元素:%@",[arrayList elementOfIndex:i]);
    }
    NSLog(@"打印元素个数:%d",arrayList.countOfElement);
    
}



void testInteger(){
    NSArrayList *arrayList = [NSArrayList new];
    [arrayList addElement:@(10)];
    [arrayList addElement:@(20)];
    [arrayList addElement:@(30)];
    [arrayList addElement:@(40)];
    for (int i = 0; i < arrayList.countOfElement; i++) {
        NSLog(@"打印数组元素%d:%@",i,[arrayList elementOfIndex:i]);
    }
    NSInteger element = [[arrayList elementOfIndex:2] intValue];
    assert(element == 30);
    [arrayList addElement:@(50) atIndex:2];
    NSLog(@"##########################");
    NSInteger element1 = [[arrayList elementOfIndex:2] intValue];
    for (int i = 0; i < arrayList.countOfElement; i++) {
        NSLog(@"打印数组元素%d:%@",i,[arrayList elementOfIndex:i]);
    }
     assert(element1 == 50);
    
}


void testPerson(){
    NSArrayList *arrayList = [NSArrayList new];
    [arrayList addElement:[[Person alloc]initPersonWithAge:10 name:@"songlin"]];
    [arrayList addElement:[[Person alloc]initPersonWithAge:11 name:@"forest"]];
    [arrayList addElement:[[Person alloc]initPersonWithAge:12 name:@"Mrs"]];
    for (int i = 0; i < arrayList.countOfElement; i++) {
    NSLog(@"打印数组元素%d:%@",i,[arrayList elementOfIndex:i]);
    }
    
    Person *person = [arrayList elementOfIndex:2];
    assert(person.age == 12);
    assert([person.name isEqualToString:@"Mrs"]);
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        testGeneric();
//        testInteger();
        testPerson();
       
    }
    return 0;
}



