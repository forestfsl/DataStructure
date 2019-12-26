#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    int boneBreak;
    
    Person(){
        
    }
    Person(string name,int boneBreak){
        this->name = name;
        this->boneBreak = boneBreak;
    }
   
     friend ostream &operator <<(ostream &os,Person &p1)
   {
             return      os <<"Person [name=" << p1.name  << ",boneBreak="<< p1.boneBreak;
   }
};
