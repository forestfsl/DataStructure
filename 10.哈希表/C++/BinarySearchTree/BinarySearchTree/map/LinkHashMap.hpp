//
//  LinkHashMap.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef LinkHashMap_hpp
#define LinkHashMap_hpp

#include <stdio.h>

#include "LinkedNode.hpp"

template <class K,class V>
class LinkHashMap{
public:
    LinkedNode<K, V> *first;
    LinkedNode<K, V> *last;
    MapNode<K, V> * createNode(K key,V value,MapNode<K, V> *parent){
        LinkedNode<K,V> *node = new LinkedNode<K,V>(key,value,parent);
    }
    void clear(){
        
    }
};

#endif /* LinkHashMap_hpp */
