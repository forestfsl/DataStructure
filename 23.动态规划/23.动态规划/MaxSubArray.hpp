//
//  MaxSubArray.hpp
//  23.动态规划
//
//  Created by fengsl on 2020/1/28.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef MaxSubArray_hpp
#define MaxSubArray_hpp

#include <stdio.h>
using namespace std;

class MaxSubArray{
public:
    int testMaxSubArray(){
        int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int len = 9;
        int dp = nums[0];
        int maxValue = dp;
        for (int i = 1; i < len; i++) {
            if (dp <= 0) {
                dp = nums[i];
            }else{
                dp = dp + nums[i];
            }
            maxValue = max(dp,maxValue);
        }
        return maxValue;
    }
};

#endif /* MaxSubArray_hpp */
