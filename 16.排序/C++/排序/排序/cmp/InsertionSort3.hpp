//
//  InsertionSort3.hpp
//  排序
//
//  Created by fengsl on 2020/1/1.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef InsertionSort3_hpp
#define InsertionSort3_hpp

#include <stdio.h>
#include "Sort.hpp"

template <class T>
class InsertionSort3:public Sort<T>{
public:
    InsertionSort3(int len,string name):Sort<T>(len,name){
                  
       }
       /*
        优化思路将交换转换为移动
        */
    void extensionSort(){
        int len = this->getArrayLen();
        for (int begin = 1; begin < len; begin++) {
            insert(begin, search(begin));
        }
    }
    
    /*
     将source 位置的元素插入到dest位置
     @param source
     @param dest;
     */
    void insert(int source,int dest){
        T v = this->array[source];
        for (int i = source; i > dest; i--) {
            this->array[i] = this->array[i - 1];
        }
        this->array[dest] = v;
    }
    
    /*
     利用二分搜索找到index 位置元素的待插入位置
     已经拍好序数组的区间范围是[0,index)
     @param index
     @return
     */
    int search(int index){
        int begin = 0;
        int end = index;
        while (begin < end) {
            int mid = (begin + end) >> 1;
            if (this->heapCmp(this->array[index], this->array[mid]) < 0) {
                end = mid;
            }else{
                begin = mid + 1;
            }
        }
        return begin;
    }
};

#endif /* InsertionSort3_hpp */
