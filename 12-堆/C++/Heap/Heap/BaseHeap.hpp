//
//  BaseHeap.hpp
//  Heap
//
//  Created by songlin on 2019/12/26.
//  Copyright © 2019 toucu. All rights reserved.
//

#ifndef BaseHeap_hpp
#define BaseHeap_hpp

#include <stdio.h>


template<class E>
class BaseHeap{
public:
    int m_size;
   virtual int size();//元素的数量
   virtual bool isEmpaty();//是否为空
   virtual void clear();//清空
   virtual void add(E element);//添加元素
   virtual E get();//获得堆顶元素
   virtual E remove();//删除堆顶元素
   virtual E replace(E element);//删除堆顶元素的同时插入一个新元素
    virtual bool isEmpty();
    
};

#endif /* BaseHeap_hpp */
