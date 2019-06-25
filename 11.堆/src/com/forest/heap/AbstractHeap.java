package com.forest.heap;

import java.util.Comparator;

public abstract class AbstractHeap<E> implements Heap<E> {
	protected int size;
	protected Comparator<E> comparator;
	public AbstractHeap(Comparator<E> comparator) {
		this.comparator = comparator;
	}
	
	public AbstractHeap() {
		this(null);
	}
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
	@SuppressWarnings("unchecked")
	protected int compare(E e1,E e2) {
		return comparator != null ? comparator.compare(e1, e2) 
				: ((Comparable<E>)e1).compareTo(e2);
	}
}
