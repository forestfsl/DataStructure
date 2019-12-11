//
//  AVLTree.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/1.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp
#include "BBST.hpp"

#include <stdio.h>

template <class E>
class AVLTree : public BBST<E> {
    
public:
    class AVLNode : public Node<E>{
    public:
        int height = 1;
        
        AVLNode(E element,Node<E> *parent) : Node<E>(element,parent) {
            this->height = 1;
        }
        //平衡因子
        int balanceFactor(){
            int leftHeight = this->left == nullptr ? 0 : ((AVLNode*)this->left)->height;
            int rightHeight = this->right == nullptr ? 0 :((AVLNode*)this->right)->height;
            return leftHeight - rightHeight;
        }
        
        
        void updateHeight(){
            int leftHeight = this->left == nullptr ? 0 : ((AVLNode*)this->left)->height;
            int rightHeight = this->right == nullptr ? 0 : ((AVLNode*)this->right)->height;
            height = 1 + max(leftHeight,rightHeight);
        }
        //寻找当前节点的最高者
        Node<E>* tallerChild(){
            int leftHeight = this->left == nullptr ? 0 : ((AVLNode*)this->left)->height;
            int rightHeight = this->right == nullptr ? 0 : ((AVLNode*)this->right)->height;
            if (leftHeight > rightHeight) return this->left;
            if (leftHeight < rightHeight) return this->right;
            return this->isLeftChild() ? this->left : this->right;
        }
        
    };
    
    typedef int(*CompareElement)(int,int);
    AVLTree():AVLTree(nullptr){
        
    }
    
    AVLTree(CompareElement compareBlock) : BBST<E>(compareBlock){
        cout << "AVLTree 的构造函数" << endl;
    }
    
    
    //更新高度
    void updateHeight(Node<E> *node){
        ((AVLNode *)node)->updateHeight();
    }
    void rebalance(Node<E> *grand){
        Node<E> *parent = ((AVLNode*)grand)->tallerChild();
        Node<E> *node = ((AVLNode*)parent)->tallerChild();
        if (parent->isLeftChild()) {//L
            if (node->isLeftChild()) {//LL
                this->rotateRight(grand);
            }else{//LR
                this->rotateLeft(parent);
                this->rotateRight(grand);
            }
        }else{//R
            if (node->isLeftChild()) {//RL
                this->rotateRight(parent);
                this->rotateLeft(grand);
            }else{//RR
                this->rotateLeft(grand);
            }
        }
    }
    
    
  
   
    Node<E>* createNode(E element,Node<E> *parent){
        AVLNode *avlNode = new AVLNode(element,parent);
        return (Node<E>*)avlNode;
    }
    
    void testAfterAdd(){
        cout << "testAfterAdd AVL" << endl;
    }
    //新添加节点之后的处理
    void afterAdd(Node<E> *node){
        //         cout << "afterAdd AVL" << endl;
        while ((node = node->parent) != nullptr) {
            if (isBalanced(node)) {
                //更新高度
                updateHeight(node);
            }else{
                //恢复平衡
                rebalance(node);
                //整棵树恢复平衡
                break;
            }
        }
    }
    
    //删除节点之后的处理
    void afterRemove(Node<E> *node){
        //         cout << "remove AVL" << endl;
        while ((node = node->parent) != nullptr) {
            if (isBalanced(node)) {
                //更新高度
                updateHeight(node);
            }else{
                //恢复平衡
                rebalance(node);
            }
        }
    }
    
    //是否是平衡因子
    bool isBalanced(Node<E> *node){
        bool isBalance = abs(((AVLNode*)node)->balanceFactor()) <= 1;
        return isBalance;
    }
    
    
    
     void subAfterRotate(Node<E> *grand,Node<E> *parent,Node<E> *child){
         
         this->afterRotate(grand,parent,child);
        // 更新高度
        updateHeight(grand);
        updateHeight(parent);
    }
    
   
    
};

#endif /* AVLTree_hpp */
