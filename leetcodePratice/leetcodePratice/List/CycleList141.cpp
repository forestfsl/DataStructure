//
//  CycleList141.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "CycleList141.hpp"

ListNode141* Solution141:: reverseList2(ListNode141 *head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode141 *newHead = nullptr;
    while (head != nullptr) {
        ListNode141 *tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
        
    }
    return newHead;
}

void Solution141::test141(){
   
}
