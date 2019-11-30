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
//#include <iostream>
//#include "Node.hpp"
//#include <queue>
#include "BinaryTree.hpp"

//using namespace std;




template<class E>
class BinarySearchTree :public BinaryTree<E>{
    typedef int(*CompareElement)(int,int);
public:
    //函数指针
    CompareElement compareBlock;
//    Visitor visitor;
    
    BinarySearchTree<E>(){
        BinarySearchTree(NULL);
    }
    BinarySearchTree<E>(CompareElement compare){
        this->compareBlock = compare;
        this->root = nullptr;
        isFinish = false;
    }
   
    
    //添加
    void add(E element){
        elementNotNullCheck(element);
        //添加第一个节点
        if (this->root == nullptr || this->root == NULL) {
            this->root = new Node<E>(element,nullptr);
            this->m_size++;
            return;
        }
        //添加的不是第一个节点
        Node<E> *parent = this->root;
        Node<E> *node = this->root;
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
        this->m_size++;
    }
    
    Node<E> * fetchNode(E element){
        Node<E> *node = this->root;
        while (node != nullptr) {
            int cmp = compare(element, node->element);
            if (cmp == 0) return node;
            if (cmp > 0) {
                node = node->right;
            }else{
                node = node->left;
            }
        }
        return nullptr;
    }
    
    //移除
    void remove(E element){
        remove(fetchNode(element));
    }
    
    void remove(Node<E> *node){
        if (node == nullptr) return;
        //移除元素必定需要size--
        this->m_size--;
        //这里需要考虑三种情况：度为2的节点，度为1的节点，度为0的节点，为了精简代码，先从度为2的开始，其实就算是删除度为2的节点，最后也就变成为删除度为1或者度为0的元素，因为度为2的删除仅仅是用后继节点的值来覆盖要删除的几点，最后要删掉的是后继节点的值（注意：后继节点变成前继节点也成立）
        if (node->hasTwoChildren()) {
             Node<E> *s = this->successor(node);
            //用后继节点的值覆盖为度为2的值
            node->element = s->element;
            node = s;
        }
        //如果来到这里代表node指向后驱节点，接下来只要进行度为1或者度为0的判断就可以了
        //删除node节点(node的度必然是1或者是0)
        Node<E> *replacement = node->left != nullptr ? node->left : node->right;
        if (replacement != nullptr) {//onde 是度为1的节点
            //更改parent
            replacement->parent = node->parent;
            //更改parent的left，right的指向
            if (node->parent == nullptr) { //node 是度为1的节点并且是根节点
                this->root = replacement;
            }else if (node == node->parent->left){
                node->parent->left = replacement;
            }else{//node == node->parent->right
                node->parent->right = replacement;
            }
        }else if (node->parent == nullptr){//node 是z叶子节点并且是根节点
            this->root = nullptr;
        }else{//node 是叶子节点，但不是根节点
            if (node == node->parent->left) {
                node->parent->left = nullptr;
            }else{//node == node->parent->right
                node->parent->right = nullptr;
            }
        }
       
//        if (s != nullptr) {
//             cout << "后继节点是" << s->element << endl;
//        }
       
    }
  
    
    void elementNotNullCheck(E element){
        if (element.size() == 0) {
            throw "element must not be null";
        }
    }
    
    int compare(E e1, E e2){
        if (compareBlock != nullptr) {
            return compareBlock(atoi(e1.c_str()),atoi(e2.c_str()));
        }
        return atoi(e1.c_str()),atoi(e2.c_str());
    }
 
   
};




#endif /* BinarySearchTree_hpp */
