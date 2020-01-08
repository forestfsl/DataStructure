//
//  Edge.hpp
//  16.Graph
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>



template <class V,class E>
class Vertex;

template <class V,class E>

class Edge{
public:
    
    Vertex<V,E> *fromVertex;
    Vertex<V,E> *toVertex;
    E weight;
    Edge(Vertex<V,E>* from,Vertex <V,E>* to){
        this->fromVertex = from;
        this->toVertex = to;
    }
    
     int hashCode(int value);
};

#endif /* Edge_hpp */
