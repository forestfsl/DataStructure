//
//  main.cpp
//  15.并查集
//
//  Created by fengsl on 2020/1/5.
//  Copyright © 2020 FLP. All rights reserved.
//

/*
并查集也叫做不相交集合(Disjoint Set)
并查集有2个核心操作：
 查找（Find）：查找元素所在的集合（这里的集合并不是特指Set这种数据结构，是指广义的数据集合）
 合并（Union）：将两个元素的集合何成为一个集合
 
 有2中常见的实现思路
 - Quick Find
 查找(Find)的时间复杂度:O(1)
 合并(Union)的时间复杂度:O(n)
 
 - Quick Union
 查找(Find) 的时间复杂度：O(logn)，可以优化到O(@n),@(n) < 5
 合并(Union)的时间复杂度:O(logn),可以优化到O(@n),@(n) < 5
 
 */
#include <iostream>
#include "TimeTool.hpp"
#include "UnionFind_QF.hpp"
#include "UnionFind_QU.hpp"
#include "UnionFind_QU_S.hpp"
#include "UnionFind_QU_R_PC.hpp"
#include "UnionFind_QU_R.hpp"
#include "UnionFind_QU_R_PH.hpp"
#include "UnionFind_QU_R_PS.hpp"
#include <assert.h>
#include <thread>

using namespace std;

#define count  1000000

void testTime(UnionFind *uf,string title){
    
    
        uf->unionElement(0, 1);
        uf->unionElement(0, 3);
        uf->unionElement(0, 4);
        uf->unionElement(2, 3);
        uf->unionElement(2, 5);
        
        uf->unionElement(6, 7);
        uf->unionElement(8, 10);
        uf->unionElement(9, 10);
        uf->unionElement(9, 11);
        
        assert(!uf->isSame(2, 7));
        
        uf->unionElement(4, 6);
        assert(uf->isSame(2, 7));
        
   
    TimeTool::checkTime(title, [](UnionFind *uf){
        for (int i = 0; i < count; i++) {
            int v1 = rand() % count;
            int v2 = rand() % count;
            uf->unionElement(v1, v2);
        }
    },uf);
}


void thread01()
{

     testTime(new UnionFind_QF(count),"UnionFind_QF");
}
    
void thread02()
{

    testTime(new UnionFind_QU(count),"UnionFind_QU");
}

void thread03()
{

    testTime(new UnionFind_QU_S(count),"UnionFind_QU_S");
}

void thread04()
{

     testTime(new UnionFind_QU_R(count),"UnionFind_QU_R");
}

void thread05(){
    testTime(new UnionFind_QU_R_PC(count),"UnionFind_QU_R_PC");
    
}

void thread06(){
     testTime(new UnionFind_QU_R_PH(count),"UnionFind_QU_R_PH");
}

void thread07(){
     testTime(new UnionFind_QU_R_PS(count),"UnionFind_QU_R_PS");
}



void testUnion(){
    thread task01(thread01);
    thread task02(thread02);
    thread task03(thread03);
    thread task04(thread04);
    thread task05(thread05);
    thread task06(thread06);
    thread task07(thread07);
    task01.join();
    task02.join();
    task03.join();
    task04.join();
    task05.join();
    task06.join();
    task07.join();
}
int main(int argc, const char * argv[]) {
  
     testUnion();
   
    return 0;
}
