//
//  UnionFind_QU_R_PH.hpp
//  15.并查集
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef UnionFind_QU_R_PH_hpp
#define UnionFind_QU_R_PH_hpp


/*
 Quick Union - 基于rank的优化 - 路径减半(Path Halving)
 
 路径分裂：使路径上的每个节点都指向其祖父节点(parent的parent）
 7<----6<----5<----4<----3<----2<----1
 
          7
     ^-----------^
     |           |
     6      ^----5----^
            |         |
            4         3
                  ^--------^
                  |        |
                  2        1

*/

#include <stdio.h>
#include "UnionFind_QU.hpp"

class UnionFind_QU_R_PH:public UnionFind_QU{
public:
    UnionFind_QU_R_PH(int capacity):UnionFind_QU(capacity){
        
    }
    
    int find(int v){
        this->rangeCheck(v);
        while (v != parents[v]) {
            parents[v] = parents[parents[v]];
            v = parents[v];
        }
        return v;
    }
};

#endif /* UnionFind_QU_R_PH_hpp */
