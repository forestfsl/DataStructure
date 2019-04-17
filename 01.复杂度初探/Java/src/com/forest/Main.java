package com.forest;


import com.forest.TimeTool.Task;


public class Main {
	
	//这个算法的复杂度是O(2^n),具体情况可以查看之后图分析哈
	public static int fib1(int n) {
		if (n <= 1) return n;
		return fib1(n - 1) + fib1(n - 2);
	}
	
	//这个算法的复杂度是O(n)
	public static int fib2(int n) {
		if (n <= 1) return n;
		int first = 0;//代表f(0)
		int second = 1;//代表f(1);
		for (int i = 0; i < n; i++) {
			int sum = first + second;
			first = second;
			second = sum;
		}
		return second;
	}
	
	public static int fib3(int n) {
		if (n <= 1) return n;
		int first = 0;//代表f(0)
		int second = 1;//代表f(1);
		while(n-- > 1) {
			second += first;
			first = second - first;
			return second;
		}
		return second;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 64;
		TimeTool.check("fib1", new Task() {
			
			@Override
			public void execute() {
				System.out.print(fib1(n));
			}
		});
		
		TimeTool.check("fib2", new Task() {
			public void execute() {
				System.out.println(fib2(n));
			}
		});
		
/* 执行结果
* 【fib1】
开始：19:38:57.472
1836311903
结束：19:39:07.327
耗时：9.854秒
-------------------------------------
【fib2】
开始：19:39:07.330
1836311903
结束：19:39:07.331
耗时：0.0秒
 */

	}
	
	//O(1)算法
	public static void test1(int n) {
		//1
		if (n > 10) {
			System.out.println("n>10");
		}else if (n > 5) {
			System.out.print(">5");
		}else {
			System.out.println("n<=5");
		}
		//i = 0;执行一次,i<4判断4次,i++ 执行4次,打印执行4次,所以总共次数是:
		//1+4+4+4,但是对于算法来说，只要最终结果是常数项，最后还是理解为O(1)
		for (int i = 0; i < 4; i++) {
			System.out.println("test");
		}
	}
	//O(n)算法
	public static void test2(int n) {
		//分析同(1),总计算次数就是1 + 3n
		for (int i = 0; i < n; i++) {
			System.out.print("test");
		}
	}
	
	public static void test3(int n) {
		//O(n^2)算法，有n^2 和 n 取最长
		//外面for执行次数1 + n + n
		//里面for执行次数n * (1 + n + n + n)
		//总执行的次数是1 + 2n + n * (1 + 3n)
		// 1 + 2n + n + 3n^2
		//3n^2 + 3n + 1
		//o(n^2)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print("test");
			}
		}
	}
	
	public static void test4(int n) {
		//1 + n + n + n * (1 + 45)
		//48n + 1
		//常数忽略不算,所以复杂度是O(n)
		for (int i = 0; i < n; i++) {
			System.out.println("test");
		}
	}
	
	public static void test5(int n) {
		//8 = 2^3;
		//16 = 2^4;
		//3 = log2(8)
		//4 = log2(16)
		
		//执行次数 = log2(n)
		//O(logn)
		//这条while语句相当于在不断的求取2的次数
		while ((n = n / 2) > 0) {
			System.out.println("test");
		}
		
	}
	public static void test6(int n) {
		//log5(n)
		//O(logn)
		while ((n = n / 5) > 0) {
			System.out.println("test");
		}
	}
	
	public static void test7(int n) {
		//1 + 2 *log2(n) + log2(n) * (1 + 3n)
		//O(nlogn)
		for (int i = 0; i < n; i = i * 2) {
			System.out.println("test");
		}
	}
	
	public static void test10(int n) {
		// O(n)
		int a = 10;
		int b = 20;
		int c = a + b;
		int[] array = new int[n];
		for (int i = 0; i < array.length; i++) {
			System.out.println(array[i] + c);
		}
	}

}
