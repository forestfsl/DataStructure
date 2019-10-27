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

//这种方法leetcode上面直接爆出超出时间限制 从前往后偷
// 时间复杂度是O(2^n),空间复杂度是O(n)
int robSum(vector<int> &nums,int begin){
    if (begin == nums.size() - 1) return nums[nums.size() - 1];
    if (begin == nums.size() - 2) return max(nums[nums.size() - 1],nums[nums.size() - 2]);
    int sum0 = nums[begin] + robSum(nums, begin + 2);
    int sum1 = robSum(nums, begin + 1);
    return max(sum0,sum1);
}
//从后往前偷 一样会超出时间限制
/*
 同样都会超时时间限制，是因为不断都有重复的操作
 从6开始
 nums[6] --> nums[4],从6开始首先要计算4
 nums[5] ---> nums[3],从5开始首先要计算3
 nums[4] --> nums[2],从4开始首先要计算2
 nums[2] ---> nums[0];从2开始首先要计算0
 nums[3] ---> nums[1],从3开始首先要计算1
 
 从5开始
 nums[5] ---> nums[3]
 nums[4] -->
 .....
 .....
 可以发现这些多了很多重复的操作，针对这种情况，我们可以采取缓存的方式来优化，就是使用缓存方式来缓存
 计算的值，例如nums[0],nums[1],nums[2],nums[3]....nums[6]....nums[nums.size()-1];
 
 时间复杂度是O(2^n),空间复杂度是O(n)
 */
int robSum2(vector<int> &nums,int begin){
    if (begin == 0) return nums[0];
    if (begin == 1) return max(nums[0],nums[1]);
    int sum0 = nums[begin] + robSum2(nums, begin - 2);
    int sum1 = robSum2(nums,begin - 1);
    return max(sum0,sum1);
}

// 时间复杂度是O(n),空间复杂度是O(n)
int robSum3(vector<int> &nums,int begin) {
     vector<int> caches;
    if (nums.size() > 1) {
        caches.push_back(nums[0]);
        caches.push_back(max(nums[0],nums[1]));
        for (int i = 2; i < nums.size(); i++) {
            //sum0 = nums[6] + nums[4]
            //sum1 = nums[4] + nums[2]
            //sum3 = nums[2] + nums[0];
            //sum4 = nums[0];
            caches.push_back(max(nums[i] + caches[i-2],caches[i-1]));
        }
    }else{
        return nums[0];
    }
   
    return caches[caches.size() - 1];
}

// 时间复杂度是O(n),空间复杂度是O(1)
int robSum4(vector<int> &nums,int begin) {
        int prev = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = cur;
            cur = max(nums[i] + prev,cur);
            prev = tmp;
        }
    return cur;
}


int Solution198::rob(vector<int> &nums){
    if (nums.size() == 0) return 0;
    
//    return robSum(nums, 0);
    return robSum3(nums, int(nums.size() - 1));
}



void Solution198::test198(){
    Solution198 solution = Solution198();
    vector<int> nums = {1,2,3,1};
    cout << "打家劫舍最大值" << solution.rob(nums) << endl;
}
