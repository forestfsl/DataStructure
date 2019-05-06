//
//  main.cpp
//  03.链表
//
//  Created by fengsl on 2019/4/21.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

class Person {
public:
    int age;
    string name;
    Person(string name,int age) {
        this->name = name;
        this->age = age;
    }
    ~Person() {
        cout<<"~Person()"<<endl;
    }
    /// 重载 == 操作符 类似 equals 方法
    bool operator ==(Person *p) {
        if (p->name == this->name && p->age == this->age) {
            return true;
        }
        return false;
    }
};

void test2(){
    LinkedList<Person *> *list = new LinkedList<Person *>();
    Person *p1 = new Person(string("fengsl"),20);
    Person *p2 = new Person(string("fengsl1"),40);
    Person *p3 = new Person(string("fengsl2"),30);
    list->add(p1);
    list->add(p2);
    list->add(p3);
    list->toString();
    int index = list->indexOf(p3);
    cout  << index << endl;
    
    //因为java和c++不同，这里调用clear()方法Person对象的内存是不会销毁的，这个在第一天复杂度的时候有提到过，注意一下
//    list->clear();
    list->clear_element([] (Person *person){
        delete person;
    });
    
    delete list;
}

void test1(){
   
    LinkedList<int> *list = new LinkedList<int>();
    list->add(10);
    list->add(20);
    list->add(30);
    list->add(40);
    list->set(0, 30);
    int removeE = list->remove(3);
    cout << removeE << endl;
    
    list->toString();
    delete list;
   
}



int main(int argc, const char * argv[]) {
    // insert code here...
    test2();
   
    return 0;
}
