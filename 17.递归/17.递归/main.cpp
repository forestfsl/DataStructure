//
//  main.cpp
//  17.递归
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//
/*
 递归：函数(方法)直接或间接调用自身，是一种常用的编程技巧
 如果递归调用没有终止，将会一直消耗栈空间，最终导致栈内存溢出(Stack Overflow)
 所以必需要有一个明确的结束递归的条件，也叫做边界条件，递归基
 注意：使用递归不是为了求得最优解，是为了简化解决问题的思路，代码会更加简洁，递归求出来的很有可能不是最优解，也有可能是最最优解
 
 递归的基本思想：
 拆解问题
 - 把规模大的问题变成规模较小的同类型问题，规模较小的问题又不断变成规模更小的问题，规模小到一定程度可以直接得出它的解
 */
#include <iostream>
#include "Fib.hpp"
#include "TimeTool.hpp"
#include "ClimbStairs.hpp"
#include "Hanoi.hpp"
#include "Hanoi.hpp"
#include "TailCall.hpp"
using namespace std;



#pragma mark 递归转非递归
/*
 递归调用过程中，会将每一次调用的参数，局部变量都保存在了对应的栈帧中(stack frame)中
 t若递归调用深度比较大，会占用比较多的栈空间，甚至会栈溢出，在有些时候，递归会存在大量的重复计算，性能非常差
 这时可以考虑将递归转化为非递归(递归100%可以转化成非递归)
 做法：自己维护一个栈，来保存参数，局部变量，但是空间复杂度依然w没有得到优化
 */


void log(int n){
    if (n < 1) return;
    log(n - 1);
    int v = n + 10;
    cout << v << endl;
}

void testLog(){
    log(4);
}

//这里重复使用变量i保存原来栈帧中的参数，空间复杂度从O(n) 降到了O(1)
void logNonRecursive(int n){
    for (int i = 1; i <= n; i++) {
        cout << (i + 10) << endl;
        
    }
}
/*
 1 + 2 + 3 +.... + (n-1) + n (n > 0)
 总消耗时间T(n) = T(n-1) + O(1),因此时间复杂度:O(n),空间复杂度:O(n);
 */
int sum(int n){
    if (n <= 1) return n;
    return n + sum(n - 1);
}


void testFib(){
    int n = 10;
       TimeTool::task("fib1", n, [](int n){
           Fib fib = Fib();
           std::cout << fib.fib1(n) << std::endl;
         });
       TimeTool::task("fib2", n, [](int n){
             Fib fib = Fib();
             std::cout << fib.fib2(n) << std::endl;
           });
}


void testClimbStairs(){
    int n = 3;
    ClimbStairs climbStairs = ClimbStairs();
    cout << "一共有" << climbStairs.climbStairs(n) << "种手法" << endl;
}


void testHanoi(){
    int n = 10;
    Hanoi haoni = Hanoi();
    haoni.hanoi(n, "A", "B", "C");
}

int main(int argc, const char * argv[]) {
//    testClimbStairs();
    testHanoi();
    return 0;
}
