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

/*
 Java
B - PathInfo [weight=10.0, edgeInfos=[EdgeInfo [from=A, to=B, weight=10.0]]]
C - PathInfo [weight=50.0, edgeInfos=[EdgeInfo [from=A, to=D, weight=30.0], EdgeInfo [from=D, to=C, weight=20.0]]]
D - PathInfo [weight=30.0, edgeInfos=[EdgeInfo [from=A, to=D, weight=30.0]]]
E - PathInfo [weight=60.0, edgeInfos=[EdgeInfo [from=A, to=D, weight=30.0], EdgeInfo [from=D, to=C, weight=20.0], EdgeInfo [from=C, to=E, weight=10.0]]]
 */
/*
 C++
E - PathInfo [weight = 60,edgeInfos = [EdgeInfo [from = A to =D weight = 30],EdgeInfo [from = D to =C weight = 20],EdgeInfo [from = C to =E weight = 10]]]
D - PathInfo [weight = 30,edgeInfos = [EdgeInfo [from = A to =D weight = 30]]]
C - PathInfo [weight = 50,edgeInfos = [EdgeInfo [from = A to =D weight = 30],EdgeInfo [from = D to =C weight = 20]]]
B - PathInfo [weight = 10,edgeInfos = [EdgeInfo [from = A to =B weight = 10]]]
 */
void testMst2(){
    ListGraph<string, int> graph = ListGraph<string, int>();
    graph.addEdge("A", "B", 10);
    graph.addEdge("A", "D", 30);
    graph.addEdge("A", "E", 100);
    graph.addEdge("B", "C", 50);
    graph.addEdge("C", "E", 10);
    graph.addEdge("D", "C", 20);
    graph.addEdge("D", "E", 60);
    unordered_map<string, PathInfo<string, int> *> *infos = graph.shortestPath("A");
    for(typename  unordered_map<string, PathInfo<string, int> *>::iterator iter = infos->begin(); iter != infos->end(); iter++){
        PathInfo<string, int> *pathInfo = iter->second;
        cout  <<iter->first << " - PathInfo [weight = "<< pathInfo->weight << ",edgeInfos = ";
        cout << "[";
        
        int len = (int)pathInfo->edgeInfos->size() - 1;
        int i = 0;
        set<EdgeInfo<string, int>*>::iterator iter1 = pathInfo->edgeInfos->begin();
                    while (iter1!=pathInfo->edgeInfos->end())
                    {
                       
                        EdgeInfo<string, int> *edgeInfo = *iter1;
                        if (len == i) {
                             cout <<"EdgeInfo "<< "[from = " << edgeInfo->from<< " to =" << edgeInfo->to<< " weight = " << edgeInfo->weight<< "]";
                        }else{
                             cout <<"EdgeInfo "<< "[from = " << edgeInfo->from<< " to =" << edgeInfo->to<< " weight = " << edgeInfo->weight<< "],";
                        }
                       
                        iter1++;
                        i++;
                    }
//        for(typename  set<EdgeInfo<string, int>*>::iterator iter = pathInfo->edgeInfos->begin(); iter != pathInfo->edgeInfos->end(); iter++){
//            EdgeInfo<string, int> *edgeInfo = *iter;
//            cout <<"EdgeInfo "<< "[from = " << edgeInfo->from<< " to =" << edgeInfo->to<< " weight = " << edgeInfo->weight<< "]";
//        }
        cout <<"]]"<< endl;
       
    }
}

