
#ifndef LinkedNode_hpp
#define LinkedNode_hpp

#include <stdio.h>
#include "MapNode.hpp"

template <class K,class V>

class LinkedNode:public MapNode<K,V> {
public:
    LinkedNode *prev;
    LinkedNode *next;
    LinkedNode<K,V>(K key,V value, MapNode<K,V> *parent):MapNode<K,V>(key,value,parent){
        this->prev = nullptr;
        this->next = nullptr;
    }
};


#endif /* LinkedNode_hpp */
