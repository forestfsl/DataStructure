package com.forest;


@SuppressWarnings("unused")
public
 class LinkedList<E> extends AbstracList<E> {
	
	private Node<E> first;
	private Node<E> last;
	
	private static class Node<E>{
		E element;
		Node<E> prev;
		Node<E> next;
		public Node(Node<E>prev,E element,Node<E>next) {
			this.prev = prev;
			this.element = element;
			this.next = next;
		}
		
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			StringBuilder sBuilder = new StringBuilder();
			if (prev != null) {
				sBuilder.append(prev.element);
			}else {
				sBuilder.append("null");
			}
			sBuilder.append("_").append(element).append("_");
			if (next != null) {
				sBuilder.append(next.element);
			}else {
				sBuilder.append("null");
			}
			return super.toString();
		}
		
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
		/*
		 * 最好：O(1)
		 * 最坏：O(n)
		 * 平均：O(n)
		 */
		return node(index).element;
	}

	@Override
	public E set(int index, E element) {
		// TODO Auto-generated method stub
		/*
		 * 最好：O(1)
		 * 最坏：O(n)
		 * 平均：O(n)
		 */
		Node<E> node = node(index);
		E oldE = node.element;
		node.element = element;
		return oldE;
	}

	@Override
	public void add(int index, E element) {
		// TODO Auto-generated method stub
		/*
		 * 最好：O(1)
		 * 最坏：O(n)
		 * 平均：O(n)
		 */
		rangeCheckForAdd(index);
		//需要判断添加方向
		if (index == size) {//往后面添加元素
			Node<E> oldLastNode = last;
			last = new Node<>(oldLastNode,element,null);
			if (oldLastNode == null) { //这是链表添加的第一个元素
				first = last;
			}else {
				oldLastNode.next = last;
			}
		}else {
			Node<E> nextNode = node(index);//获取的是当前node，但是该node即将成为插入newNode的下一个
			Node<E> prevNode = nextNode.prev;//当前node的前一个，即将成为newNode的prev
			//创建一个newNode，prev指向prevNode，next指向nextNode
			Node<E> node = new Node<>(prevNode,element,nextNode);
			//这个时候还差两个指向，一个是nextNode的prev，和prev的next
			nextNode.prev = node;
			//这里需要判断一下index == 0是否成立
			if (prevNode == null) {
				//说明是第一个元素，那么这个时候只需要first指向这个node,因为没有prevNode指向
				first = node;
			}else {
				prevNode.next = node;
			}
		}
		size++;
	}
	

	@Override
	public E remove(int index) {
		// TODO Auto-generated method stub
		/*
		 * 最好：O(1)
		 * 最坏：O(n)
		 * 平均：O(n)
		 */
		rangeCheck(index);
		
		Node<E> node = node(index);
		Node<E> prev = node.prev;
		Node<E> next = node.next;
		
		if (prev == null) { //index == 0
			first = next;
		}else {
			prev.next = next;
		}
		if (next == null) { //index == size - 1
			last = prev;
		}else {
			next.prev = prev;
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
		//因为是双向链表，所以在进行获取之前先判断一下元素
		//是在前半截还是后半截
		if (index < (size >> 1)) {
			Node<E> node = first;
			for (int i = 0; i < index; i++) {
				node = node.next;
			}
			return node;
		}else {
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
