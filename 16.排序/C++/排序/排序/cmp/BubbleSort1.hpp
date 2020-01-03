//
//  BubbleSort1.hpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef BubbleSort1_hpp
#define BubbleSort1_hpp


#include <stdio.h>
#include "Sort.hpp"

template <class T>
class BubbleSort1: public Sort<T>{
public:
    BubbleSort1(int len,string name):Sort<T>(len,name){
          
      }
    /*
     第一轮比较:
     相邻两位元素从头开始比较，一直比较到最后，第一轮比较完之后，最大值就放到了最后一个元素，
     第二轮比较：
     因为经过第一轮比较之后，最大值是最后一位了，所以第二轮比较的时候，是不需要再比较最后一位元素，这也就是第一轮的索引为什么从end = len - 1开始，然后end--的原因了
     第三轮其实就是在重复第二轮的操作一直下去，知道排好序
     */
    void extensionSort(){
         int len = this->getArrayLen();
        for (int end = len - 1; end > 0; end--) {
            for (int begin = 1; begin <= end; begin++) {
                if (this->cmp(begin,begin-1) < 0) {
                    this->swap(begin,begin - 1);
                }
            }
        }
    }
};

#endif /* BubbleSort1_hpp */
