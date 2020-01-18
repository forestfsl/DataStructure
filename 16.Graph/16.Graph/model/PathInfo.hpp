//
//  PathInfo.hpp
//  16.Graph
//
//  Created by fengsl on 2020/1/18.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef PathInfo_hpp
#define PathInfo_hpp

#include <stdio.h>
#include <set>

using namespace std;

template <class V,class E>
class EdgeInfo;

template <class V,class E>
class PathInfo{
public:
    E weight;
    set<EdgeInfo<V, E>*> *edgeInfos;
    PathInfo<V,E>(E weight){
        this->weight = weight;
        edgeInfos = new set<EdgeInfo<V, E>*>();
    }
    PathInfo(){
        edgeInfos = new set<EdgeInfo<V, E>*>();
    }
    E getWeight(){
        return weight;
    }
    void setWeight(E weight){
        this->weight = weight;
    }
   set<EdgeInfo<V, E>*> * getEdgeInfos(){
        return edgeInfos;
    }
    void setEdgeInfos(set<EdgeInfo<V, E *>>*edgeInfos){
        this->edgeInfos = edgeInfos;
    }
};
#endif /* PathInfo_hpp */
