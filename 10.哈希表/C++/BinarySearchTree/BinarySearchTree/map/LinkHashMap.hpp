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
     typedef bool(*Visitor)(K,V);
    LinkedNode<K, V> *first;
    LinkedNode<K, V> *last;

    MapNode<K, V> * createNode(K key,V value,MapNode<K, V> *parent){
        LinkedNode<K,V> *node = new LinkedNode<K,V>(key,value,parent);
        if (first == nullptr) {
            first = last = node;
        }else{

            last->next = node;
            node->prev = last;
            last = node;
        }
      
    }
    void clear(){
        first = nullptr;
        last = nullptr;
    }
    
    bool containsValue(V value){
        LinkedNode<K, V> *node = first;
        while (node != nullptr) {
            if (value == node->value) return true;
            node = node->next;
        }
        return false;
    }
    
    void traversal(Visitor visitor){
        if (visitor == nullptr) return ;
        LinkedNode<K, V> *node = first;
        while (node != nullptr) {
            isFinish = visitor(node->key,node->value);
            if (isFinish) return;
            node = node->next;
        }
    }
    
    void afterRemove(MapNode<K, V> *willNode,MapNode<K, V> *removeNode){
        LinkedNode<K, V> *node1 = (LinkedNode<K, V> *)willNode;
        LinkedNode<K, V> *node2 = (LinkedNode<K, V> *)removeNode;
        
        if (node1 != node2) {
            //交换linkedWillNode和linkedRemoveNode在链表中的位置
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
                node1->next->prev = node2;
            }
            if (node2->next == nullptr) {
                last = node2;
            }else{
                node2->next->prev = node2;
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
    }
    
    
};

#endif /* LinkHashMap_hpp */
