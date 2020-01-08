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
    set<Edge<V, E>*> edges =  set<Edge<V, E>*>();
    
    ListGraph(){
        
    }
    
    void print(){
        cout << "顶点---------------------------" << endl;
        for(const auto& vertex : vertices){
            cout << vertex.first << endl;
            cout << "out-------------------" << endl;
            for(typename set<Edge<V, E>*>::iterator iter = vertex.second->outEdges.begin(); iter != vertex.second->outEdges.end(); iter++)
            {
                Edge<V, E> *edge = *iter;
                cout <<"Edge [from=" << edge->fromVertex->value << ", to=" << edge->toVertex->value <<", weight="<<edge->weight  << endl;
                }
            cout << "in--------------------" << endl;
            for(typename set<Edge<V, E>*>::iterator iter = vertex.second->inEdges.begin(); iter != vertex.second->inEdges.end(); iter++){
                Edge<V, E> *edge = *iter;
                cout <<"Edge [from=" << edge->fromVertex->value << ", to=" << edge->toVertex->value <<", weight="<<edge->weight  << endl;
            }
        }
        
        cout << "边-----------------------------" << endl;
        for(typename set<Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++){
            Edge<V, E> *edge = *iter;
            cout <<"Edge [from=" << edge->fromVertex->value << ", to=" << edge->toVertex->value <<", weight="<<edge->weight  << endl;
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
        vertices[v] = vertex;
        
    }
    //添加边
    void addEdge(V from,V to){
        addEdge(from, to,0);
    }
    void addEdge(V from,V to,E weight){
        Vertex<V, E>* fromVertex = vertices[from];
        
        
        if (fromVertex == nullptr) {
            fromVertex = new Vertex<V, E>(from);
            vertices[from] = fromVertex;
//            auto pr = vertices.insert(pair<V, Vertex<V, E>*>{from,fromVertex});
//
//            std:: cout << "Element " << (pr.second ? "was" : "was not") << " inserted." << std::endl;
        }
        
        Vertex<V, E> *toVertex = vertices[to];
        if (toVertex == nullptr) {
            toVertex =  new Vertex<V, E>(to);
            vertices[to] = toVertex;
        }
        
        Edge<V, E> *edge = new Edge<V, E>(fromVertex,toVertex);
        edge->weight = weight;
     
        for(typename set<Edge<V, E>*>::iterator iter = fromVertex->outEdges.begin(); iter != fromVertex->outEdges.end(); iter++)
                         {
                             Edge<V, E> *tempEdge = *iter;
                            if (tempEdge->toVertex->value == edge->toVertex->value) {
                                                fromVertex->outEdges.erase(iter);
                                            }
                            
              }
        
       
        
        for(typename set<Edge<V, E>*>::iterator iter = toVertex->inEdges.begin(); iter != toVertex->inEdges.end(); iter++)
             {
                  Edge<V, E> *tempEdge = *iter;
                 if (tempEdge->fromVertex->value == edge->fromVertex->value) {
                     toVertex->inEdges.erase(iter);
                     break;
                 }
        }
        
        for(typename set<Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++)
                    {
                         Edge<V, E> *tempEdge = *iter;
                        if (tempEdge->toVertex->value == edge->toVertex->value && tempEdge->fromVertex->value == edge->fromVertex->value) {
                            edges.erase(iter);
                            break;
                        }
               }
        fromVertex->outEdges.insert(edge);
//        fromVertex->outEdges["test"] = edge;
        toVertex->inEdges.insert(edge);
//        toVertex->inEdges["test"] = edge;
        edges.insert(edge);
//        edges["test"] = edge;
       
        
    }
    //移除顶点
    void removeVertex(V v){
        Vertex<V, E> *fromVertex = vertices[v];
        for(typename unordered_map<V, Vertex<V, E>*>::iterator iter = vertices.begin(); iter != vertices.end(); iter++)
                   {
                       if (iter->second->value == fromVertex->value) {
                           vertices.erase(iter);
                        
                       }
        }
        
      
        if (fromVertex == nullptr) return;
        
        for(typename set<Edge<V, E>*>::iterator iter = fromVertex->outEdges.begin(); iter != fromVertex->outEdges.end(); iter++)
                           {
                               Edge<V, E> *edge = *iter;
                            edges.erase(edge);
                            edge->toVertex->inEdges.erase(edge);
                              
                      }
        
        for(typename set<Edge<V, E>*>::iterator iter = fromVertex->inEdges.begin(); iter != fromVertex->inEdges.end(); iter++)
                                  {
                                     Edge<V, E> *edge = *iter;
                                    edges.erase(edge);
                                   edge->fromVertex->outEdges.erase(edge);
                                    
                             }
              
    }
    //移除边
    void removeEdge(V from,V to){
        Vertex<V, E> *fromVertex = vertices[from];
        if (fromVertex == nullptr) return;
        
        Vertex<V, E> *toVertex = vertices[to];
        if (toVertex == nullptr) return;
        
        Edge<V, E> *edge =new Edge<V,E>(fromVertex,toVertex);
        
        for(typename set<Edge<V, E>*>::iterator iter = fromVertex->outEdges.begin(); iter != fromVertex->outEdges.end(); iter++)
                    {
                        Edge<V, E> *tempEdge = *iter;
                        if (tempEdge->toVertex->value == edge->toVertex->value) {
                            fromVertex->outEdges.erase(tempEdge);
                            break;
                        }
                       
               }
               
               for(typename set<Edge<V, E>*>::iterator iter = toVertex->inEdges.begin(); iter != toVertex->inEdges.end(); iter++)
                    {
                         Edge<V, E> *tempEdge = *iter;
                        if (tempEdge->fromVertex->value == edge->fromVertex->value) {
                            toVertex->inEdges.erase(iter);
                            break;
                        }
               }
               
               for(typename set<Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++)
                           {
                                Edge<V, E> *tempEdge = *iter;
                               if (tempEdge->toVertex->value == edge->toVertex->value && tempEdge->fromVertex->value == edge->fromVertex->value) {
                                   edges.erase(iter);
                                   break;
                               }
                      }
    }
    
};

#endif /* ListGraph_hpp */
