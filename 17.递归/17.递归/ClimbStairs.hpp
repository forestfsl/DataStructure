//
//  ClimbStairs.hpp
//  17.递归
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef ClimbStairs_hpp
#define ClimbStairs_hpp

#include <stdio.h>

/*
 练习2-上楼梯(跳台阶)
 楼梯有n阶台阶，上楼可以一步上1阶，也可以一步上2阶，走完n台阶共有多少种不同的走法?
 - 假设n阶台阶有f(n)种走法，第一步有2种走法
    - 如果上1阶，那就还剩n - 1阶，共f(n-1)种走法
    - 如果上2阶，那就还剩n - 2阶，共f(n-2)种走法
 所以f(n) = f(n-1) + f(n-2)
 */

class ClimbStairs{
public:
    int climbStairs(int n){
        if (n <= 2) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    
    /*
     优化思路和斐波那契数列几乎一样，因此优化思路也是一致的
     */
    int climbStaris1(int n){
        if (n <= 2) return n;
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            second = first + second;
            first = second - first;
        }
        return second;
    }
};

#endif /* ClimbStairs_hpp */
