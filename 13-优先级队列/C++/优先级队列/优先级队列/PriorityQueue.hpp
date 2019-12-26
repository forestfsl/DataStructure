//
//  PriorityQueue.hpp
//  优先级队列
//
//  Created by songlin on 2019/12/26.
//  Copyright © 2019 toucu. All rights reserved.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include <stdio.h>
#include "BinaryHeap.hpp"

template <class E>
class PriorityQueue{
public:
   BinaryHeap<E> heap;
      typedef int(*CompareElement)(E,E);
      CompareElement localCompareBlock;
      
      PriorityQueue(CompareElement compareBlock){
          heap = BinaryHeap<E>(compareBlock);
      }
      
      int size(){
          return heap.fetchSize();
      }
      
      int isEmpty(){
          return heap.isEmpty();
      }
      
      void clear(){
          heap.clear();
      }
      
      void enQueue(E element){
          heap.add(element);
      }
      
      E deQueue(){
          return heap.remove();
      }
      
      E front(){
          return heap.get();
      }
};

#endif /* PriorityQueue_hpp */
