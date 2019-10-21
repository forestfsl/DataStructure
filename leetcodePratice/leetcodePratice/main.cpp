//
//  main.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
#include "DeleteList237.hpp"
#include "ReverseList206.hpp"
#include "CycleList141.hpp"
#include "MergeList21.hpp"
#include "MergeKList23.hpp"


using namespace std;


//测试237 https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
void test237DeleteListNode(){
    Solution237::test237();
}
//测试206 https://leetcode-cn.com/problems/reverse-linked-list/
void test206ReverseList(){
    Solution206::test206();
}
//https://leetcode-cn.com/problems/linked-list-cycle/
void test141CycleList(){
    Solution141::test141();
}
//https://leetcode-cn.com/problems/merge-two-sorted-lists/
void test21MergeTwoList(){
    Solution21::test21();
}
//https://leetcode-cn.com/problems/merge-k-sorted-lists/
void test23MergeKList(){
    Solution23::test23();
}

int main(int argc, const char * argv[]) {
//    test237DeleteListNode();
//    test206ReverseList();
//    test141CycleList();
//    test21MergeTwoList();
    test23MergeKList();
    return 0;
}
