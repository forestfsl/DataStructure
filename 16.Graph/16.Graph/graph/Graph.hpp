//
//  Graph.hpp
//  16.Graph
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "WeightManager.hpp"
#include "EdgeInfo.hpp"

/*
 图由顶点vertex和边edge组成，通常标识为G = (V,E)
 G表示一个图，V是顶点集，E是边集
 顶点集V有穷且非空
 任意两个顶点之间都可以用边来表示它们之间的关系，边集E可以是空的
 
 - 有向图的边是有明确方向的
 - 有向无环图(Directed Acyclic Graph,简称DAG)
    - 如果一个有向图，从任意顶点出发无法经过若干条回到该顶点，那么它就是一个有向无环图
 - 出度，入度适用于有向图
    - 出度(Out-degree)
        - 一个顶点的出度x，是指有x跳变以该顶点为起点
        - 顶点11的出度是3
 - 入度(In-degree)
    - 一个顶点的入度为x，是指有x条边以该顶点为终点
    - 顶点11的入度是2
 
 - 无向图(Undirected Graph):无向图的边是无方向的
 - 混合图(Mixed Graph) 混合图的边可能是无向的，也可能是有向的
 - 平行边
    - 在无向图中，关联一对顶点的无向边如果多余1条，则称这些边为平行边
    - 在有向图中，关联一对顶点的有向边如果多余一条，并且它们的方向相同，则称这些边为平行边
 - 多重图(Multigraph)
    - 有平行边或者有自环的图
 - 简单图(Simple Graph）
    - 既没有平行边也没有自环的图
 - 无向完全图
    - n个顶点的无向完全图有n(n-1)/2 条边
 - 有向完全图
    - 有向完全图的任意两个顶点之间都存在方向相反的两条边
 - 稠密图(Desnse Graph):边数接近于或等于完全图
 - 稀疏图(Sparse Graph)：边数远远少于完全图
 - 有权图
    - 有权图的边可以拥有权值(Weight)
 - 连通图(Connected Graph)
    - 如果顶点x和y之间可相互抵达的路径(直接或间接的路径)，则称为x和y是联通的
    - 如果无向图G中任意两个顶点都是联通的，则称G为连通图
 - 连通分量(Connected Component)
    - 无向图的极大连通子图
    - 连通图只有一个连通分量，即其自身；非连通的无向图有多个连通分量
 - 强连通图(Strongly Connected Graph)
    - 如果有向图G中任意2个顶点都是连通的，则称G为强连通图
- 强连通分量(Strongly Connected Component)
    - 有向图的极大强连通子图
    - 强连通图只有一个强连通分量，即其自身；非强连通的向图有多个强连通分量
 
 - 图的实现方案
    - 邻接矩阵(Adjacency Matrix)
        - 一维数组存放顶点信息
        - 二位数组存放边信息
        - 适合稠密图，不然hi浪费内存空间
    - 邻接表(Adjacency List)
 */

template <class V,class E>
class Graph {
   
public:
     
    Graph(){
        
    }
    Graph(WeightManager weightManager){
        this->weightManager = weightManager;
    }
    
    //边的数量
    virtual int edgesSize(){
        return 0;
    };
    //顶点的数量
    virtual int verticesSize(){
        return 0;
    };
    //添加顶点
    virtual void addVertex(V v){};
    //添加边
    virtual void addEdge(V from,V to){};
    virtual void addEdge(V from,V to,E weight){};
    //移除顶点
    virtual void removeVertex(V v){};
    //移除边
    virtual void removeEdge(V from,V to){};
    
};

#endif /* Graph_hpp */
