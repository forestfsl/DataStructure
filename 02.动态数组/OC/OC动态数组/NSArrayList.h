//
//  NSArrayList.h
//  OC动态数组
//
//  Created by songlin on 2019/10/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArrayList : NSObject

+ (instancetype)createArrayList:(int)capacity;
//清除元素
- (void)clear;
//添加元素
- (void)addElement:(id)element;
//指定索引出添加元素
- (void)addElement:(id)element atIndex:(int)index;
//指定索引替换元素，并返回替换的元素
- (id)setElement:(id)element atIndex:(int)index;
//移除元素
- (id)removeElement;
- (id)removeElementAtIndex:(int)index;
//返回数组元素数量
- (int)countOfElement;
//是否包含元素
- (BOOL)containsElement:(id)element;
//返回元素对应的索引
- (int)indexOfElement:(id)element;
//返回元素
- (id)elementOfIndex:(int)index;



@end

NS_ASSUME_NONNULL_END
