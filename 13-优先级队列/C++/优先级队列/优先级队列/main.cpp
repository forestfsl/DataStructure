//
//  main.cpp
//  优先级队列
//
//  Created by songlin on 2019/12/26.
//  Copyright © 2019 toucu. All rights reserved.
//

#include <iostream>
#include "Person.hpp"
#include "PriorityQueue.hpp"

auto lamba = [] (Person p1,Person p2) ->int{
    return p1.boneBreak - p2.boneBreak;
};

void testPriorityQueue(){
    PriorityQueue<Person> *queue =new PriorityQueue<Person>(lamba);
    queue->enQueue(Person("jack",2));
    queue->enQueue(Person("Rose",10));
    queue->enQueue(Person("Linda",5));
    queue->enQueue(Person("Jordom",15));
    while (!queue->isEmpty()) {
      queue->deQueue();
    }
}

int main(int argc, const char * argv[]) {
    testPriorityQueue();
    return 0;
}
