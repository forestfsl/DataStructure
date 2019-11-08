//
//  Queue.hpp
//  Deque
//
//  Created by songlin on 2019/11/8.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "LinkedList2.hpp"
#include <iostream>
using namespace std;


//双端队列

template <class E>
class Queue{
private:
    LinkedList2<E> *list = new LinkedList2<E>();
    
public:
    //元素的数量
    int size(){
        return list->size();
    }
    //是否为空
    bool isEmpty(){
        return list->isEmpty();
    }
    //清空
    void clear(){
        list->clear();
    }
    //从队尾入队
    void enQueue(E element){
        list->add(element);
    }
    //从队头出队
    E deQueue(){
        return list->remove(0);
    }

    //获取队头元素
    E front(){
        return list->get(0);
    }
   
};


#endif /* Queue_hpp */
