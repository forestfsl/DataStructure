package com.forest;

import java.util.Comparator;
import com.forest.BinaryTree.Node;

@SuppressWarnings("unused")
public class BBST<E> extends BST<E> {
	public BBST() {
		this(null);
	}
	public BBST(Comparator<E>comparator) {
		super(comparator);
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
			//e-f
			f.leftNode = e;
			if (e != null) {
				e.parentNode = f;
			}
			
			//b-d-f
			d.leftNode = b;
			d.rightNode = f;
			b.parentNode = d;
			f.parentNode = d;
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
		}

}
