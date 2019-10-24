//
//  MaxPathSum124.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/24.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef MaxPathSum124_hpp
#define MaxPathSum124_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <iostream>

using namespace std;

class Solution124 {
public:
    int maxPathSum(TreeNode *root);
    void static test124();

    static int sum;
};

#endif /* MaxPathSum124_hpp */
