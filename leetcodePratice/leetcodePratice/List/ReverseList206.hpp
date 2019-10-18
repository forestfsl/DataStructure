//
//  ReverseList206.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//https://leetcode-cn.com/problems/reverse-linked-list/
//

#ifndef ReverseList206_hpp
#define ReverseList206_hpp

#include <stdio.h>

struct ListNode206 {
    int val;
    ListNode206 *next;
    ListNode206(int x): val(x),next(NULL){};
};


class Solution206 {
public:
    ListNode206 *reverseList(ListNode206 *head);
    ListNode206 *reverseList2(ListNode206 *head);
    
    void static test206();
};

#endif /* ReverseList206_hpp */
