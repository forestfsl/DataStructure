//
//  ValidSuduKu36.cpp
//  leetcodePratice
//
//  Created by fengsl on 2019/11/3.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "ValidSuduKu36.hpp"
#include <set>

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
    cout << solution.isValidSudoku(board) << endl;
}
