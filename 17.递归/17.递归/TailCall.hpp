//
//  TailCall.hpp
//  17.递归
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef TailCall_hpp
#define TailCall_hpp

#include <stdio.h>


/*
 尾调用(Tail Call):一个函数的最后一个动作是调用函数
 如果最后一个动作是调用自身，称为尾递归(Tail Recursion),是尾调用的特殊情况
 
 可以通过编译器开启是否需要启动尾部优化，然后可以查看尾部调用优化后的汇编代码和没有优化过的汇编代码分别是啥
 */
class TailCall{
    //例子1是尾部调用
    void test1(){
        int a = 10;
        int b = a + 20;
        test2(b);
    }
    void test2(int n){
        if (n < 0) return;
        test2(n - 1);
    }
    
    //例子2不是尾部调用,因为最后一个动作是乘法
    int factorial(int n){
        if (n <= 1) return n;
        return n * factorial(n - 1);
    }
    //下面将这些转换为尾调用
    int facttorial(int n){
        return facttorial(n,1);
    }
    int facttorial(int n,int result){
        if (n <= 1) return result;
        return facttorial(n - 1, result * n);
    }
};

#endif /* TailCall_hpp */
