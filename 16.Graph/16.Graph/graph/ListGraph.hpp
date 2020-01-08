//
//  ListGraph.hpp
//  16.Graph
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef ListGraph_hpp
#define ListGraph_hpp

#include <stdio.h>
#include "Graph.hpp"
#include "Vertex.hpp"
#include <set>
#include <unordered_map>

template <class V,class E>
class ListGraph:public Graph<V,E> {
    
public:
     unordered_map<V, Vertex<V, E>*> vertices =  unordered_map<V, Vertex<V, E>*>();
    unordered_map<V,Edge<V, E>*> edges =  unordered_map<V,Edge<V, E>*>();
    
    ListGraph(){
        
    }
    
    void print(){
        cout << "顶点---------------------------" << endl;
        for(const auto& vertex : vertices){
            cout << vertex.first << endl;
            cout << "out-------------------" << endl;
            cout << vertex.second.outEdges << endl;
            cout << "in--------------------" << endl;
            cout << vertex.second.inEdges << endl;
        }
        
        cout << "边-----------------------------" << endl;
        for(const auto& edge: edges){
             cout << edge << endl;
        }
    }
    
    //边的数量
     int edgesSize(){
         return (int)edges.size();
     };
    //顶点的数量
     int verticesSize(){
         return (int)vertices.size();
     };
    //添加顶点
    void addVertex(V v){
        if (vertices.find(v) != vertices.end()) return;
        Vertex<V, E> *vertex =  new Vertex<V, E>(v);
        vertices.insert(pair<V,Vertex<V, E>*>(v,vertex));
    }
    //添加边
    void addEdge(V from,V to){
        addEdge(from, to,0);
    }
    void addEdge(V from,V to,E weight){
        Vertex<V, E> *fromVertex = vertices[from];
        if (fromVertex == nullptr) {
            fromVertex = new Vertex<V, E>(from);
            vertices.insert(pair<V, Vertex<V, E>*>(from,fromVertex));
        }
        
        Vertex<V, E> *toVertex = vertices[to];
        if (toVertex == nullptr) {
            toVertex =  new Vertex<V, E>(to);
            vertices.insert(pair<V, Vertex<V, E>*>(to,toVertex));
        }
        
        Edge<V, E> *edge = new Edge<V, E>(fromVertex,toVertex);
        edge->weight = weight;
     
        for(typename unordered_map<V, Edge<V, E>*>::iterator iter = fromVertex->outEdges.begin(); iter != fromVertex->outEdges.end(); iter++)
                         {
                            if (iter->second == edge) {
                                                fromVertex->outEdges.erase(iter);
                                            }
                            
              }
        
       
        
        for(typename unordered_map<V,Edge<V, E>*>::iterator iter = toVertex->inEdges.begin(); iter != toVertex->outEdges.end(); iter++)
             {
                 if (iter->second == edge) {
                     toVertex->inEdges.erase(iter);
                 }
        }
        
        for(typename unordered_map<V,Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++)
                    {
                        if (iter->second == edge) {
                            edges.erase(iter);
                        }
               }
        
        fromVertex->outEdges.insert(pair<V, Edge<V, E>*>("test",edge));
        toVertex->inEdges.insert(pair<V, Edge<V, E>*>("test",edge));
        edges.insert(pair<V, Edge<V, E>*>("test",edge));
        
    }
    //移除顶点
    void removeVertex(V v){
        Vertex<V, E> *fromVertex = vertices[v];
        for(typename unordered_map<V, Vertex<V, E>*>::iterator iter = vertices.begin(); iter != vertices.end(); iter++)
                   {
                       if (iter->second == fromVertex) {
                           vertices.erase(iter);
                       }
        }
        
        Vertex<V, E> *vertex = vertices[v];
        if (vertex == nullptr) return;
        
        for(typename unordered_map<V,Edge<V, E>*>::iterator iter = vertex->outEdges.begin(); iter != vertex->outEdges.end(); iter++)
                           {
                               Edge<V, E> *edge = iter->second;
                            edges.erase(iter);
                            edge->toVertex->inEdges.erase(iter);
                               
                      }
        
        for(typename unordered_map<V,Edge<V, E>*>::iterator iter = vertex->inEdges.begin(); iter != vertex->inEdges.end(); iter++)
                                  {
                                     Edge<V, E> *edge = iter->second;
                                    edges.erase(iter);
                                   edge->fromVertex->outEdges.erase(iter);
                                      
                             }
              
    }
    //移除边
    void removeEdge(V from,V to){
        Vertex<V, E> *fromVertex = vertices[from];
        if (fromVertex == nullptr) return;
        
        Vertex<V, E> *toVertex = vertices[to];
        if (toVertex == nullptr) return;
        
        Edge<V, E> *edge =new Edge<V,E>(fromVertex,toVertex);
        
        for(typename unordered_map<V,Edge<V, E>*>::iterator iter = fromVertex->outEdges.begin(); iter != fromVertex->outEdges.end(); iter++)
                    {
                        if (iter->second == edge) {
                            fromVertex->outEdges.erase(iter);
                        }
                       
               }
               
               for(typename unordered_map<V,Edge<V, E>*>::iterator iter = toVertex->inEdges.begin(); iter != toVertex->outEdges.end(); iter++)
                    {
                        if (iter->second == edge) {
                            toVertex->inEdges.erase(iter);
                        }
               }
               
               for(typename unordered_map<V,Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++)
                           {
                               if (iter->second == edge) {
                                   edges.erase(iter);
                               }
                      }
    }
    
};

#endif /* ListGraph_hpp */
