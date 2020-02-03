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
#include "LCS.hpp"
#include "Knapsack.hpp"
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

void testLIS2(){
    LIS lis = LIS();
    cout << lis.lengthOfLIS2() << endl;
}

void testLIS3(){
    LIS lis = LIS();
    cout << lis.lengthOfLIS3() << endl;
    
}

void testLCS(){
    LCS lcs = LCS();
    int nums1[] = {1, 3, 5, 9,10};
    int nums1Len = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {1,4,9,10};
    int nums2Len = sizeof(nums2) / sizeof(nums2[0]);
    cout << lcs.lcs1(nums1, nums1Len, nums2, nums2Len) << endl;
}

void testLCS2(){
    LCS lcs = LCS();
    int nums1[] = {1, 3, 5, 9,10};
    int nums1Len = sizeof(nums1) / sizeof(nums1[0]);
  
    int nums2[] = {1,4,9,10};
      int nums2Len = sizeof(nums2) / sizeof(nums2[0]);

    cout << lcs.lcs2(nums1,nums1Len + 1, nums2,nums2Len + 1) << endl;
}

void testLCS3(){
    LCS lcs = LCS();
    int nums1[] = {1, 3, 5, 9,10};
    int nums1Len = sizeof(nums1) / sizeof(nums1[0]);
  
    int nums2[] = {1,4,9,10};
      int nums2Len = sizeof(nums2) / sizeof(nums2[0]);

    cout << lcs.lcs3(nums1,nums1Len + 1, nums2,nums2Len + 1) << endl;
}

void testLCS4(){
    LCS lcs = LCS();
    int nums1[] = {1, 3, 5, 9,10};
    int nums1Len = sizeof(nums1) / sizeof(nums1[0]);
  
    int nums2[] = {1,4,9,10};
      int nums2Len = sizeof(nums2) / sizeof(nums2[0]);

    cout << lcs.lcs4(nums1,nums1Len + 1, nums2,nums2Len + 1) << endl;
}

void testlongestCommonSubsequence(){
    LCS lcs = LCS();
    cout << lcs.longestCommonSubsequence() << endl;
}

void testlongestCommonSubsequence1(){
    LCS lcs = LCS();
    cout << lcs.longestCommonSubsequence1() << endl;
}

void testMaxValue1(){
    int value[] = {6,3,5,4,6};
    int weight[] = {2,2,6,5,4};
    int valueLen = sizeof(value)/sizeof(value[0]) + 1;
    int weightLen = sizeof(weight)/sizeof(weight[0]) + 1;
    int capacity = 10;//代表有10件物品
    Knapsack knapsack = Knapsack();
    cout << knapsack.maxValue1(value, weight, capacity, valueLen, weightLen) << endl;
}

void testMaxValue2(){
    int value[] = {6,3,5,4,6};
    int weight[] = {2,2,6,5,4};
    int valueLen = sizeof(value)/sizeof(value[0]) + 1;
    int weightLen = sizeof(weight)/sizeof(weight[0]) + 1;
    int capacity = 10;//代表有10件物品
    Knapsack knapsack = Knapsack();
    cout << knapsack.maxValue2(value, weight, capacity, valueLen, weightLen) << endl;
}

void testMaxValue3(){
    int value[] = {6,3,5,4,6};
    int weight[] = {2,2,6,5,4};
    int valueLen = sizeof(value)/sizeof(value[0]) + 1;
    int weightLen = sizeof(weight)/sizeof(weight[0]) + 1;
    int capacity = 10;//代表有10件物品
    Knapsack knapsack = Knapsack();
    cout << knapsack.maxValue3(value, weight, capacity, valueLen, weightLen) << endl;
}


void testmaxValueExactly(){
    int value[] = {6,3,5,4,6};
    int weight[] = {2,2,6,5,4};
    int valueLen = sizeof(value)/sizeof(value[0]) + 1;
    int weightLen = sizeof(weight)/sizeof(weight[0]) + 1;
    int capacity = 10;//代表有10件物品
    Knapsack knapsack = Knapsack();
    cout << knapsack.maxValueExactly(value, weight, capacity, valueLen, weightLen) << endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    testMaxSubArray();
//    testCoinChange();
//    testLIS();
//    testLIS2();
//    testLIS3();
//    testLCS();
//    testLCS2();
//    testLCS3();
//    testLCS4();
//    testlongestCommonSubsequence();
//    testlongestCommonSubsequence1();
    testMaxValue1();
    testMaxValue2();
    testMaxValue3();
    testmaxValueExactly();
    return 0;
}
