//
//  MergeSort.hpp
//  排序
//
//  Created by fengsl on 2020/1/1.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include "Sort.hpp"

template <class T>
class MergeSort:public Sort<T>{
public:
    MergeSort(int len,string name):Sort<T>(len,name){
               
    }
    T * leftArray;//备份数组
    void extensionSort(){
         int len = this->getArrayLen();
        leftArray = new T[len >> 1]{};
        mergeSort(0, len);
    }
    
    /*
     对【begin，end】 范围的数据进行归并排序
     */
    void mergeSort(int begin,int end){
        if (end - begin < 2) return;
        int mid = (begin + end) >> 1;
        mergeSort(begin,mid);
        mergeSort(mid,end);
        merge(begin, mid,end);
    }
    
    /*
     将[begin,mid) 和 [mid,end)范围的序列合并成一个有序序列
     */
    void merge(int begin,int mid,int end){
        int li = 0;
        int le = mid - begin;
        int ri = mid;
        int re = end;
        int ai = begin;
        //备份左边数组
        for (int i = li; i < le; i++) {
            leftArray[i] = this->array[begin + i];
        }
        
        //如果左边还没有结束
        while (li < le) {
            if (ri < re && this->heapCmp(this->array[ri], this->leftArray[li]) < 0) {
                this->array[ai++] = this->array[ri++];
            }else{
                this->array[ai++] = leftArray[li++];
            }
        }
    }
};

#endif /* MergeSort_hpp */
