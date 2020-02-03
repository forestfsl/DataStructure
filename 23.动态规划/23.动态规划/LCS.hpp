//
//  LCS.hpp
//  23.动态规划
//
//  Created by fengsl on 2020/2/1.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef LCS_hpp
#define LCS_hpp

#include <stdio.h>

/*
 最长公共子序列(Longest Common Subsequence,LCS)
 leetcode_1143_最长公共子序列
 求两个序列的最长公共子序列长度
 ABCBDAB和BDCABA的最长公共子序列长度是4，可能是BDAB，BDAB，BCAB，BCBA
 */
class LCS{
public:
    /*
     空间复杂度:O(k),k = min(n,m),n,m 是2个序列的长度
     时间复杂度:O(2^n),当n = m时
     
     最长公共子序列 - 递归实现
     假设2个序列分别是nums1,nums2
     i 属于[1,nums1.length]
     j 属于[1,nums2.length]
     假设dp(i,j) 是[nums1 前i个元素],与[nums2前j个元素]的最长公共子序列长度
     dp(i,0),dp(0,j)初始值均为0
     如果nums[i-1] = nums2[j-1],那么dp(i,j) = dp(i-1,j-1) + 1;
     如果nums1[i-1] != nums2[j-1],那么dp(i,j) = max{dp(i-1,j),dp(i,j-1)}
     */
    int lcs1(int *nums1,int i,int *nums2,int j){
        if (i == 0 || j == 0) return 0;
        if (nums1[i - 1] == nums2[j - 1]) {
            return lcs1(nums1, i - 1, nums2, j - 1) + 1;
        }
        return max(lcs1(nums1, i - 1, nums2, j),lcs1(nums1, i, nums2, j - 1));
    }

//    int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    /*
     最长公共子序列-非递归实现
     */
    int lcs2(int *nums1,int len1,int *nums2,int len2){
        int nums1Len = len1;
        int nums2Len = len2;
        if (nums1 == nullptr || nums1Len == 0) return 0;
        if(nums2 == nullptr || nums2Len == 0) return 0;
       
        int **dp; // array[M][N] 分配内存要比传入来的数组加1，是为了确保不被越界
        dp = (int **)malloc((nums1Len + 1) * sizeof(int *));
        for(int i = 0; i <= nums1Len; i++) {
            dp[i] = (int *)malloc((nums2Len + 1) * sizeof(int));
//            dp[i] = new int[N];
        }
       //输入二维数组的值
        for (int i = 0; i <= nums1Len;i++)
        {
            for (int j = 0; j <= nums2Len;j++)
            {
                dp[i][j] = 0;
            }
        }
        
        for (int i = 1; i <= nums1Len; i++) {
            for (int j = 1; j <= nums2Len; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] +1;
                }else{
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
        return dp[nums1Len][nums2Len];
    }
    
    /*
     最长公共子序列-非递归实现 滚动数组
     */
      int lcs3(int *nums1,int len1,int *nums2,int len2){
            int nums1Len = len1;
            int nums2Len = len2;
            if (nums1 == nullptr || nums1Len == 0) return 0;
            if(nums2 == nullptr || nums2Len == 0) return 0;
           
            int **dp; // array[M][N] 分配内存要比传入来的数组加1，是为了确保不被越界
            dp = (int **)malloc((nums1Len + 1) * sizeof(int *));
            for(int i = 0; i <= nums1Len; i++) {
                dp[i] = (int *)malloc((nums2Len + 1) * sizeof(int));
    //            dp[i] = new int[N];
            }
           //输入二维数组的值
            for (int i = 0; i <= nums1Len;i++)
            {
                for (int j = 0; j <= nums2Len;j++)
                {
                    dp[i][j] = 0;
                }
            }
            
          //通过两行来保存
            for (int i = 1; i <= nums1Len; i++) {
                int row = i & 1;//不是0就是1，相当于对2取模
                int prevRow = (i - 1) & 1;
                for (int j = 1; j <= nums2Len; j++) {
                    if (nums1[i - 1] == nums2[j - 1]) {
                        dp[row][j] = dp[prevRow][j - 1] +1;
                    }else{
                        dp[row][j] = max(dp[prevRow][j],dp[row][j - 1]);
                    }
                }
            }
            return dp[nums1Len & 1][nums2Len];
        }
    
    /*
     最长公共子序列-非递归实现-一维数组
     */
    int lcs4(int *nums1,int len1,int *nums2,int len2){
        if (nums1 == nullptr || len1 == 0) return 0;
        if (nums2 == nullptr || len2 == 0) return 0;
        int *dp = new int[len1]{0};
        for (int i = 1; i <= len1; i++) {
            int cur = 0;
            for (int j = 1; j <= len2; j++) {
                int leftTop = cur;
                cur = dp[j];
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = leftTop + 1;
                }else{
                    dp[j] = max(dp[j],dp[j-1]);
                }
            }
        }
        return dp[len2];
    }
    
