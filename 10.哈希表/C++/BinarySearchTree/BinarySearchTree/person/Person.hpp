//
//  Person.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/16.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Person{
    int age;
    float height;
    string name;
    bool operator==(Person &person);
    int hashCode();
    int compareTo(Person &person);
};
#endif /* Person_hpp */
