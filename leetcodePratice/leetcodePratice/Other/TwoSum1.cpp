//
//  TwoSum1.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/24.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "TwoSum1.hpp"
#include <unordered_map>

//时间复杂度是O(n),leetcode 上面需要8ms
vector<int> Solution1::twoSum1(vector<int> &nums, int target){
    unordered_map<int,int>record;
     int length = (int)nums.size();
    for (int i = 0; i < length; i++) {
        int complement = target - nums[i];
        if (record.find(complement) != record.end()) {
            return {record[complement],i};
        }
        record[nums[i]] = i;
    }
    return {-1,-1};
}
//暴力破解 时间复杂度是O(n^2),leetcode 上面需要400ms
vector<int> Solution1::twoSum(vector<int> &nums, int target){
    vector<int> result;
    int length = (int)nums.size();
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
            }
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return result;
}

void Solution1::test1(){
    Solution1 solution = Solution1();
    vector<int>nums = {2,7,11,15};
    solution.twoSum1(nums, 9);
    
}
