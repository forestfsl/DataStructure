//
//  Person.cpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/16.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "Person.hpp"

bool Person::operator==(Person &person){
    
    return person.age == age && person.height == height && person.name == name;
}

int Person::hashCode(){
    int hashCode =(int)hash<int>()(age);
    hashCode = hashCode * 31 + (int)hash<int>()(height);
    hashCode = hashCode * 31 +  (int)hash<string>()(name);
    return hashCode;
}

int Person::compareTo(Person &person){
    return age - person.age;
}

