//
//  CoinChange.hpp
//  23.动态规划
//
//  Created by fengsl on 2020/1/28.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef CoinChange_hpp
#define CoinChange_hpp

#include <stdio.h>

class CoinChange{
public:
    /*
     暴力递归(自定向下的调用，出现了重叠子问题)
     */
    int coins1(int n){
        if (n < 1) return INT_MAX;
        if (n == 25 || n == 20 || n == 5 || n == 1) return 1;
        int min1 = min(coins1(n - 25),coins1(n - 20));
        int min2 = min(coins1(n - 5),coins1(n - 1));
        return min(min1, min2) + 1;
    }
    
    /*
     记忆化搜索(自顶向下的调用)
     */
    int coins2(int n){
        if (n < 1) return -1;
        int *dp = new int[n + 1]{0};
        int *faces = new int[4]{1,5,20,25};
        for (int i = 0; i < 4; i++) {
            if (n < faces[i]) break;
            dp[faces[i]] = 1;
        }
        return coins2(n,dp);
    }
    
    int coins2(int n,int *dp){
        if (n < 1) return INT_MAX;
        if (dp[n] == 0) {
            int min1 = min(coins2(n - 25, dp),coins2(n - 20, dp));
            int min2 = min(coins2(n - 5, dp),coins2(n - 1, dp));
            dp[n] = min(min1,min2) + 1;
        }
        return dp[n];
    }
    
    /*
     递堆（自底向上）
     */
    int coins3(int n){
        if (n < 1) return -1;
        int *dp = new int[n + 1]{0};
        for (int i = 1; i <= n; i++) {
            int minValue = dp[i - 1];
            if (i >= 5) minValue = min(dp[i - 5],minValue);
            if (i >= 20) minValue = min(dp[i - 20],minValue);
            if (i >= 25) minValue = min(dp[i - 25],minValue);
            dp[i] = minValue + 1;
        }
        return dp[n];
    }
    
    int coins4(int n){
        if (n < 1) return -1;
        int *dp = new int[n + 1]{0};
        //faces[i]是凑够i分时最后那枚硬币的面值
        int *faces = new int[n + 1]{0};
        for (int i = 1; i <= n; i++) {
            int min = dp[i - 1];
            faces[i] = 1;
            
            if (i >= 5 && dp[i - 5] < min) {
                min = dp[i - 5];
                faces[i] = 5;
            }
            if (i >= 20 && dp[i - 20] < min) {
                min = dp[i - 20];
                faces[i] = 20;
            }
            if (i >= 25 && dp[i - 25] < min) {
                min = dp[i - 25];
                faces[i] = 25;
            }
            dp[i] = min + 1;
            
        }
        for (int i = 1; i < n + 1; i++) {
            cout << faces[i] << endl;
        }
        return dp[n];
    }
    
    // dp(i) 第i项斐波那契数
    // dp(i) = dp(i - 1) + dp(i - 2)
    
    // dp(41) = 凑够41需要的最少硬币数量 = min { dp(40), dp(36), dp(16), dp(21) } + 1
    // dp(41 - 1) = dp(40) = 凑够40需要的最少硬币数量
    // dp(41 - 5) = dp(36) = 凑够36需要的最少硬币数量
    // dp(41 - 25) = dp(16) = 凑够16需要的最少硬币数量
    // dp(41 - 20) = dp(21) = 凑够21需要的最少硬币数量
    // min { dp(40), dp(36), dp(16), dp(21) } + 1
    int coins5(int n){
        int *faces = new int[4]{1,5,25,20};
        int *dp = new int[n+1]{0};
        if (n < 1 || faces == nullptr) return -1;
        for (int i = 1; i <= n; i++) {
            int minValue = INT_MAX;
            for (int j = 0; j < 4;j++) {
                if (i < faces[j]) continue;
                int v = dp[i - faces[j]];
                if (v < 0 || v >= minValue) continue;
                minValue = v;
            }
            if (minValue == INT_MAX) {
                dp[i] = -1;
            }else{
                dp[i] = minValue + 1;
            }
        }
        return dp[n];
    }
};

#endif /* CoinChange_hpp */
