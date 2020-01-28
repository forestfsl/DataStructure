//
//  main.cpp
//  23.动态规划
//
//  Created by fengsl on 2020/1/28.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#include <iostream>
#include "MaxSubArray.hpp"
#include "CoinChange.hpp"
#include "LIS.hpp"
using namespace std;

/*
 动态规划(Dunimic Programming),简称DP，是去求解最优化问题的一种常用策略
 动态规划的常规步骤
 动态规划中的动态可以理解为是"会变化的状态"
 
 - 1. 定义状态（状态是原问题，子问题的解）
    - 比如定义dp(i)的含义
 - 2. 设置初始状态(边界)
    - 比如设置dp(0)的值
 - 3.确定状态转移方程
    - 比如确定dp(i)和dp(i-1)的关系
 
 
 - 无后效性
    - 推导dp(i,j)时只需要用到dp(i,j-1),dp(i-1,j)的值
    - 不需要关心dp(i,j-1),dp(i-1,j)的值是怎么求出来的
 
 - 有后效性
    - dp(i,j) 下一步要怎么走，还要关心上一步是怎么来的
    - 也就是还是要关心dp(i,j-1),dp(i-1,j)是怎么来的
 */


void testMaxSubArray(){
    MaxSubArray maxSubArray = MaxSubArray();
    cout << maxSubArray.testMaxSubArray() << endl;
}

void testCoinChange(){
    CoinChange coinChange = CoinChange();
//    cout << coinChange.coins1(41) << endl;
//    cout << coinChange.coins2(41) << endl;
//    cout << coinChange.coins3(41) << endl;
//    cout << coinChange.coins4(41) << endl;
    cout << coinChange.coins5(41) << endl;
}


void testLIS(){
    LIS lis = LIS();
    cout << lis.lengthOfLIS1() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    testMaxSubArray();
//    testCoinChange();
    testLIS();
    return 0;
}
