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
