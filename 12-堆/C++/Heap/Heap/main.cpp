//
//  main.cpp
//  Heap
//
//  Created by songlin on 2019/12/26.
//  Copyright © 2019 toucu. All rights reserved.
//

#include <iostream>
#include "BinaryHeap.hpp"
using namespace std;


auto lamb = [] (int a,int b) -> int{
    return  a - b;
};
auto lamb1 = [] (int a,int b) -> int{
    return  b - a;
};


void testMaxHeap(){
    string data [] = {"05","09","11","23","22","31","33","35","01","02","03","04"};
         int len = sizeof(data) / sizeof(string);


         BinaryHeap<string> *heap = new BinaryHeap<string>(lamb);
         
         for (int i = 0; i < len; i++) {
             heap->add(data[i]);
         }
       
       for (int i = 0; i < heap->m_size; i++) {
           cout << heap->elements[i] << endl;
       }
}

void testMinHeap(){
    string data [] = {"05","09","11","23","22","31","33","35","01","02","03","04"};
         int len = sizeof(data) / sizeof(string);


         BinaryHeap<string> *heap = new BinaryHeap<string>(lamb1);
         
         for (int i = 0; i < len; i++) {
             heap->add(data[i]);
         }
       
       for (int i = 0; i < heap->m_size; i++) {
           cout << heap->elements[i] << endl;
       }
}

void testTopK(){
    string data [] = {"05","09","11","23","22","31","33","35","01","02","03","04"};
         int len = sizeof(data) / sizeof(string);


         BinaryHeap<string> *heap = new BinaryHeap<string>(lamb1);
    
    int k = 3;
         
     for (int i = 0; i < len; i++) {
         if (heap->m_size < k) { //前k个数添加到小顶堆
              heap->add(data[i]);//logk
         }else if (data[i] > heap->get()){//如果是第k+1 个数，并且大于堆顶元素
             heap->rplace(data[i]);//logk
             
         }
        
        
     }
     //O(nlogk)
       for (int i = 0; i < heap->m_size; i++) {
           cout << heap->elements[i] << endl;
       }
}

int main(int argc, const char * argv[]) {
  

    return 0;
}
