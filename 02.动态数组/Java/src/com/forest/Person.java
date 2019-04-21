package com.forest;

public class Person {
	private int age;
	private String name;
	
	//有参数构造函数
	public Person(int age,String name) {
		this.age = age;
		this.name = name;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "Person [age=" + age + ",name=" + name + "]";
	}
	
	@Override
	protected void finalize() throws Throwable {
		// TODO Auto-generated method stub
		super.finalize();
		System.out.println("Person-finalize");
	}

}
