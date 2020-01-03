//
//  QuickSort.hpp
//  排序
//
//  Created by songlin on 2020/1/2.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include "Sort.hpp"

/**
 原理：1.从序列中选择一个轴点元素，假设每次选择0位置的元素为轴点元素
 2.利用pivot将序列分割成2个子序列，将小于pivotd的元素放在pivot前面(左侧)，将 大于pivot的元素放在pivot后面(右侧)，等于的元素放哪边都可以
 接下来对子序列进行1，2操作，知道不能再分割为止(子序列中只剩下一个元素)
 
 */

template <class T>
class QuickSort:public Sort<T> {
public:
    QuickSort(int len,string name):Sort<T>(len,name){
                  
       }
    
    void extensionSort(){
        int len = this->getArrayLen();
        quickSort(0, len);
    }
    
    
    /*
     对[begin,end) 范围的元素进行快速排序
     */
    void quickSort(int begin,int end){
        if (end - begin < 2) return;
        //确定轴点位置O(n)
        int mid = pivotIndex(begin, end);
        //对子序列进行快速排序
        quickSort(begin, mid);
        quickSort(mid + 1, end);
    }
    
    /**
     构造出[begin,end) 范围的轴点元素
     @return 轴点元素的最终位置
     */
    int  pivotIndex(int begin,int end){
         //随机选择一个元素跟begin位置进行交换，避免出现快速排序最坏的打算，减少逆向对
        this->swap(begin, (int)((rand() % (end - begin)) + begin));
        
        //备份begin位置的元素
        T pivot = this->array[begin];
        //end 指向最后一个元素
        end--;
        //whild 内部还有两个判断是用来改变遍历方向而设置的
        while (begin < end) {
            while (begin < end) {
                //不设置小于等于0的时候设置是希望能让数据可以分配得更加均匀一点
                if (this->heapCmp(pivot, this->array[end]) < 0) { //右边元素 > 轴点元素
                    end--;
                }else{//右边元素 <= 轴点元素
                    this->array[begin++] = this->array[end];
                    break;
                }
            }
            while (begin < end) {
                if (this->heapCmp(pivot, this->array[begin]) > 0){//左边元素 < 轴点元素
                    begin++;
                }else{//左边元素 >= 轴点元素
                    this->array[end--] = this->array[begin];
                    break;
                }
            }
        }
        //将轴点元素放入最终的位置
        this->array[begin] = pivot;
        //返回轴点元素位置
        return begin;
    }
    
};

#endif /* QuickSort_hpp */
