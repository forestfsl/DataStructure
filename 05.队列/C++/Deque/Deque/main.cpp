//
//  main.cpp
//  Deque
//
//  Created by songlin on 2019/11/8.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
//#include "Deque.hpp"
//#include "Queue.hpp"
#include "CircleDeque.hpp"
#include "CircleQueue.hpp"
using namespace std;

//void testDueue(){
//    Deque<int> *queue = new Deque<int>();
//    queue->enQueueFront(11);
//     queue->enQueueFront(22);
//     queue->enQueueFront(33);
//     queue->enQueueFront(44);
//    while (!queue->isEmpty()) {
//        cout << queue->deQueueRear() << endl;
//    }
//}

void testCircle(){
    CircleQueue<int> *queue = new CircleQueue<int>();
    //0 1 2 3 4 5 6 7 8 9
    for (int i = 0; i < 10; i++) {
        queue->enQueue(i);
       
    }
     queue->toString();
    //null null null null 5 6 7 8 9
    for (int i = 0; i < 5; i++) {
        cout << queue->deQueue() << endl;
    }
    queue->toString();

    
    //15 16 17 18 19 5 6 7 8 9
    for (int i = 15; i < 20; i++) {
        queue->enQueue(i);
    }
    while (!queue->isEmpty()) {
        cout << queue->deQueue() << endl;
    }
   
}

int main(int argc, const char * argv[]) {
//    testDueue();
    testCircle();
    return 0;
}
