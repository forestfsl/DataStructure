//
//  SkipListNode.hpp
//  25.SkipList
//
//  Created by fengsl on 2020/2/4.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef SkipListNode_hpp
#define SkipListNode_hpp

#include <stdio.h>

template <class K,class V>
class SkipListNode{
public:
    K key;
    V value;
    SkipListNode<K,V> **nexts;
    SkipListNode(K key,V value){
        this->key = key;
        this->value;
    }
    SkipListNode<K,V>(){
        
    }
    SkipListNode(K key,V value,int level){
        this->key = key;
        this->value = value;
//         table = new HashNode<K, V> *[DEFAULT_LOAD_CAPACITY]{};
        nexts = new SkipListNode<K,V>*[10]{};
    }
};

#endif /* SkipListNode_hpp */
