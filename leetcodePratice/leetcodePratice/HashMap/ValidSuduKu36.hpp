//
//  ValidSuduKu36.hpp
//  leetcodePratice
//
//  Created by fengsl on 2019/11/3.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef ValidSuduKu36_hpp
#define ValidSuduKu36_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution36 {
public:
    bool isValidSudoku(vector<vector<char>>& board);
    bool isValidSudoku2(vector<vector<char>>& board);
    bool isValidSudoku3(vector<vector<char>>& board);
    void static test36();
};

#endif /* ValidSuduKu36_hpp */
