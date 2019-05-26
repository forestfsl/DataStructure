package com.forest;

import java.util.Comparator;

public class AVLTree<E>extends BST<E> {
	public AVLTree() {
		this(null);
	}
	public AVLTree(Comparator<E> comparator){
		super(comparator);
	}
	
	@Override
	protected void afterAdd(Node<E> node) {
		// TODO Auto-generated method stub
		while ((node = node.parentNode) != null) {
			if (isBalanced(node)) {
				//更新高度
				updateHeight(node);
			}else {
				//恢复平衡
				rebalance2(node);
				//整棵树恢复平衡
				break;
			}
		}
	}
	
	@Override
	protected void afterRemove(Node<E> node) {
		// TODO Auto-generated method stub
		while ((node = node.parentNode) != null) {
			if (isBalanced(node)) {
				//更新高度
				updateHeight(node);
			}else {
				//恢复平衡
				rebalance(node);
			}
		}
	}
	
	@Override
	protected Node<E> createNode(E element, Node<E> parent) {
		// TODO Auto-generated method stub
		return new AVLNode(element, parent);
	}
	
	/**
	 * 恢复平衡
	 * 
	 */
	private void rebalance2(Node<E>grandnNode) {
		Node<E> parentNode = ((AVLNode<E>)grandnNode).tallerChild();
		Node<E> node = ((AVLNode<E>)parentNode).tallerChild();
		if (parentNode.isLeftChild()) { //L
			if (node.isLeftChild()) {//LL
				rotateRight(grandnNode);
			}else {//LR
				rotateLeft(parentNode);
				rotateRight(grandnNode);
			}
		}else {//R
			if (node.isLeftChild()) { //RL
				rotateRight(parentNode);
				rotateLeft(grandnNode);
			}else { //RR
				rotateLeft(grandnNode);
			}
			
		}
	}
	
	/**
	 * 恢复平衡
	 * @param node 高度最低的那个不平衡节点
	 * @return
	 */
	private void rebalance(Node<E>grand) {
		Node<E> parentNode = ((AVLNode<E>)grand).tallerChild();
		Node<E> node = ((AVLNode<E>)parentNode).tallerChild();
		if (parentNode.isLeftChild()) { //L
			if (node.isLeftChild()) { //LL
				rotate(grand, node, node.rightNode, parentNode, parentNode.rightNode, grand);
			}else {
				rotate(grand, parentNode, node.leftNode, node, node.rightNode, grand);
			}
		}else {//R
			if (node.isLeftChild()) {//RL
				rotate(grand, grand, node.leftNode, node, node.rightNode, parentNode);
			}else {
				//RR
				rotate(grand, grand, parentNode.leftNode, parentNode, node.leftNode, node);
			}
		}
	}
	
	private void rotate(
		Node<E> r,//子树的根节点
		Node<E> b,Node<E> c,
		Node<E> d,
		Node<E> e,Node<E> f) {
		//让d称为这棵子树的根节点
		d.parentNode = r.parentNode;
		if (r.isLeftChild()) {
			r.parentNode.leftNode = d;
		}else if (r.isRightChild()) {
			r.parentNode.rightNode = d;
		}else {
			root = d;
		}
		
		//b-c
		b.rightNode = c;
		if (c != null) {
			c.parentNode = b;
		}
		updateHeight(b);
		//e-f
		f.leftNode = e;
		if (e != null) {
			e.parentNode = f;
		}
		updateHeight(f);
		
		//b-d-f
		d.leftNode = b;
		d.rightNode = f;
		b.parentNode = d;
		f.parentNode = d;
		updateHeight(d);
	}
	
	
	private void rotateLeft(Node<E>grandNode) {
		Node<E>parentNode = grandNode.rightNode;
		Node<E>childNode = parentNode.leftNode;
		grandNode.rightNode = childNode;
		grandNode.leftNode = grandNode;
		afterRotate(grandNode, parentNode, childNode);
	}
	
	private void rotateRight(Node<E>grandNode) {
		Node<E> parentNode = grandNode.leftNode;
		Node<E> childNode = parentNode.rightNode;
		grandNode.leftNode = childNode;
		parentNode.rightNode = grandNode;
		afterRotate(grandNode, parentNode, childNode);
	}
	
	private void afterRotate(Node<E>grandNode,Node<E>parentNode,Node<E>childNode) {
		//让parent称为子树的根节点
		parentNode.parentNode = grandNode.parentNode;
		if (grandNode.isLeftChild()) {
			grandNode.parentNode.leftNode = parentNode;
		}else if (grandNode.isRightChild()) {
			grandNode.parentNode.rightNode = parentNode;
		}else {
			//grand 是root节点
			root = parentNode;
		}
		//更新child的parent
		grandNode.parentNode = parentNode;
		//更新高度
		updateHeight(grandNode);
		updateHeight(parentNode);
	}
	
	private boolean isBalanced(Node<E> node) {
		return Math.abs(((AVLNode<E>)node).balanceFactor()) <= 1;
	}
	
	private void updateHeight(Node<E>node) {
		((AVLNode<E>)node).updateHeight();
	}
	
	
	private static class AVLNode<E> extends Node<E>{
		int height = 1;
		
		public AVLNode(E element,Node<E>parent) {
			super(element, parent);
		}
		
		public int balanceFactor() {
			int leftHeight = leftNode == null ? 0 : ((AVLNode<E>)leftNode).height;
			int rightHeight = rightNode == null ? 0 : ((AVLNode<E>)rightNode).height;
			return leftHeight - rightHeight;
		}
		
		public void updateHeight(){
			int leftHeight = leftNode == null ? 0 :((AVLNode<E>)leftNode).height;
			int rightHeight = rightNode == null ? 0 : ((AVLNode<E>)rightNode).height;
			height = 1 + Math.max(leftHeight, rightHeight);
		}
		
		public Node<E> tallerChild(){
			int leftHeight = leftNode == null ? 0 : ((AVLNode<E>)leftNode).height;
			int rightHeight = rightNode == null ? 0 : ((AVLNode<E>)rightNode).height;
			if(leftHeight > rightHeight) return leftNode;
			if(leftHeight < rightHeight) return rightNode;
			return isLeftChild() ? leftNode : rightNode;
		}
		
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			String parentString = "null";
			if (parentNode != null) {
				parentString = parentNode.element.toString();
			}
			return element + "_p(" + parentString + ")_h" + height + ")";
		}
		
	}
}
