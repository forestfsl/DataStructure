//
//  ValidSympol20.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/11/7.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "ValidSympol20.hpp"
#include <map>
#include <stack>

//https://www.runoob.com/cplusplus/cpp-strings.html string介绍


bool Solution20::isValid3(string s){
   stack<char> st;
    int lenght = (int)s.length();
  
    for (int i = 0; i < lenght; i++) {
          char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }else{
            if (st.empty()) return false;
            char left = st.top();
            st.pop();
            if (left == '(' && c != ')') return false;
            if (left == '[' && c != ']') return false;
            if (left == '{' && c != '}') return false;
        }
    }
    return st.empty();
}

//思路：首先栈为空的时候，直接push入栈，当栈不为空的时候，直接就将元素入栈就是是左括号也没有问题，因为最后遍历完，stack还是会被pop空的，如果最后没有pop空或者栈的元素比字符串一半的元素要多的时候，这些都是不符合的情况
bool Solution20::isValid2(string s){
    if (s.empty()) {
        return true;
    }
    map<char, char> sMap = {{')', '('},
        {'}', '{'},
        {']', '['}};
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty()) {
            st.push(s[i]);
        } else {
            if (sMap[s[i]] != st.top()) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        if (st.size() > s.size() / 2) {
            return false;
        }
    }
    return st.empty();
}

//思路：预算创建好map，map中key为左括号，value为右括号，然后遍历字符集，如果key中包含字符，就push进stack，如果是y不包含，自然而然就是右括号，所以会将stacka顶部keey元素然后从map中取出对应的value，判断是否相等，不相等就返回false
bool Solution20::isValid(string s){
    map<char,char> map;
    map.insert(pair<char, char>('(', ')'));
    map.insert(pair<char, char>('{', '}'));
    map.insert(pair<char, char>('[', ']'));
    stack<char>stack;
    
    int length = (int)s.length();
    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (map.count(s[i])) { //左括号
            stack.push(c);
        }else{
            //右括号
            if (stack.size() == 0 ) return false;
            if (c != map[stack.top()]) return false;
            stack.pop();
        }
    }
    
    return stack.size() == 0;
}

void Solution20::test20(){
    string str1 = "()[]{}";
    Solution20 solution = Solution20();
    cout << solution.isValid3(str1) << endl;
}
