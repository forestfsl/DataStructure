//
//  BinarySearchTree.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/11/12.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template<class E>
class BinarySearchTree {
    typedef int(*CompareElement)(int,int);
public:
    static class Node{
    public:
        E element; //元素值
        Node *left;//左子节点
        Node *right;//右子节点
        Node *parent;//父节点
        //构造函数
        Node(E element,Node *parent){
            this->element = element;
            this->parent = parent;
            this->left = nullptr;
            this->right = nullptr;
        }
    };
    int m_size;
    Node *root;
    int compare_element(CompareElement);
    //函数指针
    CompareElement compareBlock;
    BinarySearchTree<E>(){
        BinarySearchTree(NULL);
    }
    BinarySearchTree<E>(CompareElement compare){
        this->compareBlock = compare;
        root = nullptr;
    }
    
    int size(){
        return m_size;
    }
    bool isEmpty(){
        return m_size == 0;
    }
    void clear(){
        root = NULL;
        m_size = 0;
    }
    
    void add(E element){
        elementNotNullCheck(element);
        //添加第一个节点
        if (root == nullptr || root == NULL) {
            root = new Node(element,nullptr);
            m_size++;
            return;
        }
        //添加的不是第一个节点
        Node *parent = root;
        Node *node = root;
        int cmp = 0;
        //遍历tree
        do {
            cmp = compare(element, node->element);
            parent = node;
            if (cmp > 0) {
                node = node->right;
            }else if (cmp < 0){
                node = node->left;
            }else{
                node->element = element;
                return;
            }
        } while (node != nullptr || node != NULL);
        //遍历完毕之后插入元素节点
        Node *newNode = new Node(element,parent);
        if (cmp > 0) {
            parent->right = newNode;
        }else{
            parent->left = newNode;
        }
        m_size++;
    }
    
    void elementNotNullCheck(E element){
        if (!element) {
            throw "element must not be null";
        }
    }
    
    int compare(E e1, E e2){
        if (compareBlock != nullptr) {
            return compareBlock(e1,e2);
        }
        return e1 - e2;
    }
 

};


#endif /* BinarySearchTree_hpp */
