//
//  Flatten114.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/24.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "Flatten114.hpp"

/*
     1                 1
   /   \                \
  2     5    ->>>>>>>>   2
 / \     \                \
3   4     6                3
                            \
                             4
                              \
                               5
                                \
                                 6
从左到右的展开称为二叉树展开为链表

从结果集可以看到，最终所求链表就是二叉树前序遍历的结果：1--2--3--4--5--6
 解题思路1：前序遍历二叉树，每遍历到一个节点，就保存旧的right，并设置right = left，然后left = null，，然后再将旧的right嫁接到最右下角 flatten方法
解题思路2：前序遍历非递归实现 flattern2
解题思路3：后续遍历 flattern3
 二叉树后续遍历（右-左-root）的结果是：6-5-4-3-2-1，于是可以想到一种新思路，后续遍历二叉树，每遍历到一个节点，就让它的right指向上一个遍历到的节点，并清空它的left
 
 
在leetcode上面执行最快的是flattern2
*/
void Solution114::test114(){
    TreeNode *firstNode = new TreeNode(1);
    TreeNode *secondNode = new TreeNode(2);
    TreeNode *thirdNode = new TreeNode(3);
    TreeNode *fourthNode = new TreeNode(4);
    TreeNode *fifthNode = new TreeNode(5);
    TreeNode *sixNode = new TreeNode(6);
    firstNode->left = secondNode;
    firstNode->right = fifthNode;
    secondNode->left = thirdNode;
    secondNode->right =fourthNode;
    fifthNode->right = sixNode;
    Solution114 solution = Solution114();
    solution.flatten3(firstNode);
}
//时间，空间复杂度是O(n)
void Solution114::flatten(TreeNode* root){
    if (root == nullptr) return;
    cout << root->val << endl;
    //记录旧的right值
    TreeNode *oldRightNode = root->right;
    if (root->left) {
        root->right = root->left;
        root->left = nullptr;
        //嫁接到最右下角
        TreeNode *rightMost = root;
        while (rightMost->right) {
            rightMost = rightMost->right;
        }
        rightMost->right = oldRightNode;
    }
        flatten(root->right);
    
}
//时间复杂度是O(n),空间复杂度是O(1) 非递归
void Solution114::flatten2(TreeNode* root){
    while (root != nullptr) {
        cout << root->val << endl;
        //记录旧的right值
        TreeNode *oldRightNode = root->right;
        if (root->left) {
            root->right = root->left;
            root->left = nullptr;
            //嫁接到最右下角
            TreeNode *rightMost = root;
            while (rightMost->right) {
                rightMost = rightMost->right;
            }
            rightMost->right = oldRightNode;
        }
        root = root->right;
    }
 
}
//时间，空间复杂度是O(n)
void Solution114::flatten3(TreeNode* root){
    if (root == nullptr) return;
    
    
    flatten3(root->right);
    flatten3(root->left);
    cout << root->val << endl;
    
    //记录上一个节点
    if (preNode != nullptr) {
        root->right = preNode;
        root->left = nullptr;
    }
    preNode = root;
    

}
