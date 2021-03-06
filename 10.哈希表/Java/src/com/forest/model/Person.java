package com.forest.model;

public class Person implements Comparable<Person>{
	private int age;
	private float height;
	private String name;
	public Person(int age,float height,String name) {
		this.age = age;
		this.height = height;
		this.name = name;
	}
	@Override
	public boolean equals(Object obj) {
		//内存地址
		if (this == obj) return true;
		if (obj == null || obj.getClass() != getClass()) return false;
		//比较成员变量
		Person person = (Person)obj;
		return person.age == age && person.height == height 
				&& (person.name == null ? name == null : person.name.equals(name));
	}
	@Override
	public int hashCode() {
		int hashCode = Integer.hashCode(age);
		hashCode = hashCode * 31 + Float.hashCode(height);
		hashCode = hashCode * 31 + (name != null ? name.hashCode() : 0);
		return hashCode;
	}
	@Override
	public int compareTo(Person o) {
		// TODO Auto-generated method stub
		return age - o.age;
	}
	

}
