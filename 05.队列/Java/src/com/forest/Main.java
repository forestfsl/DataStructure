package com.forest;



public class Main {
	
	static void testStack() {
		Stack<Integer> stack = new Stack<>();
		stack.push(11);
		stack.push(22);
		stack.push(33);
		stack.push(44);
		
		while (!stack.isEmpty()) {
			System.out.println(stack.pop());
		}
	}
	
	static void testQueue() {
		Queue<Integer> queue = new Queue<>();
		queue.enQueue(11);
		queue.enQueue(22);
		queue.enQueue(33);
		queue.enQueue(44);
		while (!queue.isEmpty()) {
			System.out.println(queue.deQueue());
		}
	}
	
	static void testDqueue() {
		
	}
	
	@SuppressWarnings("unused")
	static void testCircleQueue() {
		CircleQueue<Integer> queue = new CircleQueue<Integer>();
		// 0 1 2 3 4 5 6 7 8 9
		for (int i = 0; i < 10; i++) {
			queue.enQueue(i);
		}
		// null null null null null 5 6 7 8 9
		for (int i = 0; i < 5; i++) {
			queue.deQueue();
		}
		// 15 16 17 18 19 5 6 7 8 9
		for (int i = 15; i < 20; i++) {
			queue.enQueue(i);
		}
		while (!queue.isEmpty()) {
			System.out.println(queue.deQueue());
		}
		System.out.println(queue);
	}
	
	@SuppressWarnings("unused")
	static public void testCircleDqueue() {
		CircleDeque<Integer> queue = new CircleDeque<Integer>();
		//头5 4 3 2 1 100 101 102 103 104 
		//当数据容量的不够的时候，会动态扩容
		//第一次扩容 头5 4 3 2 1 100 101 102 103 104  105 106 8 7 6 尾
		
		//第二次扩容 头8 7 6 5 4 3 2 1 100 101 102 103 104 105 106 107 108 109 null null 19 9尾
		for (int i = 0; i < 10; i++) {
			queue.enQueueFront(i + 1);
			queue.enQueueRear(i+100);
		}
		//头null 7 6 5 4 3 2 1 100 101 102 103 104 105 106 null null null null null null null 尾
		for (int i = 0; i < 3; i++) {
			queue.deQueueFront();
			queue.deQueueRear();
		}
		//头11 7 6 5 4 3 2 1 100 101 102 103 104 105 106 null null null null null null 12 尾
		queue.enQueueFront(11);
		queue.enQueueFront(12);
		System.out.println(queue);
		while (!queue.isEmpty()) {
			System.out.println(queue.deQueueFront());
		}
		
		
	}
	
	public static void main(String[] args) {
//		testQueue();
		testCircleQueue();
		testCircleDqueue();
	}
	

}
