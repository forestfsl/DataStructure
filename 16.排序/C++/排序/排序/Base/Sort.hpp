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
#include <time.h>
#include <iostream>
#include<sys/timeb.h>
using namespace std;

template <class T>
class Sort{
public:
    long long systemtime()
    {
        timeb t;
        ftime(&t);
        return t.time*1000+t.millitm;
    }
    double cmpCount;
    double swapCount;
    long time;
    T *array;
    int m_len;
    string name;
    
    Sort<T>(int len,string name){
        array = new T[len]{};
        this->name = name;
        this->m_len = len;
        cmpCount = 0;
        swapCount = 0;
    }
    
     void sort(const T array [],int len){
        
        if (array == nullptr || len < 2) return;
     
         for (int i = 0; i < len; i++) {
             this->array[i] = array[i];
         }
         //time1
//        auto beginTime = std::chrono::high_resolution_clock::now();
//         extensionSort();
//        auto endTime = std::chrono::high_resolution_clock::now();
//        auto elapsedTime= std::chrono::duration_cast<std::chrono::seconds>(endTime - beginTime);
//         std::cout  <<"elapsed time is " << elapsedTime.count() << " second" << std::endl;
//              time = elapsedTime.count();
//         std::cin.get();
         
         //time2
//         clock_t start,ends;
//         start=clock();
//         extensionSort();
//
//
//         ends=clock();
//
//         time = ends-start;
        
         
         //time3
         long long start=systemtime();
        extensionSort();
//        cout<<systemtime()-start<<" 毫秒";
         time = systemtime()-start;
     
        
        
    }
    
    virtual void extensionSort(){
        cout << "父类" << endl;
    }
    
//    int compareTo(Sort &o){
//        int result = (int)(time - o.time);
//        if (result != 0) return result;
//
//        result = cmpCount - o.cmpCount;
//        if (result != 0) return result;
//
//        return swapCount - o.swapCount;
//    }
//
    
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
        if (this->array[v1] > this->array[v2]) {
            return 1;
        }else if (this->array[v1] < this->array[v2]){
            return -1;
        }else{
            return 0;
        }
    }
    
    int heapCmp(T v1,T v2){
        cmpCount++;
        return v1 - v2;
    }
    
    void swap(int i1,int i2){
        swapCount++;
        T tmp = this->array[i1];
        this->array[i1] = this->array[i2];
        this->array[i2] = tmp;
    }
    
    string toString(){
        string timeStr = "耗时:" + to_string(time / 1000.0) + "s(" + to_string(time) + "ms)";
        string compareCountStr = "比较" + numberString(cmpCount);
        string swapCountStr = "交换" + numberString(swapCount);
        string stableStr = "稳定性:" + to_string(isStable());
        return  this->name + "\t" + stableStr + "\t" + timeStr + "\t" + compareCountStr + "\t" + swapCountStr + "\n" + "----------------------------------------------------------------";
    }
    
    string numberString(int number){
        if (number < 10000) return  to_string(number);
        if (number < 100000000) return to_string(number / 10000.0) + "万";
        return to_string(number/ 1000000000.0) + "亿";
    }
    
    bool isStable(){
        if (this->name == "SelectionSort") return false;
        
        return true;
    }
    
    int getArrayLen()
    {
//      return (sizeof(*array) / sizeof(T));
//        cout << "数组的长度是:" << this->m_len << endl;
        return this->m_len;
    }

    
};

#endif /* Sort_hpp */
