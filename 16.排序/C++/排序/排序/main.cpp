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
#include "InsertionSort1.hpp"
#include "InsertionSort2.hpp"
#include "InsertionSort3.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "ShellSort.hpp"
using namespace std;


#define localArrayLen 100
#define localMin 1
#define localMax 99

static void testSorts1(int localLen, int *array, Sort<int>*sort){
    int len = localLen;
//    for (int i = 0; i < localLen; i++) {
//        cout <<"testSorts1" << array[i] << endl;
//    }
    sort->sort(array,len);
    cout << "----------------------------------------------------------------" << endl;
//    for (int i = 0; i < len; i++) {
//        cout << sort->array[i] << endl;
//       
//    }
     cout << sort->toString() << endl;
}

template <class T>
static void testSorts( const T &array, Sort<int>*sort){
     int len = (sizeof(array) / sizeof(array[0]));
//    for (int i = 0; i < len; i++) {
//        cout << array[i] << endl;
//    }

    sort->sort(array,len);
//    cout << "---------------------------------------" << endl;
//    for (int i = 0; i < len; i++) {
//        cout << sort->array[i] << endl;
//
//    }
     cout << sort->toString() << endl;
}


template <class T>
static int fetchArrayLen(const T &array){
    int len = (sizeof(array) / sizeof(array[0]));
    return len;
}

/*
【MergeSort】
稳定性：true     耗时：0.0s(0ms)     比较：16     交换：0
------------------------------------------------------------------
【QuickSort】
稳定性：false     耗时：0.0s(0ms)     比较：16     交换：5
------------------------------------------------------------------
【BubbleSort3】
稳定性：true     耗时：0.0s(0ms)     比较：26     交换：14
------------------------------------------------------------------
【HeapSort】
稳定性：false     耗时：0.0s(0ms)     比较：27     交换：7
------------------------------------------------------------------
【InsertionSort3】
稳定性：true     耗时：0.001s(1ms)     比较：16     交换：0
------------------------------------------------------------------
【ShellSort】
稳定性：false     耗时：0.001s(1ms)     比较：23     交换：14
------------------------------------------------------------------
【SelectionSort】
稳定性：false     耗时：0.001s(1ms)     比较：28     交换：7
------------------------------------------------------------------
 */

void customSelectionSort(){
      int testarray [] = {7,3,5,8,6,7,4,5};
    int len = fetchArrayLen(testarray);
       Sort<int> *selectionSort = new SelectionSort<int>(len,"SelectionSort");
       testSorts1(len,testarray, selectionSort);
}

void customBubbleSort1(){
    int testarray [] = {7,3,5,8,6,7,4,5};
    int len = fetchArrayLen(testarray);
    Sort<int> *selectionSort1 = new BubbleSort1<int>(len,"BubbletSort1");
    testSorts1(len,testarray, selectionSort1);
}

void customBubbleSort2(){
    int testarray [] = {7,3,5,8,6,7,4,5};
       int len = fetchArrayLen(testarray);
    Sort<int> *selectionSort1 = new BubbleSort2<int>(len,"BubbletSort2");
    testSorts1(len,testarray, selectionSort1);
}


void customBubbleSort3(){
    int testarray [] = {7,3,5,8,6,7,4,5};
          int len = fetchArrayLen(testarray);
    Sort<int> *selectionSort1 = new BubbleSort3<int>(len,"BubbletSort3");
    testSorts1(len,testarray, selectionSort1);
}

void customHeapSort(){
    int testarray [] = {7,3,5,8,6,7,4,5};
          int len = fetchArrayLen(testarray);
    Sort<int> *selectionSort1 = new HeapSort<int>(len,"HeapSort");
    testSorts1(len,testarray, selectionSort1);
}


void customSelectionSort1(){
    int testarray [] = {7,3,5,8,6,7,4,5};
          int len = fetchArrayLen(testarray);
    Sort<int> *selectionSort1 = new SelectionSort<int>(len,"SelectionSort");
    testSorts1(len,testarray, selectionSort1);
}

void customInsertionSort1(){
    int testarray [] = {7,3,5,8,6,7,4,5};
          int len = fetchArrayLen(testarray);
       Sort<int> *selectionSort1 = new InsertionSort1<int>(len,"InsertionSort1");
       testSorts1(len,testarray, selectionSort1);
    
}

