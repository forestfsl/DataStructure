//
//  MergeList21.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/21.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef MergeList21_hpp
#define MergeList21_hpp


#include <stdio.h>
#include "ListNode.hpp"

class Solution21 {
public:
    //遍历方式
    ListNode *mergeTwoList(ListNode *l1,ListNode *l2);
     ListNode *mergeTwoList2(ListNode *l1,ListNode *l2);
    void static test21();
    //递归模式
    ListNode *RecursiveMergeTwoList(ListNode *l1,ListNode *l2);
};

#endif /* MergeList21_hpp */
