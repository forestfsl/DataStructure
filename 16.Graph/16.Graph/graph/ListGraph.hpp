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
#include <queue>
#include <stack>
#include <unordered_map>
#include "MinHeap.hpp"
#include "UnionFind.hpp"
#include "PathInfo.hpp"


template <class V,class E>

class ListGraph:public Graph<V,E> {
    typedef bool(*VertexVisitor)(V v);
//    typedef bool(*Comparator)(Edge<V,E>* e1,Edge<V, E>* e2);
    
public:
     WeightManager weightManager;
     unordered_map<V, Vertex<V, E>*> vertices =  unordered_map<V, Vertex<V, E>*>();
    set<Edge<V, E>*> edges =  set<Edge<V, E>*>();
//    Comparator comparator;
   
    ListGraph(){
        
    }
    ListGraph(WeightManager weightManager){
        this->weightManager = weightManager;
    }
    
    void print(){
        cout << "顶点---------------------------" << endl;
        for(const auto& vertex : vertices){
            cout << vertex.first << endl;
            cout << "out-------------------" << endl;
            for(typename set<Edge<V, E>*>::iterator iter = vertex.second->outEdges.begin(); iter != vertex.second->outEdges.end(); iter++)
            {
                Edge<V, E> *edge = *iter;
                cout <<"Edge [from=" << edge->from->value << ", to=" << edge->to->value <<", weight="<<edge->weight  << endl;
                }
            cout << "in--------------------" << endl;
            for(typename set<Edge<V, E>*>::iterator iter = vertex.second->inEdges.begin(); iter != vertex.second->inEdges.end(); iter++){
                Edge<V, E> *edge = *iter;
                cout <<"Edge [from=" << edge->from->value << ", to=" << edge->to->value <<", weight="<<edge->weight  << endl;
            }
        }
        
        cout << "边-----------------------------" << endl;
        for(typename set<Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++){
            Edge<V, E> *edge = *iter;
            cout <<"Edge [from=" << edge->from->value << ", to=" << edge->to->value <<", weight="<<edge->weight  << endl;
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
//            auto pr = vertices.insert(pair<V, Vertex<V, E>*>{from,from});
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
                            if (tempEdge->to->value == edge->to->value) {
                                                fromVertex->outEdges.erase(iter);
                                            }
                            
              }
        
       
        
        for(typename set<Edge<V, E>*>::iterator iter = toVertex->inEdges.begin(); iter != toVertex->inEdges.end(); iter++)
             {
                  Edge<V, E> *tempEdge = *iter;
                 if (tempEdge->from->value == edge->from->value) {
                     toVertex->inEdges.erase(iter);
                     break;
                 }
        }
        
        for(typename set<Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++)
                    {
                         Edge<V, E> *tempEdge = *iter;
                        if (tempEdge->to->value == edge->to->value && tempEdge->from->value == edge->from->value) {
                            edges.erase(iter);
                            break;
                        }
               }
        fromVertex->outEdges.insert(edge);
//        from->outEdges["test"] = edge;
        toVertex->inEdges.insert(edge);
//        to->inEdges["test"] = edge;
        edges.insert(edge);
//        edges["test"] = edge;
       
        
    }
    //移除顶点
    void removeVertex(V v){
        Vertex<V, E> *from = vertices[v];
        for(typename unordered_map<V, Vertex<V, E>*>::iterator iter = vertices.begin(); iter != vertices.end(); iter++)
                   {
                       if (iter->second->value == from->value) {
                           vertices.erase(iter);
                        
                       }
        }
        
      
        if (from == nullptr) return;
        
        for(typename set<Edge<V, E>*>::iterator iter = from->outEdges.begin(); iter != from->outEdges.end(); iter++)
                           {
                               Edge<V, E> *edge = *iter;
                            edges.erase(edge);
                            edge->to->inEdges.erase(edge);
                              
                      }
        
        for(typename set<Edge<V, E>*>::iterator iter = from->inEdges.begin(); iter != from->inEdges.end(); iter++)
                                  {
                                     Edge<V, E> *edge = *iter;
                                    edges.erase(edge);
                                   edge->from->outEdges.erase(edge);
                                    
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
                        if (tempEdge->to->value == edge->to->value) {
                            fromVertex->outEdges.erase(tempEdge);
                            break;
                        }
                       
               }
               
               for(typename set<Edge<V, E>*>::iterator iter = toVertex->inEdges.begin(); iter != toVertex->inEdges.end(); iter++)
                    {
                         Edge<V, E> *tempEdge = *iter;
                        if (tempEdge->from->value == edge->from->value) {
                            toVertex->inEdges.erase(iter);
                            break;
                        }
               }
               
               for(typename set<Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++)
                           {
                                Edge<V, E> *tempEdge = *iter;
                               if (tempEdge->to->value == edge->to->value && tempEdge->from->value == edge->from->value) {
                                   edges.erase(iter);
                                   break;
                               }
                      }
    }
    
