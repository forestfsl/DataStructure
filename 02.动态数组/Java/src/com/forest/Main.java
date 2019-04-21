package com.forest;

import com.forest.ArrayList;
import com.forest.Person;

/**
 * 
 * @author songlin
 *
 */
public class Main {
	public static void main(String[] args) {
		// new是向堆空间申请内存
		ArrayList<Person> persons  = new ArrayList<>();
		persons.add(new Person(10, "Jack"));
		persons.add(new Person(12, "James"));
		persons.add(new Person(15, "Rose"));
		System.out.println("销毁前：" + persons);
		persons.clear();
		System.gc();
		System.out.println(persons);
		
		
//		persons.add(new Person(22, "abc"));			
//		
//		ArrayList<Integer> ints  = new ArrayList<>();
//		ints.add(10);
//		ints.add(10);
//		ints.add(22);
//		ints.add(33);
//		System.out.println(ints);
	}
	
}
