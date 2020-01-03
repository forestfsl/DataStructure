//
//  CountingSort.hpp
//  排序
//
//  Created by songlin on 2020/1/3.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef CountingSort_hpp
#define CountingSort_hpp

#include <stdio.h>
#include "Sort.hpp"


/*
 统计每个整数在序列中出现的次数，进而推导出每个整数在有序序列中的索引
 */

template <class T>
class CountingSort:public Sort<T> {
public:
    CountingSort(int len,string name):Sort<T>(len,name){
        
    }
    
     void extensionSort(){
           int len = this->getArrayLen();
//         countingSort0(len);
           countingSort1(len);
       }
    
    //假设array中的最小值是min，array中的元素k对应的counts索引是k-min,array 中的元素k在有序序列中的索引，counts[k-min]-p,其中p代表着是倒数第几个k
    
    //从索引0开始依次存放3-8出现的次数
    //元素 3      4       5       6       7       8
    //索引 0      1       2       3       4       5
    //次数 1      1       2       1       2       1
    
    //元素 3      4       5       6       7       8
    //索引 0      1       2       3       4       5
    //次数 1      2       4       5       7       8
    //每个次数累加上其前面的所有次数，得到的就是元素在有序序列中的位置信息，例如元素8 在有序序列中的索引counts[8-3] - 1结果为7
    void countingSort1(int len){
        //找出最值
        int max = this->array[0];
        int min = this->array[0];
        for (int i = 1; i < len ; i++) {
            if (this->array[i] > max) {
                max = this->array[i];
            }
            if (this->array[i] < min) {
                min = this->array[i];
            }
        }
        
        //开辟内存空间，存储次数
        int *counts = new int [max - min + 1];
        //统计每个整数出现的次数
        for (int i = 0; i < len; i++) {
            counts[this->array[i] - min]++;
        }
        
        //累加次数
        for (int i = 1; i < max - min + 1; i++) {
            counts[i] += counts[i - 1];
        }
        
        //从后往前遍历元素，将它放到有序数组中的合适位置
        int *newArray = new int[len]{};
        for (int i = len - 1; i >= 0; i--) {
            newArray[--counts[this->array[i] - min]] = this->array[i];
        }
        
        //将有序数组赋值到array
        for (int i = 0; i < len; i++) {
            this->array[i] = newArray[i];
        }
    }
    
    //1.无法对负整数进行排序 2.及其浪费内存空间 3.是个不稳定的排序
   void countingSort0(int len){
        //找出最大值
       int max = this->array[0];
       for (int i = 1; i < len; i++) {
           if (this->array[i] > max){
               max = this->array[i];
           }
       }//O(n)
       
       //开辟内存空间，存储每个整数出现的次数
       int *counts = new int[1 + max]{};
       //根据每个整数出现的次数
       for (int i = 0; i < len; i++) {
           counts[this->array[i]]++;
       }//O(n)
       
       //根据整数的出现次数，对整数进行排序
       int index = 0;
       for (int i = 0; i < (1 + max); i++) {
           while (counts[i]-- > 0) {
               this->array[index++] = i;
           }
       }//O(n)
    }
    
    
    
};
#endif /* CountingSort_hpp */
