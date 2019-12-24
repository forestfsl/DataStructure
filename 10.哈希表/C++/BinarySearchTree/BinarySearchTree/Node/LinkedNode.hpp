//
//  LinkedNode.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/24.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef LinkedNode_hpp
#define LinkedNode_hpp

#include <stdio.h>
#include "HashNode.hpp"

template <class K,class V>
class LinkedNode: public HashNode<K,V> {
public:
    LinkedNode<K,V> *prev;
    LinkedNode<K,V> *next;
    LinkedNode<K,V>(K key,V value ,HashNode<K, V>*parent):HashNode<K,V>(key,value,parent){
        this->prev = nullptr;
        this->next = nullptr;
    }
};

#endif /* LinkedNode_hpp */
