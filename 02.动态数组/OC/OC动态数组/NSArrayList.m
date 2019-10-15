//
//  NSArrayList.m
//  OC动态数组
//
//  Created by songlin on 2019/10/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#import "NSArrayList.h"

@interface NSArrayList ()
//元素数量
@property (nonatomic, assign) int size;
//元素大小
@property (nonatomic,strong,nullable) NSMutableArray<id> *arrayList;
//数组容量
@property (nonatomic, assign) int capacity;
@end

static const int DEFAULT_CAPACITY = 10;
static const int ELEMENT_NOT_FOUND = -1;

@implementation NSArrayList

- (instancetype)init{
    if (self = [super init]) {
        self.capacity = (self.capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : self.capacity;
        self.arrayList = [NSMutableArray arrayWithCapacity:self.capacity];
    }
    return self;
}

+ (instancetype)createArrayList:(int)capacity{
    NSArrayList *arrayList = [[NSArrayList alloc]init];
    arrayList.arrayList = [NSMutableArray arrayWithCapacity:capacity];
    return arrayList;
}

- (int)countOfElement{
    return self.size;
}

- (BOOL)containsElement:(id)element{
    return [self indexOfElement:element] != ELEMENT_NOT_FOUND;
}

- (int)indexOfElement:(id)element{
    for (int i = 0; i < self.size; i++) {
        if ([self.arrayList[i] isEqual:element]) {
            return i;
        }
    }
    return ELEMENT_NOT_FOUND;
}
- (void)clear{
    for (int i = 0; i < self.size; i++) {
        self.arrayList[i] = [NSNull null];
    }
    self.size = 0;
}
- (void)addElement:(id)element{
    [self addElement:element atIndex:self.size];
}

- (void)addElement:(id)element atIndex:(int)index{
    [self rangeCheckForAddWithIndex:self.size];
    [self ensureCapacity];
    for (int i = self.size; i > index; i--) {
        self.arrayList[i] = self.arrayList[i - 1];
    }
    self.arrayList[index] = element;
    self.size++;
}

- (id)setElement:(id)element atIndex:(int)index{
    [self rangeCheckIndex:index];
    //取出旧元素值
    id oldElement = self.arrayList[index];
    self.arrayList[index] = element;
    return oldElement;
}

- (id)removeElement{
   return [self removeElementAtIndex:self.size - 1];
}

- (id)removeElementAtIndex:(int)index{
    [self rangeCheckIndex:index];
    id oldElement = self.arrayList[index];
    for (int i = 0; i < self.size; i++) {
        if (index == i) {
            //移动数组元素
            self.arrayList[i - 1] = self.arrayList[i];
        }
    }
    //最后一个元素处理
    self.arrayList[--self.size] = [NSNull null];
    return oldElement;
}

- (void)ensureCapacity{
    if (self.size < self.capacity) {
//        NSLog(@"无需扩容");
        return;
    }
    self.capacity = self.capacity + (self.capacity >> 2);
    NSMutableArray *capacityList = [NSMutableArray arrayWithCapacity:self.capacity];
    for (int i = 0; i < self.size; i++) {
        capacityList[i] = self.arrayList[i];
    }
    NSLog(@"容量从%lu扩容到%d",(unsigned long)self.arrayList.count,self.capacity);
    self.arrayList = capacityList;
  
}

- (id)elementOfIndex:(int)index{
    [self rangeCheckIndex:index];
    for (int i = 0; i < self.size; i++) {
        if (index == i) {
            return self.arrayList[index];
        }
    }
    return nil;
}

- (void)rangeCheckForAddWithIndex:(int)index{
    if (index < 0 || index > self.size) {
        @throw @"数组越界";
    }
}
- (void)rangeCheckIndex:(int)index{
    if (index < 0 || index >= self.size) {
        @throw @"数组越界";
    }
    
}

//- (NSString *)description{
//    NSString *string = @"size=";
//    string = [string stringByAppendingString:[NSString stringWithFormat:@"%d",self.size]];
//    string = [string stringByAppendingString:@",["];
//    for (int i = 0; i < self.size; i++) {
//        if (i != 0) {
//            string = [string stringByAppendingString:@","];
//        }
//        id element = self.arrayList[i];
//        if ([element isKindOfClass:[NSNumber class]]) {
//            string = [string stringByAppendingString:[NSString stringWithFormat:@"%@",element]];
//        }else{
//            [string stringByAppendingString:element];
//        }
//       
//    }
//    string = [string stringByAppendingString:@"]"];
//    return string;
//}

- (void)dealloc{
    NSLog(@"NSArrayList 释放了");
}
@end
