//
//  MaxPathSum124.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/24.
//  Copyright © 2019 songlin. All rights reserved.
//

/*
           A
         /  \
        B    C
       / \   / \
      D   E  F  G
 思路：1.对每一个节点都算出:有穿过它但不穿过它府机电的最大路径和
 2.整体最大路径和：1中所有计算结果的最大值
 假设S(L)是穿过L节点但是不穿过它父节点的最大路径和，假设V(K)是节点K能提供给父节点的最大路径值
 S(A) = A + max(V(B),0) + max(V(C),0);
 S(B) = B + max(V(D),0) + max(V(E),0);
 S(C) = C + max(V(F),0) + max(V(G),0);
 S(D) = D + 0 + 0;
 S(E) = E + 0 + 0;
 S(F) = F + 0 + 0;
 
 那么如何求一个节点能提供给父节点的最大路劲值呢？
 V(B) = B + max(max(V(D),0),max(V(E),0));
 V(C) = C + max(max(V(F),0),max(V(G),0));
 V(A) = A + max(max(V(B),0),max(V(C),0);
 V(D) = D + max(0,0);
 V(E) = E + max(0,0);
 V(F) = F + max(0,0);
 V(G) = G + max(0,0);
 
 由此可见，求1个节点能提供给父节点的最大路径值，需要一直遍历到最底下元素并获取左元素的值和右元素的值，因此我们可以采取后序遍历(左-由-root）
 */
#include "MaxPathSum124.hpp"

void Solution124::test124(){
    TreeNode *firstNode = new TreeNode(2);
    TreeNode *secondNode = new TreeNode(-1);
    TreeNode *thirdNode = new TreeNode(3);
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    
    Solution124 solution = Solution124();
    solution.maxPathSum(firstNode);
    
}

int Solution124::sum = INT_MIN;

int fetchNodeVMax(TreeNode *root){
    //如果root为空的话，直接返回0即可
    if (root == nullptr) return 0;
    
    int left = fetchNodeVMax(root->left);
    int right = fetchNodeVMax(root->right);
    
    Solution124::sum = max(Solution124::sum,root->val + max(left,0) + max(right,0));
    cout << "最大路径值是 sum = :" << Solution124::sum << endl;
    
    return root->val + max(max(left,0),max(right,0));
}



int Solution124::maxPathSum(TreeNode *root){
    fetchNodeVMax(root);
    return sum;
}


