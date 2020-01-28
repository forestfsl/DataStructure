//
//  LIS.hpp
//  23.动态规划
//
//  Created by fengsl on 2020/1/28.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef LIS_hpp
#define LIS_hpp

#include <stdio.h>

class LIS{
public:
    /*
     动态规划 dp(i)是存放着以nums[i]结尾的最长上升子序列的长度,i属于[0,nums.length)
     */
    int lengthOfLIS1(){
        int nums[] = {10, 2, 2, 5, 1, 7, 101, 18};
        int len = sizeof(nums) / sizeof(nums[0]);
        int *dp = new int[len]{0};
        int maxValue = dp[0] = 1;
        for (int i = 1; i < len; i++) {
            //首先赋值所有的长度都是1
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;//如果后面的小于前面的则continue
                dp[i] = max(dp[i],dp[j] + 1);
            }
            maxValue = max(dp[i],maxValue);
        }
        return maxValue;
    }
};

#endif /* LIS_hpp */
