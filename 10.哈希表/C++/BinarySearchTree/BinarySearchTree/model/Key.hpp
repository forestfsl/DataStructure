//
//  Key.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Key_hpp
#define Key_hpp

#include <stdio.h>

class Key{
public:
    int value;
    Key(int value){
        this->value = value;
    }
   virtual bool operator==(const Key & key) const
    {
        return key.value == value;
    }
   

};

struct hash_keyName{
       int operator()(const Key & key) const{
           return key.value / 10;
       }
   };
#endif /* Key_hpp */
