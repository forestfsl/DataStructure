#include <stdio.h>
#include "Edge.hpp"
#include <set>
#include <unordered_map>
using namespace std;

template <class V,class E>
class Vertex{
public:
    V value;
    unordered_map<V,Edge<V, E>*> inEdges =  unordered_map<V,Edge<V, E>*>();
    unordered_map<V,Edge<V, E>*> outEdges =  unordered_map<V,Edge<V, E>*>();

    Vertex<V,E>(V value){
        this->value = value;
    }

    int hashCode(int value);
    
    void funcA();

};
