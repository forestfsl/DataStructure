package com.forest;

import com.forest.BinarySearchTree.Visitor;

public class Main {
//	BinarySearchTree<Integer> bst = new BinarySearchTree<>();
//	for (int i = 0; i < 10; i++) {
//		bst.add((int)(Math.random() * 100));
//	}
	
	//测试二叉树
	static void testBinarySearchTree() {
		Integer data[] = new Integer[] {
				4,7,9,2,5,8,11,3,12,1
		};
		BinarySearchTree<Integer> bstTree = new BinarySearchTree<>();
		for (int i = 0; i < data.length; i++) {
			bstTree.add(data[i]);
		}
		BinaryTrees.println(bstTree);
	}
	
	//测试打印工具
	static void testPrinterTool() {
		BinaryTrees.println(new BinaryTreeInfo() {
			
			@Override
			public Object string(Object node) {
				// TODO Auto-generated method stub
				return node.toString() + "_";
			}
			
			@Override
			public Object root() {
				// TODO Auto-generated method stub
				return "A";
			}
			
			@Override
			public Object right(Object node) {
				// TODO Auto-generated method stub
				if (node.equals("A")) return "C";
				if (node.equals("C")) return "E";
				return null;
			}
			
			@Override
			public Object left(Object node) {
				// TODO Auto-generated method stub
				if(node.equals("A")) return "B";
				if(node.equals("C")) return "D";
				return null;
			}
		});
	}
	
	//测试对象
	static void testPerson() {
		BinarySearchTree<Person> bstTree = new BinarySearchTree<>();
		bstTree.add(new Person(10,"jack"));
		bstTree.add(new Person(12,"rose"));
		bstTree.add(new Person(6,"tim"));
		bstTree.add(new Person(10,"mical"));
		BinaryTrees.println(bstTree);
	}
	
	//前序遍历
	static void testPreOrder() {
		Integer data[] = new Integer[] {
				7,4,9,2,5
		};
		
		//创建二叉树
		BinarySearchTree<Integer> bst = new BinarySearchTree<>();
		for (int i = 0; i < data.length; i++) {
			bst.add(data[i]);
		}
		BinaryTrees.println(bst);
		System.out.println(bst.isComplete());
		
		bst.preorder(new Visitor<Integer>() {
			
			@Override
			public void visit(Integer element) {
				// TODO Auto-generated method stub
				System.out.print("_" + element + "_");
			}
		});
		
		System.out.println("树的高度是"+ bst.height());
		
	}
	
	//中序遍历
	static void testInorder() {
		Integer data[] = new Integer[] {
				7,4,9,2,5
		};
		
		//创建二叉树
		BinarySearchTree<Integer> bst = new BinarySearchTree<>();
		for (int i = 0; i < data.length; i++) {
			bst.add(data[i]);
		}
		BinaryTrees.println(bst);
		System.out.println(bst.isComplete());
		
		bst.inorder(new Visitor<Integer>() {

			@Override
			public void visit(Integer element) {
				// TODO Auto-generated method stub
				System.out.print("_" + element + "_");
			}
		});
	}
	
	//后续遍历
	static void testPostorder() {
		Integer data[] = new Integer[] {
				7,4,9,2,5
		};
		
		//创建二叉树
		BinarySearchTree<Integer> bst = new BinarySearchTree<>();
		for (int i = 0; i < data.length; i++) {
			bst.add(data[i]);
		}
		BinaryTrees.println(bst);
		System.out.println(bst.isComplete());
		
		bst.postorder(new Visitor<Integer>() {

			@Override
			public void visit(Integer element) {
				// TODO Auto-generated method stub
				System.out.print("_" + element + "_");
			}
		});
	}
	//层序遍历
	static void testLevelorder() {
		Integer data[] = new Integer[] {
				7,4,9,2,5
		};
		
		//创建二叉树
		BinarySearchTree<Integer> bst = new BinarySearchTree<>();
		for (int i = 0; i < data.length; i++) {
			bst.add(data[i]);
		}
//		BinaryTrees.println(bst);
//		System.out.println(bst.isComplete());
		
		bst.levelOrder(new Visitor<Integer>() {

			@Override
			public void visit(Integer element) {
				// TODO Auto-generated method stub
				System.out.print("_" + element + "_");
			}
		});
	}
	
	//测试删除
	static void testRemove() {
		Integer data[] = new Integer[] {
				7,4,9,2,11,3,12,1,10
		};
		BinarySearchTree<Integer>bSearchTree = new BinarySearchTree<>();
		for (int i = 0; i < data.length; i++) {
			bSearchTree.add(data[i]);
		}
		BinaryTrees.println(bSearchTree);
		bSearchTree.remove(11);
		BinaryTrees.println(bSearchTree);
	}

	
	
	
	
	public static void main(String[] args) {
//		testBinarySearchTree();
//		testPrinterTool();
//		testPerson();
//		testPreOrder();
//		testPostorder();
//		testLevelorder();
//		testInorder();
		testRemove();
	}

}
