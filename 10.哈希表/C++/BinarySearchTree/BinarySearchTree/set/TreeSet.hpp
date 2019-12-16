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
public:
    typedef  bool(*VisitorSet)(E);
    TreeMap<E, E> *map;
    typedef int(*CompareElement)(int,int);
       
       //函数指针
    CompareElement compareBlock;

    static VisitorSet visitorSet;
    TreeSet<E>(){
        map  = new TreeMap<E, E>();
    }
    
    TreeSet<E>(CompareElement compareBlock){
         map  = new TreeMap<E, E>(compareBlock);
    }
    
   
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
        map->put(element,element);
    }
    
    void remove(E element){
        map->remove(element);
    }
    
    bool static block(E key,E value){
        cout << "key=" << key << "----" <<"value=" << value << endl;
        return false;
    }
    
    void  traversal() {

        map->traversal1([] (E key,E value)  -> bool{
      
            return block(key,value);
            
            
        });
    }
    
};

#endif /* TreeSet_hpp */
