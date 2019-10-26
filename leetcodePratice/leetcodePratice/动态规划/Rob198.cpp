//
//  Rob198.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/26.
//  Copyright © 2019 songlin. All rights reserved.
//


/*
 从0开始获取到的最大值，和不从0开始获取到的最大值
 */

#include "Rob198.hpp"

int robSum(vector<int> &nums,int begin){
    
    int sum0 = nums[begin] + robSum(nums, begin + 2);
    int sum1 = robSum(nums, begin + 1);
    return max(sum0,sum1);
}

int Solution198::rob(vector<int> &nums){
    if (nums.size()) return 0;
    
    return robSum(nums, 0);
}



void Solution198::test98(){
    Solution198 solution = Solution198();
    vector<int> nums = {1,2,3,1};
    cout << "打家劫舍最大值" << solution.rob(nums) << endl;
}
