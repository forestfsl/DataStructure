//
//  DailyTemperatures739.cpp
//  leetcodePratice
//
//  Created by songlin on 2019/10/23.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "DailyTemperatures739.hpp"

//跳跃法 从右到左对比
vector<int> Solution739::dailyTemperatures(vector<int> &T){
    vector<int> result(T.size());
    //最后一个元素肯定为0，因为后面没有元素对比
    result[T.size() - 1] = 0;
    int iLength = int(T.size() - 2);
    int jLength = int(T.size());
    //遍历元素,外层遍历
    for (int i = iLength; i >= 0; i--) {
        //内层遍历，对比元素 j += rsult[j] 这一步就是跳过一些不符合条件的元素，减少对比次数
        /*
         举个例子说明一下，假如现在i=2，T[i] = 75,j=3,T[j] = 71,75 < 71 ,但是后面比71大的值是72,索引是5，那么result[3] = 2；第一轮对比不匹配之后，会进行第二次对比，那么第二次对比的时候，只要找到比71大的最近一个元素即可，这样就可以减少比对次数，从而提升效率
         */
        for (int j = i + 1; j < jLength; j += result[j]) {
            if (T[i] < T[j]) {
                result[i] = j - i;
                break;
            }else if (result[j] == 0){
                result[i] = 0;
                break;
            }
        }
    }
    return result;
}

//栈对比法，只不过是反过来，里面保存着最大的元素，从右边开始，匹配到比top元素大的，就将top元素pop掉，然后将当前元素值入栈，当前元素值，是到最后一个元素的一个最大值，栈由此至终就最多存放一个元素
vector<int> Solution739::dailyTemperatures3(vector<int> &T){
    stack<int> s;
    int n = (int)T.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && T[i] >= T[s.top()]) {
            s.pop();
        }
        res[i] = s.empty() ? 0 : s.top() - i;
        s.push(i);
    }
    return res;

}

//栈对比法（入栈的是元素索引值）
/*
 1.思路是从首元素开始，如果栈为空的时候入栈
 2.当栈不为空时候，对比top元素和当前元素，如果top元素大于当前元素，就将当前元素索引值入栈，如果top元素小于当前元素的话，那么就有result[top元素索引] = 当前元素索引-top元素索引，
 */
vector<int> Solution739::dailyTemperatures2(vector<int> &T){
    stack<int>nodeStack;
    vector<int> result(T.size());
    int length = (int)T.size();
    for (int i = 0; i < length; i++) {
        //如果栈不为空，并且栈顶元素小于当前元素的话
   
        while (!nodeStack.empty()) {
            int topIndex = nodeStack.top();
            if ( T[topIndex] < T[i]) {
                result[topIndex]  = i - topIndex;
                nodeStack.pop();
            }else{
                result[i] = 0;
                break;
            }
        }
        nodeStack.push(i);
    }
    return result;
}

void Solution739::test739(){
    vector<int> test = {73,74,75,71,69,72,76,73};
    Solution739 solution = Solution739();
    vector<int> result = solution.dailyTemperatures3(test);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
