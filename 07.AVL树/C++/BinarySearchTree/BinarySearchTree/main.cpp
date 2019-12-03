//
//  main.cpp
//  BinarySearchTree
//
//  Created by songlin on 2019/11/12.
//  Copyright © 2019 songlin. All rights reserved.
//

#include <iostream>

#include "BinarySearchTree.hpp"
#include "BinaryTreeLevelOrderPrinter.hpp"
#include "AVLTree.hpp"
using namespace std;

int sum(int a,int b){
    return a+b;
}

void testPreOrder(BinarySearchTree<string> *tree){
    cout <<"前序遍历开始:";
    tree->preorder([] (string element) -> bool{
        cout << element << " ";
        return element == "04" ? true : false;
    });
    cout << "前序遍历结束" << endl;
}

void testInOrder(BinarySearchTree<string> *tree){
    cout <<"中序遍历开始:";
    tree->inorder([] (string element) -> bool{
        cout << element << " ";
        return false;
    });

     cout << "中序遍历结束" << endl;
}

void testPostOrder(BinarySearchTree<string> *tree){
    cout <<"后续遍历开始:";
    tree->postorder([] (string element) -> bool{
        cout << element << " ";
        return false;
    });

    cout << "后续遍历结束" << endl;
}

void testLevelOrder(BinarySearchTree<string> *tree){
     cout << "层序遍历开始" << endl;
    tree->levelorder([] (string element) -> bool{
        cout << element << " ";
        return false;
    });
     cout << "层序遍历结束" << endl;
}

auto lamb = [] (int a,int b) -> int{
    return  a - b;
};

void testBST(){

    string data [] = { "08", "04", "13","02","06", "10","01", "03", "05", "07", "09" ,"12","11"};
    int len = sizeof(data) / sizeof(string);

    BinarySearchTree<string> *tree = new BinarySearchTree<string>(lamb);
    for (int i = 0; i < len; i++) {
        tree->add(data[i]);
    }
    BinaryTreeLevelOrderPrinter<string>::printerWithTree(tree);

    testPreOrder(tree);

    testInOrder(tree);

    testPostOrder(tree);

    testLevelOrder(tree);

    cout << "树的高度是" << tree->heightRecursive() << endl;
    cout << "树的高度是" << tree->heightLevelOrder() << endl;
    cout << "树是否是完全二叉树:" << tree->isCompleteTree() << endl;


    tree->remove("11");

    BinaryTreeLevelOrderPrinter<string>::printerWithTree(tree);
}

int main(int argc, const char * argv[]) {
   
    
//    string data [] = { "38", "18", "04","03","05", "69","68", "85", "71", "34", "36", "29", "100" };
//    string data [] = { "04", "01", "08","02","07", "10","03", "05", "09", "11", "06" };

    string data [] = {"01","02","03"};
    int len = sizeof(data) / sizeof(string);
    
    
    AVLTree<string> *avlTree = new AVLTree<string>(lamb);
    
    for (int i = 0; i < len; i++) {
        avlTree->add(data[i]);
//        avlTree->testAdd();
    }
     BinaryTreeLevelOrderPrinter<string>::printerWithTree(avlTree);
    
    return 0;
}
