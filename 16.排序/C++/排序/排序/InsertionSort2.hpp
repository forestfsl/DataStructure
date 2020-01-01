//
//  InsertionSort2.hpp
//  排序
//
//  Created by fengsl on 2020/1/1.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef InsertionSort2_hpp
#define InsertionSort2_hpp

#include <stdio.h>
#include "Sort.hpp"

template <class T>
class InsertionSort2:public Sort<T>{
public:
    InsertionSort2(int len,string name):Sort<T>(len,name){
               
    }
    /*
     优化思路将交换转换为移动
     */
    void extensionSort(){
         int len = this->getArrayLen();
        for (int begin = 1; begin < len ; begin++) {
            int cur = begin;
            T v = this->array[cur];
            while (cur > 0 && this->heapCmp(v, this->array[cur - 1]) < 0) {
                this->array[cur] = this->array[cur - 1];
                cur--;
            }
            this->array[cur] = v;
            
        }
    }
};

#endif /* InsertionSort2_hpp */
