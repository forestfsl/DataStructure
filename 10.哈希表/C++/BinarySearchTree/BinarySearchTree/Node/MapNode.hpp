//
//  MapNode.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef MapNode_hpp
#define MapNode_hpp

#include <stdio.h>


 static const bool kRED = false;
static const bool KBlack = true;
// static const bool kBLACK = true;
//
//size_t hashCode =(int)hash<int>()(p.age);
//       hashCode = hashCode * 31 + (int)hash<int>()(p.height);
//       hashCode = hashCode * 31 +  (int)hash<string>()(p.name);
//       return hashCode;
template <class K,class V>
class MapNode{
public:
    int hash;
    K key;
    V value;
    bool color = kRED;
    MapNode *left;
    MapNode *right;
    MapNode *parent;
    MapNode(K key,V value,MapNode<K,V> *parent){
        this->key = key;
        this->hash = MapNodeHash(key);
        this->value = value;
        this->parent = parent;
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
    
    MapNode * sibling(){
        if (isLeftChild()) {
            return  parent->right;
        }
        if (isRightChild()) {
            return parent->left;
        }
        return nullptr;
    }
    
    int MapNodeHash(K key){
        int hashCode = (K)::hash<K>();
        
        return hashCode ^ (hashCode >> 16);
    }
};

#endif /* MapNode_hpp */
