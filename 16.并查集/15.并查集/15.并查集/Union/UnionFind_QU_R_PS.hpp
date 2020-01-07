//
//  UnionFind_QU_R_PS.hpp
//  15.并查集
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef UnionFind_QU_R_PS_hpp
#define UnionFind_QU_R_PS_hpp


/*
 Quick Union - 基于rank的优化 - 路径分裂(Path Spliting)
 路径分裂：使路径上的每个节点都指向其祖父节点(parent的parent）
 7<----6<----5<----4<----3<----2<----1
 
          7
     ^--------^
     |        |
     6        5
     |        |
     4        3
     |        |
     2        1

 */

#include <stdio.h>
#include "UnionFind_QU.hpp"


class UnionFind_QU_R_PS:public UnionFind_QU{
public:
    UnionFind_QU_R_PS(int capacity):UnionFind_QU(capacity){
        
    }
    
    int find(int v){
        this->rangeCheck(v);
        while (v != parents[v]) {
            int p = parents[v];
            parents[v] = parents[parents[v]];
            v = p;
        }
        return v;
    }
};

#endif /* UnionFind_QU_R_PS_hpp */
