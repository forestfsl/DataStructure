package com.forest.circle;

import com.forest.AbstractList;



public class SingleCircleLinkList<E> extends AbstractList<E> {
	private Node<E> first;
	private static class Node<E> {
		
		E element;
		Node<E> next;
		@SuppressWarnings("unused")
		public Node(E element, Node<E> next) {
			this.element = element;
			this.next = next;
		}
		
		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();
			sb.append(element).append("_").append(next.element);
			return sb.toString();
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
		rangeCheckForAdd(index);
		
		if (index == 0) {
			Node<E> newFirstNode = new Node<>(element,first);
			Node<E> lastNode = (size == 0) ? newFirstNode : node(size - 1);
			lastNode.next = newFirstNode;
			first = newFirstNode;
		}else {
			Node<E> prevNode = node(index - 1);
			prevNode.next = new Node<>(element,prevNode.next);
		}
		size++;
	}

	@Override
	public E remove(int index) {
		rangeCheck(index);
		
		Node<E> node = first;
		if (index == 0) {
			if (size == 1) {
				first = null;
			} else {
				Node<E> last = node(size - 1);
				first = first.next;
				last.next = first;
			}
		} else {
			Node<E> prev = node(index - 1);
			node = prev.next;
			prev.next = node.next;
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
	
	/**
	 * 获取index位置对应的节点对象
	 */
	private Node<E> node(int index){
		rangeCheck(index);
		
		Node<E> node = first;
		for (int i = 0; i < index; i++) {
			node = node.next;
		}
		return node;
	}
	
	@Override
	public String toString() {
		StringBuilder string = new StringBuilder();
		string.append("size=").append(size).append(", [");
		Node<E> node = first;
		for (int i = 0; i < size; i++) {
			if (i != 0) {
				string.append(", ");
			}
			
			string.append(node);
			
			node = node.next;
		}
		string.append("]");
		return string.toString();
	}
	
	
}
