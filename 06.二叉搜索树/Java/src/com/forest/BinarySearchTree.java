package com.forest;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

import javax.xml.bind.helpers.ParseConversionEventImpl;

@SuppressWarnings("unused")
public class BinarySearchTree<E> implements BinaryTreeInfo {
	private int size;
	private Node<E>root;
	private Comparator<E> comparator;
	
	//无参构造函数
	public BinarySearchTree() {
		this(null);
	}
	//有参构造
	public BinarySearchTree(Comparator<E> comparator) {
		this.comparator = comparator;
	}
	
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
	
	public void add(E element) {
		elementNotNullCheck(element);
		//添加第一个节点
		if (root == null) {
			root = new Node<>(element, null);//根节点是不需要父节点的
			size++;
			return;
		}
		//添加的不是第一个节点
		//找到父节点
		Node<E> parentNode = root;
		//遍历的时候用的一个node变量
		Node<E> node = root;
		int cmp = 0;
		while (node != null) {
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
		}
		//看看插入到父节点的哪个位置
		Node<E> newNode = new Node<>(element,parentNode);
		if (cmp > 0) {
			parentNode.rightNode = newNode;
		}else {
			parentNode.leftNode = newNode;
		}
		size++;
	}
	
	public void remove(E element) {
		remove(node(element));
	}
	
	//是否包含节点
	public boolean contains(E element) {
		return node(element) != null;
	}
	private void remove(Node<E> node) {
		Node<E> tempNode = root;
		if(node == null) return;
		size--;
		if (node.hasTwoChildren()) { //度为2的节点
			//找到后继节点
			Node<E> stepNode = successor(node);
			//用后继节点的值覆盖要删除的节点并且度为2的值
			node.element = stepNode.element;
			//删除后继节点
			node = stepNode;
		}
		//删除node节点（node的度必然是1或者0）
		Node<E> replacementNode = node.leftNode != null ? node.leftNode : node.rightNode;
		if (replacementNode != null) { //node是度为1的节点
			//更改parent
			replacementNode.parentNode = node.parentNode;
			//更改parent的left，right的指向
			if (node.parentNode == null) { //node是度为1的节点并且是根节点
				root = replacementNode;
			}else if (node == node.parentNode.leftNode) {
				node.parentNode.leftNode = replacementNode;
			}else {
				//node == node.parent.right
				node.parentNode.rightNode = replacementNode;
			}
		}else if (node.parentNode == null) { //node 是叶子节点并且是根节点
			root = null;
		}else {
			//node 是叶子节点，但不是根节点
			if (node == node.parentNode.leftNode) {
				node.parentNode.leftNode = null;
			}else {
				//node == node.parent.right
				node.parentNode.rightNode = null;
			}
		}
		
	}
	
	/**
	 * 暴露前序遍历方法
	 */
	public void preorder(Visitor<E>visitor) {
		if(visitor == null) return;
		preorder(root,visitor);
	}
	
	/**
	 * 前序遍历
	 * @return
	 */
	private void preorder(Node<E> node, Visitor<E>visitor) {
		if(node == null || visitor.stop) return;
		
		if(visitor.stop) return;
		visitor.stop = visitor.visit(node.element);
		preorder(node.leftNode, visitor);
		preorder(node.rightNode, visitor);
	}
	
	/**
	 * 暴露中序遍历方法
	 */
	public void inorder(Visitor<E>visitor) {
		if(visitor == null) return;
		inorder(root, visitor);
	}
	
	/**
	 * 中序遍历
	 * @return
	 */
	private void inorder(Node<E>node, Visitor<E>visitor) {
		if (node == null || visitor.stop) return;
		
		inorder(node.leftNode, visitor);
		if(visitor.stop) return;
		visitor.stop = visitor.visit(node.element);
		inorder(node.rightNode, visitor);
	}
	
	/**
	 * 暴露后序遍历方法
	 */
	public void postorder(Visitor<E> visitor) {
		if (visitor == null) return;
		postorder(root,visitor);
	}
	
	/**
	 * 后序遍历
	 * @return
	 */
	private void postorder(Node<E>node,Visitor<E>visitor) {
		if (node == null || visitor.stop) return;
		
		postorder(node.leftNode, visitor);
		postorder(node.rightNode, visitor);
		if(visitor.stop) return;
		visitor.stop = visitor.visit(node.element);
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
			if(visitor.visit(node.element)) return;
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
				if(node.leftNode != null) {
					queue.offer(node.leftNode);
				}
			}
		}
		return true;
	}
	
	public boolean isComplete2() {
		if (root == null) return false;
		Queue<Node<E>> queue = new LinkedList<>();
		queue.offer(root);
		boolean leaf = false;
		while (!queue.isEmpty()) {
			Node<E> node = queue.poll();
			if(leaf && !node.isLeaf()) return false;
			//首先保证所有节点都能入队，如果左节点有值就将左节点入队，右节点有值就将右节点入队
			if(node.leftNode != null) {
				queue.offer(node.leftNode);
			}else if(node.rightNode != null) {
				//node.leftNode == null && node.right != null
				return false;
				
			}
			if(node.rightNode != null) {
				queue.offer(node.rightNode);
			}else {
				//node.left == null && node.right == null
				//node.left != null && node.right == null
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
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		StringBuilder sBuilder = new StringBuilder();
		toString(root,sBuilder,"");
		return sBuilder.toString();
	}
	private void toString(Node<E>node,StringBuilder sBuilder,String prefix) {
		if (node == null) return;
		toString(node.leftNode,sBuilder,prefix + "L---");
		sBuilder.append(prefix).append(node.element).append("\n");
		toString(node.rightNode,sBuilder,prefix + "R---");
	}
	/**
	 * 返回值等于0，代表e1和e2相等，返回值大于0，代表e1大于e2；返回值小于0，代表e1小于e2
	 * @param element
	 */
	@SuppressWarnings("unchecked")
	private int compare(E e1,E e2) {
		if (comparator != null) {
			return comparator.compare(e1, e2);
		}
		return ((Comparable<E>)e1).compareTo(e2);
	}
	
	private void elementNotNullCheck(E element) {
		if (element == null) {
			throw new IllegalArgumentException("element must not be null");
		}
	}
	//获取节点的前驱节点
	private Node<E> predecessor(Node<E>node){
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
	private Node<E> successor(Node<E> node){
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
	public static abstract class Visitor<E>{
		boolean stop;
		/**
		 * 如果返回true，代表停止
		 * @param element
		 * @return
		 */
		abstract boolean visit(E element);
	}
	
	private static class Node<E>{
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
	}
	
	/**
	 * 根据元素获取节点
	 * @param element
	 * @return
	 */
	private Node<E> node(E element){
		Node<E> node = root;
		//通过遍历的方式获取node节点
		while (node != null) {
			int cmp = compare(element, node.element);
			//如果两个元素相等，直接返回当前元素
			if(cmp == 0) return node;
			//如果element大于node.element,赋值右节点继续遍历
			if (cmp > 0) {
				node = node.rightNode;
			}else {
				//如果element小于node.element,赋值左节点继续遍历
				node = node.leftNode;
			}
		}
		return null;
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
		@SuppressWarnings("unchecked")
		Node<E> myNode = (Node<E>)node;
		String parentString = "null";
		if (myNode.parentNode != null) {
			parentString = myNode.parentNode.element.toString();
		}
		return myNode.element + "_p(" + parentString + ")";
	}


}
