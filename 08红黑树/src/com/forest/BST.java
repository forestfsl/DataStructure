package com.forest;

import java.util.Comparator;

@SuppressWarnings("unchecked")
public class BST<E>extends BinaryTree<E>{
	private Comparator<E> comparator;
	
	public BST() {
		this(null);
	}
	
	public BST(Comparator<E> comparator) {
		this.comparator = comparator;
	}
	
	public void add(E element) {
		elementNotNullCheck(element);
		//添加第一个节点
		if (root == null) {
			root = createNode(element, null);
			size++;
			//新添加节点之后的处理
			afterAdd(root);
			return;
		}
		
		//添加的不是第一个节点
		//找到父节点
		Node<E> parentNode = root;
		Node<E> node = root;
		int cmp = 0;
		do {
			cmp = compare(element, node.element);
			parentNode = node;
			if (cmp > 0) {
				node = node.rightNode;
			}else if (cmp < 0) {
				node = node.leftNode;
			}else {
				//相等
				node.element = element;
				return;
			}
		} while (node != null);
		//看看插入到父节点的哪个位置
		Node<E> newNode = createNode(element, parentNode);
		if (cmp > 0) {
			parentNode.rightNode = newNode;
		}else {
			parentNode.leftNode = newNode;
		}
		size++;
		//新添加节点之后的处理
		afterAdd(newNode);
	}
	
	public void remove(E element) {
		remove(node(element));
	}
	
	public boolean contains(E element) {
		return node(element) != null;
	}
	
	private void remove(Node<E> node) {
		if(node == null) return;
		size--;
		if (node.hasTwoChildren()) {
			//度为2的节点
			Node<E> sNode = successor(node);
			//用后继节点的值覆盖度为2的值
			node.element = sNode.element;
			//删除后移节点
			node = sNode;
		}
		
		//删除node节点(node 的度必然是1或者0)
		Node<E> replacementNode = node.leftNode != null ? node.leftNode : node.rightNode;
		if (replacementNode != null) {//node 是度为1的节点
			//更改parent
			replacementNode.parentNode = node.parentNode;
			//更改parent的leftNode，rightNode
			if (node.parentNode == null) {//node是度为1的节点
				root = replacementNode;
			}else if (node == node.parentNode.leftNode) {
				node.parentNode.leftNode = replacementNode;
			}else {
				//node == node.parentNode.rightNode
				node.parentNode.rightNode = replacementNode;
			}
			//删除节点之后的处理
			afterRemove(node);	
		}else if (node.parentNode == null) { //node 是叶子节点并且是根节点
			root = null;
			//删除节点之后的处理
			afterRemove(node);
		}else {
			//node 是叶子节点，但不是根节点
			if (node == node.parentNode.leftNode) {
				node.parentNode.leftNode = null;
			}else {
				node.parentNode.rightNode = null;
			}
			//删除节点之后的处理
			afterAdd(node);
		}
	}
	
	private Node<E> node(E element){
		Node<E> node = root;
		while (node != null) {
			int cmp = compare(element, node.element);
			if(cmp == 0) return node;
			if(cmp > 0) {
				node = node.rightNode;
			}else {
				node = node.leftNode;
			}
		}
		return null;
	}
	
	protected void elementNotNullCheck(E element) {
		if (element == null) {
			throw new IllegalArgumentException("element must not be null");
		}
	}
	
	protected void afterAdd(Node<E>node) {}
	protected void afterRemove(Node<E> node) {}
	
	/**
	 * 返回值等于0，代表e1和e2相等,返回值大于0，代表e1大于e2;返回值小于0
	 * 代表e1小于e2
	 */
	private int compare(E e1,E e2) {
		if (comparator != null) {
			return comparator.compare(e1,e2);
		}
		return ((Comparable<E>)e1).compareTo(e2);
	}

	
}
