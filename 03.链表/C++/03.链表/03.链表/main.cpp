//
//  main.cpp
//  03.链表
//
//  Created by fengsl on 2019/4/21.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
#include "LinkedList2.hpp"
#include "SingleCircleLinkedList.hpp"
#include "DoubleCircleLinkedList.hpp"

class Person {
public:
    int age;
    string name;
    Person(string name,int age) {
        this->name = name;
        this->age = age;
        cout << "Person()" << endl;
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
    friend ostream &operator<<(ostream &stream, const Person *p)
    {
        stream << p->name << "的年龄是"<< p->age << endl;
        return stream;
    }
};

//测试单向链表
void test2(){
    LinkedList<Person *> *list = new LinkedList<Person *>();
    Person *p1 = new Person(string("fengsl"),20);
    Person *p2 = new Person(string("fengsl1"),40);
    Person *p3 = new Person(string("fengsl2"),30);
    list->add(p1);
    list->add(p2);
    list->add(p3);
    list->toString();
//    int index = list->indexOf(p3);
//    cout  << index << endl;
//    
//    //因为java和c++不同，这里调用clear()方法Person对象的内存是不会销毁的，这个在第一天复杂度的时候有提到过，注意一下
////    list->clear();
//    list->clear_element([] (Person *person){
//        delete person;
//    });
//    list->clear_element(void (*clearFunc)(Person *))
    
    delete list;
}

//测试双向链表
void test3(){
    LinkedList2<Person *> *list = new LinkedList2<Person *>();
    Person *p1 = new Person(string("fengsl"),20);
    Person *p2 = new Person(string("fengsl1"),40);
    Person *p3 = new Person(string("fengsl2"),30);
    Person *p4 = new Person(string("fengsl3"),60);
    list->add(p1);
    list->add(p2);
    list->add(p3);
    list->toString();
    int index = list->indexOf(p3);
    cout  << index << endl;
    list->set(0,p4);
    cout << "##################" << endl;
    cout << list->get(0) << endl;
    list->toString();

    list->clearElement([] (Person *person){
        delete person;
    });
     delete p1;
     delete list;
}

void josephuse(){
    DoubleCircleLinkedList<int> *list = new DoubleCircleLinkedList<int>();
    for (int i = 1; i <= 8; i++) {
        list->add(i);
    }
    list->reset();
    while (!list->isEmpty()) {
        list->next();
        list->next();
        cout << list->remove() << endl;
    }
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

void testSingleCircleList(){
    SingleCircleLinkedList<Person *> *list = new SingleCircleLinkedList<Person *>();
    Person *p1 = new Person(string("fengsl"),20);
    Person *p2 = new Person(string("fengsl1"),40);
    Person *p3 = new Person(string("fengsl2"),30);
    Person *p4 = new Person(string("fengsl3"),60);
    list->add(p1);
    list->add(p2);
    list->add(p3);
    list->toString();
    int index = list->indexOf(p3);
    cout  << index << endl;
    list->set(0,p4);
    cout << "##################" << endl;
    cout << list->get(0) << endl;
    list->toString();

    list->clearElement([] (Person *person){
        delete person;
    });
    delete p1;
    delete list;
}
class Person1
{

public:
    int age;
    string name;
    
    void SetAge(int age)
    {
        this->age = age;
    }
    friend ostream &operator<<(ostream &stream, const Person1 &p)
    {
        stream << p.age << endl;
        return stream;
    }
};
int main(int argc, const char * argv[]) {
//    Person1 a;
//    a.SetAge(10);
//    cout << a << endl;
    
   
//    test3();
//    testSingleCircleList();
    josephuse();
   
    return 0;
}
