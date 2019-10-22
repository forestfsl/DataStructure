//
//  ValidBST98.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/22.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "ValidBST98.hpp"




//指定范围 前序遍历 时间复杂度和空间复杂度都是O(n)
bool isValidBSTDLR(TreeNode *root,int min,int max){
    if (root == nullptr) return true;
    if (min != -999999999 && root->val <= min) return false;
    if (max != 999999999 && root->val >= max) return false;
    if(!isValidBSTDLR(root->left, min, root->val)) return false;
    if(!isValidBSTDLR(root->right, root->val, max)) return false;
    return true;

}

bool Solution98::isValidBST3(TreeNode *root){
    return isValidBSTDLR(root, -999999999, 999999999);
}


//指定范围 后续遍历 时间复杂度和空间复杂度都是O(n)
bool isValidBSTLRD(TreeNode *root,int min,int max){
    if (root == nullptr) return true;
    if(!isValidBSTLRD(root->left, min, root->val)) return false;
    if(!isValidBSTLRD(root->right, root->val, max)) return false;
    
    if (min != -999999999 && root->val <= min) return  false;
    if (max != 999999999 && root->val >= max) return false;
    
    return true;
}

void Solution98::offer(TreeNode *node, int min, int max){
    if (node == nullptr) return;
    this->nodes.push(node);
    this->mins.push(min);
    this->maxs.push(max);
}

bool Solution98::isValidBST5(TreeNode *root){
    if (root == nullptr) return true;
    offer(root, -999999999, 999999999);
    while (!nodes.empty()) {
        TreeNode *node = nodes.front();
        nodes.pop();
        int min = mins.front();
        mins.pop();
        if (min != -999999999 && node->val <= min) return false;
        int max = maxs.front();
        maxs.pop();
        if (max != 999999999 && node->val >= max) return false;
        offer(node->left, min, node->val);
        offer(node->right, node->val, max);
    }
    return true;
}


bool Solution98::isValidBST4(TreeNode *root){
     return isValidBSTLRD(root, -999999999, 999999999);
}

//中序遍历递归 时间复杂度和空间复杂度都是O(n)
static  int last = -999999999;
bool Solution98::isValidBST(TreeNode *root){
  
    if (root == nullptr) return true;
    //左边
    if(!isValidBST(root->left)) return false;
    //判断条件
    if(last != -999999999 && root->val <= last) return false;
    last = root->val;
    //右边
    if(!isValidBST(root->right)) return false;
    return true;
}
//中序遍历迭代 时间复杂度和空间复杂度都是O(n)
bool Solution98::isValidBST2(TreeNode *root){
    if (root == nullptr) return true;
     int last = -999999999;
    stack<TreeNode *>nodeStack;
    while (true) {
        while (root != nullptr) {
            nodeStack.push(root);
            root = root->left;
        }
        //执行到这里说明前面的所有left节点(同时有些也是根节点)都已经添加进栈里面了，这个时候需要出栈
        if (nodeStack.empty()) break;
        
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            if(last != -999999999 && node->val <= last) return false;
            last = node->val;
            root = node->right;
        
    }
    
    return true;
}

void Solution98::test98(){
    Solution98 solution = Solution98();
    TreeNode *sevenNode = new TreeNode(7);
    TreeNode *fourthNode = new TreeNode(4);
    TreeNode *nineNode = new TreeNode(9);
    TreeNode *twoNode = new TreeNode(2);
    TreeNode *fiveNode = new TreeNode(5);
    TreeNode *eightNode = new TreeNode(8);
    TreeNode *elevenNode = new TreeNode(11);
    TreeNode *oneNode = new TreeNode(1);
    TreeNode *threeNode = new TreeNode(3);
    TreeNode *tenNode = new TreeNode(10);
    TreeNode *twleveNode = new TreeNode(12);
    sevenNode->left = fourthNode;
    sevenNode->right = nineNode;
    fourthNode->left = twoNode;
    fourthNode->right = fiveNode;
    nineNode->left = eightNode;
    nineNode->right = elevenNode;
    twoNode->left = oneNode;
    twoNode->right = threeNode;
    elevenNode->left = tenNode;
    elevenNode->right = twleveNode;
    
    cout << solution.isValidBST(sevenNode) << endl;
    cout << solution.isValidBST2(sevenNode) << endl;
    cout << solution.isValidBST3(sevenNode) << endl;
    cout << solution.isValidBST4(sevenNode) << endl;
    cout << solution.isValidBST5(sevenNode) << endl;
    cout << "验证二叉搜索树" << endl;
}
