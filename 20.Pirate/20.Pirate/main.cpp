//
//  main.cpp
//  20.Pirate
//
//  Created by fengsl on 2020/1/27.
//  Copyright © 2020 NeonChange. All rights reserved.
//

/*
 贪心策略，也称为贪婪策略
 每一步都采取当前状态下的最优的选择(局部最优解)，从而导出全局最优解
 */

#include <iostream>
#include "Pirate.hpp"
#include "CoinChange.hpp"
#include "Knapsack.hpp"
using namespace std;

/*
 2
 3
 4
 5
 7
 一共选了5件古董
 */
void test1(){
    Pirate pirate = Pirate();
    pirate.testPirate();
}

/*
 25
 10
 5
 1
 4
 */
void testCoinChange1(){
    CoinChange coinChange = CoinChange();
    int *faces = new int[4]{25,10,5,1};
    coinChange.coinChange(faces, 4, 41);
}

/*
 25
 10
 5
 1
 一共需要4枚硬币
 */
void testCoinChange2(){
    CoinChange coinChange = CoinChange();
    int *faces = new int[4]{25,10,5,1};
    coinChange.coinChange2(faces, 4, 41);
}

/*
 25
 10
 5
 1
 一共需要4枚硬币
 */
void testCoinChange3(){
    CoinChange coinChange = CoinChange();
    int *faces = new int[4]{25,10,5,1};
    coinChange.coinChange3(faces, 4, 41);
}
void testKnapsack(){
    Knapsack knapstack = Knapsack();
    knapstack.testSelect1();
}

int main(int argc, const char * argv[]) {
//    test1();
//    testCoinChange1();
//    testCoinChange2();
//    testCoinChange3();
    testKnapsack();
    return 0;
}
