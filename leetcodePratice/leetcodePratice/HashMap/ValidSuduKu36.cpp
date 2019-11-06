//
//  ValidSuduKu36.cpp
//  leetcodePratice
//
//  Created by fengsl on 2019/11/3.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "ValidSuduKu36.hpp"
#include <set>
//
//class Solution {
//public:
//    bool isValidSudoku(vector<vector<char>>& board) {
//        vector<vector<int>> rows(9, vector<int>(10, 0));//共9行，每行10个数字对应0~9
//        vector<vector<int>> cols(9, vector<int>(10, 0));//9列
//        vector<vector<int>> cell(9, vector<int>(10, 0));//9个单元格
//        for (int i = 0; i < 9; ++i) {
//            for (int j = 0; j < 9; ++j) {
//                if(board[i][j]=='.') continue;
//                int e = board[i][j] - '0';
//                if (rows[i][e] == 0) rows[i][e]++;
//                else return false; //如果有重复的直接返回false
//                if (cols[j][e] == 0) cols[j][e]++;
//                else return false;
//                int ci = map(i, j);
//                if (cell[ci][e] == 0) cell[ci][e]++;
//                else return false;
//            }
//        }
//        return true;
//    }
//    int map(int i, int j) {
//        int a = i / 3;
//        int b = j / 3;
//        return a + b * 3;
//    }
//};

bool Solution36::isValidSudoku2(vector<vector<char>>& board){
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
             char num = board[row][col];
            if (num == '.') continue;
            num -= '1';//数组是从0到8，如果不减去1的话，数组会越界
            if (rows[row][num]) return false;
            if (cols[col][num]) return false;
            int boxIndex = (row / 3) * 3 + col / 3;
            if (boxes[boxIndex][num]) return false;
            rows[row][num] = true;
            cols[col][num] = true;
            boxes[boxIndex][num] = true;
        }
       
        
    }
    return true;
}

bool Solution36::isValidSudoku3(vector<vector<char>>& board){
    short rows[9] = {0};
    short cols[9] = {0};
    short boxes[9] = {0};
    short cur = 0;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int num = board[row][col];
            if (num == '.') continue;
            cur = (short)(1 << (num - '1'));
            if ((rows[row] & cur) != 0) return false;
            if ((cols[col] & cur) != 0) return false;
            int boxIndex = row / 3 * 3 + col / 3;
            if ((boxes[boxIndex] & cur) != 0) return false;
            rows[row] += cur;
            cols[col] += cur;
            boxes[boxIndex] += cur;
        }
    }
    return true;
}

bool Solution36::isValidSudoku(vector<vector<char>>& board){
    set<char> rows[9];
    set<char>cols[9];
    set<char>boxes[9];
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            char num = board[row][col];
            if (num == '.') continue;
            int boxIndex = (row / 3) * 3 + col / 3;
            if(rows[row].count(num)) return false;
            if(cols[col].count(num)) return false;
            if (boxes[boxIndex].count(num)) return false;
            rows[row].insert(num);
            cols[col].insert(num);
            boxes[boxIndex].insert(num);
        }
    }
    
    return true;
}

void Solution36::test36(){
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution36 solution = Solution36();
    cout << solution.isValidSudoku3(board) << endl;
}