    /*
     广度优先搜索(Breadth First Search,BFS),又称为宽度优先搜索，横向优先搜索
     之前所学的二叉树层序遍历就是一种广度优先搜索
     */
    void bfs(V begin,VertexVisitor visitor){
        if (visitor == nullptr) return;
        Vertex<V, E> *beginVertex = vertices[begin];
        if(beginVertex == nullptr) return;
        
        set<Vertex<V, E> *> visitedVertices = set<Vertex<V, E>*>();
        queue<Vertex<V, E> *> queue;
        queue.push(beginVertex);
        visitedVertices.insert(beginVertex);
        while (!queue.empty()) {
            Vertex<V, E> *vertex = queue.front();
            queue.pop();
            if (visitor(vertex->value)) return;
            
            for (Edge<V, E> *edge : vertex->outEdges) {
                if (visitedVertices.find(edge->to) != visitedVertices.end()) continue;
                queue.push(edge->to);
                visitedVertices.insert(edge->to);
            }
        }
        
    }
    
    /*
     深度优先搜索(Depth First Search,DFS) 非递归实现
     */
    void dfs(V begin,VertexVisitor visitor){
        if (visitor == nullptr) return;
        Vertex<V, E> *beginVertex = vertices[begin];
        if (beginVertex == nullptr) return;
        set<Vertex<V, E> *> visitedVertices = set<Vertex<V,E>*>();
        stack<Vertex<V, E> *> *dfsstack = new stack<Vertex<V, E> *>();
        //先访问起点
        dfsstack->push(beginVertex);
        visitedVertices.insert(beginVertex);
        if (visitor(begin)) return;
        
        while (!dfsstack->empty()) {
            Vertex<V, E> *vertex = dfsstack->top();
            dfsstack->pop();
            for (Edge<V, E> *edge : vertex->outEdges) {
               if (visitedVertices.find(edge->to) != visitedVertices.end()) continue;
               dfsstack->push(edge->from);
                dfsstack->push(edge->to);
               visitedVertices.insert(edge->to);
                if (visitor(edge->to->value)) return;
            }
            
        }
    }
    
    /*
       深度优先搜索(Depth First Search,DFS) 递归实现
       */
    void dfs2(Vertex<V, E*> *vertex, set<Vertex<V, E>*>visitedVertices){
        cout << vertex->value << "--->";
        visitedVertices.insert(vertex);
         for (Edge<V, E> *edge : vertex->outEdges) {
             if (visitedVertices.find(edge->to) != visitedVertices.end()) continue;
             dfs2(edge->to, visitedVertices);
        }
    }
    
