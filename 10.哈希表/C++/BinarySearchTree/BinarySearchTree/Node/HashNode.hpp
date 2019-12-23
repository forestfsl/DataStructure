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
    K  key;
    V value;
    bool color = RED;
    HashNode<K,V> *left;
    HashNode<K,V> *right;
    HashNode<K,V> *parent;
    HashNode<K,V>(K key,V value,HashNode<K,V>*parent):key(0){
        this->key = key;
        this->value = value;
        this->parent = parent;
        this->hash = HashNodeHash(key);
        this->left = nullptr;
        this->right = nullptr;
        
    }
    HashNode<K,V> (K key,V value){
        this->key = key;
        this->value = value;
        this->parent = nullptr;
        this->hash = HashNodeHash(key);
        this->left = nullptr;
        this->right = nullptr;
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
    
    HashNode<K,V>* sibling(){
        if (isLeftChild()) {
            return parent->right;
        }
        if (isRightChild()) {
            return parent->left;
        }
        return nullptr;
    }
    
    int HashNodeHash(K key){
           int hashCode = Key::hashName(key);
           
           return hashCode ^ (hashCode >> 16);
       }
};

#endif /* HashNode_hpp */
