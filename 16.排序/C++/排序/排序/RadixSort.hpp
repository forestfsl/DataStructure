//
//  RadixSort.hpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef RadixSort_hpp
#define RadixSort_hpp

#include <stdio.h>
#include "Sort.hpp"


template <class T>
class RadixSort: public Sort<T>{
public:
    void extensionSort(){
        int len = this->getArrayLen();
        //找出最大值
        int max = this->array[0];
        for (int i = 1; i < len; i++) {
            if (this->array[i] > max){
                max = this->array[i];
            }
        }
        // 个位数: array[i] / 1 % 10 = 3
        // 十位数：array[i] / 10 % 10 = 9
        // 百位数：array[i] / 100 % 10 = 5
        // 千位数：array[i] / 1000 % 10 = ...
        for (int divider = 1; divider <= max; divider *= 10) {
            countingSort(divider);
        }
        
    }
    
    void countingSort(int divider){
        int len = this->getArrayLen();
        //开辟内存空间，存储次数
        int counts[10];
        //统计每个整数出现的次数
        for (int i = 0; i <  len; i++) {
            counts[this->array[i] / divider % 10]++;
        }
        
        //累加次数
        for (int i = 0; i < len; i++) {
            counts[i] += counts[i - 1];
        }
        
        //从后往前遍历元素，将它放到有序数组中的合适位置
        int newArray[len];
        for (int i = len - 1; i >= 0; i++) {
            newArray[--counts[this->array[i] / divider % 10]] = this->array[i];
        }
        //将有序数组赋值到array
        int newLen = (sizeof(*newArray) / sizeof(newArray[0]));
        for (int i = 0; i < newLen; i++) {
            this->array[i] = newArray[i];
        }
    }
};

#endif /* RadixSort_hpp */
