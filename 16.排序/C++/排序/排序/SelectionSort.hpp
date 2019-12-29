//
//  SelectionSort.hpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef SelectionSort_hpp
#define SelectionSort_hpp

#include <stdio.h>
#include "Sort.hpp"

template <class T>
class SelectionSort:public Sort<T> {
public:
    void extensionSort(){
        int len = this->getArrayLen();
//        for (int end = len - 1; end > 0; end--) {
//            int max = 0;
//            for (int begin = 1; begin <= end; begin++) {
//        if (this->cmp(max, begin) <= 0) {
//               max = begin;
//        }
//            }
//        }
//        this->swap(max, end);
//    }
        
        for (int end = len - 1 ; end > 0; end--) {
            int max = 0;
            for (int begin = 1; begin <= end; begin++) {
                   if (this->cmp(max, begin) < 0) {
                   max = begin;
                }
            }
            this->swap(max, end);
        }
    }
};

#endif /* SelectionSort_hpp */
