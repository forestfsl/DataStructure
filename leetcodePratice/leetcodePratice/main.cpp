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
#include "EvalRPN150.hpp"
#include "MergeList21.hpp"
#include "MergeKList23.hpp"
#include "ValidBST98.hpp"
#include "DailyTemperatures739.hpp"
#include "MaxPathSum124.hpp"
#include "Flatten114.hpp"
#include "TwoSum1.hpp"
#include "Rob198.hpp"

using namespace std;


//测试237 删除链表节点 https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
void test237DeleteListNode(){
    Solution237::test237();
}
//测试206 翻转链表 https://leetcode-cn.com/problems/reverse-linked-list/
void test206ReverseList(){
    Solution206::test206();
}
//141判断链表是否有环 https://leetcode-cn.com/problems/linked-list-cycle/
void test141CycleList(){
    Solution141::test141();
}

//150 逆波 https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/comments/
void test150EvalRPN(){
    Solution150::test150();
}

//21合并两个链表 https://leetcode-cn.com/problems/merge-two-sorted-lists/
void test21MergeTwoList(){
    Solution21::test21();
}
//23 合并k个链表 https://leetcode-cn.com/problems/merge-k-sorted-lists/
void test23MergeKList(){
    Solution23::test23();
}
//有效二叉树98 https://leetcode-cn.com/problems/validate-binary-search-tree/
void test98ValidBST(){
    Solution98::test98();
}
//每日温度739 https://leetcode-cn.com/problems/daily-temperatures/
void test739Tempatures(){
    Solution739::test739();
}

// 124二叉树中的最大路径和 https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
void test124MaxPathSum() {
    Solution124::test124();
}
//114. 二叉树展开为链表 https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
void test114Flatten(){
    Solution114::test114();
}
//求和1
void test1TwoSum(){
    Solution1::test1();
}


//198. 打家劫舍 https://leetcode-cn.com/problems/house-robber/
void test98Rob(){
    Solution98::test98();
}


int main(int argc, const char * argv[]) {
//    test237DeleteListNode();
//    test206ReverseList();
//    test141CycleList();
//    test150EvalRPN();
//    test21MergeTwoList();
//    test23MergeKList();
//    test98ValidBST();
//    test739Tempatures();
//    test124MaxPathSum();
//    test114Flatten();
//    test1TwoSum();
    test98Rob();

    return 0;
}
