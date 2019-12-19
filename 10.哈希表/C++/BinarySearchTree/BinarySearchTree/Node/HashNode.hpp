//
//  HashNode.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/18.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <stdio.h>

template <class K,class V>

class HashNode{
public:
    int hash ;
    K key;
    V value;
    bool color = kRED;
    HashNode<K,V> *left;
    HashNode<K,V> *right;
    HashNode<K,V> *parent;
    HashNode(K key,V value,HashNode<K,V>*parent){
        this->key = key;
        this->value = value;
        this->parnet = parent;
        this->hash = HashNodeHash(key);
        
    }
    
    bool hasTwoChildren(){
        return left != nullptr && right != nullptr;
    }
    
    bool isLeftChild(){
        return parent != nullptr && this == parent->left;
    }
    
    bool isRightChild(){
        return parent != nullptr && this == parent->right;
    }
    
    HashNode<K,V> sibling(){
        if (isLeftChild()) {
            return parent->right;
        }
        if (isRightChild()) {
            return parent->left;
        }
        return nullptr;
    }
    
    int HashNodeHash(K key){
           int hashCode = (K)::hash<K>();
           
           return hashCode ^ (hashCode >> 16);
       }
};

#endif /* HashNode_hpp */
