#include <stdio.h>
#include "Edge.hpp"
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

template <class V,class E>
class Vertex{
public:
    V value;
    set<Edge<V, E>*> inEdges =  set<Edge<V, E>*>();
    set<Edge<V, E>*> outEdges =  set<Edge<V, E>*>();

    Vertex<V,E>(V value){
        this->value = value;
    }

    int hashCode(int value);
    
    void funcA();
    bool operator==(const Vertex& s) const
    {
        return s.value = value;
    }

    

};
