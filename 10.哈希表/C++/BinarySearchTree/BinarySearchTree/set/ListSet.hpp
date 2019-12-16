//
//  ListSet.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef ListSet_hpp
#define ListSet_hpp


#include <stdio.h>
//#include "FSet.hpp"

#include "LinkedList2.hpp"

template <class E>
class ListSet {
public:
    typedef bool(*Visitor)(int);
    LinkedList2<E> *list = new LinkedList2<E>();
    
    int size(){
        return list->getSize();
    }
    bool isEmpty(){
        return list->isEmpty();
    }
    void clear(){
        list->clear();
    }
    bool contains(E element){
        return list->contains(element);
    }
    void add(E element){
        int index = list->indexOf(element);
        if (index != ELEMENT_NOT_FOUND2) {
            list->set(index, element);
        }else{
            //不存在就添加
            list->add(element);
        }
    }
    void remove(E element){
        int index = list->indexOf(element);
        if (index != ELEMENT_NOT_FOUND2) {
            list->remove(index);
        }
    }
    void traversal(Visitor visitor){
        if (visitor == nullptr) return;
        int size = list->getSize();
        for (int i = 0; i < size; i++) {
            visitor(list->get(i));
        }
    }
};

#endif /* ListSet_hpp */
