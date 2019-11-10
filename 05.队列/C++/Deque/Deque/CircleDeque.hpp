//
//  CircleDeque.hpp
//  Deque
//
//  Created by fengsl on 2019/11/10.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef CircleDeque_hpp
#define CircleDeque_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sys/malloc.h>

using namespace std;

template <class E>
class CircleDeque {
private:
    int front;
    int m_size;
    static const int DEFAULT_CAPACITY = 10;
     E *elements = new E[DEFAULT_CAPACITY]{  };
    int maxSize;
public:
    CircleDeque(){
        front = 0;
        m_size = 0;
        maxSize = DEFAULT_CAPACITY;
    }
    int size(){
        return m_size;
    }
    bool isEmpty(){
        return m_size == 0;
    }
    void clear(){
        for (int i = 0; i < m_size; i++) {
            elements[realIndex(i)] = nullptr;
        }
        front = 0;
        m_size = 0;
    }
    /**
     * 从头部出队
     */
    E deQueueFront(){
        E frontElement = elements[front];
        elements[front] = nullptr;
        front = realIndex(1);
        m_size--;
        return frontElement;
    }
    /*
     *从尾部出队
     */
    E deQueueRear(){
        int rearIndex = realIndex(m_size - 1);
        E rear = elements[rearIndex];
        elements[rearIndex] = nullptr;
        m_size--;
        return rear;
    }
    
    /**
     * 从尾部入队
     */
    E enQueueRear(E element){
        ensureCapacity(m_size + 1);
        elements[realIndex(m_size)] = element;
        m_size++;
    }
    
    /**
     * 从头部入队
     */
    void enQueueenQueueFront(E element){
        ensureCapacity(m_size + 1);
        front = realIndex(-1);
        elements[front] = element;
        m_size++;
    }
  
    //获取头部元素
    E frontElement(){
        return elements[front];
    }
    //获取队尾元素
    E rear(){
        return elements[realIndex(m_size - 1)];
    }
    int realIndex(int index){
        index += front;
        if (index < 0) {
            return index + maxSize;
        }
        int realIndex = index - (index > maxSize ? maxSize : 0);
        return realIndex;
    }
    
    void ensureCapacity(int capacity){
        int oldCapacity = maxSize;
        if (oldCapacity >= capacity) return;
        //新容量为旧容量的1.5倍
        int newCapacity = oldCapacity + (oldCapacity >> 1);
       
        E *newElements = new E[maxSize]{};
        for (int i = 0; i < m_size; i++) {
            newElements[i] = elements[realIndex(i)];
        }
         maxSize = newCapacity;
        elements = newElements;
        front = 0;
    }
    void toString(){
        cout << "capacity=" << maxSize << endl;
        cout << "size=" << m_size << endl;
        cout << "front=" << front << endl;
        cout << "[";
        for (int i = 0; i < m_size; i++) {
            if (i != 0) {
                cout << ",";
            }
            cout << elements[i];
        }
    }
};

#endif /* CircleDeque_hpp */
