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
#include "Node.hpp"

using namespace std;

template<class E>
class BinarySearchTree {
    typedef int(*CompareElement)(int,int);
public:
   
    int m_size;
    Node<E> *root;
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
            root = new Node<E>(element,nullptr);
            m_size++;
            return;
        }
        //添加的不是第一个节点
        Node<E> *parent = root;
        Node<E> *node = root;
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
        Node<E> *newNode = new Node<E>(element,parent);
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
 
    Node<E> *leftNode(Node<E> *node){
        return node->left;
    }
    Node <E> *rightNode(Node<E> *node){
        return node->right;
    }
    Node<E>* rootNode(){
        return this->root;
    }
    E nodeElement(Node<E>node){
        return node->element;
    }
    
};




#endif /* BinarySearchTree_hpp */
