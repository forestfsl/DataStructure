//
//  main.cpp
//  18.回溯
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#include <iostream>
#include "BackTracking1.hpp"
#include "BackTracking2.hpp"
#include "BackTracking3.hpp"
using namespace std;


void testBackTracking1(){
    BackTracking1 backTracking = BackTracking1();
    backTracking.placeQueens(8);
}

void testBackTracking2(){
    BackTracking2 backTracking = BackTracking2();
    backTracking.placeQueens(8);
}

void testBackTracking3(){
    BackTracking3 backTracking = BackTracking3();
    backTracking.placeQueens();
}

int main(int argc, const char * argv[]) {
//    testBackTracking1();
//    testBackTracking2();
     testBackTracking3();
    return 0;
}
