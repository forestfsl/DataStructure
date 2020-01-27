//
//  CoinChange.hpp
//  20.Pirate
//
//  Created by fengsl on 2020/1/27.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef CoinChange_hpp
#define CoinChange_hpp
#include <algorithm>

#include <stdio.h>

/*
 假设有25分，10分，5分，1分的硬币，现在要找给用户41分的零钱，如何办到硬币个数最少
 
 在这里使用贪心策略求解的结果并不是最优解，最优解应该是2枚20分，1枚1分的硬币，共3枚硬币
 */
class CoinChange{
public:
    void coinChange(int *faces,int len,int money){
        //1 5 20 25
        sort(faces, faces + len);
        int coins = 0;
        int idx = len;
        while (idx >= 0) {
            while (money >= faces[idx]) {
                cout << faces[idx] << endl;
                money -= faces[idx];
                coins++;
            }
            idx--;
        }
        cout <<"一共需要" << coins << "枚硬币" << endl;
    }
    
    void coinChange2(int *faces,int len,int money){
        sort(faces, faces + len,cmp);
        int coins = 0;
        int i = 0;
        while (i < len) {
            if (money < faces[i]) {
                i++;
                continue;
            }
            cout << faces[i] << endl;
            money -= faces[i];
            coins++;
        }
        cout << "一共需要" << coins << "枚硬币" << endl;
    }
    
    void coinChange3(int *faces,int len,int money){
         sort(faces, faces + len);
        int coins = 0;
        for (int i = len; i >= 0; i--) {
            if (money < faces[i]) {
                continue;
            }
            cout << faces[i] << endl;
            money -= faces[i];
            coins++;
            i = len;
        }
        cout << "一共需要" << coins << "枚硬币" << endl;
    }
    
    static bool cmp(int a,int b){
        return a > b;
    }
};

#endif /* CoinChange_hpp */
