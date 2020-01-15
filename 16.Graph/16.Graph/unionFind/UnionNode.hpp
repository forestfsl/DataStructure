//
//  Node.hpp
//  16.Graph
//
//  Created by fengsl on 2020/1/15.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef UnionNode_hpp
#define UnionNode_hpp

#include <stdio.h>

template <class V>
class UnionNode{
public:
    V value;
    UnionNode<V> *parent = this ;
    int rank = 1;
    UnionNode(V value){
        this->value = value;
    }
};

#endif /* Node_hpp */
