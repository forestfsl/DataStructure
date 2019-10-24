//
//  Flatten114.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/24.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Flatten114_hpp
#define Flatten114_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <iostream>

using namespace std;

class Solution114 {
public:
    void flatten(TreeNode * root);
    void flatten3(TreeNode * root);
    void flatten2(TreeNode * root);
    void static test114();
    TreeNode *preNode;
};

#endif /* Flatten114_hpp */
