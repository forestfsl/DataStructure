//
//  Deque.hpp
//  Deque
//
//  Created by songlin on 2019/11/8.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Deque_hpp
#define Deque_hpp

#include <stdio.h>
#include "LinkedList2.hpp"
#include <iostream>
using namespace std;

//双端队列

template <class E>
class Deque{
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
    void enQueueRear(E element){
        list->add(element);
    }
    //从队头出队
    E deQueueFront(){
       return list->remove(0);
    }
    //从队头入队
    void enQueueFront(E element){
        list->add(0, element);
    }
    //从队尾出队
    E deQueueRear(){
        return list->remove(list->size() - 1);
    }
    //获取队头元素
    E front(){
        return list->get(0);
    }
    //获取队列的尾元素
    E rear(){
        return list->get(list->size() - 1);
    }
};

#endif /* Deque_hpp */
