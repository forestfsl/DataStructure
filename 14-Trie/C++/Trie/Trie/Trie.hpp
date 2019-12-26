//
//  Trie.hpp
//  Trie
//
//  Created by songlin on 2019/12/26.
//  Copyright © 2019 toucu. All rights reserved.
//

#ifndef Trie_hpp
#define Trie_hpp

#include <stdio.h>
#include "Node.hpp"
#include <unordered_map>

template <class V>
class Trie{
public:
    static const int DEFAULTNUMBER = 99999;
    int size;
    //如果Node中为空的时候可以赋值这个
     unordered_map<char, Node<V>*> children1;
    Node<V>* root;
    
    int fetchSize(){
        return size;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    void clear(){
        size == 0;
        root = nullptr;
    }
    
    V get(string key){
        Node<V> *keyNode = node(key);
        return keyNode != nullptr && keyNode->word ? keyNode->value : DEFAULTNUMBER;
    }
    
    bool contains(string key){
        Node<V> *keyNode = node(key);
        return keyNode != nullptr && keyNode->word;
    }
    
    V add(string key,V value){
        KeyCheck(key);
        //创建根节点
        if (root == nullptr) {
            root = new Node<V>(0);
        }
        Node<V> *node = root;
        int len = (int)key.size();
        for (int i = 0; i < len; i++) {
            char c = key[i];
            bool emptyChildren = node->children.empty();
          
           
            Node<V> *childNode = emptyChildren ? nullptr :(Node<V>*)node->children[c];
            
            if (childNode == nullptr) {
                childNode = new Node<V>(node);
                childNode->character = c;
                node->children = emptyChildren ? children1 : node->children;
               
                node->children.insert(pair<char, Node<V>*>(c,childNode));
            }
            node = childNode;
        }
        if (node->word) {//已经存在这个单词
            V oldValue = node->value;
            node->value = value;
            return oldValue;
        }
        //新增一个单词
        node->word = true;
        node->value = value;
        size++;
        return 99999;
    }
    
    V remove(string key){
        //找到最后一个节点
        Node<V> *keyNode = node(key);
        //如果不是单词结尾，不用做任何处理
        if (keyNode == nullptr || !keyNode->word) return 99999;
        size--;
        V oldValue = keyNode->value;
        //如果还有子节点
        if (!keyNode->children.empty()) {
            keyNode->word = false;
            keyNode->value = 99999;
            return oldValue;
        }
        
        //如果没有子节点
        Node<V> *parent = nullptr;
        while ((parent = keyNode->parent) != nullptr) {
            parent->children.erase(keyNode->character);
            if (parent->word || !parent->children.empty()) break;
        }
        return oldValue;
    }
    
    bool startsWith(string prefix){
        return node(prefix) != nullptr;
   
    }
   
    Node<V> *node(string key){
        KeyCheck(key);
        Node<V> *node = root;
        int len = (int)key.size();
        for (int i = 0; i < len; i++) {
            if (node == nullptr || node->children.empty()) return nullptr;
            char c = key[i];
            node = node->children[c];
        }
        return node;
    }
    
    void KeyCheck(string key){
        if (key == "nullptr" || key.size() == 0) {
            throw "key must not be nullptr";
        }
    }
    
};
#endif /* Trie_hpp */
