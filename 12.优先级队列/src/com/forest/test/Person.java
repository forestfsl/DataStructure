package com.forest.test;

public class Person  implements Comparable<Person>{
	private String name;
	private int boneBreak;
	public Person(String name,int boneBreak) {
		this.name = name;
		this.boneBreak = boneBreak;
	}
	
	@Override
	public int compareTo(Person o) {
		// TODO Auto-generated method stub
		return this.boneBreak - o.boneBreak;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "Person [name=" + name + ",boneBreak=" + boneBreak + "]";
	}
}
