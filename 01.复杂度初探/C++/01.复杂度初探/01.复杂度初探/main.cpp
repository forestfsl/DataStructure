//
//  main.cpp
//  01.复杂度初探
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "TimeTool.hpp"
using namespace std;


//定义全局方法
//算法复杂度O(2^n)
int fib1(int n){
    if (n <= 1) {
        return n;
    }
    return fib1(n - 1) + fib1(n - 2);
}

//算法复杂度O(n)
int fib2(int n){
    if (n <= 1) {
        return n;
    }
    int first = 0;
    int second = 1;
    for (int i = 0; i < n - 1; i++) {
        int sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}

//算法复杂度O(n)
int fib3(int n){
    if (n <= 1) {
        return n;
    }
    int first = 0;
    int second = 1;
    while (n-- > 1) {
        second = first + second;
        first = second - first;
    }
    return second;
}

void test1(int n){
    //1
    if (n > 10) {
        cout << "n > 10" << endl;
    }else if (n > 5){
        cout << "n > 5" << endl;
    }
    
    // 1 + 4 + 4 + 4
    for (int i = 0; i < 4; i++) {
        cout<<"test"<<endl;
    }
}

void test2(int n) {
    // O(n)
    // 1 + 3n
    for (int i = 0; i < n; i++) {
        cout<<"test"<<endl;
    }
}

void test3(int n) {
    // 1 + 2n + n * (1 + 3n)
    // 1 + 2n + n + 3n^2
    // 3n^2 + 3n + 1
    // O(n^2)
    
    // O(n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<"test"<<endl;
        }
    }
}

void test4(int n) {
    // 1 + 2n + n * (1 + 45)
    // 1 + 2n + 46n
    // 48n + 1
    // O(n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 15; j++) {
            cout<<"test"<<endl;
        }
    }
}

void test5(int n) {
    // 8 = 2^3
    // 16 = 2^4
    
    // 3 = log2(8)
    // 4 = log2(16)
    
    // 执行次数 = log2(n)
    // O(logn)
    while ((n = n / 2) > 0) {
        cout<<"test"<<endl;
    }
}

void test6(int n) {
    // log5(n)
    // O(logn)
    while ((n = n / 5) > 0) {
        cout<<"test"<<endl;
    }
}

void test7(int n) {
    // 1 + 2*log2(n) + log2(n) * (1 + 3n)
    
    // 1 + 3*log2(n) + 2 * nlog2(n)
    // O(nlogn)
    for (int i = 1; i < n; i = i * 2) {
        // 1 + 3n
        for (int j = 0; j < n; j++) {
            cout<<"test"<<endl;
        }
    }
}

void test10(int n) {
    // O(n)
    int a = 10;
    int b = 20;
    int c = a + b;
    //定义一个int [] 数组 初始化每个元素为0
    int *array = new int[n]{0};
    for (int i = 0; i <n; i++) {
        cout<<array[i]+c<<endl;
    }
    //这里和java，OC为什么会不一样d，是因为他们一个有ARC，一个有GC
    delete [] array;
}



int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    int n = 64;
    //这里的[](int n){}是一个lamba表达式
//    TimeTool::task("fib1", n, [](int n){
//        std::cout << fib1(n) << std::endl;
//    });
    TimeTool::task("fib2", n, [](int n){
        std::cout << fib2(n) << std::endl;
    });
    //用block
    TimeTool::check("fib3", n, ^(int n) {
        std::cout << fib3(n) << std::endl;
    });
    
    /*
     * 终端打印结果：
     fib1
     开始计算:2019-04-17 11:52:55
     1640636603
     结束时间2019-04-17 12:05:55 这个时间不定，有可能半天都出不来，更加说明这种计算方式效率是低到要命
     fib2
     开始计算:2019-04-17 12:05:55
     1640636603
     结束时间2019-04-17 12:05:55
     耗时:0秒
     fib3
     开始计算:
     1640636603
     结束时间
     耗时:0秒
     Program ended with exit code: 0
     */
    return 0;
}
