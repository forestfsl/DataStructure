//
//  main.cpp
//  02.动态数组
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>
#include "Person.hpp"
#include "ArrayList.hpp"


template <typename Item>
class NSNumber {
private:
    Item _data;
public:
    NSNumber(Item data) : _data(data) {
        
    }
    ~NSNumber() {
        cout << "~NSNumber()" << endl;
    }
};

//调用有参构造函数ArrayList(int capacity)
//无参调用有参函数ArrayList()
//Person(int age, char *name)
//~Person()
//调用析构函数 ~ArrayList()
void test2(){
    cout << "test2 ##################################";
    ArrayList<Person>array(2);
    
  
    Person *person = new Person(10, (char *)"fengsl");
   
    array.add(*person);
    delete person;
    person = nullptr;
    
 //下面这句会调用两次构造函数*p 调用一次构造函数，add的时候又调用一次构造函数
//    Person(const Person &person)
//    Person(const Person &person)
//    ~Person()
//    ~Person()
//    array.add(*person);
    

    
//调用一次有参初始化，一次拷贝构造，说明假如对象Person(10, (char *)"fengsl") 和加入*person 调用方法不一样，但是add的时候最终调用的都是
//拷贝构造函数
//    Person(int age, char *name)
//    Person(const Person &person)
//    ~Person()
//    ~Person()
//    array.add(Person(10, (char *)"fengsl"));
    

//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
//    array.add(Person(10, (char *)"fengsl"));
}


void test1(){
    ArrayList<Person *> *persons = new ArrayList<Person *>();
    persons->add(new Person(1,(char *)"fengsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
//    persons->add(new Person(2,(char *)"songsl"));
    //    persons->display();
        persons->clear();
        delete  persons;
    
    //    ArrayList<NSNumber<int>*> *ints = new ArrayList<NSNumber<int>*>();
    //    ints->add(new NSNumber<int>(10));
    //    ints->add(new NSNumber<int>(10));
    //    ints->add(new NSNumber<int>(22));
    //    ints->add(new NSNumber<int>(33));
    //
    //    ints->display();
    //
    //    ints->clear();
    //
    //    delete ints;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //test1 和test2 说明了内存在栈中和d在堆中的区别
    test1();
    test2();
    return 0;
}

