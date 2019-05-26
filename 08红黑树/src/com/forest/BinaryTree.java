package com.forest;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

import javax.xml.bind.helpers.ParseConversionEventImpl;

@SuppressWarnings("unused")
public class BinaryTree<E> implements BinaryTreeInfo {
	protected int size;
	protected Node<E>root;
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
	
	public void clear() {
		root = null;
		size = 0;
	}
	
		
	
	
	
	/**
	 * 暴露前序遍历方法
	 */
	public void preorder(Visitor<E>visitor) {
		preorder(root,visitor);
	}
	
	/**
	 * 前序遍历
	 * @return
	 */
	private void preorder(Node<E> node, Visitor<E>visitor) {
		if(node == null || visitor == null) return;
		
		visitor.visit(node.element);
		preorder(node.leftNode, visitor);
		preorder(node.rightNode, visitor);
	}
	
	/**
	 * 暴露中序遍历方法
	 */
	public void inorder(Visitor<E>visitor) {
		inorder(root, visitor);
	}
	
	/**
	 * 中序遍历
	 * @return
	 */
	private void inorder(Node<E>node, Visitor<E>visitor) {
		if (node == null || visitor == null) return;
		
		inorder(node.leftNode, visitor);
		visitor.visit(node.element);
		inorder(node.rightNode, visitor);
	}
	
	/**
	 * 暴露后序遍历方法
	 */
	public void postorder(Visitor<E> visitor) {
		postorder(root,visitor);
	}
	
	/**
	 * 后序遍历
	 * @return
	 */
	private void postorder(Node<E>node,Visitor<E>visitor) {
		if (node == null || visitor == null) return;
		postorder(node.leftNode, visitor);
		postorder(node.rightNode, visitor);
		visitor.visit(node.element);
	}
	/**
	 * 层级遍历
	 * @return
	 */
	public void levelOrder(Visitor<E>visitor) {
		if (root == null || visitor == null) return;
		Queue<Node<E>> queue = new LinkedList<>();
		queue.offer(root);
		while (!queue.isEmpty()) {
			Node<E> node = queue.poll();
			visitor.visit(node.element);
			if (node.leftNode != null) {
				queue.offer(node.leftNode);
			}
			if (node.rightNode != null) {
				queue.offer(node.rightNode);
			}
		}
	}
	
	/**
	 * 是否遍历完
	 * @return
	 */
	public boolean isComplete() {
		if (root == null) return false;
		Queue<Node<E>> queue = new LinkedList<>();
		queue.offer(root);
		boolean leaf = false;
		while (!queue.isEmpty()) {
			Node<E> node = queue.poll();
			if(leaf && !node.isLeaf()) return false;
			
			if (node.hasTwoChildren()) {
				queue.offer(node.leftNode);
				queue.offer(node.rightNode);
			}else if (node.leftNode == null && node.rightNode != null) {
				return false;
			}else {
				//后面遍历的节点都必需是叶子节点
				leaf = true;
			}
		}
		return true;
	}
	
	
	public int height() {
		if (root == null) return 0;
		//树的高度
		int height = 0;
		//存储着每一层的元素数量
		int levelSize = 1;
		Queue<Node<E>> queue = new LinkedList<>();
		queue.offer(root);
		
		while (!queue.isEmpty()) {
			Node<E> node = queue.poll();
			levelSize--;
			if (node.leftNode != null) {
				queue.offer(node.leftNode);
			}
			if (node.rightNode != null) {
				queue.offer(node.rightNode);
			}
			if (levelSize == 0) {//意味着即将要访问下一层
				levelSize = queue.size();
				height++;
			}
		}
		return height;
	}
	
	public  int height2() {
		return height(root);
	}
	
	private int height(Node<E>node) {
		if (node == null) return 0;
		return 1 + Math.max(height(node.leftNode),height(node.rightNode));
		
	}
	
	protected Node<E> createNode(E element,Node<E>parent){
		return new Node<>(element, parent);
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		StringBuilder sBuilder = new StringBuilder();
		toString(root,sBuilder,"");
		return sBuilder.toString();
	}
	protected void toString(Node<E>node,StringBuilder sBuilder,String prefix) {
		if (node == null) return;
		toString(node.leftNode,sBuilder,prefix + "L---");
		sBuilder.append(prefix).append(node.element).append("\n");
		toString(node.rightNode,sBuilder,prefix + "R---");
	}
	
	protected void elementNotNullCheck(E element) {
		if (element == null) {
			throw new IllegalArgumentException("element must not be null");
		}
	}
	//获取节点的前驱节点
	protected Node<E> predecessor(Node<E>node){
		//前驱节点在左子树当中(left.right.right.right....)
		Node<E> pNode = node.leftNode;
		if (pNode != null) {
			while (pNode.rightNode != null) {
				pNode = pNode.rightNode;
			}
			return pNode;
		}
		//从父节点，祖父节点中寻找前驱节点
		while (node.parentNode != null && node == node.parentNode.leftNode) {
			node = node.parentNode;
		}
		return node.parentNode;
	}
	
	//获取节点的后驱节点
	protected Node<E> successor(Node<E> node){
		if (node == null) return null;
		//后驱节点在左子树当中(ight.left.left.left....)
		Node<E> p = node.rightNode;
		if (p != null) {
			while (p.leftNode != null) {
				p = p.leftNode;
			}
			return p;
		}
		
//		从父节点，祖父节点中寻找后驱节点
		while (node.parentNode != null && node == node.parentNode.rightNode) {
			node = node.parentNode;
		}
		return node.parentNode;
	}
	
	//一个遍历的的二叉树接口
	public static interface Visitor<E>{
		void visit(E element);
	}
	
	public static class Node<E>{
		E element;//元素值
		Node<E> leftNode;//左节点
		Node<E> rightNode;//右节点
		Node<E> parentNode;//父节点
		public Node(E element,Node<E>parent) {
			this.element = element;
			this.parentNode = parent;
		}
		
		public boolean isLeaf() {
			return leftNode == null && rightNode == null;
		}
		public boolean hasTwoChildren() {
			return leftNode != null && rightNode != null;
		}
		public boolean isLeftChild() {
			return parentNode != null && this == parentNode.leftNode;
		}
		public boolean isRightChild() {
			return parentNode != null && this == parentNode.rightNode;
		}
		public Node<E> sibling(){
			if (isLeftChild()) {
				return parentNode.rightNode;
			}
			if (isRightChild()) {
				return parentNode.leftNode;
			}
			return null;
		}
	}
	

	@Override
	public Object root() {
		// TODO Auto-generated method stub
		return root;
	}

	@SuppressWarnings("unchecked")
	@Override
	public Object left(Object node) {
		// TODO Auto-generated method stub
		return ((Node<E>)node).leftNode;
	}

	@SuppressWarnings("unchecked")
	@Override
	public Object right(Object node) {
		// TODO Auto-generated method stub
		return ((Node<E>)node).rightNode;
	}
	@Override
	public Object string(Object node) {
		// TODO Auto-generated method stub
		return node;
	}


}
