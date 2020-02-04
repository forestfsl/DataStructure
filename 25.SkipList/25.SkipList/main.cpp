//
//  main.cpp
//  25.SkipList
//
//  Created by fengsl on 2020/2/3.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#include <iostream>
#include "SkipList.hpp"
#include "TimeTool.hpp"
using namespace std;

void testSkipList(){
    SkipList<int, int> list = SkipList<int, int>();
    int count = 100000;
    int delta = 10;
    for (int i = 0; i < count; i++) {
        list.put(i,i + delta);
    }
}

int main(int argc, const char * argv[]) {
    TimeTool::task2("SkipList",[](){
            testSkipList();
            });

    return 0;
}
