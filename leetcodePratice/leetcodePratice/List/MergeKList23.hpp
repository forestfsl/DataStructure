//
//  MergeKList23.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/21.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef MergeKList23_hpp
#define MergeKList23_hpp

#include <stdio.h>
#include "ListNode.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Solution23 {
public:
    ListNode *mergerKList(vector<ListNode *>& lists);
    ListNode *mergerKList2(vector<ListNode *>& lists);
    ListNode *mergerKList3(vector<ListNode *>& lists);
    ListNode *stupidMergerKList(vector<ListNode *>& lists);
    void static test23();
};

#endif /* MergeKList23_hpp */
