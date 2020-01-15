//
//  UnionFind.hpp
//  16.Graph
//
//  Created by fengsl on 2020/1/15.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <stdio.h>
#include "UnionNode.hpp"
#include <unordered_map>
//Vertex<V, E>*
template <class V>
class UnionFind{
public:
//    unordered_map<V, Vertex<V, E>*> vertices =  unordered_map<V, Vertex<V, E>*>();
     unordered_map<V,UnionNode<V>*> nodes =  unordered_map<V,UnionNode<V>*>();
    void makeSet(V v){
        if (nodes.find(v) != nodes.end()) return;
        nodes.insert(pair<V, UnionNode<V>*>(v,new UnionNode<V>(v)));
    }
    
    /*
     找出v的根节点
     */
    UnionNode<V> * findNode(V v){ 
        UnionNode<V> *node = nodes[v];
        
        
        while (node->value != node->parent->value) {
            node->parent = node->parent->parent;
            node = node->parent;
        }
        return node;
    }
    
    V find(V v){
        UnionNode<V> *node = findNode(v);
        return node->value;
    }
    
    void unionElement(V v1,V v2){
        UnionNode<V> *p1 = findNode(v1);
        UnionNode<V> *p2 = findNode(v2);
        if (p1 == nullptr || p2 == nullptr) return;
        if(p1->value == p2->value) return;
        int rankeDelta = p1->rank - p2->rank;
        if (rankeDelta < 0) {
            p1->parent = p2;
        }else if (rankeDelta > 0){
            p2->parent = p1;
        }else{
            p1->parent = p2;
            p2->rank += 1;
        }
    }

    bool isSame(V v1,V v2){
        return find(v1) == find(v2);
    }
};

#endif /* UnionFind_hpp */
