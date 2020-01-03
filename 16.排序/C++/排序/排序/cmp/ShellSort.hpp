//
//  ShellSort.hpp
//  排序
//
//  Created by songlin on 2020/1/2.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef ShellSort_hpp
#define ShellSort_hpp

#include <stdio.h>
#include "ShellSort.hpp"
#include "Sort.hpp"
#include <vector>
using namespace std;

/**
 希尔排序把序列看做是一个矩阵，分成m列，逐步将列进行排序，m从某个整数逐渐减为1，当m为1时，整个序列完全有序，因此希尔排序也被称为递减增量排序(Diminishing Increment Sort)
 希尔本人给出的步长序列是n/2^k,比如n为16时，步长序列是{1,2,4,8}
 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
 按照8列进行排序
 16 15 14 13 12 11 10 9
  8 7  6     5   4   3  2  1
 
 8   7   6    5   4    3    2    1
16  15  14 13  12  11  10  9
 
 8 7 6 5 4 3 2 1 16 15 14 13 12 11 10 9
 
 分成4列进行排序
8    7   6  5
4    3   2  1
16 15 14 13
12 11 19 9
 
 4   3      2   1
 8    7    6    5
 12 11  10   9
 16 15 14 13
 
 4 3 2 1 8 7 6 5 4 12 11 10 9 16 15 14 13
 
 按成2列进行排序
 4   3
 2   1
 8    7
 6    5
12  11
10  9
16   15
14   13
 
 2      1
 4      3
 6      5
 8      7
 10    9
 12    11
 14    13
 16    15
 
 2 1 4 3 6 5 8 7 10 9 12 11 14 13 16 15
 
 2
 1
 ...
 16
 15
 
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 */

template <class T>
class ShellSort:public Sort<T>{
    
public:
    vector <int > stepArray;
    ShellSort(int len,string name):Sort<T>(len,name){
                     
          }
       
    void extensionSort(){
        shellStepSequence();
        for (int step : stepArray) {
            shellSortMethod(step);
        }
    }
    
    
   void shellSortMethod(int step){
         int len = this->getArrayLen();
       //col:第几列，column的简称
       for (int col = 0; col < step; col++) {//对第col列进行排序
           //col,col+step,col+2*step,col+3*step
           for (int begin = col + step; begin < len; begin += step) {
               int cur = begin;
               while (cur > col && this->cmp(cur,cur - step) < 0) {
                   this->swap(cur,cur - step);
                   cur -= step;
               }
           }
       }
    }
    
    
    /**
     分成step列进行排序
     */
    
    /*
     生成序列
     */
    vector <int > shellStepSequence(){
        
        int step = this->getArrayLen();
      
        while ((step >>= 1) >0) {
            stepArray.push_back(step);
        }
        return stepArray;
    }
    
};

#endif /* ShellSort_hpp */
