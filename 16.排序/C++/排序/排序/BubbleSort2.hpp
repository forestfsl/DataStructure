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
    BubbleSort2(int len,string name):Sort<T>(len,name){
        
    }
    /*
    这个优化对于有序数组更加明显，通过声明一个sorted等于true，如果遍历完一次之后，sorted没有等于false，说明是有序数组，直接退出循环，如果sorted等于false，可以肯定该数组不是前序排列，继续遍历，为什么sorted要在for循环里面每次都要设置为yes呢，经过前面的一轮之后，有可能数组从无序编程了有序
    */
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
