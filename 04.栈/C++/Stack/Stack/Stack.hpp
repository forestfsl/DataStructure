//
//  Stack.hpp
//  Stack
//
//  Created by songlin on 2019/11/5.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp


#include <stdio.h>
#include "LinkedList2.hpp"
#include <iostream>
using namespace std;

template <class E>
class Stack : LinkedList2<E>{
private:
    LinkedList2<E> *list = new LinkedList2<E>();
public:
    Stack(){
        cout << "stack" << endl;
    }
    ~Stack(){
        cout << "~stack" << endl;
    }
    void clear(){
        list->clear();
    }
    int size(){
        return list->size();
    }
    bool isEmpty(){
        return list->isEmpty();
    }
    void push(E element){
        list->add(element);
    }
    E pop(){
        return list->remove(list->size() - 1);
    }
    E top(){
        return list->get(list->size() - 1);
    }
};
#endif /* Stack_hpp */
