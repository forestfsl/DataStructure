//
//  main.cpp
//  16.Graph
//
//  Created by songlin on 2020/1/7.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#include <iostream>
#include "ListGraph.hpp"

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
int main(int argc, const char * argv[]) {

//    test();
    test1();
    return 0;
}
