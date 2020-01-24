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
    /*
     Bellman-Ford 也属于单元最短路径算法，支持负权边，还能检测出是否有负权环
     算法原理：对所有的边进行V-1 次松弛操作(V是节点数量),得到所有可能的最短路径
     时间复杂度:O(EV),E是边数量，V是节点数量
     最好情况是从左到右的顺序对边进行松弛操作
     最坏情况是恰好每次都从右到左的顺序对边进行松弛操作
     */
    unordered_map<V,PathInfo<V, E>*> * bellmanFord(V begin){
        Vertex<V, E> *beginVertex = vertices[begin];
        if(beginVertex == nullptr) return nullptr;
         unordered_map<V, PathInfo<V, E> *> *selectedPaths = new unordered_map<V, PathInfo<V, E>*>();
        //为了确保后面遍历顺利进行，这里首先制造一个插进去selectedPaths
        selectedPaths->insert(pair<V, PathInfo<V, E>*>(begin,new PathInfo<V, E>(0)));
        //获取遍历次数
        int count = (int)vertices.size() - 1;
        for (int i = 0; i < count; i++) {// v - 1 次
            for (Edge<V, E> *edge : edges) {
                PathInfo<V, E> *fromPath = nullptr;
                for(typename  unordered_map<V, PathInfo<V, E> *>::iterator iter = selectedPaths->begin(); iter != selectedPaths->end(); iter++){
                    if (iter->first == edge->from->value) {
                        fromPath = iter->second;
                         break;
                    }
                   
            }
                if (fromPath == nullptr) continue;
                relax(edge,fromPath,selectedPaths);
                
            }
        }
//        for (Edge<V, E> *edge : edges) {
//           PathInfo<V, E> *fromPath = nullptr;
//           for(typename  unordered_map<V, PathInfo<V, E> *>::iterator iter = selectedPaths->begin(); iter != selectedPaths->end(); iter++){
//               if (iter->first == edge->from->value) {
//                   fromPath = iter->second;
//                    break;
//               }
//           }
//
//           if (fromPath == nullptr) continue;
//           relax(edge,fromPath,selectedPaths);
//            cout << "有负权环" << endl;
//            return selectedPaths;
//           }
        selectedPaths->erase(begin);
        return selectedPaths;
    }
    /*
     松弛
     @param edge 需要松弛的边
     @param fromPath edge的from的最短路径信息
     @param paths 存放着其他点(对于dijkstra来说，就是还没有离开桌面的点)最短的路径信息
     */
    bool relax(Edge<V, E> *edge,PathInfo<V, E>*fromPath,unordered_map<V, PathInfo<V, E>*>*paths){
        //新的可选择的最短路径:beginVertex 到edge.from的最短路径 + edge.weight
        E newWeight = fromPath->weight + edge->weight;
        //以前的最短路径:beginVertex 到edge.to的u最短路径
        PathInfo<V, E> *oldPath = nullptr;
        for(typename  unordered_map<V,PathInfo<V, E>*>::iterator iter = paths->begin(); iter != paths->end(); iter++){
              
               if (iter->first == edge->to->value) {
                   oldPath = iter->second;
               }
           }
       
        if (oldPath != nullptr && (newWeight - oldPath->weight) >= 0) return false;
         if (oldPath == nullptr) {
                   oldPath = new PathInfo<V, E>();
                   paths->insert(pair<V, PathInfo<V, E>*>(edge->to->value,oldPath));
            
        }else{
               for(typename  set<EdgeInfo<V, E>*>::iterator iter = fromPath->edgeInfos->begin(); iter != fromPath->edgeInfos->end(); iter++){
                   
               }
               oldPath->edgeInfos->clear();
        }
        oldPath->weight = newWeight;
         for(typename  set<EdgeInfo<V, E>*>::iterator iter = fromPath->edgeInfos->begin(); iter != fromPath->edgeInfos->end(); iter++){
                EdgeInfo<V, E>* edgeInfo = *iter;

                oldPath->edgeInfos->insert(edgeInfo);
        }
         oldPath->edgeInfos->insert(edge->info());
        return true;
    }
    /*
     Floyd 属于多远最短路径算法，能够求出2个顶点之间的最短路径，支持负权边
     时间复杂度O(v^3),效率比执行V次Dijkstra算法要好(V是顶点数量）
     算法原理:
     从任意顶点i到任意顶点j的最短路径不外乎两种可能
     1.直接从i到j
     2.从i经过若干个顶点到j
        - 假设dist(i,j)为顶点i到顶点j的最短路径距离
        - 对于每一个顶点k，检查dist(i,k) + dist(k,j) < dist(i,j) 是否成立
            - 如果成立，证明从i到k再到j的路径比i直接到j的路径短，设置dist(i,j) = dist(i,k) + dist(k,j_
              当我们遍历完所有节点k，dist(i,j)中记录的便是i到j的最短路径距离
     */
    unordered_map<V, unordered_map<V, PathInfo<V, E> *>> *floydShortestPath(){
        unordered_map<V,unordered_map<V, PathInfo<V, E>*>> *paths = new unordered_map<V,unordered_map<V, PathInfo<V, E>*>>();
        //初始化
        for(typename set<Edge<V, E>*>::iterator iter = edges.begin(); iter != edges.end(); iter++){
            Edge<V, E> *edge = *iter;
            unordered_map<V, PathInfo<V, E> *> *pathValue = new  unordered_map<V, PathInfo<V, E> *>();
   
            for(typename  unordered_map<V, unordered_map<V, PathInfo<V, E> *>>::iterator iter = paths->begin(); iter != paths->end(); iter++){
                if (iter->first == edge->from->value) {
                    pathValue = &iter->second;
                    break;
                }
            }
//            {
//                pathValue = new  unordered_map<V, PathInfo<V, E> *>();
//                paths->insert(pair<V,unordered_map<V, PathInfo<V, E>*>>(pathKey,pathValue));
//            }
            
            
            PathInfo<V, E> *pathInfo = new PathInfo<V, E>(edge->weight);
            pathInfo->edgeInfos->insert(edge->info());
            pathValue->insert(pair<V, PathInfo<V, E>*>(edge->to->value,pathInfo));
            paths->insert(pair<V,unordered_map<V, PathInfo<V, E> *>>(edge->from->value,*pathValue));
            
        }
        
        for(const auto& vertex : vertices){
            V v2 = vertex.first;
            for(const auto& vertex : vertices){
                V v1 = vertex.first;
                for(const auto& vertex : vertices){
                    V  v3 = vertex.first;
                    if (v1 == v2 || v2 == v3 || v1 == v3) continue;
                    
                    //v1 -> v2
                    PathInfo<V, E> *path12 = getPathInfos(v1, v2, paths);
                    if (path12 == nullptr) continue ;
                    
                    //v2 -> v3
                    PathInfo<V, E> *path23 = getPathInfos(v2, v3, paths);
                    if (path23 == nullptr) continue;
                    
                    //v1 -> v3
                    PathInfo<V, E> *path13 = getPathInfos(v1, v3, paths);
                    
                    E newWeight = path12->weight + path23->weight;
                    if (path13 != nullptr && newWeight - path13->weight >= 0) continue;
                    
                    if (path13 == nullptr) {
                        path13 = new PathInfo<V, E>();
                        unordered_map<V, PathInfo<V, E> *> *pathValue = nullptr;
                 
                        for(typename  unordered_map<V, unordered_map<V, PathInfo<V, E> *>>::iterator iter = paths->begin(); iter != paths->end(); iter++){
                        
                            if (iter->first == v1) {
                                pathValue = &iter->second;
                                pathValue->insert(pair<V, PathInfo<V, E> *>(v3,path13));
                                break;
                            }
                        }
                    }else{
                         path13->edgeInfos->clear();
                    }
                    path13->weight = newWeight;
                 for(typename  set<EdgeInfo<V, E>*>::iterator iter = path12->edgeInfos->begin(); iter != path12->edgeInfos->end(); iter++){
                            EdgeInfo<V, E>* edgeInfo = *iter;
                     path13->edgeInfos->insert(edgeInfo);
                 }
                    for(typename  set<EdgeInfo<V, E>*>::iterator iter = path23->edgeInfos->begin(); iter != path23->edgeInfos->end(); iter++){
                        EdgeInfo<V, E>* edgeInfo = *iter;
                       path13->edgeInfos->insert(edgeInfo);
                    }
                }
            }
        }
        return paths;
    }
    PathInfo<V, E> *getPathInfos(V from,V to,unordered_map<V,unordered_map<V, PathInfo<V, E>*>> *paths){
        unordered_map<V, PathInfo<V, E>*> *pathValue = nullptr;
 
        for(typename  unordered_map<V,unordered_map<V, PathInfo<V, E>*>>::iterator iter = paths->begin(); iter != paths->end(); iter++){
           if (iter->first == from) {
               pathValue = &iter->second;
               break;
            }
        }
        if (pathValue == nullptr) {
            return nullptr;
        }else{
           PathInfo<V, E> *returnPathValue = nullptr;

           for(typename  unordered_map<V, PathInfo<V, E>*>::iterator iter = pathValue->begin(); iter != pathValue->end(); iter++){

              if (iter->first == to) {
                  returnPathValue = iter->second;
                  break;
               }
           }
            return returnPathValue;
        }
    }
};


#endif /* ListGraph_hpp */
