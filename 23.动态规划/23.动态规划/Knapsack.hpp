//
//  Knapsack.hpp
//  23.动态规划
//
//  Created by fengsl on 2020/2/2.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef Knapsack_hpp
#define Knapsack_hpp

#include <stdio.h>

class Knapsack{
public:
    /*
     假设values是价值数组，weights是重量数组
     编号为k的物品，价值是values[k],重量是weights[k],k属于[0,n)
     
     假设dp(i,j)是最大承重为j，有前i件物品可选时的最大总价值，i属于[1,n),j属于[1,W]
     dp(i,0),dp(0,j) 初始值均为0
     如果j < weights[i - 1],那么dp(i,j) = dp(i - 1,j)
     如果j 大于等于 weights[i - 1],那么dp(i,j) = max(dp[i -1,j] (dp[i-1,j - weights[i-1]) + values[i - 1]);
     动态-递归实现
     */
    int maxValue1(int *values,int *weights,int capacity,int valueLen,int weightLen){

        if (values == nullptr || valueLen == 0) return 0;
        if(weights == nullptr || weightLen == 0) return 0;
       
        int **dp; // array[M][N] 分配内存要比传入来的数组加1，是为了确保不被越界
        dp = (int **)malloc((valueLen + 1) * sizeof(int *));
        for(int i = 0; i <= valueLen; i++) {
            dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
        }
       //输入二维数组的值
        for (int i = 0; i <= valueLen;i++)
        {
            for (int j = 0; j <= capacity;j++)
            {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= valueLen; i++) {
            for (int j = 1; j <= capacity; j++) {
                if (j < weights[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j],values[i-1] + dp[i-1][j-weights[i-1]]);
                }
            }
        }
        return dp[valueLen][capacity];
    }
    /*
     动态非递归实现
     通过图片(pdf课件08动态规划-0-1背包-非递归实现，一维数组)，可以看出dp(i,j)都是由dp(i-1,k) 推导出来的，也就是说，第i行的数据是由它的上一行第i-1行推导出来的，因此，可以使用一维数组来优化，
     另外，由于k小于等于j，所以j的遍历应该由大到小，否则会数据错乱
     因为计算后面的值，需要用到前面的值，如果从左往右的话，当计算到某个值的时候，需要上面一行的前面数值的时候，会发现数值已经被当行给覆盖了，因为这个是一维数组
     */
    int maxValue2(int *values,int *weights,int capacity,int valueLen,int weightLen){
        if (values == nullptr || valueLen == 0) return 0;
        if (weights == nullptr || weightLen == 0) return 0;
        if (valueLen != weightLen || capacity <= 0) return 0;
        int *dp = new int[capacity + 1]{0};
        for (int i = 1; i <= valueLen; i++) {
            for (int j = capacity; j >= 1; j--) {
                if (j < weights[i - 1]) continue;
                dp[j] = max(dp[j],values[i - 1] + dp[j - weights[i - 1]]);
            }
        }
        return dp[capacity];
    }
    
    //j的下界可以从1改为weights[i - 1]
    int maxValue3(int *values,int *weights,int capacity,int valueLen,int weightLen){
           if (values == nullptr || valueLen == 0) return 0;
           if (weights == nullptr || weightLen == 0) return 0;
           if (valueLen != weightLen || capacity <= 0) return 0;
           int *dp = new int[capacity + 1]{0};
           for (int i = 1; i <= valueLen; i++) {
               for (int j = capacity; j >= weights[i - 1]; j--) {
                   dp[j] = max(dp[j],values[i - 1] + dp[j - weights[i - 1]]);
               }
           }
           return dp[capacity];
       }
    
    int maxValueExactly(int *values,int *weights,int capacity,int valueLen,int weightLen){
        if (values == nullptr || valueLen == 0) return 0;
        if (weights == nullptr || weightLen == 0) return 0;
        if (valueLen != weightLen || capacity <= 0) return 0;
        int *dp = new int[capacity + 1]{0};
        for (int j = 1; j <= capacity; j++) {
            dp[j] = INT_MIN;
        }
        for (int i = 1; i <= valueLen; i++) {
            for (int j = capacity; j >= weights[i - 1]; j--) {
                dp[j] = max(dp[j] ,values[i - 1] + dp[j - weights[i - 1]]);
            }
        }
        return dp[capacity] < 0 ? - 1 : dp[capacity];
    }
};

#endif /* Knapsack_hpp */
