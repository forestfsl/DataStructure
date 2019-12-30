//
//  main.cpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#include <iostream>
#include "SelectionSort.hpp"
#include "BubbleSort1.hpp"
#include "BubbleSort2.hpp"
#include "BubbleSort3.hpp"
#include "HeapSort.hpp"
#include "RadixSort.hpp"
#include "Integers.hpp"
using namespace std;


template <class T>
static void testSorts1(int localLen, const T &array, Sort<int>*sort){
//     int len = (sizeof(array) / sizeof(array[0]));
    int len = localLen;
//    for (int i = 0; i < len; i++) {
//        cout << array[i] << endl;
//    }
   
    sort->sort(array,len);
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < len; i++) {
        cout << sort->array[i] << endl;
       
    }
     cout << sort->toString() << endl;
}

template <class T>
static void testSorts( const T &array, Sort<int>*sort){
     int len = (sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < len; i++) {
        cout << array[i] << endl;
    }
   
    sort->sort(array,len);
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < len; i++) {
        cout << sort->array[i] << endl;
       
    }
     cout << sort->toString() << endl;
}


template <class T>
static int fetchArrayLen(const T &array){
    int len = (sizeof(array) / sizeof(array[0]));
    return len;
}

void testSelectionSort(){
      int testarray [] = {7,3,5,8,6,7,4,5};
    int len = fetchArrayLen(testarray);
       Sort<int> *selectionSort = new SelectionSort<int>(len,"SelectionSort");
       testSorts(testarray, selectionSort);
}


void testSelectionSort1(){
    int localLen = 100000;
     
      int *randomrray = Integers::randomArray(localLen,1,99999);

      
      Sort<int> *selectionSort1 = new SelectionSort<int>(localLen,"SelectionSort");
      testSorts1(localLen,randomrray, selectionSort1);
}

int main(int argc, const char * argv[]) {
   
    
  
    
   
    
    return 0;
}
