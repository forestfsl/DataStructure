//
//  Pirate.hpp
//  20.Pirate
//
//  Created by fengsl on 2020/1/27.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef Pirate_hpp
#define Pirate_hpp

#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;


/*
 贪心策略：每一次都优选选择重量最小的古董
 海盗船的载重量为W，每件股东的重量为w1，海盗们应该如何把尽可能多的数量股东装上海盗船，比如W为39，w1 分别为
 3,5,4,19,7,2,11
 */
class Pirate{
   
public:
    int weights[8] = {3,5,4,10,7,14,2,11};
    int capacity = 30;
    int weight = 0;
    int count = 0;
    
    
    void testPirate(){
        sort(weights, weights + 8,compare);
        for (int i = 0; i < 8 && weight < capacity; i++) {
            int newWeight = weight + weights[i];
            if (newWeight <= capacity) {
                weight = newWeight;
                count++;
                cout << weights[i] << endl;
            }
        }
        cout << "一共选了" << count << "件古董" << endl;
    }
    static bool compare(int a,int b){
           return a < b;
    }
   
};

#endif /* Pirate_hpp */
