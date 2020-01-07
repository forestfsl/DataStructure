//
//  UnionFind_QU.hpp
//  15.并查集
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 FLP. All rights reserved.
//


/*
 
 0 1 2 3 4
 0 1 2 3 4      0 1 2 3 4
 
 Quick Union的union(v1,v2)：让v1的根节点指向v2的根节点
 union(1,0)
 0 1 2 3 4        0     2   3   4
                  ^
                  |
 0 0 2 3 4        1
 
 union(1,2)
 0 1 2 3 4
 2 0 2 3 4       3      4       2<----0<----1
 
 union(3,4)
 0 1 2 3 4
 2 0 2 4 4      4<-----3    2<------0<-----1
 
 
 union(3,1)
 0 1 2 3 4
                    2
                 /    \
                4      0
               /        \
              3          1
 2 0 2 4 2
 */

#ifndef UnionFind_QU_hpp
#define UnionFind_QU_hpp

#include <stdio.h>
#include "UnionFind.hpp"

class UnionFind_QU:public UnionFind{
public:
    UnionFind_QU(int capacity):UnionFind(capacity){
        
    }
    
    /*
     通过parent链条不断向上找，知道找到根节点
     */
     int find(int v){
            this->rangeCheck(v);
    //        cout << parents[v] << endl;
         while (v != parents[v]) {
             v = parents[v];
         }
            return v;
        }
    
    
    /*
     将v1的根节点嫁接到v2的根节点
     */
    void unionElement(int v1,int v2){
        int p1 = find(v1);
        int p2 = find(v2);
        if (p1 == p2) return;
        parents[p1] = p2;
    }
};

#endif /* UnionFind_QU_hpp */
