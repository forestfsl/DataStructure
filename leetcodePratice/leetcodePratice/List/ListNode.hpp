//
//  ListNode.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/21.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif /* ListNode_hpp */
