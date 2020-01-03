//
//  BubbleSort3.hpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef BubbleSort3_hpp
#define BubbleSort3_hpp

#include <stdio.h>
#include "Sort.hpp"

template <class T>
class BubbleSort3: public Sort<T>{
public:
    BubbleSort3(int len,string name):Sort<T>(len,name){
        
    }
    /**
     这个优化是记录最后一次交换的索引值
     
          10  4 1 3 2 5 7 8 9-->4 1 3 2 5 7 8 9 10
        第二轮比较可以看到交换的索引值实在3，那么第三轮end的值就直接编程了0 -- 3 ，减少了交换的次数
     */
    void extensionSort(){
         int len = this->getArrayLen();
        for (int end = len - 1; end > 0; end--) {
            int sortedIndex = 1;
            for (int begin = 1; begin <= end; begin++) {
                if (this->cmp(begin,begin-1) < 0) {
                    this->swap(begin,begin - 1);
                    sortedIndex = begin;
                }
            }
            end = sortedIndex;
        }
    }
};

#endif /* BubbleSort3_hpp */
