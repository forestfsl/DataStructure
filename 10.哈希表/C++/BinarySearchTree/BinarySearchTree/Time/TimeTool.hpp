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
#include <iostream>
using namespace std;


class TimeTool{
public:
    typedef void(*ExcuteFunction)(void);
 
    static void spanTime(ExcuteFunction localExcute,string title){
        auto beginTime = std::chrono::high_resolution_clock::now();
       
       if (localExcute) {
           localExcute();
       }
      auto endTime = std::chrono::high_resolution_clock::now();
       
      auto elapsedTime= std::chrono::duration_cast<std::chrono::seconds>(endTime - beginTime);
      std::cout << "title:"<<title<<"---" <<"elapsed time is " << elapsedTime.count() << " second" << std::endl;
      std::cin.get();
   
//       return elapsedTime.count();

   }
    static void checkTime(string title,ExcuteFunction excute){
        spanTime(excute,title);
    }
};

#endif /* TimeTool_hpp */
