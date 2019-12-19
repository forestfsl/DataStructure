//
//  SubKey.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef SubKey_hpp
#define SubKey_hpp

#include <stdio.h>
#include "SubKey2.hpp"

class SubKey1:public Key{
public:

    SubKey1(int value):Key(value){
        
    }
//    bool operator!=(const SubKey1 & key1) const
//          {
//              if (key1 == *this) {
//                  return true;
//              }
//              return false;
//          }
    
    bool operator==(const SubKey1 & key) const
       {
//           if (key != *this) {
//               return false;
//           }
            return key.value == value;
       }
    
};

#endif /* SubKey_hpp */
