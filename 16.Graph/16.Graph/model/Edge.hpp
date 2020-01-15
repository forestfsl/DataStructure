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
#include <iostream>
#include <string>

using namespace std;



template <class V,class E>
class Vertex;

template <class V,class E>
class EdgeInfo;


template <class V,class E>

class Edge{
public:
    
    Vertex<V,E> *from;
    Vertex<V,E> *to;
    E weight;
    Edge(Vertex<V,E>* from,Vertex <V,E>* to){
        this->from = from;
        this->to = to;
    }
    
     int hashCode(int value);
    
    bool operator==(const Edge& s);
       
//   friend ostream &operator <<(ostream &os,Edge &p1)
//       {
//                 return      os << ;
//       }
    
    EdgeInfo<V, E>* info(){
        return new EdgeInfo<V, E>(from->value,to->value,weight);
    }
};

#endif /* Edge_hpp */
