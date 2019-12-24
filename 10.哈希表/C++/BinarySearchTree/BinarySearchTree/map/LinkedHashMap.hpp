//
//  LinkedHashMap.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/24.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef LinkedHashMap_hpp
#define LinkedHashMap_hpp

#include <stdio.h>
#include "LinkedNode.hpp"
#include "HashMapV0.hpp"

template <class K,class V>
class LinkedHashMap: public HashMapV0<K,V> {
public:
    typedef bool(*Visitor)(K,V);
    LinkedNode<K, V>*first = nullptr;
    LinkedNode<K, V>*last = nullptr;
    
    void clearLinkedHashMap(){
        this->clear();
        first = nullptr;
        last = nullptr;
    }
    
    bool containsLinkedHashMapValue(V value){
        LinkedNode<K, V> *node = first;
        while (node != nullptr) {
            if(value == node->value) return true;
            node = node->next;
        }
        return false;
    }
    
    HashNode<K, V> * createNode(K key,V value,HashNode<K, V> *parent){
        LinkedNode<K, V>*node = new LinkedNode<K, V>(key,value,parent);
        if (first == nullptr) {
            first = last = node;
        }else{
            last->next = node;
            node->prev = last;
            last = node;
        }
        return node;
    }
    
    void traversal(Visitor visitor){
        if(visitor == nullptr) return;
        LinkedNode<K, V> *node = first;
        while (node != nullptr) {
            visitor(node->key,node->value);
            node = node->next;
        }
    }
    
    void afterRemove(HashNode<K, V>*willNode, HashNode<K, V>*removeNode){
        LinkedNode<K, V> *node1 = (LinkedNode<K, V>*)willNode;
        LinkedNode<K, V> *node2 = (LinkedNode<K, V>*)removeNode;
        if (node1 != node2) {
            //交换linkedWillNode 和 linkedRemoved在链表中的位置（交换的原因是因为红黑树修复的过程中只是将值交换，但是linkedHashMap中还没有交换，这样的话，如果不交换遍历的时候顺序会因为这点出现问题）
            //交换prev
            LinkedNode<K, V> *tmp = node1->prev;
            node1->prev = node2->prev;
            node2->prev = tmp;
            if (node1->prev == nullptr) {
                first = node1;
            }else{
                node1->prev->next = node1;
            }
            
            if (node2->prev == nullptr) {
                first = node2;
            }else{
                node2->prev->next = node2;
            }
            
            //交换next
            tmp = node1->next;
            node1->next = node2->next;
            node2->next = tmp;
            if (node1->next == nullptr) {
                last = node1;
            }else{
                node1->next->prev = node1;
            }
            
            if (node2->next == nullptr) {
                last = node2;
            }else{
                node2->next->prev = node2;
            }
        }
        
        LinkedNode<K, V> *prev = node2->prev;
        LinkedNode<K, V> *next = node2->next;
        if (prev == nullptr) {
            first = next;
        }else{
            prev->next = next;
        }
        
        if (next == nullptr) {
            last = prev;
        }else{
            next->prev = prev;
        }
    }
};

#endif /* LinkedHashMap_hpp */
