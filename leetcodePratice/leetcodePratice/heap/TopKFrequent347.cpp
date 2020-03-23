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


vector<int> Solution347::topKFrequent3(vector<int> &nums, int k){
    // 用哈希map记录每个数字出现的次数
    unordered_map<int, int> hashmap;
    vector<int> result;
    int maxCount = 0;
    for (int i = 0; i < nums.size(); i++){
        hashmap[nums[i]]++;
        maxCount = max(maxCount, hashmap[nums[i]]);
    }
    // 采用桶排序，对次数进行排序
    // 桶的数量
    int bucketCount = maxCount + 1;
    vector<vector<int>> buckets(bucketCount);
    for (auto it : hashmap){
        buckets[it.second].push_back(it.first);
    }
    int length = (int)buckets.size() - 1;
    for (int i = length; i >= 0; i--){
        if (!buckets[i].empty()){
            for (auto num : buckets[i]){
                result.push_back(num);
                if (result.size() == k){
                    return result;
                }
            }
        }
    }
    
    return result;
    
}


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
//        https://blog.csdn.net/ding_yingzi/article/details/79973809
//        https://blog.csdn.net/xie1xiao1jun/article/details/41486293
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
    solution.topKFrequent2(nums,2);
}
