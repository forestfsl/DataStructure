//
//  main.cpp
//  16.Graph
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#include <iostream>
#include "ListGraph.hpp"
#include "MinHeap.hpp"

void test(){
    ListGraph<string, int> graph = ListGraph<string, int>();
    graph.addEdge("V0", "V1");
    graph.addEdge("V1", "V0");

    graph.addEdge("V0", "V2");
    graph.addEdge("V2", "V0");

    graph.addEdge("V0", "V3");
    graph.addEdge("V3", "V0");

    graph.addEdge("V1", "V2");
    graph.addEdge("V2", "V1");

    graph.addEdge("V2", "V3");
    graph.addEdge("V3", "V2");

    graph.print();
}




/*
 test() 输出结果
 C++
 顶点---------------------------
 V2
 out-------------------
 Edge [from=V2, to=V0, weight=0
 Edge [from=V2, to=V1, weight=0
 Edge [from=V2, to=V3, weight=0
 in--------------------
 Edge [from=V0, to=V2, weight=0
 Edge [from=V1, to=V2, weight=0
 Edge [from=V3, to=V2, weight=0
 V3
 out-------------------
 Edge [from=V3, to=V0, weight=0
 Edge [from=V3, to=V2, weight=0
 in--------------------
 Edge [from=V0, to=V3, weight=0
 Edge [from=V2, to=V3, weight=0
 V1
 out-------------------
 Edge [from=V1, to=V0, weight=0
 Edge [from=V1, to=V2, weight=0
 in--------------------
 Edge [from=V0, to=V1, weight=0
 Edge [from=V2, to=V1, weight=0
 V0
 out-------------------
 Edge [from=V0, to=V2, weight=0
 Edge [from=V0, to=V1, weight=0
 Edge [from=V0, to=V3, weight=0
 in--------------------
 Edge [from=V1, to=V0, weight=0
 Edge [from=V2, to=V0, weight=0
 Edge [from=V3, to=V0, weight=0
 边-----------------------------
 Edge [from=V0, to=V2, weight=0
 Edge [from=V0, to=V1, weight=0
 Edge [from=V1, to=V0, weight=0
 Edge [from=V2, to=V0, weight=0
 Edge [from=V0, to=V3, weight=0
 Edge [from=V3, to=V0, weight=0
 Edge [from=V1, to=V2, weight=0
 Edge [from=V2, to=V1, weight=0
 Edge [from=V2, to=V3, weight=0
 Edge [from=V3, to=V2, weight=0
 Program ended with exit code: 0
 */

/*
 Java
[顶点]-------------------
V0
out-----------
[Edge [from=V0, to=V1, weight=null], Edge [from=V0, to=V3, weight=null], Edge [from=V0, to=V2, weight=null]]
in-----------
[Edge [from=V3, to=V0, weight=null], Edge [from=V1, to=V0, weight=null], Edge [from=V2, to=V0, weight=null]]
V1
out-----------
[Edge [from=V1, to=V2, weight=null], Edge [from=V1, to=V0, weight=null]]
in-----------
[Edge [from=V0, to=V1, weight=null], Edge [from=V2, to=V1, weight=null]]
V2
out-----------
[Edge [from=V2, to=V3, weight=null], Edge [from=V2, to=V1, weight=null], Edge [from=V2, to=V0, weight=null]]
in-----------
[Edge [from=V1, to=V2, weight=null], Edge [from=V0, to=V2, weight=null], Edge [from=V3, to=V2, weight=null]]
V3
out-----------
[Edge [from=V3, to=V0, weight=null], Edge [from=V3, to=V2, weight=null]]
in-----------
[Edge [from=V2, to=V3, weight=null], Edge [from=V0, to=V3, weight=null]]
[边]-------------------
Edge [from=V0, to=V1, weight=null]
Edge [from=V1, to=V2, weight=null]
Edge [from=V2, to=V3, weight=null]
Edge [from=V0, to=V3, weight=null]
Edge [from=V0, to=V2, weight=null]
Edge [from=V3, to=V0, weight=null]
Edge [from=V1, to=V0, weight=null]
Edge [from=V2, to=V1, weight=null]
Edge [from=V3, to=V2, weight=null]
Edge [from=V2, to=V0, weight=null]
*/

