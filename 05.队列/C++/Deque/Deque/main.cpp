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

void testCircleDueue(){
    CircleDeque<int> *queue = new CircleDeque<int>();
//    5 4 3 2 1  100 101 102 103 104 105
    //经历过第一次次扩容
    // 头5 4 3 2 1  100 101 102 103 104 105 106 8 7 6 尾
      //经历过第二次扩容
//     头 8 7 6  5 4 3 2 1  100 101 102 103 104 105 106 107 108 109 null null 10 9 尾
    for (int i = 0; i < 10; i++) {
        queue->enQueueFront(i + 1);
        queue->enQueueRear(i + 100);
    }
    queue->toString();
    
    // 头 null 7 6  5 4 3 2 1  100 101 102 103 104 105 106 null null null null null null null 尾
    for (int i = 0; i < 3; i++) {
        queue->deQueueFront();
        queue->deQueueRear();
    }
      queue->toString();

    queue->enQueueFront(11);
    queue->enQueueFront(22);
    // 头 11 7 6  5 4 3 2 1  100 101 102 103 104 105 106 null null null null null null 12 尾
    while (!queue->isEmpty()) {
        cout << queue->deQueueFront() << endl;
    }
    
    
}

int main(int argc, const char * argv[]) {
//    testDueue();
//    testCircle();
    testCircleDueue();
    return 0;
}
