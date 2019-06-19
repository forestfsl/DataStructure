package com.forest.circle;

import com.forest.AbstractList;




@SuppressWarnings("unused")
public class CircleLinkedList<E>extends AbstractList<E> {
	private Node<E> first;
	private Node<E> last;
	private Node<E> current;
	private static class Node<E>{
		E element;
		Node<E> prev;
		Node<E> next;
		public Node(Node<E> prev,E element,Node<E>next) {
			this.prev = prev;
			this.element = element;
			this.next = next;
		}
		
		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();
			
			if (prev != null) {
				sb.append(prev.element);
			} else {
				sb.append("null");
			}
			
			sb.append("_").append(element).append("_");

			if (next != null) {
				sb.append(next.element);
			} else {
				sb.append("null");
			}
			
			return sb.toString();
		}
		
	}
	
	public void reset() {
		current = first;
	}
	public E next() {
		if (current == null) return null;
		current = current.next;
		return current.element;
	}
	
	public E remove() {
		if (current == null) return null;
		Node<E> next = current.next;
		E element = remove(current);
		if (size == 0) {
			current = null;
		} else {
			current = next;
		}
		
		return element;

	}

	@Override
	public void clear() {
		// TODO Auto-generated method stub
		size = 0;
		first = null;
		last = null;
		
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
		E olE = node.element;
		node.element = element;
		return olE;
	}

	@Override
	public void add(int index, E element) {
		// TODO Auto-generated method stub
		rangeCheckForAdd(index);

		// size == 0
		// index == 0
		if (index == size) { // 往最后面添加元素
			Node<E> oldLast = last;
			last = new Node<>(oldLast, element, first);
			if (oldLast == null) { // 这是链表添加的第一个元素
				first = last;
				first.next = first;
				first.prev = first;
			} else {
				oldLast.next = last;
				first.prev = last;
			}
		} else {
			Node<E> next = node(index); 
			Node<E> prev = next.prev; 
			Node<E> node = new Node<>(prev, element, next);
			next.prev = node;
			prev.next = node;
			
			if (next == first) { // index == 0
				first = node;
			}
		}
		
		size++;

	}

	@Override
	public E remove(int index) {
		// TODO Auto-generated method stub
		rangeCheck(index);
		return remove(node(index));
	}
	
	private E remove(Node<E>node) {
		if (size == 1) {
			first = null;
			last = null;
		} else {
			Node<E> prev = node.prev;
			Node<E> next = node.next;
			prev.next = next;
			next.prev = prev;
			
			if (node == first) { // index == 0
				first = next;
			}
			
			if (node == last) { // index == size - 1
				last = prev;
			}
		}
		
		size--;
		return node.element;
	}
	
	/**
	 * 获取index位置对应的节点对象
	 */
	private Node<E>node(int index){
		rangeCheck(index);
		
		if (index < (size >> 1)) {
			Node<E> node = first;
			for (int i = 0; i < index; i++) {
				node = node.next;
			}
			return node;
		} else {
			Node<E> node = last;
			for (int i = size - 1; i > index; i--) {
				node = node.prev;
			}
			return node;
		}
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		StringBuilder stringBuilder = new StringBuilder();
		stringBuilder.append("size=").append(size).append(", [");
		Node<E> node = first;
		for (int i = 0; i < size; i++) {
			if (i != 0) {
				stringBuilder.append(", ");
			}
			stringBuilder.append(node);
			node = node.next;
		}
		stringBuilder.append("]");
		return stringBuilder.toString();
	}
	

	@Override
	public int indexOf(E element) {
		// TODO Auto-generated method stub
		if (element == null) {
			Node<E> node = first;
			for (int i = 0; i < size; i++) {
				if (node.element == null) return i;
				node = node.next;
			}
		}else {
			Node<E> node = first;
			for (int i = 0; i < size; i++) {
				if (element.equals(node.element)) return i;
				
				node = node.next;
			}
		}
		return ELEMENT_NOT_FOUND;
	}
	
	
	
}
