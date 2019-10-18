//
//  ReverseList206.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "ReverseList206.hpp"
#include <iostream>

using namespace std;


//递归法
ListNode206* Solution206:: reverseList(ListNode206 *head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode206 *reverseHead = reverseList(head->next);
   
    head->next->next = head;
    head->next = NULL;
    
    return reverseHead;
}
//遍历
ListNode206* Solution206:: reverseList2(ListNode206 *head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode206 *newHead = nullptr;
    while (head != nullptr) {
        ListNode206 *tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
       
    }
    return newHead;
}

void Solution206::test206(){
    ListNode206 *first = new ListNode206(1);
    ListNode206 *second = new ListNode206(2);
    ListNode206 *third = new ListNode206(3);
    ListNode206 *fourth = new ListNode206(4);
    ListNode206 *fifth = new ListNode206(5);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;
    ListNode206 *node = first;
    for (int i = 0; i < 5; i++) {
        cout << node->val<<"-->"<<node->next<<endl;
        node = node->next;
    }
    cout << "递归反转链表"<< endl;
    Solution206 solution = Solution206();
    first = solution.reverseList(first);
    ListNode206 *node1 = first;
    for (int i = 0; i < 5; i++) {
        cout << node1->val<<"-->"<<node1->next<<endl;
        node1 = node1->next;
    }
    
     cout << "遍历反转链表"<< endl;
    first = solution.reverseList2(first);
    ListNode206 *node2 = first;
    for (int i = 0; i < 5; i++) {
        cout << node2->val<<"-->"<<node2->next<<endl;
        node2 = node2->next;
    }
}
