//
//  main.cpp
//  Deque
//
//  Created by songlin on 2019/11/8.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
#include "Deque.hpp"
//#include "Queue.hpp"
using namespace std;

void testDueue(){
    Deque<int> *queue = new Deque<int>();
    queue->enQueueFront(11);
     queue->enQueueFront(22);
     queue->enQueueFront(33);
     queue->enQueueFront(44);
    while (!queue->isEmpty()) {
        cout << queue->deQueueRear() << endl;
    }
}

int main(int argc, const char * argv[]) {
    testDueue();
    return 0;
}