void test1(){
      ListGraph<string, int> graph = ListGraph<string, int>();
            graph.addEdge("V1", "V0", 9);
            graph.addEdge("V1", "V2", 3);
            graph.addEdge("V2", "V0", 2);
            graph.addEdge("V2", "V3", 5);
            graph.addEdge("V3", "V4", 1);
            graph.addEdge("V0", "V4", 6);
            
            graph.removeEdge("V0", "V4");
            graph.removeVertex("V0");

            graph.print();
}
/*
 test1()输出结果
 顶点---------------------------
 V2
 out-------------------
 Edge [from=V2, to=V3, weight=5
 in--------------------
 Edge [from=V1, to=V2, weight=3
 V4
 out-------------------
 in--------------------
 Edge [from=V3, to=V4, weight=1
 V3
 out-------------------
 Edge [from=V3, to=V4, weight=1
 in--------------------
 Edge [from=V2, to=V3, weight=5
 V1
 out-------------------
 Edge [from=V1, to=V2, weight=3
 in--------------------
 边-----------------------------
 Edge [from=V1, to=V2, weight=3
 Edge [from=V2, to=V3, weight=5
 Edge [from=V3, to=V4, weight=1
 Program ended with exit code: 0
 */



auto lamba = [] (int element) ->bool{
    cout << element << "-->";
    return false;
};
//0-->1-->4-->2-->6-->7-->5-->3-->
void testBfs(){
    ListGraph<int, int> graph = ListGraph<int, int>();
     graph.addEdge(0, 1);
     graph.addEdge(0, 4);
     graph.addEdge(1, 2);
     graph.addEdge(2, 0);
     graph.addEdge(2, 4);
     graph.addEdge(2, 5);
     graph.addEdge(3, 1);
     graph.addEdge(4, 6);
     graph.addEdge(4, 7);
     graph.addEdge(5, 3);
     graph.addEdge(5, 7);
     graph.addEdge(6, 2);
     graph.addEdge(6, 7);
     graph.bfs(0, lamba);
//     graph.print();
    
}
auto lamba1 = [] (string element) ->bool{
    cout << element << "-->";
    return false;
};



//a-->b-->e-->c-->f a-->b-->e-->f-->c a-->e-->f-->c-->b a-->e-->c-->b-->f
void testDfs(){
    ListGraph<string, int> graph = ListGraph<string, int>();
    graph.addEdge("a", "b");
    graph.addEdge("a", "e");
    graph.addEdge("b", "e");
    graph.addEdge("c", "b");
    graph.addEdge("d", "a");
    graph.addEdge("e", "c");
    graph.addEdge("e", "f");
    graph.addEdge("f", "c");
    graph.dfs("a", lamba1);
}



