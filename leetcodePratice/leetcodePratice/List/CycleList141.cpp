//
//  CycleList141.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "CycleList141.hpp"
#include <iostream>

using namespace std;

bool Solution141:: cycleList(ListNode141 *head){

    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode141 *slow = head;
    ListNode141 *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

void Solution141::test141(){
    ListNode141 *firstNode = new ListNode141(1);
    ListNode141 *secondNode = new ListNode141(2);
    ListNode141 *thirdNode = new ListNode141(3);
    ListNode141 *fourthNode = new ListNode141(4);
    ListNode141 *fifthNode = new ListNode141(5);
    ListNode141 *sixNode = new ListNode141(6);
    ListNode141 *sevenNode = new ListNode141(7);
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = fifthNode;
    fifthNode->next = sixNode;
    sixNode->next = sevenNode;
//    sevenNode->next = firstNode;
    Solution141 solution = Solution141();
    cout << "1：代表有环，0：代表没有"<< endl << solution.cycleList(firstNode) << endl;
}