void customInsertionSort2(){
    int testarray [] = {7,3,5,8,6,7,4,5};
          int len = fetchArrayLen(testarray);
       Sort<int> *selectionSort1 = new InsertionSort2<int>(len,"InsertionSort2");
       testSorts1(len,testarray, selectionSort1);
    
}
void customInsertionSort3(){
    int testarray [] = {7,3,5,8,6,7,4,5};
          int len = fetchArrayLen(testarray);
       Sort<int> *selectionSort1 = new InsertionSort3<int>(len,"InsertionSort3");
       testSorts1(len,testarray, selectionSort1);
    
}

void customMergeSort(){
    int testarray [] = {7,3,5,8,6,7,4,5};
          int len = fetchArrayLen(testarray);
       Sort<int> *selectionSort1 = new MergeSort<int>(len,"MergeSort");
       testSorts1(len,testarray, selectionSort1);
    
}

void customQuickSort(){
    int testarray [] = {7,3,5,8,6,7,4,5};
       int len = fetchArrayLen(testarray);
    Sort<int> *selectionSort1 = new QuickSort<int>(len,"QuickSort");
    testSorts1(len,testarray, selectionSort1);
}

void customShellSort(){
    int testarray [] = {7,3,5,8,6,7,4,5};
       int len = fetchArrayLen(testarray);
    Sort<int> *selectionSort1 = new ShellSort<int>(len,"ShellSort");
    testSorts1(len,testarray, selectionSort1);
}


//##################################################################3
void testBubbleSort1(){
    int localLen = localArrayLen;
    int *randomrray = Integers().randomArray(localLen,1,localMax);
    Sort<int> *selectionSort1 = new BubbleSort1<int>(localLen,"BubbletSort1");
    testSorts1(localLen,randomrray, selectionSort1);
}

void testBubbleSort2(){
    int localLen = localArrayLen;
    int *randomrray = Integers().randomArray(localLen,1,localMax);
    Sort<int> *selectionSort1 = new BubbleSort2<int>(localLen,"BubbletSort2");
    testSorts1(localLen,randomrray, selectionSort1);
}


void testBubbleSort3(){
    int localLen = localArrayLen;
    int *randomrray = Integers().randomArray(localLen,1,localMax);
    Sort<int> *selectionSort1 = new BubbleSort3<int>(localLen,"BubbletSort3");
    testSorts1(localLen,randomrray, selectionSort1);
}

void testHeapSort(){
    int localLen = localArrayLen;
    int *randomrray = Integers().randomArray(localLen,1,localMax);
    Sort<int> *selectionSort1 = new HeapSort<int>(localLen,"HeapSort");
    testSorts1(localLen,randomrray, selectionSort1);
}


void testSelectionSort1(){
    int localLen = localArrayLen;
    int *randomrray = Integers().randomArray(localLen,1,localMax);
    Sort<int> *selectionSort1 = new SelectionSort<int>(localLen,"SelectionSort");
    testSorts1(localLen,randomrray, selectionSort1);
}

void testInsertionSort1(){
    int localLen = localArrayLen;
       int *randomrray = Integers().randomArray(localLen,1,localMax);
       Sort<int> *selectionSort1 = new InsertionSort1<int>(localLen,"InsertionSort1");
       testSorts1(localLen,randomrray, selectionSort1);
    
}
/*
【MergeSort】
稳定性：true     耗时：0.0s(0ms)     比较：537     交换：0
------------------------------------------------------------------
【ShellSort】
稳定性：false     耗时：0.0s(0ms)     比较：706     交换：410
------------------------------------------------------------------
【HeapSort】
稳定性：false     耗时：0.0s(0ms)     比较：1024     交换：99
------------------------------------------------------------------
【BubbleSort3】
稳定性：true     耗时：0.0s(0ms)     比较：4850     交换：2507
------------------------------------------------------------------
【InsertionSort3】
稳定性：true     耗时：0.001s(1ms)     比较：527     交换：0
------------------------------------------------------------------
【QuickSort】
稳定性：false     耗时：0.001s(1ms)     比较：597     交换：62
------------------------------------------------------------------
【SelectionSort】
稳定性：false     耗时：0.001s(1ms)     比较：4950     交换：99
------------------------------------------------------------------
 */

int main(int argc, const char * argv[]) {

//    testBubbleSort1();
//    testBubbleSort2();
//    testBubbleSort3();
//    testHeapSort();
//    testSelectionSort1();
//    testInsertionSort1();
    
//    customBubbleSort1();
//    customBubbleSort2();
//    customBubbleSort3();
//    customHeapSort();
//    customSelectionSort();
//    customInsertionSort1();
//    customInsertionSort2();
//    customInsertionSort3();
    customMergeSort();
    customQuickSort();
    customShellSort();
    return 0;
}
