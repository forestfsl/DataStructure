package com.forest.test;

import com.forest.queue.PriorityQueue;

public class Main {
	
	static void test1() {
		PriorityQueue<Person> queue = new PriorityQueue<>();
		queue.enQueue(new Person("Jack", 2));
		queue.enQueue(new Person("Rose", 10));
		queue.enQueue(new Person("Jake", 5));
		queue.enQueue(new Person("Hames", 15));
		while (!queue.isEmpty()) {
			System.out.println(queue.deQueue());
		}
	}
	
	public static void main(String[] args) {
		test1();
	}

}