    /*
     生成树(Spanning Tree):也称为支撑树
     求最小的生成树的2个经典的算法：Prim(普利姆算法) Kruskal(克鲁斯科尔算法)
     
     */
    //Prim(普利姆算法)
    set<EdgeInfo<V, E>*>* prim(){
        Vertex<V, E> *vertex = nullptr;
        for(const auto& iter : vertices){
            vertex = iter.second;
        }
        set<EdgeInfo<V, E>*> *edgeinfos = new set<EdgeInfo<V, E>*>();
        set<Vertex<V, E>*> *addedVertices =  new set<Vertex<V, E>*>();
        //这里已经将起点加进去了，之后就算反过来对比的时候也没有问题
        addedVertices->insert(vertex);
        MinHeap<Edge<V, E>*> *heap = new MinHeap<Edge<V, E>*>(vertex->outEdges,[] (Edge<V,E>* e1,Edge<V, E>* e2) ->int{
    
               return e2->weight - e1->weight;
            
        });
        int verticeSize = (int)vertices.size();
        while (!heap->isEmpty() && addedVertices->size() < verticeSize) {
            Edge<V, E> *edge = heap->remove();
            if (addedVertices->find(edge->to) != addedVertices->end()) continue;
            edgeinfos->insert(edge->info());
            addedVertices->insert(edge->to);
            for (Edge<V, E>* edge: edge->to->outEdges) {
                heap->add(edge);
            }
        }
        return edgeinfos;
                   
    }
    // Kruskal(克鲁斯科尔算法)
    /*
     按照边的权重顺序(从小到大)将边加入生成树中，知道生成树中含有V-1条边为止(V是顶点数量),若加入该边会与生成树形成环，则不加入该边
     */
    set<EdgeInfo<V, E>*>* kruskal(){
        int edgeSize = (int)vertices.size() - 1;
        if (edgeSize == -1) return nullptr;
        set<EdgeInfo<V, E>*> *edgeInfos = new set<EdgeInfo<V, E>*>();
        MinHeap<Edge<V, E> *> *heap = new MinHeap<Edge<V, E> *>(edges,[] (Edge<V,E>* e1,Edge<V, E>* e2) ->int{
            return e2->weight - e1->weight;
        });
        UnionFind<Vertex<V, E>*> *uf = new UnionFind<Vertex<V, E>*>();
        for(const auto& vertex : vertices){
            uf->makeSet(vertex.second);
        }
        while (!heap->isEmpty() && edgeInfos->size() < edgeSize) {
            Edge<V, E> *edge = heap->remove();
            if (uf->isSame(edge->from, edge->to)) continue;
            edgeInfos->insert(edge->info());
            uf->unionElement(edge->from, edge->to);
        }
        return edgeInfos;
    }
    
    /*
     - 最短路径：是指两顶点之间权值之和最小的路径(有向图，无向图均适用，不能有负权环)
     - 最短路径-无权图(无权图相当于是全部边权值为1的有权图)
     - 最短路径-负权边
        - 有负权边，但没有负权环时，存在最短路径
    - 最短路径-负权环
        - 有负权环时，不存在最短路径
     
     Dijkstra 属于单源最短路径算法，用于计算一个顶点到其他所有顶点的最短路径，使用前提是不能有负权边，时间复杂度可优化至O(ElogV),E是边数量，V是节点数量
     */
    
