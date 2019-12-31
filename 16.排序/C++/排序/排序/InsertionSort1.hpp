//
//  InsertionSort1.hpp
//  排序
//
//  Created by songlin on 2019/12/31.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef InsertionSort1_hpp
#define InsertionSort1_hpp

#include <stdio.h>
#include "Sort.hpp"

template <class T>
class InsertionSort1:public Sort<T> {
public:
      InsertionSort1(int len,string name):Sort<T>(len,name){
            
        }
        void extensionSort(){
            int len = this->getArrayLen();
            for (int begin = 1; begin < len; begin++) {
//                  cout << "-------------InsertionSort1--------------------" << endl;
                int cur = begin;
                while (cur > 0 && this->cmp(cur,cur - 1) < 0) {
                    this->swap(cur, cur - 1);
                    cur--;
                }
            }
           
        }
};

#endif /* InsertionSort1_hpp */
