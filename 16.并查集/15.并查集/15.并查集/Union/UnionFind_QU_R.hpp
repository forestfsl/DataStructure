//
//  UnionFind_QU_R.hpp
//  15.并查集
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef UnionFind_QU_R_hpp
#define UnionFind_QU_R_hpp


/*
 矮的数嫁接到高的数
 基于rank的优化,是因为基于size的优化，可能会存在树不平衡的情况
 3<----2<-----<----1                4
                            ^----^----^----^
                            |    |    |    |
                            5    6    7    8
 union(1,4)
                          4
               ^-----^----^----^----^
               |     |    |    |    |
               3     5    6    7    8
               |
               2
               |
               0
               |
               1
 
 
 经过rank的优化之后
       3
   ^-----^
   |     |
   2     4<------------
   |     |   |    |    |
   0     5   6    7    8
   |
   1
 */
#include <stdio.h>
#include "UnionFind_QU.hpp"

class UnionFind_QU_R:public UnionFind_QU{
public:
    int *ranks;
    UnionFind_QU_R(int capacity):UnionFind_QU(capacity){
        ranks = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            ranks[i] = 1;
        }
    }
    
    void unionElement(int v1,int v2){
        int p1 = find(v1);
        int p2 = find(v2);
        if (p1 == p2) return;
        
        if (ranks[p1] < ranks[p2]) {
            parents[p1] = p2;
        }else if (ranks[p1] > ranks[p2]){
            parents[p2] = p1;
        }else{
            parents[p1] = p2;
            ranks[p2] += 1;
        }
    }
};


#endif /* UnionFind_QU_R_hpp */
