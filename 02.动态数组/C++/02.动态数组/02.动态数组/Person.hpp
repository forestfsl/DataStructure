//
//  Person.hpp
//  02.动态数组
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

//声明.h头文件
class Person {
    int m_age;
    char *m_name;
    friend ostream &operator<<(ostream &, const Person &);
public:
    Person();
    Person(int age, char * name);
    Person(const Person &person);
    ~Person();
    void setAge(int age);
    int getAge();
};



#endif /* Person_hpp */
