//
//  UnionFind_QU_R_PC.hpp
//  15.并查集
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef UnionFind_QU_R_PC_hpp
#define UnionFind_QU_R_PC_hpp


/*
 虽然有了基于rank的优化，树会相对平衡点
 但是随着union的次数增多，树的高度依然会越来越高，导致find变慢，尤其是底层节点，所以我们可以采取路径压缩
 路径压缩的概念：使find时候路径上的所有节点指向根节点，从而降低数的高度
 
     3                      4
 ^-----^                 ^------^
 |     |                 |      |
 2     0                 5      6
 |                       |
 1                       7
 
 union(1,5)
 
        4
     /  |  \
    3   5   6
   / \  |
  2   0 7
 /
 1
 
 
            4
 ^----^----^----^----^---->----
 |    |    |    |    |    |   |
 0    1    2    3     5   6   7
 
 
 */

#include <stdio.h>
#include "UnionFind_QU.hpp"

class UnionFind_QU_R_PC:public UnionFind_QU{
public:
    UnionFind_QU_R_PC(int capacity):UnionFind_QU(capacity){
        
    }
    
    int find(int v){//v == 1 parents[v] == 2
        this->rangeCheck(v);
        if (parents[v]  != v) {
            parents[v] = find(parents[v]);
        }
        return parents[v];
    }
};

#endif /* UnionFind_QU_R_PC_hpp */
