//
//  KMP.hpp
//  25.字符串
//
//  Created by fengsl on 2020/2/5.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef KMP_hpp
#define KMP_hpp

#include <stdio.h>

/*
 KMP 是Knuth-Morris-Pratt 的简称（取名自3位发明人的名字），于1977年发布
 
 KMP - next表的使用
 KMP会预算根据模式s串生成一张next表，一般是个数组
 当遇到不匹配的时候，pi = next[pi] ,然后向右移动pi - next[pi]的距离
 
 */

class KMP{
public:
    static int indexOf(char text[],int tlen,string pattern){
        if (text == nullptr) return -1;
       if (tlen == 0) return -1;
       string name = pattern;
       char buf[] = {0};
       strcpy(buf , name.c_str());//字符串转字符数组，使用strcpy
       int plen = sizeof(buf) / sizeof(buf[0]);
       if (plen == 0) return -1;
       if (tlen < plen) return -1;
        
      //next 表
        int *next = next2(pattern);
        int pi = 0,ti = 0,lenDelta = tlen - plen;
        while (pi < plen && ti - pi <= lenDelta) {
            if (pi < 0 || text[ti] == buf[pi]) {
                ti++;
                pi++;
            } else {
                pi = next[pi];
            }
        }
        return (pi == plen) ? (ti - pi) : -1;
    }
    //优化
    static int *next2(string pattern){
        string name = pattern;
        char buf[] = {0};
        strcpy(buf , name.c_str());//字符串转字符数组，使用strcpy
        int charsLen = sizeof(buf) / sizeof(buf[0]);
        int *next = new int[charsLen]{0};
        next[0] = -1;//关于-1的取值不明白可以查看课件pdf
        int i = 0;
        int n = -1;
        int iMax = charsLen - 1;
        while (i < iMax) {
            if (n < 0 || buf[i] == buf[n]) {
                ++i;
                ++n;
                if (buf[i] == buf[n]) {
                    next[i] = next[n];
                }else{
                    next[i] = n;
                }
            }else{
                n = next[n];
            }
        }
        return next;
    }
    
    int *next(string pattern){
        string name = pattern;
        char chars[] = {0};
        strcpy(chars , name.c_str());//字符串转字符数组，使用strcpy
        int charsLen = sizeof(char) / sizeof(chars[0]);
        int *next = new int[charsLen]{0};
        next[0] = -1;//关于-1的取值不明白可以查看课件pdf
        int i = 0;
        int n = -1;
        int iMax = charsLen - 1;
        while (i < iMax) {
            if (n < 0 || chars[i] == chars[n]) {
                next[++i] = ++n;
            }else{
                n = next[n];
            }
        }
        return next;

    }

    
};

#endif /* KMP_hpp */
