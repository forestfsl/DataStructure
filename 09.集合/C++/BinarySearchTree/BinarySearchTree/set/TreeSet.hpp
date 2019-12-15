//
//  TreeSet.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef TreeSet_hpp
#define TreeSet_hpp

#include <stdio.h>
#include "TreeMap.hpp"

template <class E>
class TreeSet {
    typedef bool(*VisitorSet)(E);
    E keyStr;
    E valueStr;
    TreeMap<E, E> *map = new TreeMap<E, E>();
    int size(){
        return map->size;
    }
    
    bool isEmpty(){
        return map->isEmpty();
    }
    void clear(){
        map->clear();
    }
    
    bool contains(E element){
        return map->containsKey(element);
    }
    
    void add(E element){
        map->put(element,nullptr);
    }
    
    void remove(E element){
        map->remove(element);
    }
    
    bool block(VisitorSet visitor,E key){
        visitor(key);
    }
    
    void  traversal(VisitorSet visitor) {
        map->traversal1([] (E key,E value)  -> bool{
//            visitor(key);
        });
    }
};

#endif /* TreeSet_hpp */
