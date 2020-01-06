//
//  UnionFind.hpp
//  15.并查集
//
//  Created by fengsl on 2020/1/6.
//  Copyright © 2020 FLP. All rights reserved.
//

#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <stdio.h>

class UnionFind{
public:
    int *parents;//父类整型数组
    int len;
    UnionFind(int capacity){
        if (capacity < 0) {
            throw "capacity must be >= 0";
        }
        parents = new int[capacity];
        len = capacity;
        //初始化时候让每个元素属于一个单元素集合
        for (int i = 0; i < capacity; i++) {
            parents[i] = i;
        }
    }
    
    /*
     查找v所属的集合(根节点)
     */
    virtual int find(int v){
        return -1;
    }
    
    /*
     合并v1,v2所在的集合
     */
    virtual void unionElement(int v1,int v2){
        
    }
    
    /*
     查找v1,v2是否属于同一个集合
     */
    bool isSame(int v1, int v2){
        return find(v1) == find(v2);
    }
    
    void rangeCheck(int v){
        if (v < 0 ||  v >= len){
            throw "v is out of bounds";
        }
    }
};

#endif /* UnionFind_hpp */
