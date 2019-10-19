//
//  CycleList141.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef CycleList141_hpp
#define CycleList141_hpp

#include <stdio.h>


struct ListNode141 {
    int val;
    ListNode141 *next;
    ListNode141(int x): val(x),next(NULL){};
};


class Solution141 {
public:
    bool cycleList(ListNode141 *head);
    
    void static test141();
};
#endif /* CycleList141_hpp */

