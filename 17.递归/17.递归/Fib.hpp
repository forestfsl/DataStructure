//
//  Fib.hpp
//  17.递归
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef Fib_hpp
#define Fib_hpp

#include <stdio.h>

/*
 斐波那契数列：1，1，2，3，5，8，13，21，34，...
 F(1) = 1,F(2) = 1,F(n) = F(n-1) + F(n-2) (n 大于等于3)
 编写第一个函数n项 斐波那契数列
 int fib(int n) {
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);
 }
 根据递推式T(n) = T(n-1) + T(n-2) + O(1),可得知时间复杂度:O(2^n)
 空间复杂度:O(n)
 递归调用的空间复杂度 = 递归深度 * 每次调用所需的辅助空间
 可以看到特别多的重复计算，这是一种自顶向下的调用过程
 */

class Fib{
public:
    int n = 64;
    /*
     fib优化1--记忆化
     用数组存放过计算的结果，避免重复计算
     时间复杂度:O(n)
     空间复杂度:O(n)
     */
    int fib1(int n){
        if (n <= 2) return 1;
        int *array = new int[n + 1]{};
        array[2] = array[1] = 1;
        return fib1(array,n);
    }
    
    int fib1(int *array,int n){
        if (array[n] == 0){
            array[n] = fib1(array,n - 1) + fib1(array,n - 2);
        }
        return array[n];
    }
    
    /*
     fib优化2--去除递归调用
     时间复杂度:O(n)
     空间复杂度:O(n)
     */
    int fib2(int n){
        if (n <= 2) return 1;
        int *array = new int[n + 1]{};
        array[2] = array[1] = 1;
        for (int i = 3; i <= n; i++) {
            array[i] = array[i - 1] + array[i - 2];
        }
        return array[n];
    }
    
    /*
     fib优化3--使用数组中的2个元素，所以可以使用滚动数组来优化
     时间复杂度:O(n),空间复杂度:O(1)
     */
    int fib3(int n){
        if (n <= 2) return 1;
        int *array = new int[2]{};
        array[0] = array[1] = 1;
        for (int i = 3; i <= n; i++) {
            array[i % 2] = array[(i-1) % 2] + array[(i - 2) % 2];
        }
        return array[n % 2];
    }
    /*
     fib优化4-位运算取代模运算
     乘除摸运算效率低，建议用其他方式取代
     */
    int fib4(int n){
        if (n <= 2) return 1;
        int *array = new int[2];
        array[0] = array[1] = 1;
        for (int i = 3; i <= n; i++) {
            array[i & 1] = array[(i - 1) & 1] + array[(i - 2 ) & 1];
        }
        return array[n & 1];
    }
    
    /*
     fib 优化5
     */
    int fib5(int n){
        if (n <= 2) return 1;
        int first = 1;
        int second = 1;
        for (int i = 3; i <= n; i++) {
            second = first + second;
            first = second - first;
        }
        return second;
    }
   
   
    //尾递归示例--斐波那契数列
    int fib6(int n){
        if (n <= 2) return 1;
        return fib6(n - 1) + fib6(n - 2);
    }
    
    int fib7(int n){
        return fib7(n,1,1);
    }
    int fib7(int n,int first,int second){
        if (n <= 1) return first;
        return fib7(n - 1,second, first + second);
    }
    

};

#endif /* Fib_hpp */
