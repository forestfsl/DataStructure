//
//  ValidBST98.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/22.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef ValidBST98_hpp
#define ValidBST98_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

class Solution98 {
public:
    bool isValidBST(TreeNode* root);
    bool isValidBST2(TreeNode *root);
    bool isValidBST3(TreeNode *root);
    bool isValidBST4(TreeNode *root);
    bool isValidBST5(TreeNode *root);
    void static test98();
    void offer(TreeNode *node, int min, int max);
    queue<TreeNode *>nodes;
    queue<int>mins;
    queue<int>maxs;
};

#endif /* ValidBST98_hpp */
