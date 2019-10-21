//
//  EvalRPN150.cpp
//  leetcodePratice
//
//  Created by fengsl on 2019/10/20.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution150 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        
        for (int i = 0;i < tokens.size() ;++ i) {
            int n2 = 0;
            int n1 = 0;
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                n2 = numbers.top();
                numbers.pop();
                n1 = numbers.top();
                numbers.pop();
            }
           
            if (tokens[i] == "+") {
                numbers.push( n1 + n2);
            }else if(tokens[i] == "/"){
                numbers.push(n1 / n2);
            }else if(tokens[i] == "*"){
                numbers.push(n1 * n2);
            }else if(tokens[i] == "-"){
                numbers.push(n1 - n2);
            }
            else{
                numbers.push(stoi(tokens[i]));
            }
           
        }

        
        return numbers.top();
    }
   
    void static test150(){
        Solution150 solution = Solution150();
//        vector<string> evalRPNList = {"2","1","+","3","*"};
        vector<string> evalRPNList = {"4","13","5","/","+"};
       cout << "逆波兰表达式求值" << solution.evalRPN(evalRPNList) << endl;
    }
    bool  isOperator(string token){
        string tokenStr = "+-*/";
        string::size_type idx;
        idx = tokenStr.find(token);
        if(idx == string::npos )//不存在。
        {
            cout << "not found\n";
            return false;
        }else//存在。
        {
            cout <<"found\n";
            return true;
        }
        
    }
};
