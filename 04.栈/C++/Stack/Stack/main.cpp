//
//  main.cpp
//  Stack
//
//  Created by songlin on 2019/11/5.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
  
    Stack<int>stack ;
    stack.push(11);
    stack.push(22);
    stack.push(33);
    stack.push(44);
    while (!stack.isEmpty()) {
        cout << stack.pop() << endl;
    }
    return 0;
}