void testMst3(){
     ListGraph<string, int> graph = ListGraph<string, int>();
        graph.addEdge("A", "B", 10);
        graph.addEdge("A", "D", 30);
        graph.addEdge("A", "E", 100);
        graph.addEdge("B", "C", 50);
        graph.addEdge("C", "E", 10);
        graph.addEdge("D", "C", 20);
        graph.addEdge("D", "E", 60);
    unordered_map<string, PathInfo<string, int> *> *infos = graph.bellmanFord("A");
        for(typename  unordered_map<string, PathInfo<string, int> *>::iterator iter = infos->begin(); iter != infos->end(); iter++){
            PathInfo<string, int> *pathInfo = iter->second;
            cout  <<iter->first << " - PathInfo [weight = "<< pathInfo->weight << ",edgeInfos = ";
            cout << "[";
            
            int len = (int)pathInfo->edgeInfos->size() - 1;
            int i = 0;
            set<EdgeInfo<string, int>*>::iterator iter1 = pathInfo->edgeInfos->begin();
                        while (iter1!=pathInfo->edgeInfos->end())
                        {
                           
                            EdgeInfo<string, int> *edgeInfo = *iter1;
                            if (len == i) {
                                 cout <<"EdgeInfo "<< "[from = " << edgeInfo->from<< " to =" << edgeInfo->to<< " weight = " << edgeInfo->weight<< "]";
                            }else{
                                 cout <<"EdgeInfo "<< "[from = " << edgeInfo->from<< " to =" << edgeInfo->to<< " weight = " << edgeInfo->weight<< "],";
                            }
                           
                            iter1++;
                            i++;
                        }
    //        for(typename  set<EdgeInfo<string, int>*>::iterator iter = pathInfo->edgeInfos->begin(); iter != pathInfo->edgeInfos->end(); iter++){
    //            EdgeInfo<string, int> *edgeInfo = *iter;
    //            cout <<"EdgeInfo "<< "[from = " << edgeInfo->from<< " to =" << edgeInfo->to<< " weight = " << edgeInfo->weight<< "]";
    //        }
            cout <<"]]"<< endl;
           
        }
}

/*
 C++ 输出
 E - PathInfo [weight = 60,edgeInfos = [EdgeInfo [from = A to =D weight = 30],EdgeInfo [from = D to =C weight = 20],EdgeInfo [from = C to =E weight = 10]]]
 D - PathInfo [weight = 30,edgeInfos = [EdgeInfo [from = A to =D weight = 30]]]
 C - PathInfo [weight = 50,edgeInfos = [EdgeInfo [from = A to =D weight = 30],EdgeInfo [from = D to =C weight = 20]]]
 B - PathInfo [weight = 10,edgeInfos = [EdgeInfo [from = A to =B weight = 10]]]
 */

