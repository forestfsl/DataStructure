//
//  main.cpp
//  25.字符串
//
//  Created by fengsl on 2020/2/4.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#include <iostream>
#include "BruteForce01.hpp"
#include "KMP.hpp"
using namespace std;

/*
 串(Sequence)
 
 字符串thank的前缀(prefix），真前缀(proper prefix),后缀(suffix),真后缀(proper suffix)
 - 前缀 t,th,tha,than,thank
 - 真前缀 t,th,tha,than
 - 后缀 thank,hank,ank,nk,k
 - 真后缀 hank,ank,nk,k
 
 几个经典的串匹配算法
 蛮力(Brute Force)
 KMP
 Boyer-Moore
 Rabin-Karp
 Sunday
 */


 //字符串转字符数组
//        string name = "ABC";
//        char buf[] = {0};
//        strcpy(buf , name.c_str());//字符串转字符数组，使用strcpy
//        cout << name.c_str() << endl;//name.c_str()将字符串转换成字符数组
//        cout << buf << endl;

//        //字符数组转字符串
//        char buf1[]= "哈哈哈哈";
//        string name1;
//        name1 = buf1;
//        cout << name1 << endl;

void testBruteForce01(){
    char text[] = {"HelloWorld"};
    int len = sizeof(text) / sizeof(text[0]);
    
    cout << "e 在字符串中的索引是"<< BruteForce01::indexOf(text,len, "e") << endl;
}

void testKMP(){
    char text[] = {"HelloWorld"};
   int len = sizeof(text) / sizeof(text[0]);
   
   cout << "e 在字符串中的索引是"<< KMP::indexOf(text,len, "e") << endl;
}

int main(int argc, const char * argv[]) {
    testBruteForce01();
    testKMP();
 
    return 0;
}
