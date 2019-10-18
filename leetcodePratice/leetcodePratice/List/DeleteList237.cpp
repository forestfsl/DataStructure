//
//  DeleteList237.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
//

#include "DeleteList237.hpp"

#include <iostream>

using namespace std;

void Solution237::deleteNode(ListNode237 *node){  //node 是需要删除的值
  //用下一个元素的值去覆盖当前的值
    node->val = node->next->val;
    node->next = node->next->next;
}

void Solution237::test237(){
    ListNode237 *first = new ListNode237(4);
    ListNode237 *second = new ListNode237(5);
    ListNode237 *third = new ListNode237(1);
    ListNode237 *fourth = new ListNode237(9);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    ListNode237 *node = first;
    for (int i = 0; i < 4; i++) {
        cout << node->val<<"-->"<<node->next<<endl;
        node = node->next;
    }
    cout << "删除节点5"<< endl;
    //    删除节点5
    Solution237 solution = Solution237();
    solution.deleteNode(second);
    ListNode237 *node1 = first;
    for (int i = 0; i < 3; i++) {
        cout << node1->val<<"-->"<<node1->next<<endl;
        node1 = node1->next;
    }
}

Solution237:: Solution237(){
    cout << "初始化函数" << endl;
}

Solution237::~Solution237(){
    cout << "析构函数" << endl;
}

