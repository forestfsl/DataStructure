//
//  UnionFind_QU_S.hpp
//  15.并查集
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 FLP. All rights reserved.
//


/*
 UnionFind_QU 的union过程中，可能会出现数不平衡的情况，甚至可能退化成链表
 2<----0<----1
 3                union(1,3)-------->     3<----2<----2<----0<----1
 
 有两种常见的优化方案：
 第一种是基于size的优化(元素少的数嫁接到元素多的数)，
 2<----0<----1
 3                union(1,3)-------->           2
                                             /     \
                                            0       3
                                         /
                                        1
第二种是基于rank的优化(矮的数嫁接到高的数)
 */

#ifndef UnionFind_QU_S_hpp
#define UnionFind_QU_S_hpp
#include "UnionFind_QU.hpp"

#include <stdio.h>

class UnionFind_QU_S:public UnionFind_QU{
public:
    int *sizes;
    UnionFind_QU_S(int capacity):UnionFind_QU(capacity){
        sizes = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            sizes[i] = 1;
        }
    }
    
    /*
     将v1的根节点嫁接到v2的根节点上
     */
    void unionElement(int v1,int v2){
           int p1 = find(v1);
           int p2 = find(v2);
           if (p1 == p2) return;
        if (sizes[p1] < sizes[p2]) {
            parents[p1] = p2;
            sizes[p2] += sizes[p1];
        }else{
            parents[p2] = p1;
            sizes[p1] += sizes[p2];
        }
       }
    
};

#endif /* UnionFind_QU_S_hpp */
