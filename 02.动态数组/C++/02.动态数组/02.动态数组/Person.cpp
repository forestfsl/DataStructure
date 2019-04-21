//
//  Person.cpp
//  02.动态数组
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "Person.hpp"
#include <iostream>
using namespace std;
//::是域运算符
//实现.cpp源文件
Person::Person(){
    cout << "Person()" << endl;
}
Person::Person(int age, char *name):m_age(age),m_name(name){
    cout << "Person(int age, char *name)" << endl;
}

Person::Person(const Person &person):m_age(person.m_age),m_name(person.m_name){
     cout << "Person(const Person &person)" << endl;
}

ostream &operator<<(ostream &cout, const Person &person) {
    return cout << "person 对象地址是" << person << "age=" << person.m_age << "name=" << person.m_name;
}

Person::~Person(){
    cout << "~Person()"<< endl;
}

void Person::setAge(int age){
    this->m_age = age;
}



int Person::getAge(){
    return this->m_age;
}
