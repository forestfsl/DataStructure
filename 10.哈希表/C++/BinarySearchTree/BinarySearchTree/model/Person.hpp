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
public:
    int age;
    float height;
    string name;
    Person(int age,float height,string name){
        this->age = age;
           this->height = height;
           this->name = name;
    }

    bool operator==(const Person & person) const
       {
           return person.age == age && person.height == height && person.name == name;
       }
    int hashCode(){
        int hashCode =(int)hash<int>()(age);
          hashCode = hashCode * 31 + (int)hash<int>()(height);
          hashCode = hashCode * 31 +  (int)hash<string>()(name);
          return hashCode;
    }
    int compareTo(Person &person){
         return age - person.age;
    }
};

struct hash_name1{
    size_t operator()(const Person & p) const{
        size_t hashCode =(int)hash<int>()(p.age);
        hashCode = hashCode * 31 + (int)hash<int>()(p.height);
        hashCode = hashCode * 31 +  (int)hash<string>()(p.name);
        return hashCode;
//         return hash<string>()(p.name) ^ hash<int>()(p.age) ^ hash<float>()(p.height);//
    }
};

//struct hash_name{
//    size_t operator()(const Person & p) const{
//        return hash<string>()(p.name) ^ hash<int>()(p.age);// hash<string>()(p.name)就是求这个string对应hash值得方法
//    }
//};

#endif /* Person_hpp */
