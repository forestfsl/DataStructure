//
//  Divide.hpp
//  21.分治
//
//  Created by fengsl on 2020/1/27.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef Divide_hpp
#define Divide_hpp

#include <stdio.h>
using namespace std;


/*
 求解[begin,end)中最大连续子序列的和
 */

class Divide{
public:
    void testDivide(){
         int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4 };
        cout << maxSubArray(nums, 0, 9) << endl;
    }
    
    void testDivide1(){
        int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4 };
        cout << maxSubarray1(nums,9, 0,9) << endl;
    }
    
    void testDivide2(){
        int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4 };
        cout << maxSubarray2(nums,9, 0,9) << endl;
    }
    
    /*
     假设[begin,end)的最大连续子序列和是S[i,j),那么它有3中可能
     [i,j)存在于[begin,mid)中，同时S[i,j)也是[begin,mid)的最大连续子序列和
     [i,j)存在于[mid,end)中，同时S[i,j)也是[mid,end)的最大连续子序列和
     [i,j)一部分存在于[begin,mid)中，另一部分存在于[mid,end)中
     */
    int maxSubArray(int *nums,int begin,int end){
        //如果只有1个数，那当前的数目就是最大的连续子序列和
        if (end - begin < 2) return nums[begin];
        //求出中间值
        int mid = (begin + end) >> 1;
        int leftMax = nums[mid - 1];
        int leftSum = leftMax;
        for (int i = mid - 2; i >= begin; i--) {
            leftSum += nums[i];
            leftMax = max(leftMax,leftSum);
        }
        int rightMax = nums[mid];
        int rightSum = rightMax;
        for (int i = mid + 1; i < end; i++) {
            rightSum += nums[i];
            rightMax = max(rightMax,rightSum);
        }
        return max(leftMax + rightMax,max(maxSubArray(nums, begin, mid),maxSubArray(nums, mid, end)));
        
    }
    
    /*
     暴力破解-优化
     */
    int maxSubarray2(int *nums,int len,int begin,int end){
        if (nums == nullptr || len == 0) return 0;
        int maxValue = INT_MIN;
        for (int begin = 0; begin < len; begin++) {
            int sum = 0;
            for (int end = begin; end < len; end++) {
                //sum 是[begin,end]的和
                sum += nums[end];
                maxValue = max(maxValue,sum);
            }
        }
        return maxValue;
    }
    
    /*
     暴力破解
     */
    int maxSubarray1(int *nums,int len,int begin,int end){
        if (nums == nullptr || len == 0) return 0;
        int maxValue = INT_MIN;
        for (int begin = 0; begin < len; begin++) {
            for (int end = begin; end < len; end++) {
                //sum 是[begin,end]的和
                int sum = 0;
                for (int i = begin; i <= end; i++) {
                    sum += nums[i];
                }
                maxValue = max(maxValue,sum);
            }
        }
        return maxValue;
    }

  
    
};

#endif /* Divide_hpp */
