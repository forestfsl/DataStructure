package com.forest;

/**
 * 手动涉及一个动态扩容数组
 * @author songlin
 *
 */
@SuppressWarnings("unchecked")
public class ArrayList<E> {
	/*
	 * 元素的数量
	 */
	private int size;
	/*
	 * 所有元素
	 */
	private E[] elements;
	
	private static final int DEFAULT_CAPACITY = 10;
	private static final int ELEMENT_NOT_FOUND = -1;
	
	//构造函数
	public ArrayList(int capacity) {
		capacity = (capacity < DEFAULT_CAPACITY) ?  DEFAULT_CAPACITY : capacity;
		//java 中只有生成一个Object数组才能实现泛型
		elements = (E[])new Object [capacity];
	}
	
	public ArrayList() {
		this(DEFAULT_CAPACITY);
	}

	/**
	 * 清楚所有元素
	 */
	public void clear() {
		//消除对象的内存，如果是int可以直接size等于0，是因为int直接存在数组内存中
		for (int i = 0; i < size; i++) {
			elements[i] = null;
		}
		size = 0;
	}
	
	/**
	 * 元素的数量
	 */
	public int size() {
		return size;
	}
	
	/**
	 * 是否为空
	 */
	public boolean isEmpty() {
		return size == 0;
	}
	/**
	 * 获取index位置的元素
	 * @param index
	 * @return
	 */
	public E get(int index) {
		rangeCheck(index);
		return elements[index];
	}

	/**
	 * 设置index位置的元素
	 * @param index
	 * @param element
	 * @return 原来的元素ֵ
	 */
	public E set(int index, E element) {
		rangeCheck(index);
		
		E old = elements[index];
		elements[index] = element;
		return old;
	}

	/**
	 * 是否包含某个元素
	 */
	public boolean contains(E element) {
		return indexOf(element) != ELEMENT_NOT_FOUND;
	}
	/**
	 * 查看元素的索引
	 */
	public int indexOf(E element) {
		if (element == null) {
			for (int i = 0; i < size; i++) {
				if(elements[i] == null) return i;
			}
		}else {
			for (int i = 0; i < size; i++) {
				if(element.equals(elements[i])) return i;
			}
		}
		return ELEMENT_NOT_FOUND;
	}
	
	
	/*
	 * 添加元素到尾部
	 */
	public void add (E element) {
		add(size, element);
	}
	
	/*
	 * 在index位置插入一个元素
	 */
	public void add (int index, E element) {
		rangeCheckForAdd(index);
		ensureCapacity(size + 1);
		for (int i = size; i > index; i--) {
			elements[i] = elements[i - 1];
		}
		elements[index] = element;
		size++;
	}
	
	/**
	 * 删除index位置的元素
	 */
	public E remove(int index) {
		rangeCheck(index);
		E oldE = elements[index];
		for (int i = index + 1; i < size; i++) {
			elements[i - 1] = elements[i];
		}
		//移除最后一个对象内存
		elements[--size] = null;
		return oldE;
	}
	
	
	
	/**
	 * 保证要有capacity的容量
	 * @param index
	 */
	@SuppressWarnings("unused")
	private void ensureCapacity(int capacity) {
		//容量足够，直接返回
		int oldCapacity = elements.length;
		if(oldCapacity >= capacity) return;
		//容量不够，开始扩容1.5
		int newCapacity = oldCapacity + (oldCapacity >> 1);
		E [] newElementsEs = (E[])new Object[newCapacity];
		for (int i = 0; i < size; i++) {
			newElementsEs[i] = elements[i];
		}
		elements = newElementsEs;
		capacity = newCapacity;
		System.out.print(oldCapacity + "扩容为" + newCapacity);
	}
	
	@SuppressWarnings("unused")
	private void rangeCheck(int index) {
		if (index < 0 || index >= size) {
			outOfBounds(index);
		}
	}
	
	private void outOfBounds(int index) {
		throw new IndexOutOfBoundsException("Index:" + index + ",Size:" + size);
	}
	
	@SuppressWarnings("unused")
	private void rangeCheckForAdd(int index) {
		if (index < 0 || index > size) {
			outOfBounds(index);
		}
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		//size=3,[99,88,77]
		StringBuilder stringBuilder = new StringBuilder();
		stringBuilder.append("size=").append(size).append(",[");
		
		for (int i = 0; i < size; i++) {
			if (i != 0) {
				stringBuilder.append(", ");
			}
			
			stringBuilder.append(elements[i]);
			
//			if (i != size - 1) {
//				string.append(", ");
//			}
		}
		stringBuilder.append("]");
		return stringBuilder.toString();
	}
}
