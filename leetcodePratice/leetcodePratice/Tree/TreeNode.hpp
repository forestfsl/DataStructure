//
//  TreeNode.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/22.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
#endif /* TreeNode_hpp */
