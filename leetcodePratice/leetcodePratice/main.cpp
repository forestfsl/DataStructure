//
//  main.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/18.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
#include "DeleteList237.hpp"
#include "ReverseList206.hpp"

using namespace std;


//测试237 https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
void test237DeleteListNode(){
    Solution237::test237();
}
//测试206 https://leetcode-cn.com/problems/reverse-linked-list/
void test206ReverseList(){
    Solution206::test206();
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    test237DeleteListNode();
    
    test206ReverseList();
    return 0;
}
