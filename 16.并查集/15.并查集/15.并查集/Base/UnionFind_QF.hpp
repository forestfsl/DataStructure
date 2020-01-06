//
//  UnionFind_QF.hpp
//  15.并查集
//
//  Created by fengsl on 2020/1/6.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef UnionFind_QF_hpp
#define UnionFind_QF_hpp

#include <stdio.h>
#include "UnionFind.hpp"

class UnionFind_QF:public UnionFind{
public:
    UnionFind_QF(int capacity):UnionFind(capacity){
        
    }
    
    //父节点就是根节点
    int find(int v){
        this->rangeCheck(v);
//        cout << parents[v] << endl;
        return parents[v];
    }
    
    //将v1所在集合的所有元素，都嫁接到v2的父节点上
    void unionElement(int v1,int v2){
        int p1 = find(v1);
        int p2 = find(v2);
        if (p1 == p2) return;
        
        for (int i = 0; i < this->len; i++) {
            if (parents[i] == p1) {
                parents[i] = p2;
            }
        }
    }
};

#endif /* UnionFind_QF_hpp */
