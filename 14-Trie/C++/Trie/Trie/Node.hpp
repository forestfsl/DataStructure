//
//  Node.hpp
//  Trie
//
//  Created by songlin on 2019/12/26.
//  Copyright © 2019 toucu. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <unordered_map>
using namespace std;

template <class V>
class Node{
public:
    Node<V>* parent;
    unordered_map<char, Node<V>*> children;
    char character;
    V value;
    bool word;//是否为单词的结尾，是否为一个完整的单词
    Node<V>(Node<V> *parent){
        this->parent = parent;
    }
    
   };

#endif /* Node_hpp */
