//
//  HeapSort.hpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include <stdio.h>
#include "Sort.hpp"

template <class T>
class HeapSort:public Sort<T> {
public:
    HeapSort(int len,string name):Sort<T>(len,name){
        
    }
    int heapSize;
    void extensionSort(){
      
         heapSize = this->getArrayLen();

        //批量建堆
        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
            siftDown(i);
        }
        
        while (heapSize > 1) {
            //交换堆顶元素和尾部元素(将最大值放到末尾元素，然后0位置siftDown)
            this->swap(0, --heapSize);
            
            //对0位置进行siftDown(恢复堆的性质)
            siftDown(0);
        }
    }
    
    void siftDown(int index){
        T element = this->array[index];
        int half = heapSize >> 1;
        while (index < half) { //index 必需是非叶子节点
            //默认是左边跟父节点比
            int childIndex = (index << 1) + 1;
            T child = this->array[childIndex];
            
            int rightIndex = childIndex + 1;
            
            //右子节点比左子节点大
            if (rightIndex < heapSize && this->heapCmp(this->array[rightIndex],child) > 0) {
                child = this->array[childIndex = rightIndex];
            }
            //大于等于子节点
            if (this->heapCmp(element, child) >= 0) break;
            
            this->array[index] = child;
            index = childIndex;
        }
        this->array[index] = element;
    }
};

#endif /* HeapSort_hpp */
