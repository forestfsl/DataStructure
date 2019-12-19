//
//  Student.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp


#include <stdio.h>
#include "Person.hpp"

class Student: public Person{
public:
    Student(int age,float height, string name): Person(age,height,name){
        
    }
};

#endif /* Student_hpp */
