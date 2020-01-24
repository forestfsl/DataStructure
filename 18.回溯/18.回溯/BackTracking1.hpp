//
//  BackTracking1.hpp
//  18.回溯
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef BackTracking1_hpp
#define BackTracking1_hpp

#include <stdio.h>
using namespace std;

class BackTracking1{
public:
    //数组索引是行号，数组元素是列号
    int *cols;
    int len;
    //一共有多少种摆法
    int ways;
    void placeQueens(int n){
        if (n < 1) return;
        cols = new int[n]{0};
        len = n;
        place(0);
        cout << n << "皇后一共有" << ways << "种摆法" << endl;
    }
    //从row行开始摆放皇后
    void place(int row){
        if (row == len) {
            ways++;
            show();
            return;
        }
        for (int col = 0; col < len; col++) {
            if (isValid(row, col)) {
                //在第row行第col列摆放皇后
                cols[row] = col;
                place(row + 1);
            }
        }
    }
    
    //判断row行第col列是否可以摆放皇后
    bool isValid(int row, int col){
        for (int i = 0; i < row; i++) {
            //第col列已经有皇后
            if (cols[i] == col) {
                cout << "[" << row << "][" << col << "]=false" << endl;
                return false;
            }
            //第i行的皇后和第row行第col列格子处在同一斜线上
            if (row - i == abs(col - cols[i])) {
                cout << "[" << row << "][" << col << "]=false" << endl;
                return false;
            }
        }
        cout << "[" << row <<"][" << col << "]=true" << endl;
        return true;
    }
    
    void show(){
        for (int row = 0; row < len; row++) {
            for (int col = 0; col < len; col++) {
                if (cols[row] == col) {
                    cout << "1 ";
                }else{
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        cout << "--------------------------------------------------------" << endl;
    }
};

#endif /* BackTracking1_hpp */
