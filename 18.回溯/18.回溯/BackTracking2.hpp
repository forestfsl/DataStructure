//
//  BackTracking2.hpp
//  18.回溯
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef BackTracking2_hpp
#define BackTracking2_hpp

#include <stdio.h>

class BackTracking2{
public:
    //数组索引是行号，数组元素是列号
    int *queens;
    //标记着某一列是否有皇后
    bool *cols;
    //标记着某一斜线是否有皇后(左上角--->右下角)
    bool *leftTop;
    //标记着某一斜线上是否有皇后(右上角-->左下角)
    bool *rightTop;
    int len;
    //一共有多少种摆法
    int ways;
    void placeQueens(int n){
        if (n < 1) return;
        queens = new int[n]{0};
        len = n;
        cols = new bool[n]{false};
        leftTop = new bool[(n << 1) - 1]{false};
        rightTop = new bool[(n << 1) - 1]{false};
        place(0);
        cout << n << "皇后一共有" << ways << "种摆法" << endl;
    }
    /*
     从第row行开始摆放皇后
     */
    void place(int row){
        if (row == len) {
            ways++;
            show();
            return;
        }
        for (int col = 0; col < len; col++) {
            if (cols[col]) continue;
            int ltIndex = row - col + len - 1;
            if(leftTop[ltIndex]) continue;
            int rtIndex = row + col;
            if(rightTop[rtIndex]) continue;
            
            queens[row] = col;
            cols[col] = true;
            leftTop[ltIndex] = true;
            rightTop[rtIndex] = true;
            place(row + 1);
            cols[col] = false;
            leftTop[ltIndex] = false;
            rightTop[rtIndex] = false;
        }
    }
    void show(){
        for (int row = 0; row < len; row++) {
            for (int col = 0; col < len; col++) {
                if (queens[row] == col) {
                    cout << "1 ";
                }else{
                    cout <<"0 ";
                }
            }
            cout << endl;
        }
        cout << "---------------------------------------------" << endl;
    }
};

#endif /* BackTracking2_hpp */
