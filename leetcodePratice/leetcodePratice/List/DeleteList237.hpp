//
//  DeleteList237.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef DeleteList237_hpp
#define DeleteList237_hpp

#include <stdio.h>


struct ListNode237 {
    int val;//元素值
    ListNode237 *next; //下一个指向的元素
    ListNode237(int x):val(x),next(NULL){}//ListNode初始化方法
    
};

class Solution237 {
public:
    Solution237();
    ~Solution237();
    void deleteNode(ListNode237 *node);
    void static test237();
    
};

#endif /* DeleteList237_hpp */
