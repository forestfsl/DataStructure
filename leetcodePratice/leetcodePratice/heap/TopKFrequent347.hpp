//
//  TopKFrequent347.hpp
//  leetcodePratice
//
//  Created by fengsl on 2019/10/27.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef TopKFrequent347_hpp
#define TopKFrequent347_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution347 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k);
    vector<int> topKFrequent2(vector<int>& nums, int k);
    vector<int> topKFrequent3(vector<int>& nums, int k);

    void static test347();
};

#endif /* TopKFrequent347_hpp */
