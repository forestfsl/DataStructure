//
//  CircleQueue.hpp
//  Deque
//
//  Created by fengsl on 2019/11/9.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef CircleQueue_hpp
#define CircleQueue_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sys/malloc.h>

using namespace std;

template<class E>
class CircleQueue{
private:
    int front;
    int m_size;
    static const int DEFAULT_CAPACITY = 10;
    int maxSize;
public:

    E *elements = new E[DEFAULT_CAPACITY]{  };
    CircleQueue(){
        front = 0;
        m_size = 0;
        maxSize = DEFAULT_CAPACITY;
    }
    bool isEmpty(){
        return m_size == 0;
    }
    void clear(){
        for (int i = 0; i < m_size; i++) {
            elements[realindex(i)] = NULL;
        }
        front = 0;
        m_size = 0;
    }
    int size(){
        return m_size;
    }
    void enQueue(E element){
        ensureCapacity(m_size + 1);
        cout << "打印入栈元素" << element << endl;
        elements[realindex(m_size)] = element;
        m_size++;
    }
    
    E frontElement(){
        return elements[front];
    }
    
    E deQueue(){
        E frontElement = elements[front];
        elements[front] = NULL;
        front = realindex(1);
        m_size--;
        return frontElement;
    }
    
    
    /**
     * 在这个例子当中，我们采取front等于最大值，然后再加上最大值的
     * m_size 也是不会超过2m，所以可以采取下面的公式
     假设长度是7，那么front最大值就是6，那么m_size最大
     也只是能够去到6而已，6 + 6 等于12 < 2*7
     * 条件 n > m && n < 2m ,n m > 0
     * int n = 13;
     * int m = 10
     if n > m
     n % m ----> n - m
     */
    int realindex(int index){
        //return (front + index) % elements length
        index += front;
       
        int realIndex =  index - (index >= maxSize ? maxSize : 0);
        cout << "打印真实索引" << realIndex << endl;
        return realIndex;
    }
    void ensureCapacity(int capacity){
        int oldCapacity = maxSize;
        if (oldCapacity >= capacity) return;
        //新容量为旧容量的1.5倍
        int newCapacity = oldCapacity + (oldCapacity >> 1);
        maxSize = newCapacity;
        E *newElements = new E[newCapacity]{};
        for (int i = 0; i < m_size; i++) {
            int index = realindex(i);
            newElements[i] = elements[index];
        }
        elements = newElements;
        //重置front
        front = 0;
    }
    
    void toString(){
        cout << endl;
        cout << "capacity=" << maxSize << endl;
        cout << "m_size=" << m_size << endl;
        cout << "front=" << front << endl;
        cout << "[" ;
        for (int i = 0; i < maxSize; i++) {
            if (i != 0) {
                cout << "," << endl;
            }
            cout << elements[i];
        }
        cout << "]" << endl;

    }
    
};

#endif /* CircleQueue_hpp */