ListGraph<int, int> undirectedGraph(int data[12][3],int row,int colomn){
    ListGraph<int, int> graph = ListGraph<int, int>();
    
    for (int i = 0; i < row; i++) {
        int *edge = data[i];
       
        if (colomn == 1) {
            graph.addVertex(edge[0]);
        }else if (colomn == 2){
            graph.addEdge(edge[0], edge[1]);
            graph.addEdge(edge[1], edge[0]);
        }else if (colomn == 3){
            graph.addEdge(edge[0], edge[1], edge[2]);
            graph.addEdge(edge[1], edge[0], edge[2]);
        }
    }
    return graph;
}
void testMst(){
   
    int data[12][3] = {{0, 2, 2}, {0, 4, 7},
        {1, 2, 3}, {1, 5, 1}, {1, 6, 7},
        {2, 4, 4}, {2, 5, 3}, {2, 6, 6},
        {3, 7, 9},
        {4, 6, 8},
        {5, 6, 4}, {5, 7, 5}};
 
     ListGraph<int, int> graph = undirectedGraph(data,12,3);
//     graph.addEdge(0, 2, 2);
//     graph.addEdge(0, 4, 7);
//     graph.addEdge(1, 2, 3);
//     graph.addEdge(1, 5, 1);
//     graph.addEdge(1, 6, 7);
//     graph.addEdge(2, 4, 4);
//     graph.addEdge(2, 5, 3);
//     graph.addEdge(2, 6, 6);
//     graph.addEdge(3, 7, 9);
//     graph.addEdge(4, 6, 8);
//     graph.addEdge(5, 6, 4);
//     graph.addEdge(5, 7, 5);
    set<EdgeInfo<int, int>*> *infos  = graph.prim();
    for(typename set<EdgeInfo<int, int>*>::iterator iter = infos->begin(); iter != infos->end(); iter++){
        EdgeInfo<int, int> *edgeInfo = *iter;
        cout <<"EdgeInfo [from=" << edgeInfo->from <<", to=" << edgeInfo->to <<", weight=" << edgeInfo->weight << "]" << endl;
    }
    /*
    C++:
    EdgeInfo [from=0, to=2, weight=2]
    EdgeInfo [from=2, to=5, weight=3]
    EdgeInfo [from=5, to=1, weight=1]
    EdgeInfo [from=2, to=4, weight=4]
    EdgeInfo [from=5, to=6, weight=4]
    EdgeInfo [from=5, to=7, weight=5]
    EdgeInfo [from=7, to=3, weight=9]
    */
    /*
     java:
     EdgeInfo [from=0, to=2, weight=2.0]
     EdgeInfo [from=5, to=1, weight=1.0]
     EdgeInfo [from=5, to=7, weight=5.0]
     EdgeInfo [from=2, to=5, weight=3.0]
     EdgeInfo [from=7, to=3, weight=9.0]
     EdgeInfo [from=2, to=4, weight=4.0]
     EdgeInfo [from=5, to=6, weight=4.0]
     */
     
}
/*
 C++
 EdgeInfo [from=7, to=3, weight=9]
 EdgeInfo [from=5, to=7, weight=5]
 EdgeInfo [from=2, to=4, weight=4]
 EdgeInfo [from=2, to=0, weight=2]
 EdgeInfo [from=5, to=6, weight=4]
 EdgeInfo [from=1, to=2, weight=3]
 EdgeInfo [from=5, to=1, weight=1]
 */
/*
 Java
 EdgeInfo [from=7, to=5, weight=5.0]
 EdgeInfo [from=1, to=5, weight=1.0]
 EdgeInfo [from=1, to=2, weight=3.0]
 EdgeInfo [from=5, to=6, weight=4.0]
 EdgeInfo [from=2, to=0, weight=2.0]
 EdgeInfo [from=2, to=4, weight=4.0]
 EdgeInfo [from=3, to=7, weight=9.0]
 */

void testMst1(){
    int data[12][3] = {{0, 2, 2}, {0, 4, 7},
           {1, 2, 3}, {1, 5, 1}, {1, 6, 7},
           {2, 4, 4}, {2, 5, 3}, {2, 6, 6},
           {3, 7, 9},
           {4, 6, 8},
           {5, 6, 4}, {5, 7, 5}};
    
    ListGraph<int, int> graph = undirectedGraph(data,12,3);
    set<EdgeInfo<int, int>*> *infos  = graph.kruskal();
       for(typename set<EdgeInfo<int, int>*>::iterator iter = infos->begin(); iter != infos->end(); iter++){
           EdgeInfo<int, int> *edgeInfo = *iter;
           cout <<"EdgeInfo [from=" << edgeInfo->from <<", to=" << edgeInfo->to <<", weight=" << edgeInfo->weight << "]" << endl;
       }
}

int main(int argc, const char * argv[]) {

//    test();
//    test1();
//    testBfs();
//    testDfs();
//    testMst()
    testMst1();
    return 0;
}
