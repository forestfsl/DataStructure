package com.forest.list;

public abstract class AbstracList<E> implements List<E> {
	/**
	 * 元素的数量
	 */
	protected int size;
	/**
	 * 元素的数量
	 */
	@Override
	public int size() {
		// TODO Auto-generated method stub
		return size;
	}
	
	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return size == 0;
	}
	
	@Override
	public boolean contains(E element) {
		// TODO Auto-generated method stub
		return indexOf(element) != ELEMENT_NOT_FOUND;
	}
	
	@Override
	public void add(E element) {
		// TODO Auto-generated method stub
		add(size,element);
	}
	protected void outOfBounds(int index) {
		throw new IndexOutOfBoundsException("Index:" + index + ", Size:" + size);
	}
	
	protected void rangeCheck(int index) {
		if (index < 0 || index >= size) {
			outOfBounds(index);
		}
	}
	
	protected void rangeCheckForAdd(int index) {
		if (index < 0 || index > size) {
			outOfBounds(index);
		}
	}
}
