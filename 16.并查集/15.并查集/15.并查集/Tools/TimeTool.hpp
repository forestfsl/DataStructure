//
//  TimeTool.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef TimeTool_hpp
#define TimeTool_hpp

#include <stdio.h>
#include <chrono>
#include "UnionFind.hpp"
#include <iostream>
#include<sys/timeb.h>
#include <time.h>

using namespace std;


class TimeTool{
public:
   static long long systemtime()
    {
        timeb t;
        ftime(&t);
        return t.time*1000+t.millitm;
    }
    typedef void(*ExcuteFunction)(UnionFind *uf);

    static void spanTime(ExcuteFunction localExcute,string title,UnionFind *uf){
//        auto beginTime = std::chrono::high_resolution_clock::now();
//       
//       if (localExcute) {
//           localExcute(uf);
//       }
//      auto endTime = std::chrono::high_resolution_clock::now();
//       
//      auto elapsedTime= std::chrono::duration_cast<std::chrono::seconds>(endTime - beginTime);
//      std::cout << "title:"<<title<<"---" <<"elapsed time is " << elapsedTime.count() << " second" << std::endl;
//      std::cin.get();
   
         //time3
        long long start = systemtime();
        if (localExcute) {
            localExcute(uf);
        }
     
        long long end = systemtime();
        
        cout << "title:"<<title<<"---" <<"elapsed time is " << (end - start) / 1000.0 << " ms" << endl;
             

   }
    static void checkTime(string title,ExcuteFunction excute,UnionFind *uf){
        spanTime(excute,title,uf);
    }
};

#endif /* TimeTool_hpp */
