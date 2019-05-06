package com.forest;

public class Main {
	public static void main(String[] args) {
		//test
		List<Integer> list = new LinkedList<>();
		list.add(30);
		list.add(0, 100);
		list.add(20);
		list.add(list.size(), 40);
		// [10, 30, 40]
		
		list.remove(1);
		
		System.out.println(list);

	}
	

}
