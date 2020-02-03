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
    
    /*
     牌顶
     把每个数字看做是一张扑克牌，从左到右按顺序处理每一个扑克牌
     将它压在（从左边数过来），第一个牌顶大于等于它的牌堆上面
     如果找不到牌顶大于等于它的牌堆，将它翻入这个新牌堆中
     */
    int lengthOfLIS2(){
        int nums[] = {10, 2, 2, 5, 1, 7, 101, 18};
        int numLen = sizeof(nums) / sizeof(nums[0]);
        //牌堆的数量
        int len = 0;
        //牌顶数组
        int *top = new int[numLen]{0};
        //遍历所有的牌
        for (int i = 0; i < numLen; i++) {
            int j = 0;
            while (j < len) {
                //找到第一个大于等于num的牌顶
                if (top[j] >= nums[i]) {
                    top[j] = nums[i];
                    break;
                }
                //牌顶 < num
                j++;
            }
            if (j == len) {//新建一个牌堆
                len++;
                top[j] = nums[i];
            }
        }
        return len;
    }
    
    /*
      牌顶 最长上升子序列-二分搜索-思路 空间复杂度:O(n),时间复杂度:O(nlogn)
     */
    int lengthOfLIS3(){
        int nums[] = {10, 2, 2, 5, 1, 7, 101, 18};
        int numLen = sizeof(nums) / sizeof(nums[0]);
        int len = 0; //len 作为牌堆的数量
        //牌堆的数量
        int *top = new int[numLen]{0};
        for (int i = 0; i < numLen; i++) {
            int begin = 0;
            int end = len;
            while (begin < end) {
                int mid = (begin + end) >> 1;
                if (nums[i] <= top[mid]) {
                    end = mid;
                }else{
                    begin = mid + 1;
                }
            }
            //返回索引插入
            //覆盖牌顶
            top[begin] = nums[i];
            //检查是否要新建一个牌堆
            if (begin == len) len++;
        }
        return len;
    }
};

#endif /* LIS_hpp */
