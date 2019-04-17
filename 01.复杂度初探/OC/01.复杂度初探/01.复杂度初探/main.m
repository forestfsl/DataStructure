//
//  main.m
//  01.复杂度初探
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TimeTool.h"


//定义全局方法
//算法复杂度O(2^n)
int fib1(int n){
    if (n <= 1) {
        return n;
    }
    return fib1(n - 1) + fib1(n - 2);
}

//算法复杂度O(n)
int fib2(int n){
    if (n <= 1) {
        return n;
    }
    int first = 0;
    int second = 1;
    for (int i = 0; i < n - 1; i++) {
        int sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}

//算法复杂度O(n)
int fib3(int n){
    if (n <= 1) {
        return n;
    }
    int first = 0;
    int second = 1;
    while (n-- > 1) {
        second = first + second;
        first = second - first;
    }
    return second;
}

void test1(int n){
    //1
    if (n > 10) {
        NSLog(@"n > 10" );
    }else if (n > 5){
         NSLog(@"n > 5");
    }
    
    // 1 + 4 + 4 + 4
    for (int i = 0; i < 4; i++) {
        NSLog(@"test");
    }
}

void test2(int n) {
    // O(n)
    // 1 + 3n
    for (int i = 0; i < n; i++) {
       NSLog(@"test");
    }
}

void test3(int n) {
    // 1 + 2n + n * (1 + 3n)
    // 1 + 2n + n + 3n^2
    // 3n^2 + 3n + 1
    // O(n^2)
    
    // O(n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           NSLog(@"test");
        }
    }
}

void test4(int n) {
    // 1 + 2n + n * (1 + 45)
    // 1 + 2n + 46n
    // 48n + 1
    // O(n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 15; j++) {
           NSLog(@"test");
        }
    }
}

void test5(int n) {
    // 8 = 2^3
    // 16 = 2^4
    
    // 3 = log2(8)
    // 4 = log2(16)
    
    // 执行次数 = log2(n)
    // O(logn)
    while ((n = n / 2) > 0) {
        NSLog(@"test");
    }
}

void test6(int n) {
    // log5(n)
    // O(logn)
    while ((n = n / 5) > 0) {
        NSLog(@"test");
    }
}

void test7(int n) {
    // 1 + 2*log2(n) + log2(n) * (1 + 3n)
    
    // 1 + 3*log2(n) + 2 * nlog2(n)
    // O(nlogn)
    for (int i = 1; i < n; i = i * 2) {
        // 1 + 3n
        for (int j = 0; j < n; j++) {
           NSLog(@"test");
        }
    }
}

void test10(int n) {
    // O(n)
    int a = 10;
    int b = 20;
    int c = a + b;
    //定义一个int [] 数组 初始化每个元素为0
    NSArray *array = [NSArray new];
   
    for (int i = 0; i <n; i++) {
        NSLog(@"%d",[array[i] intValue] + c);
    }

}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        int n = 64;
        [TimeTool check:@"fib1" completion:^{
            fib1(n);
        }];
        [TimeTool check:@"fib2" completion:^{
            fib2(n);
        }];
    }
    return 0;
}
