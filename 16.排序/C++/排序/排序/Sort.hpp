//
//  Sort.hpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
#include <chrono>
#include <iostream>
using namespace std;

template <class T>
class Sort{
public:
    int cmpCount;
    int swapCount;
    long time;
    T *array;
    int m_len;
    string name;
    
    Sort<T>(int len,string name){
        array = new T[len]{};
        this->name = name;
        this->m_len = len;
    }
    
     void sort(const T array [],int len){
        
        if (array == nullptr || len < 2) return;
     
         for (int i = 0; i < len; i++) {
             this->array[i] = array[i];
         }
        auto beginTime = std::chrono::high_resolution_clock::now();
        
        extensionSort();
         
        auto endTime = std::chrono::high_resolution_clock::now();
       auto elapsedTime= std::chrono::duration_cast<std::chrono::seconds>(endTime - beginTime);
        std::cout  <<"elapsed time is " << elapsedTime.count() << " second" << std::endl;
         time = elapsedTime.count();
        std::cin.get();
        
        
        
    }
    
    virtual void extensionSort(){
        cout << "父类" << endl;
    }
    
    int compareTo(Sort &o){
        int result = (int)(time - o.time);
        if (result != 0) return result;
        
        result = cmpCount - o.cmpCount;
        if (result != 0) return result;
        
        return swapCount - o.swapCount;
    }
    
    
//    int cmp(int i1, int i2){
//        cmpCount++;
//        if (array[i1] > array[i2]) {
//            return 1;
//        }else if (array[i1] < array[i2]){
//            return -1;
//        }else{
//            return 0;
//        }
//    }
    
    int cmp(T v1, T v2){
        cmpCount++;
        if (array[v1] > array[v2]) {
            return 1;
        }else if (array[v1] < array[v2]){
            return -1;
        }else{
            return 0;
        }
    }
    
    void swap(int i1,int i2){
        swapCount++;
        T tmp = array[i1];
        array[i1] = array[i2];
        array[i2] = tmp;
    }
    
    string toString(){
        string timeStr = "耗时:" + to_string(time / 1000.0) + "s(" + to_string(time) + "ms)";
        string compareCountStr = "比较" + numberString(cmpCount);
        string swapCountStr = "交换" + numberString(swapCount);
        string stableStr = "稳定性:" + to_string(isStable());
        return  this->name + "\n" + stableStr + "\n" + timeStr + "\n" + compareCountStr + "\n" + swapCountStr + "\n" + "--------------------------------------------";
    }
    
    string numberString(int number){
        if (number < 10000) return  to_string(number);
        if (number < 100000000) return to_string(number / 10000.0) + "万";
        return to_string(number/ 1000000000.0) + "亿";
    }
    
    bool isStable(){
        if (this->name == "isStable") return false;
        
        return true;
    }
    
    int getArrayLen()
    {
//      return (sizeof(*array) / sizeof(T));
        cout << "数组的长度是:" << this->m_len << endl;
        return this->m_len;
    }

    
};

#endif /* Sort_hpp */
