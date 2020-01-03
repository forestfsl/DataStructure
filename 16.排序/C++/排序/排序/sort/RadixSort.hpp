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

/*
 基数排序非常适用于整数排序(尤其是非负整数)，执行流程大概如下：
 依次对个位数，十位数，百位数，千位数，万位数...进行排序（从低位到高位）注意：如果先对高位排序，再对低位排序，是不可行的
 126 69 593 23 6 89 54 8
 593 23 54 126 6 8 69 89
 6 8 23 126 54 69 89 593
 6 8 23 54 69 89 126 593
 */

template <class T>
class RadixSort: public Sort<T>{
public:
    RadixSort(int len,string name):Sort<T>(len,name){
           
       }
    
    //下面的实现方法是使用计数排序来实现的，通过对比个位数，十位数，百位数。。。。
    
    /*
     最好，最坏，平均时间复杂度:O(d * (n + k)),d是最大值的位数，k是进制
     空间复杂度:O(n+k),k 是进制
     */
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
        //开辟内存空间，存储次数,长度写死为10，是因为只需要存储0...9 即可
        int counts[10] = {};
        //统计每个整数出现的次数
        for (int i = 0; i <  len; i++) {
            counts[this->array[i] / divider % 10]++;
        }
        
        //累加次数
        int countLen = (sizeof(counts) / sizeof(counts[0]));
        for (int i = 1; i < countLen; i++) {
            counts[i] += counts[i - 1];
        }
        
        //从后往前遍历元素，将它放到有序数组中的合适位置
        int *newArray = new int[len];
//        int newArray[8] = {}; // 3 4 5 5 6 7 7 8
        
        for (int i = len - 1; i >= 0; i--) {
//            cout <<"===" << --counts[this->array[i] / divider % 10] << endl;
            newArray[--counts[this->array[i] / divider % 10]] = this->array[i];
        }
      
        //将有序数组赋值到array  int testarray [] = {7,3,5,8,6,7,4,5};
//        int newLen = (sizeof(*newArray) / sizeof(newArray[0]));
        for (int i = 0; i < len; i++) {
            this->array[i] = newArray[i];
        }
    }
};

#endif /* RadixSort_hpp */
