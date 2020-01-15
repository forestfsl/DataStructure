//
//  EdgeInfo.hpp
//  16.Graph
//
//  Created by fengsl on 2020/1/14.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef EdgeInfo_hpp
#define EdgeInfo_hpp

#include <stdio.h>

template <class V,class E>
class EdgeInfo {
    
public:
    V from;
    V to;
    E weight;
    EdgeInfo(V from,V to,E weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    
    V getFrom(){
        return from;
    }
    
    void setFrom(V from){
        this->from = from;
    }
    V getTo(){
        return  to;
    }
    void setTo(V to){
        this->to = to;
    }
    E getWeight(){
        return weight;
    }
    void setWeight(E weight){
        this->weight = weight;
    }
};

#endif /* EdgeInfo_hpp */
