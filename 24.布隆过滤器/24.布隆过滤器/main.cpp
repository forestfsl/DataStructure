//
//  main.cpp
//  24.布隆过滤器
//
//  Created by fengsl on 2020/2/3.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#include <iostream>
#include "BloomFilter.hpp"
using namespace std;

void testBllomFilter(){
    BloomFilter<int> bf = BloomFilter<int>(1000000,0.01);
    for (int i = 1; i <= 1000000; i++) {
        bf.put(i);
    }
    int count = 0;
    for (int i = 100001; i <= 200000; i++) {
        if (bf.contains(i)) {
            count++;
        }
    }
    cout << count << endl;
    
//    // 数组
//    String[] urls = {};
//    BloomFilter<String> bf = new BloomFilter<String>(10_0000_0000, 0.01);
//    /*
//    for (String url : urls) {
//        if (bf.contains(url)) continue;
//        // 爬这个url
//        // ......
//        
//        // 放进BloomFilter中
//        bf.put(url);
//    }*/
//    
//    for (String url : urls) {
//        if (bf.put(url) == false) continue;
//        // 爬这个url
//        // ......
//    }
}


int main(int argc, const char * argv[]) {
    testBllomFilter();
    return 0;
}
