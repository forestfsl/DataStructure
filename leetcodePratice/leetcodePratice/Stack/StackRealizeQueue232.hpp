//
//  StackRealizeQueue232.hpp
//  leetcodePratice
//
//  Created by songlin on 2019/11/7.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef StackRealizeQueue232_hpp
#define StackRealizeQueue232_hpp
//232. 用栈实现队列 https://leetcode-cn.com/problems/implement-queue-using-stacks/
#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;


//思路：创建两个栈，一个in，一个out，执行push的时候都是往in里面push，举个例子说明一下，加入现在push1 push2 push3，现在假如想模拟队列功能，先进先出的功能，那么1就首先要被pop出来，所以就要反方向顺序将3，2，1分别入栈到out，那么这个时候就是1在最上面了，可以利用栈的特性，直接弹出，此时out里面还有两个元素，那么下次pop的时候首先就要先检查out是否为空，如果out为空，才从in里面获取元素并且push进去out，否则直接从out弹出即可
class MyQueue {
private:
    stack<int>instack;
    stack<int>outstack;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
       
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        checkOutStack();
       int topElement = outstack.top();
        outstack.pop();
        return topElement;
    }
    
    /** Get the front element. */
    int peek() {
        checkOutStack();
       return  outstack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
          return instack.empty() && outstack.empty();
    }
    /** check is nil*/
    void checkOutStack(){
        if (outstack.empty()) {
            while (!instack.empty()) {
                outstack.push(instack.top());
                instack.pop();
            }
        }
    }
};
#endif /* StackRealizeQueue232_hpp */
