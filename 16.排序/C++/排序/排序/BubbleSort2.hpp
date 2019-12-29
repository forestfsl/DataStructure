//
//  BubbleSort2.hpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef BubbleSort2_hpp
#define BubbleSort2_hpp

#include <stdio.h>

#include "Sort.hpp"

template <class T>
class BubbleSort2: public Sort<T>{
public:
    void extensionSort(){
         int len = this->getArrayLen();
        for (int end = len - 1; end > 0; end--) {
            bool sorted = true;
            for (int begin = 1; begin <= end; begin++) {
                if (this->cmp(begin,begin-1) < 0) {
                    this->swap(begin,begin - 1);
                    sorted = false;
                }
            }
            if (sorted) break;
        }
    }
};


#endif /* BubbleSort2_hpp */
