//
//  MergeList21.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/21.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "MergeList21.hpp"
#include <iostream>
using namespace std;

ListNode* Solution21:: mergeTwoList(ListNode *l1, ListNode *l2){
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode *head = nullptr;
    if (l1->val <= l2->val) {
        head = l1;
        l1 = l1->next;
    }else{
        head = l2;
        l2 = l2->next;
    }
    //需要生成多一个临时变量，以免元素的值被覆盖
    ListNode *currentNode = head;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            currentNode = currentNode->next = l1;
            l1 = l1->next;
        }else{
            currentNode = currentNode->next = l2;
            l2 = l2->next;
        }
    }
    if (l1 == nullptr) {
        currentNode->next = l2;
    }else if (l2 == nullptr){
        currentNode->next = l1;
    }
    
    return head;
    
}

ListNode* Solution21:: mergeTwoList2(ListNode *l1, ListNode *l2){
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode *head = new ListNode(0);
   
    //需要生成多一个临时变量，以免元素的值被覆盖
    ListNode *currentNode = head;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val && l1->next != NULL) {
            currentNode = currentNode->next = l1;
            l1 = l1->next;
        }else if(l2->next != NULL && l1->val > l2->val){
            currentNode = currentNode->next = l2;
            l2 = l2->next;
        }
    }
    if (l1 == nullptr) {
        currentNode->next = l2;
    }else if (l2 == nullptr){
        currentNode->next = l1;
    }
    
    return head;
    
}

ListNode *Solution21::RecursiveMergeTwoList(ListNode *l1, ListNode *l2){
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    if (l1->val <= l2->val) {
        l1->next = RecursiveMergeTwoList(l1->next, l2);
        return l1;
    }else{
        l2->next = RecursiveMergeTwoList(l1, l2->next);
        return l2;
    }
}

void Solution21::test21(){
    ListNode *k1FirstNode = new ListNode(1);
    ListNode *k1SecondNode = new ListNode(2);
    ListNode *k1ThirdNode = new ListNode(4);
    k1FirstNode->next = k1SecondNode;
    k1SecondNode->next = k1ThirdNode;
    
    ListNode *k2FirstNode = new ListNode(1);
    ListNode *k2SecondNode = new ListNode(3);
    ListNode *k2ThirdNode = new ListNode(4);
    k2FirstNode->next = k2SecondNode;
    k2SecondNode->next = k2ThirdNode;
    
    //遍历
    Solution21 solution = Solution21();
//    ListNode *head = solution.mergeTwoList(k1FirstNode, k2FirstNode);
//    cout << head << endl;
    
    //递归
    ListNode *rhead = solution.RecursiveMergeTwoList(k1FirstNode, k2FirstNode);
    cout << rhead << endl;
}
