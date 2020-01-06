//
//  TimeTool.hpp
//  01.复杂度初探
//  声明实现分离
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef TimeTool_hpp
#define TimeTool_hpp

#include <stdio.h>


//定义一个指向函数类型为void()(int n) 函数的指针
typedef void (*Func)(int n);

typedef void (*FuncVoid)(void);


typedef void(^FuncBlock)(int n);

class TimeTool {
    //实例变量可以在这里定义
    
public:
    //公共方法定义，在这里我定义一个C++类的静态方法
    static void task(const char *title,int n,Func func);
    
    static void task2(const char *title,FuncVoid func)
    
    static void check(const char * title,int n, FuncBlock funcBlock);
};

#endif /* TimeTool_hpp */
