package com.forest;

import java.util.ArrayList;
import java.util.List;

public class Main {
	
	static void test1() {
		Integer data[] = new Integer[] {
				57,52,92,96,53,95,13,63,34,82,76,54,9,68,39
		};
		
		AVLTree<Integer> avlTree = new AVLTree<>();
		for (int i = 0; i < data.length; i++) {
			avlTree.add(data[i]);
		}
		
//		for (int i = 0; i < data.length; i++) {
//			avlTree.remove(data[i]);
//		}
		BinaryTrees.println(avlTree);
	}
	
	static void test2() {
		List<Integer> dataList =  new ArrayList<>();
		for (int i = 0; i < 100_0000; i++) {
			dataList.add(((int)Math.random() * 100_1000));
		}
		
		BST<Integer> bst = new BST<>();
		for (int i = 0; i < dataList.size(); i++) {
			bst.add(dataList.get(i));
		}
		
		for (int i = 0; i < dataList.size(); i++) {
			bst.contains(dataList.get(i));
		}
		AVLTree<Integer>avlTree = new AVLTree<>();
		for (int i = 0; i < dataList.size(); i++) {
			avlTree.add(dataList.get(i));
		}
		
		for (int i = 0; i < dataList.size(); i++) {
			avlTree.contains(dataList.get(i));
		}
		for (int i = 0; i < dataList.size(); i++) {
			avlTree.remove(dataList.get(i));
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		test1();
	}

}
