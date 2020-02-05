//
//  BruteForce01.hpp
//  25.字符串
//
//  Created by fengsl on 2020/2/4.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef BruteForce01_hpp
#define BruteForce01_hpp

#include <stdio.h>
using namespace std;


/*
 性能分析
 n是文本串长度，m是模式串长度
 最多n-m+1轮
 
 最好情况
 -只需一轮比较就完全匹配，比较m次
 -时间复杂度O(m)
 
 最坏情况(字符集越大，出现概率越低)
 执行了n-m+1轮比较（n是文本串的长度）
 每轮都比较致模式串的末字符后失败(m-1次成功，1次失败)
 时间复杂度O(m *(n-m+1)),由于一般m远小于n，所以为O(nm)
 */


class BruteForce01 {
public:
    
    //优化 在恰当的时候可以提前退出，减少比较次数
    static int indexOf(char text[],int tlen,string pattern){
        if (text == nullptr) return -1;
        if (tlen == 0) return -1;
        string name = pattern;
        char buf[] = {0};
        strcpy(buf , name.c_str());//字符串转字符数组，使用strcpy
        int plen = sizeof(buf) / sizeof(buf[0]);
        if (plen == 0) return -1;
        if (tlen < plen) return -1;
        
        int pi = 0;
        int ti = 0;
        int lenDelta =  tlen - plen;
        while (pi < plen && ti - pi <= lenDelta) {
            if (text[ti] == buf[pi]) {
                ti++;
                pi++;
            }else{
                ti -= pi - 1;
                pi = 0;
            }
        }
        return (pi == plen) ? (ti - pi) : -1;
    }
    //未优化
    static int indexOf2(char text[],int tlen,string pattern){
        if (text == nullptr) return -1;
        if (tlen == 0) return -1;
        string name = pattern;
        char buf[] = {0};
        strcpy(buf , name.c_str());//字符串转字符数组，使用strcpy
        int plen = sizeof(buf) / sizeof(buf[0]);
        if (plen == 0) return -1;
        if (tlen < plen) return -1;
        
        int pi = 0,ti = 0;
        while (pi < plen && ti < tlen) {
            if (text[ti] == buf[pi]) {
                ti++;
                pi++;
            }else{
                ti -= pi - 1;
                pi = 0;
            }
        }
        return (pi == plen) ? (ti - pi) : -1;
    }
    
    /*
     ti 是指每一轮比较中Text收个比较字符的位置
     匹配失败：pi=0；ti++
     匹配成功:pi == plen;
     */
    static int indexOf3(char text[],int tlen,string pattern){
        if (text == nullptr) return -1;
               if (tlen == 0) return -1;
               string name = pattern;
               char buf[] = {0};
               strcpy(buf , name.c_str());//字符串转字符数组，使用strcpy
               int plen = sizeof(buf) / sizeof(buf[0]);
               if (plen == 0) return -1;
               if (tlen < plen) return -1;
        int tiMax = tlen - plen;
        for (int ti = 0; ti <= tiMax; ti++) {
            int pi = 0;
            for (; pi < plen; pi++) {
                if (text[ti + pi] != buf[pi]) break;
            }
            if (pi == plen) return ti;
        }
        return -1;
    }
    
};

#endif /* BruteForce01_hpp */
