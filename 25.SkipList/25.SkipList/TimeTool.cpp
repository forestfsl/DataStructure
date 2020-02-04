//
//  TimeTool.cpp
//  01.复杂度初探
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "TimeTool.hpp"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

std::string getTime()
 {
     time_t timep;
     time (&timep);
     char tmp[64];
     strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
     return tmp;
}


void TimeTool::task2(const char *title,FuncVoid func){
    //优化一下，如果func为nil或者n不大于0，则没有必要往下执行
    if (func == nullptr) {
        printf("方法体为空或者n不大于0");
        return;
    }
    std::cout<< title << std::endl;
    std::cout<< "开始计算:"<<  getTime() << std::endl;
    //获取开始时间
    clock_t beginTime = clock();
    //调用函数
    (*func)();
    //获取结束时间
    clock_t endTime = clock();
    std::cout << "结束时间" <<  getTime()<< std::endl;
    double delta = (endTime - beginTime)/CLOCKS_PER_SEC;
    std::cout << "耗时:" << delta << "秒" << std::endl;
}

//方法实现，前面TimeTool::是C++的语法
void TimeTool::task(const char *title,int n,Func func){
    //优化一下，如果func为nil或者n不大于0，则没有必要往下执行
    if (func == nullptr || !(n > 0)) {
        printf("方法体为空或者n不大于0");
        return;
    }
    std::cout<< title << std::endl;
    std::cout<< "开始计算:"<<  getTime() << std::endl;
    //获取开始时间
    clock_t beginTime = clock();
    //调用函数
    (*func)(n);
    //获取结束时间
    clock_t endTime = clock();
    std::cout << "结束时间" <<  getTime()<< std::endl;
    double delta = (endTime - beginTime)/CLOCKS_PER_SEC;
    std::cout << "耗时:" << delta << "秒" << std::endl;
}

void TimeTool::check(const char *title, int n, FuncBlock funcBlock){
    //优化一下，如果func为nil或者n不大于0，则没有必要往下执行
    if (funcBlock == nullptr || !(n > 0)) {
        printf("方法体为空或者n不大于0");
        return;
    }
    std::cout<< title << std::endl;
    std::cout<< "开始计算:" << std::endl;
    //获取开始时间
    clock_t beginTime = clock();
    //调用函数
   funcBlock(n);
    //获取结束时间
    clock_t endTime = clock();
    std::cout << "结束时间" << std::endl;
    double delta = (endTime - beginTime)/CLOCKS_PER_SEC;
    std::cout << "耗时:" << delta << "秒" << std::endl;
}
