//
//  Hanoi.hpp
//  17.递归
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef Hanoi_hpp
#define Hanoi_hpp
#include <string>


/*
 A      B       C
 汉诺塔-思路
 - 其实分2中情况讨论即可
    - 当n == 1时，直接将盘子从A移动到C
    - 当n > 1时，可以拆分成3个步骤
        - 1.将n-1个盘子从A移动到B
        - 2.将编号为n的盘子从A移动到C
        - 3.将n - 1个盘子从B移动到C
 */

#include <stdio.h>
using namespace std;

class Hanoi{
public:
    //将i号盘子从from移动到to
    void move(int i,string from,string to){
        cout << i << "号盘子: " << from << "->" << to << endl;
    }
    
    /*
     将n个盘子从p1移动到p3
     T(n) = 2 + T(n-1) + O(1)
     因此时间复杂度是:O(2^n)
     空间复杂度是:O(n)
     */
    void hanoi(int n,string p1, string p2, string p3){
        if (n <= 1) {
            move(n, p1, p3);
            return;
        }
        hanoi(n - 1, p1, p3, p2);
        move(n, p1, p3);
        hanoi(n - 1, p2, p1, p3);
    }
};


#endif /* Hanoi_hpp */
