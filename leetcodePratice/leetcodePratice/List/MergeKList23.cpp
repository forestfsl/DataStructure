//
//  MergeKList23.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/21.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "MergeKList23.hpp"
#include <queue>


bool static complare(ListNode *a,ListNode *b)

{
    
    return a->val < b->val;
    
}

ListNode static * RecursiveMergeTwoList(ListNode *l1, ListNode *l2){
    if (l1 == nullptr || l1 == NULL) return l2;
    if (l2 == nullptr || l2 == NULL) return l1;
    if (l1->val <= l2->val) {
        l1->next = RecursiveMergeTwoList(l1->next, l2);
        return l1;
    }else{
        l2->next = RecursiveMergeTwoList(l1, l2->next);
        return l2;
    }
}


ListNode static *mergeTwoList(ListNode *l1, ListNode *l2){
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode *head = nullptr;
    if (l1 != NULL & l2!=NULL && l1->val <= l2->val) {
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

ListNode * Solution23::mergerKList2(vector<ListNode *> &lists){
    if (lists.size() == 0) {
        return nullptr;
    }

    //采取两两合并操作，可以使用合并2个有序链表的操作方法
    long length = lists.size() ;
    for (int i = 0;i< length;i++) {//k 次遍历
        lists[0] = mergeTwoList(lists[0], lists[i + 1]);
    }
   
    return lists[0];
}

struct cmp {
    bool operator()(ListNode *a,ListNode *b){
        return a->val > b->val;
    }
};

ListNode * Solution23::mergerKList3(vector<ListNode *> &lists){
    if (!&lists || lists.size() == 0) return nullptr;
    ListNode *head = new ListNode(0);
    ListNode *currentHead = head;
    priority_queue<ListNode*,vector<ListNode*>,cmp> q;
    long length = lists.size();
    for (int i = 0; i < length; i++) {
        if (lists[i] != nullptr) {
            q.push(lists[i]);
        }
    }
    while (!q.empty()) {
        ListNode *headNode = q.top();
        q.pop();
        if (headNode->next != nullptr) {
            q.push(headNode->next);
        }
        currentHead = currentHead->next = headNode;
    }

    
    return head->next;
}
//时间复杂度大概是O(nk)
ListNode * Solution23::mergerKList(vector<ListNode *> &lists){
    if (lists.size() == 0) {
        return  nullptr;
    }
//遍历list表里面的数据，将头元素进行比较，取出最小值，然后将其赋值给current->next(使用虚拟头结点),然后再将对应的链表的下一个元素赋值给对应值
//    需要一个临时中间索引值来存储最小值
  
    ListNode *head = new ListNode(0);
    ListNode *currentHead = head;
    bool isContinue = true;
    long length = lists.size() ;
    while (isContinue) {//多少个节点执行多少次n
        int minIndex = -1;//默认值为-1
        for (int i = 0;i< length;i++) {//k 次遍历
            if (lists[i] == nullptr) continue;
            if (minIndex == -1 || lists[i]->val < lists[minIndex]->val) {
                minIndex = i;//取出最小索引
            }
        }
        if (minIndex == -1) break;
        currentHead = currentHead->next = lists[minIndex];
        lists[minIndex] = lists[minIndex]->next;
    }
  
    return head->next;
}

//时间复杂度O(nlogn) + O(kn) + O(n) 加法原则取最大，空间复杂度是O(n)
ListNode * Solution23::stupidMergerKList(vector<ListNode *> &lists){
    vector<ListNode *>nodeList;
    //遍历list，获取每一个链表，假设有k条链表，假设总结点是n个
    for (ListNode *kModel : lists) {//遍历k次
        while (kModel != nullptr) {//遍历n次
            nodeList.push_back(kModel);
            kModel = kModel->next;
        }
    }
    ListNode *head = new ListNode(0);
    ListNode *currentNode = head;
//    sort函数用于C++中，对给定区间所有元素进行排序，默认为升序，也可进行降序排序。sort函数进行排序的时间复杂度为n*log2n
    sort(nodeList.begin(), nodeList.end(),complare);//默认从小到大
    for (ListNode *sortModel : nodeList) {
        currentNode = currentNode->next = sortModel;
    }
    return head->next;
}



void Solution23::test23(){
    ListNode *k1FirstNode = new ListNode(1);
    ListNode *k1SecondNode = new ListNode(3);
    ListNode *k1ThirdNode = new ListNode(5);
    k1FirstNode->next = k1SecondNode;
    k1SecondNode->next = k1ThirdNode;
    k1ThirdNode->next = NULL;
    
    ListNode *k2FirstNode = new ListNode(2);
    ListNode *k2SecondNode = new ListNode(4);
    ListNode *k2ThirdNode = new ListNode(6);
    k2FirstNode->next = k2SecondNode;
    k2SecondNode->next = k2ThirdNode;
    k2ThirdNode->next = NULL;
    
    ListNode *k3FirstNode = new ListNode(7);
    ListNode *k3SecondNode = new ListNode(8);
    ListNode *k3ThirdNode = new ListNode(9);
    k3FirstNode->next = k3SecondNode;
    k3SecondNode->next = k3ThirdNode;
    k3ThirdNode->next = NULL;
    
    ListNode *k4FirstNode = new ListNode(10);
    ListNode *k4SecondNode = new ListNode(11);
    ListNode *k4ThirdNode = new ListNode(16);
    k4FirstNode->next = k4SecondNode;
    k4SecondNode->next = k4ThirdNode;
    k4ThirdNode->next = NULL;
    
    //这个测试C++版本在leetcode上面提交的时候爆出了超出时间限制得情况,说明这个时间复杂度非常高
    /*
     [[-10,-6,-4,-4,0,2,2,2,2],[-5,1,3,4,4,4],[-9],[-9],[-10,-8,-5,-4,-3,-3,-2,4],[-10,-8,-7,-4,-4,0,1,2],[-8,-1,4],[-6,-5,-2,-2,-1,1,3,4]]
     */
    Solution23 solution = Solution23();
    vector<ListNode *>listModel = {
        k1FirstNode,k2FirstNode,k3FirstNode,k4FirstNode
    };
    //stupid
//    ListNode *firstHead = solution.stupidMergerKList(listModel);
//    cout << stupidHead << endl;
    
    //逐一比较 leetcode 时间通过，说明复杂度相对来说比第一种情况要好
//    ListNode *secondHead = solution.mergerKList(listModel);
//    cout << secondHead << endl;
    
//    ListNode *thirdHead = solution.mergerKList2(listModel);
//    cout << thirdHead << endl;
    
    ListNode *fourthHead = solution.mergerKList3(listModel);
    cout << fourthHead << endl;
    
}
