//
//  SubKey2.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef SubKey2_hpp
#define SubKey2_hpp

#include <stdio.h>

class SubKey2: public Key{
public:
    SubKey2(int value):Key(value){
        
    }
    bool operator==(const SubKey2 & key) const
           {
    //           if (key != *this) {
    //               return false;
    //           }
                return key.value == value;
           }
};

#endif /* SubKey2_hpp */
