//
//  BloomFilter.hpp
//  24.布隆过滤器
//
//  Created by fengsl on 2020/2/3.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef BloomFilter_hpp
#define BloomFilter_hpp

#include <stdio.h>
#include<cmath>
using namespace std;

/*
 布隆过滤器 Bloom Filter 1970年由布隆提出，它是一个空间效率高的概率性数据结构，可以用来告诉你:一个元素一定不存在或者可能存在
 
 - 优缺点
    - 优点：空间效率和查询时间都远远超过一般的算法
    - 缺点：有一定的误判率，删除困难
 
实际上是一个很长的二进制向量和一系列随机隐射函数
 
 布隆过滤器的原理：
 假设布隆过滤器由20位二进制，3个哈希函数组成，每个元素经过哈希函数处理都能生成一个索引位置
 - 添加元素：将每一个哈希函数生成的索引位置都设为1
    - 如果有一个哈希函数生成的索引位置不为1，就代表不存在(100%准确)
    - 如果每一个哈希函数生成的索引位置都为1，就代表存在(存在一定的误判率)
 
 布隆过滤器的误判率
 - 误判率p受3个元素影响：二进制位的个数m，哈希函数的个数为k，数据规模n
 （1 - e^-k(n+0.5)/(m-1))^k
 (1 - e^-kn/m)^k
 - 已知误判率p，数据规模n，求二进制位的个数m，哈希函数的个数k
 m = -nlnp/((ln2)^2)
 k = - lnp/ln2
 k = -lnp/ln2 = -log2^p
 */

template <class T>
class BloomFilter {
public:
    /*
     二进制向量的长度(一共有多少个二进制位)
     */
    int bitSize;
    /*
     二进制向量
     */
    long *bits;
    /*
     哈希函数的个数
     */
    int hashSize;
    
    /*
     @param n 数据规模
     @param p 误判率，取值范围(0,1)
     */
     BloomFilter(int n,double p){
        if (n <= 0 || p <= 0 || p >= 1) {
            throw "wrong n or p";
        }
        double ln2 = log(2);
         double logp = log(p);
         //求出二进制向量的长度
         bitSize = (int)(- (n * logp) / (ln2 * ln2));
         //求出哈希函数的个数
         hashSize = (int)(bitSize * ln2 / n);
         //bits 数组的长度
         int longSize = sizeof(long) * 8;
         bits = new long[(bitSize + longSize - 1) / longSize];
         //每一页显示100条数据，pageSize
         //一共有999999条数据，n
         //请问有多少页 pageCount = (n + pageSize - 1) /pageSize
    }
    
    /*
     添加元素1
     */
    bool put (T value){
        nullCheck(value);
        //利用value生成2个整数
        int hash1 = (int)hash<int>()(value);
        int hash2 = hash1 >> 16;
        bool result = false;
        for (int i = 1; i <= hashSize; i++) {
            int combinedHash = hash1 + (i * hash2);
            if (combinedHash < 0) {
                combinedHash = ~combinedHash;
            }
            //生成一个二进制位的索引
            int index = combinedHash % bitSize;
            //设置index位置的二进制为1
            if (set(index)) result = true;
            
            //  101010101010101010
            //| 000000000000000100 1 << index
            //  101010101010101010
        }
        return result;
    }
    
    /*
     判断一个元素是否存在
     */
    bool contains(T value){
        nullCheck(value);
        //利用value生成2个整数
        int hash1 = (int)hash<int>()(value);
        int hash2 = hash1 >> 16;
        
        for (int i = 1; i <= hashSize; i++) {
            int combinedHash = hash1 + (i * hash2);
            if (combinedHash < 0) {
                combinedHash = ~combinedHash;
            }
            //生成一个二进位的索引
            int index = combinedHash % bitSize;
            //查询index位置的二进位是否为0
            if (!get(index)) return false;
        }
        return true;
    }
    
    /*
     设置index位置的二进制位为1
     */
    bool set(int index){
         int longSize = sizeof(long) * 8;
        long value = bits[index / longSize];
        int bitValue = 1 << (index % longSize);
        bits[index / longSize] = value | bitValue;
        return (value & bitValue) == 0;
    }
    
    /*
     查看index位置的二进位的值
     @return true 代表1，false代表0
     */
    bool get(int index){
         int longSize = sizeof(long) * 8;
        long value = bits[index / longSize];
        return (value & (1 << (index % longSize))) != 0;
    }
    
    void nullCheck(T value){
        if (value < 0) {
            throw "Value must >= 0";
        }
    }
};

#endif /* BloomFilter_hpp */
