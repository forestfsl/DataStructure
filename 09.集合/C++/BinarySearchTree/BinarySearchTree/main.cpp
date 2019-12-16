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
#include "RBTree.hpp"
#include "TimeTool.hpp"
#include <stdio.h>
#include <chrono>
#include "FileInfo.hpp"
#include "ListSet.hpp"
#include "TreeMap.hpp"
#include "TreeSet.hpp"
#include <thread>

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


void avlTest(){
    string data [] = {"01","02","03","04"};
    int len = sizeof(data) / sizeof(string);
    
    
    AVLTree<string> *avlTree = new AVLTree<string>(lamb);
    
    for (int i = 0; i < len; i++) {
        avlTree->add(data[i]);
    }
    BinaryTreeLevelOrderPrinter<string>::printerWithTree(avlTree);
    
    avlTree->remove("01");
    BinaryTreeLevelOrderPrinter<string>::printerWithTree(avlTree);
}


void testRBTree(){
    string data [] = {"55","87","56","74","96","22","62","20","70","68","90","50"};
     int len = sizeof(data) / sizeof(string);
    RBTree<string> *rbTree = new RBTree<string>(lamb);
    for (int i = 0; i < len; i++) {
        rbTree->add(data[i]);
         BinaryTreeLevelOrderPrinter<string>::printerWithTree(rbTree);
        cout << "------------------------------------------------" << endl;
    }
    
}

void testRBTree1(){
    string data [] = {"55","87","56","74","96","22","62","20","70","68","90","50"};
     int len = sizeof(data) / sizeof(string);
    RBTree<string> *rbTree = new RBTree<string>(lamb);
    for (int i = 0; i < len; i++) {
        rbTree->add(data[i]);
    }
     BinaryTreeLevelOrderPrinter<string>::printerWithTree(rbTree);
    
    for (int i = 0; i < len; i++) {
          rbTree->add(data[i]);
          rbTree->remove(data[i]);
         cout << "------------------------------------------------" << endl;
         cout << "[" << data[i] + "]" << endl;
         BinaryTreeLevelOrderPrinter<string>::printerWithTree(rbTree);
      }
  
    
}

int fib1(int n){
    if (n <= 1) {
        return n;
    }
    return fib1(n - 1) + fib1(n - 2);
}


auto lamb1 = []  ()-> void{
     list<string>listWorld = FileInfo::fetchListWorld();
     ListSet<string> *listSet = new ListSet<string>();
    
    auto it=listWorld.begin();
      for(;it!=listWorld.end();it++)
        {
            string english = (string)*it;
            listSet->add(english);
        }
       for(;it!=listWorld.end();it++)
              {
                  string english = (string)*it;
                  listSet->contains(english);
              }
    for(;it!=listWorld.end();it++)
      {
          string english = (string)*it;
          listSet->remove(english);
      }
    
};

auto lamb2 = []  ()-> void{
       list<string>listWorld = FileInfo::fetchListWorld();
      TreeSet<string> *treeSet = new TreeSet<string>(lamb);
    
       auto it=listWorld.begin();
         for(;it!=listWorld.end();it++)
           {
               string english = (string)*it;
               treeSet->add(english);
           }
   
            for(;it!=listWorld.end();it++)
              {
                  string english = (string)*it;
                  treeSet->contains(english);
              }
    for(;it!=listWorld.end();it++)
      {
          string english = (string)*it;
          treeSet->remove(english);
      }

};



void testListSet(){
    ListSet<int> *listSet = new ListSet<int>();
    listSet->add(10);
    listSet->add(11);
    listSet->add(12);
    listSet->add(11);
    listSet->add(10);
    
   listSet->traversal([] (int element) -> bool{
       cout << element << endl;;
       return false;
   });
}

void testTreeSet(){
    TreeSet<string> *treeSet = new TreeSet<string>(lamb);
    treeSet->add("50");
    treeSet->add("10");
    treeSet->add("20");
    treeSet->add("30");
    treeSet->add("20");
    treeSet->add("40");
    treeSet->traversal();
}

void testTreeSet1(){
    TreeSet<string> *treeSet = new TreeSet<string>();
    treeSet->add("g");
    treeSet->add("c");
    treeSet->add("c");
    treeSet->add("d");
    treeSet->add("e");
    treeSet->add("f");
    treeSet->add("a");
    treeSet->traversal();
}


void testTreeMap(){
    TreeMap<string, int> *map = new TreeMap<string, int>();
    map->put("c", 2);
    map->put("a", 5);
    map->put("b", 6);
    map->put("a", 8);
    map->traversal1([] (string key,int value) -> bool {
        cout << key <<"_" << to_string(value) << endl;
        return false;
    });
}
void thread01()
{
//    for (int i = 0; i < 5; i++)
//    {
//        cout << "Thread 01 is working ！" << endl;
//
//    }
    TimeTool::checkTime("ListSet", lamb1);
}
    
void thread02()
{
//    for (int i = 0; i < 5; i++)
//    {
//        cout << "Thread 02 is working ！" << endl;
//
//    }
    TimeTool::checkTime("TreeSet", lamb2);
}

int main(int argc, const char * argv[]) {
   
    
//    string data [] = { "38", "18", "04","03","05", "69","68", "85", "71", "34", "36", "29", "100" };
//    string data [] = { "04", "01", "08","02","07", "10","03", "05", "09", "11", "06" };
//    avlTest();
//    TimeTool::checkTime("ListSet", lamb1);
//    TimeTool::checkTime("TreeSet", lamb2);

//    FileInfo::fetchWorld();
//    testListSet();
//    testTreeSet1();
//    testRBTree1();
//    testTreeMap();
    
    thread task01(thread01);
    thread task02(thread02);
    task01.join();
    task02.join();
    return 0;
}
