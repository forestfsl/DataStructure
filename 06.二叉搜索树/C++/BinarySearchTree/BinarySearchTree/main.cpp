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
using namespace std;

int sum(int a,int b){
    return a+b;
}

int main(int argc, const char * argv[]) {
    auto lamb = [] (int a,int b) -> int{
        return  a - b;
    };
    
    string data [] = { "38", "18", "4", "69", "85", "71", "34", "36", "29", "100" };
    int len = sizeof(data) / sizeof(string);
    
    BinarySearchTree<string> *tree = new BinarySearchTree<string>(lamb);
    for (int i = 0; i < len; i++) {
           tree->add(data[i]);
       }
    BinaryTreeLevelOrderPrinter<string>::printerWithTree(tree);
    cout << "debug test node element" << endl;
    
    return 0;
}
