//
//  BackTracking3.hpp
//  18.回溯
//
//  Created by fengsl on 2020/1/24.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef BackTracking3_hpp
#define BackTracking3_hpp

#include <stdio.h>

class  BackTracking3{
public:
    /*
     数组索引是行号，数组元素是列号
     */
    int *queens;
    /*
     标记着某一个是否有皇后
     */
    int cols;
    /*
     标记着某一斜线上是否有皇后(左上角-->右下角)
     */
    int leftTop;
    int rightTop;
    int ways;
    int len;
    
    void placeQueens(){
        queens = new int[8]{};
        len = 8;
        place(0);
        cout << "8皇后一共有" << ways << "种摆法" << endl;
    }
    
    void place(int row){
        if (row == 8) {
            ways++;
            show();
            return;
        }
        
        // 01111101 n
       //&11111011  ~00000100
       // 01111001
        
        for (int col = 0; col < len; col++) {
            // & 取值
            int cv = 1 << col;//移动col代表需要取那个col的二进制的值
            if ((cols & cv) != 0) continue;
            
            int lv = 1 << (row - col + 7);
            if ((leftTop & lv) != 0) continue;
            
            int rv = 1 << (row + col);
            if ((rightTop & rv) != 0) continue;
            
            
           
            
            // | 赋值
            queens[row] = col;
            cols |= cv;
            leftTop |= lv;
            rightTop |= rv;
            place(row + 1);
            cols &= ~cv;
            leftTop &= ~lv;
            rightTop &= ~rv;
        }
    }
    
    void show(){
        for (int row = 0; row < len; row++) {
            for (int col = 0; col < len; col++) {
                if (queens[row] == col) {
                    cout << "1 ";
                }else{
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        cout << "----------------------------------------------" << endl;
    }
    
};

#endif /* BackTracking3_hpp */