    unordered_map<V, PathInfo<V, E> *> * shortestPath(V begin){
        return dijkstra(begin);
    }
    
    
    unordered_map<V, PathInfo<V, E> *>* dijkstra(V begin){
        Vertex<V, E>* beginVertex = vertices[begin];
   
        
        unordered_map<V, PathInfo<V, E> *> *selectedPaths = new unordered_map<V, PathInfo<V, E>*>();
        unordered_map<Vertex<V, E>*, PathInfo<V, E>*> *paths = new unordered_map<Vertex<V, E>*, PathInfo<V, E>*>();
        
        PathInfo<V, E> *newPathInfo = new PathInfo<V, E>(0);
        paths->insert(pair<Vertex<V, E>*, PathInfo<V, E>*>(beginVertex,newPathInfo));
//        paths[beginVertex] = newPathInfo;
        
        while (!paths->empty()) {
            //minVertex 离开桌面
            Vertex<V, E> *minVertex = getMinKeyPath(paths);
            PathInfo<V, E> *minValue = getMinValuePath(paths);
            selectedPaths->insert(pair<V, PathInfo<V, E> *>(minVertex->value,minValue));
//            selectedPaths[minVertex->value] = minValue;
          paths->erase(minVertex);
          //对它的minVertex的outEdges进行松弛操作
          for(const auto& edge : minVertex->outEdges){
              //如果edge.to 已经离开桌面，就没有必要进行松弛
              if(selectedPaths->find(edge->to->value) != selectedPaths->end()) continue;
              relaxForDijkstra(edge,minValue,paths);
          }
  
        }
        selectedPaths->erase(begin);
        return selectedPaths;
    }
    /*
     relasForDijkstrl 松弛
     @param edge 需要进行松弛的边
     @param fromPath edge 的from的最短路径
     @param paths 存放着其他店(对于dijkstra来说，就是没有离开桌面的点)的最短路径信息
     */
    void relaxForDijkstra(Edge<V, E> *edge,PathInfo<V, E> *fromPath,unordered_map<Vertex<V, E>*, PathInfo<V, E>*>*paths){
        //新的可选择的最短路径:beginVertex到edge.from 的最短路径 + edge.weight
        E newWeight = fromPath->weight + edge->weight;
        //以前的最短路径:beginVertex 到edge.to的最短路径
        PathInfo<V, E> *oldPath = nullptr;
        Vertex<V, E> *oldKey;
        for(typename  unordered_map<Vertex<V, E>*, PathInfo<V, E>*>::iterator iter = paths->begin(); iter != paths->end(); iter++){
            oldKey = iter->first;
            if (oldKey->value == edge->to->value) {
                oldPath = iter->second;
            }
        }
       
        
        if (oldPath != nullptr){
            int delta = newWeight - oldPath->weight;
            if (delta >= 0) {
                return;
            }
        }
        
        if (oldPath == nullptr) {
            oldPath = new PathInfo<V, E>();
            paths->insert(pair<Vertex<V,E> *, PathInfo<V, E> *>(edge->to,oldPath));
     
        }else{
            for(typename  set<EdgeInfo<V, E>*>::iterator iter = fromPath->edgeInfos->begin(); iter != fromPath->edgeInfos->end(); iter++){
                
            }
            oldPath->edgeInfos->clear();
        }
        oldPath->weight = newWeight;

        for(typename  set<EdgeInfo<V, E>*>::iterator iter = fromPath->edgeInfos->begin(); iter != fromPath->edgeInfos->end(); iter++){
            EdgeInfo<V, E>* edgeInfo = *iter;
//            cout << edgeInfo->from << edgeInfo->to<<edgeInfo->weight << endl;
            oldPath->edgeInfos->insert(edgeInfo);
        }
        
        oldPath->edgeInfos->insert(edge->info());
    }
    
    
    Vertex<V, E> *getMinKeyPath(unordered_map<Vertex<V, E>*, PathInfo<V, E>*> *paths){
   
       Vertex<V,E> *minKey;
       PathInfo<V,E> *minValue;
       Vertex<V,E>*entryKey;
       PathInfo<V,E>*entryValue;
       for(typename  unordered_map<Vertex<V, E>*, PathInfo<V, E>*>::iterator iter = paths->begin(); iter != paths->end(); iter++){
           minKey = iter->first;
           minValue = iter->second;
           break;
       }
       for(typename  unordered_map<Vertex<V, E>*, PathInfo<V, E>*>::iterator iter = paths->begin(); iter != paths->end(); iter++){
           entryKey = iter->first;
           entryValue = iter->second;
           int weightDelta = entryValue->weight - minValue->weight;
            if (weightDelta < 0) {
                minKey = entryKey;
            }
       }

       return minKey;

    }
    
    /*
     从paths中挑一个最小的路径出来
     */
    PathInfo<V, E>* getMinValuePath(unordered_map<Vertex<V, E>*, PathInfo<V, E>*> *paths){
    Vertex<V,E>*minKey;
      PathInfo<V, E>*minValue;
      Vertex<V,E>*entryKey;
      PathInfo<V,E>*entryValue;
      for(typename  unordered_map<Vertex<V, E>*, PathInfo<V, E>*>::iterator iter = paths->begin(); iter != paths->end(); iter++){
          minKey = iter->first;
          minValue = iter->second;
          break;
      }
      for(typename  unordered_map<Vertex<V, E>*, PathInfo<V, E>*>::iterator iter = paths->begin(); iter != paths->end(); iter++){
          entryKey = iter->first;
          entryValue = iter->second;
          int weightDelta = entryValue->weight - minValue->weight;
           if (weightDelta < 0) {
               minValue = entryValue;
           }
      }

      return minValue;
        
    }
};


#endif /* ListGraph_hpp */
