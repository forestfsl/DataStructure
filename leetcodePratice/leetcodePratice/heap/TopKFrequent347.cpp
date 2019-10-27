//
//  TopKFrequent347.cpp
//  leetcodePratice
//
//  Created by fengsl on 2019/10/27.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "TopKFrequent347.hpp"
#include <unordered_map>
#include <queue>
#include <map>


//小根堆模式 //全排序 时间复杂度优于O(nlogn) 空间复杂度是O(n)
vector<int> Solution347::topKFrequent2(vector<int> &nums, int k){
    using E = pair<int, int>;
    priority_queue<E,vector<E>,greater<E>> minHeap;
    map<int,int >counter;
    for (auto e : nums) {//O(n)
        ++counter[e];
    }
    //元素是字典
    for (auto &x : counter) {//O(mlogk)
        auto pair = make_pair(x.second, x.first);
        if (minHeap.size() == k) {
            if (pair < minHeap.top()) continue;
            //如果pair的值大于的话，删除最小元素
            minHeap.pop();
        }
        //push map元素入栈
        minHeap.push(move(pair));
    }
    vector<int> res(minHeap.size());
    k = res.size();
    while (!minHeap.empty()) {//O(k)
        res[--k] = minHeap.top().second;
        minHeap.pop();
    }
    return res;
}

//全排序 时间复杂度优于O(nlogn) 空间复杂度是O(n)
vector<int> Solution347::topKFrequent(vector<int> &nums, int k){
 
    unordered_map<int, int> m;
    for (const auto &i : nums) {//O(n)
        ++m[i];
    }
     vector<pair<int, int>> tmp;
    

    for (auto& i : m)
        tmp.push_back(i);
    
    //假设数据规模为n的数组中，不同元素的个数是m O(mlogm)
    sort(tmp.begin(), tmp.end(),
         [=](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; });
    vector<int> res;
    auto it = tmp.cbegin();
    //O(K)
    for (int i = 0; i < k; ++i) {
        res.push_back(it->first);
        ++it;
    }
    return res;
}

void Solution347::test347(){
    Solution347 solution = Solution347();
    vector<int>nums = {1,1,1,1,2,2,3,2};
    solution.topKFrequent3(nums,2);
}