void testMultiSp(){
    ListGraph<string, int> graph = ListGraph<string, int>();
   graph.addEdge("A", "B", -1);
   graph.addEdge("A", "C", 4);
   graph.addEdge("B", "C", 3);
   graph.addEdge("B", "D", 2);
   graph.addEdge("B", "E", 2);
   graph.addEdge("D", "B", 1);
   graph.addEdge("D", "C", 5);
   graph.addEdge("E", "D", -3);
    unordered_map<string, unordered_map<string, PathInfo<string, int> *>> *sp = graph.floydShortestPath();
    for(typename  unordered_map<string, unordered_map<string, PathInfo<string, int> *>>::iterator iter = sp->begin(); iter != sp->end(); iter++){
        unordered_map<string, PathInfo<string, int> *> *paths = &iter->second;
        cout << iter->first <<"______________________________________________________" << endl;
        for(typename  unordered_map<string, PathInfo<string, int> *>::iterator iter = paths->begin(); iter != paths->end(); iter++){
                    PathInfo<string, int> *pathInfo = iter->second;
                    cout  <<iter->first << " - PathInfo [weight = "<< pathInfo->weight << ",edgeInfos = ";
                    cout << "[";
                    
                    int len = (int)pathInfo->edgeInfos->size() - 1;
                    int i = 0;
                    set<EdgeInfo<string, int>*>::iterator iter1 = pathInfo->edgeInfos->begin();
                                while (iter1!=pathInfo->edgeInfos->end())
                                {
                                   
                                    EdgeInfo<string, int> *edgeInfo = *iter1;
                                    if (len == i) {
                                         cout <<"EdgeInfo "<< "[from = " << edgeInfo->from<< " to =" << edgeInfo->to<< " weight = " << edgeInfo->weight<< "]";
                                    }else{
                                         cout <<"EdgeInfo "<< "[from = " << edgeInfo->from<< " to =" << edgeInfo->to<< " weight = " << edgeInfo->weight<< "],";
                                    }
                                   
                                    iter1++;
                                    i++;
                                }
                    cout <<"]]"<< endl;

        }
        
    }
}
/*
 Java
 A---------------------
 B - PathInfo [weight=-1.0, edgeInfos=[EdgeInfo [from=A, to=B, weight=-1.0]]]
 C - PathInfo [weight=2.0, edgeInfos=[EdgeInfo [from=A, to=B, weight=-1.0], EdgeInfo [from=B, to=C, weight=3.0]]]
 D - PathInfo [weight=-2.0, edgeInfos=[EdgeInfo [from=A, to=B, weight=-1.0], EdgeInfo [from=B, to=E, weight=2.0], EdgeInfo [from=E, to=D, weight=-3.0]]]
 E - PathInfo [weight=1.0, edgeInfos=[EdgeInfo [from=A, to=B, weight=-1.0], EdgeInfo [from=B, to=E, weight=2.0]]]
 B---------------------
 C - PathInfo [weight=3.0, edgeInfos=[EdgeInfo [from=B, to=C, weight=3.0]]]
 D - PathInfo [weight=-1.0, edgeInfos=[EdgeInfo [from=B, to=E, weight=2.0], EdgeInfo [from=E, to=D, weight=-3.0]]]
 E - PathInfo [weight=2.0, edgeInfos=[EdgeInfo [from=B, to=E, weight=2.0]]]
 D---------------------
 B - PathInfo [weight=1.0, edgeInfos=[EdgeInfo [from=D, to=B, weight=1.0]]]
 C - PathInfo [weight=4.0, edgeInfos=[EdgeInfo [from=D, to=B, weight=1.0], EdgeInfo [from=B, to=C, weight=3.0]]]
 E - PathInfo [weight=3.0, edgeInfos=[EdgeInfo [from=D, to=B, weight=1.0], EdgeInfo [from=B, to=E, weight=2.0]]]
 E---------------------
 B - PathInfo [weight=-2.0, edgeInfos=[EdgeInfo [from=E, to=D, weight=-3.0], EdgeInfo [from=D, to=B, weight=1.0]]]
 C - PathInfo [weight=1.0, edgeInfos=[EdgeInfo [from=E, to=D, weight=-3.0], EdgeInfo [from=D, to=B, weight=1.0], EdgeInfo [from=B, to=C, weight=3.0]]]
 D - PathInfo [weight=-3.0, edgeInfos=[EdgeInfo [from=E, to=D, weight=-3.0]]]

 C++
 E______________________________________________________
 B - PathInfo [weight = -2,edgeInfos = [EdgeInfo [from = D to =B weight = 1],EdgeInfo [from = E to =D weight = -3]]]
 C - PathInfo [weight = 1,edgeInfos = [EdgeInfo [from = B to =C weight = 3],EdgeInfo [from = D to =B weight = 1],EdgeInfo [from = E to =D weight = -3]]]
 D - PathInfo [weight = -3,edgeInfos = [EdgeInfo [from = E to =D weight = -3]]]
 D______________________________________________________
 E - PathInfo [weight = 3,edgeInfos = [EdgeInfo [from = B to =E weight = 2],EdgeInfo [from = D to =B weight = 1]]]
 C - PathInfo [weight = 4,edgeInfos = [EdgeInfo [from = B to =C weight = 3],EdgeInfo [from = D to =B weight = 1]]]
 B - PathInfo [weight = 1,edgeInfos = [EdgeInfo [from = D to =B weight = 1]]]
 B______________________________________________________
 E - PathInfo [weight = 2,edgeInfos = [EdgeInfo [from = B to =E weight = 2]]]
 D - PathInfo [weight = -1,edgeInfos = [EdgeInfo [from = B to =E weight = 2],EdgeInfo [from = E to =D weight = -3]]]
 C - PathInfo [weight = 3,edgeInfos = [EdgeInfo [from = B to =C weight = 3]]]
 A______________________________________________________
 D - PathInfo [weight = -2,edgeInfos = [EdgeInfo [from = A to =B weight = -1],EdgeInfo [from = B to =E weight = 2],EdgeInfo [from = E to =D weight = -3]]]
 E - PathInfo [weight = 1,edgeInfos = [EdgeInfo [from = A to =B weight = -1],EdgeInfo [from = B to =E weight = 2]]]
 B - PathInfo [weight = -1,edgeInfos = [EdgeInfo [from = A to =B weight = -1]]]
 C - PathInfo [weight = 2,edgeInfos = [EdgeInfo [from = A to =B weight = -1],EdgeInfo [from = B to =C weight = 3]]]
 */

int main(int argc, const char * argv[]) {

//    test();
//    test1();
//    testBfs();
//    testDfs();
//    testMst();
//    testMst1();
//    testMst3();
    testMultiSp();
    return 0;
}