    /*
     最长公共子串 - 思路 二维数组
     假设2个字符串分别是str1,str2
     i 属于[1,str1.length]
     j 属于[1,str2.length]
     
     假设dp(i,j)是以str1[i-1],str2[j-1]结尾的最长公共子串长度
     dp(j,0),dp(0,j) 初始值均为0
     如果str1[j-1] = str2[j-1],那么dp(i,j) = dp(i-1,j-1) + 1;
     如果str1[j-1] = str2[j-1],那么dp(i,j) = 0;
     最长公共子串的长度是所有dp(i,j)中的最大值max[dp(i,j)]
     
     空间复杂度 O(n + m)
     时间复杂度 O(n + m)
     */
    int longestCommonSubsequence(){
//        string chars1[] = {"1","2","3","5","9","10"};
//        string chars2[] = {"1","2","5","9"};
                int chars1[] = {1,2,3,5,9,10};
                int chars2[] = {1,2,3};
        int nums1Len = sizeof(chars1) / sizeof(chars1[0]) + 1;
        int nums2Len = sizeof(chars2) / sizeof(chars2[0]) + 1;
        int **dp; // array[M][N] 分配内存要比传入来的数组加1，是为了确保不被越界
          dp = (int **)malloc((nums1Len + 1) * sizeof(int *));
          for(int i = 0; i <= nums1Len; i++) {
              dp[i] = (int *)malloc((nums2Len + 1) * sizeof(int));
          }
         //输入二维数组的值
          for (int i = 0; i <= nums1Len;i++)
          {
              for (int j = 0; j <= nums2Len;j++)
              {
                  dp[i][j] = 0;
              }
          }
        int currentMax = 0;
        for (int i = 1; i <= nums1Len; i++) {
            for (int j = 1; j <= nums2Len; j++) {
                if(chars1[i - 1] != chars2[j - 1]) continue;
                dp[i][j] = dp[i - 1][j - 1] + 1;
                currentMax = max(currentMax,dp[i][j]);
            }
        }
        return currentMax;
    }
    
    /*
       最长公共子串 - 思路 二维数组
     */
    int longestCommonSubsequence1(){
       string chars1[] = {"1","2","3","5","9","10"};
       string chars2[] = {"1","2","5","9"};
       int nums1Len = sizeof(chars1) / sizeof(chars1[0]);
       int nums2Len = sizeof(chars2) / sizeof(chars2[0]);
        string *rowChars = chars1;
        string *colsChars = chars2;
        int rowLen = nums1Len;
        int colLen = nums2Len;
        
        if (nums1Len < nums2Len) {
            colsChars = chars1;
            rowChars = chars2;
            rowLen = nums2Len;
            colLen = nums1Len;
        }
        
        int *dp = new int[colLen + 1]{0};
        for (int i = 1; i <= rowLen; i++) {
            int cur = 0;
            for (int j = 1; j <= colLen; j++) {
                int leftTop = cur;
                cur = dp[j];
                if (rowChars[i - 1] == colsChars[j - 1]) {
                    dp[j] = leftTop + 1;
                }else{
                    dp[j] = max(dp[j],dp[j - 1]);
                }
            }
        }
        
        return dp[colLen];
    }
};

#endif /* LCS_hpp */
