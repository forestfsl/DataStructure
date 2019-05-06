package com.forest;

import com.sun.org.apache.bcel.internal.generic.RETURN;

@SuppressWarnings("unused")
 class LinkedList<E> extends AbstracList<E> {
	
	private Node<E> first;
	
	private static class Node<E>{
		E element;
		Node<E> next;
		public Node(E element,Node<E>next) {
			this.element = element;
			this.next = next;
		}
		
	}

	@Override
	public void clear() {
		// TODO Auto-generated method stub
		size = 0;
		first = null;
		
	}

	@Override
	public E get(int index) {
		// TODO Auto-generated method stub
		return node(index).element;
	}

	@Override
	public E set(int index, E element) {
		// TODO Auto-generated method stub
		Node<E> node = node(index);
		E oldE = node.element;
		node.element = element;
		return oldE;
	}

	@Override
	public void add(int index, E element) {
		// TODO Auto-generated method stub
		if (index == 0) {
			first = new Node<>(element, first);
		}else {
			Node<E> prevNode = node(index - 1);
			prevNode.next = new Node<>(element, prevNode.next);
		}
		size++;
		
	}
	

	@Override
	public E remove(int index) {
		// TODO Auto-generated method stub
		Node<E> node = first;
		if (index == 0) {
			first = first.next;
		}else {
			Node<E> prevNode = node(index - 1);
			node = prevNode.next;
			prevNode.next = node.next;
		}
		size--;
		return node.element;
	}

	@Override
	public int indexOf(E element) {
		// TODO Auto-generated method stub
		if (element == null) {
			Node<E> node = first;
			for (int i = 0; i < size; i++) {
				if(node.element == null) return i;
				node = node.next;
			}
		}else {
			Node<E> node = first;
			for (int i = 0; i < size; i++) {
				if(element.equals(node.element)) return i;
				node = node.next;
			}
		}
		return ELEMENT_NOT_FOUND;
	}
	
	/**
	 * 获取index位置对应的节点对象
	 */
	private  Node<E>node(int index){
		rangeCheck(index);
		Node<E> node = first;
		for (int i = 0; i < index; i++) {
			node = node.next;
		}
		return node;
		
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		StringBuffer stringBuffer = new StringBuffer();
		stringBuffer.append("size=").append(size).append(",[");
		Node<E> node = first;
		for (int i = 0; i < size; i++) {
			if (i != 0) {
				stringBuffer.append(", ");
			}
			stringBuffer.append(node.element);
			node = node.next;
		}
		stringBuffer.append("]");
		return stringBuffer.toString();
	}
	
}
