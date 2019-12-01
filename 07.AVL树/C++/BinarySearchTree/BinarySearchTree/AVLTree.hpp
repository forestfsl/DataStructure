//
//  AVLTree.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/1.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp
#include "BinarySearchTree.hpp"

#include <stdio.h>

template <class E>
class AVLTree : public BinarySearchTree<E> {
     typedef int(*CompareElement)(int,int);
public:
    AVLTree(){
        AVLTree(nullptr);
    }
    
    AVLTree(CompareElement compareBlock) : BinarySearchTree<E>(compareBlock){
        cout << "AVLTree 的构造函数" << endl;
        
    }
    
    
     class AVLNode : public Node<E>{
         int height = 1;
        
        AVLNode(E element,Node<E> *parent) : Node<E>(element,parent) {
            
        }
         //平衡因子
        int balanceFactor(){
            int leftHeight = this->left == nullptr ? 0 : ((AVLNode)left)->height;
            int rightHeight = this->right == nullptr ? 0 : ((AVLNode)right)->height;
            return leftHeight - rightHeight;
        }
         
         void rebalance(Node<E> *grand){
             Node<E> *parent = ((AVLNode)grand)->tallerChild();
             Node<E> *node = ((AVLNode)parent)->tallerChild();
             if (parent->isLeftChild()) {//L
                 if (node->isLeftChild()) {//LL
                     rotateRight(grand);
                 }else{//LR
                     rotateLeft(parent);
                     rotateRight(grand);
                 }
             }else{//R
                 if (node->isLeftChild()) {//RL
                     rotateRight(parent);
                     rotateLeft(grand);
                 }else{//RR
                     rotateLeft(grand);
                 }
             }
         }
   
         
         //左旋转
         /*
                    g                                  p
                  /   \                             /      \
                |      p                           g         n
                |     / \                        /   \      /  \
                |    |   n                      |     |    |    |
                |    |  /  \                    |     |    |    |
                T0   |  |  |                    |     |    T2   |
                    T1  T2 |新增                T0     T1        T3
                           T3
          */
         void rotateLeft(Node<E> *grand){
             Node<E> *parent = grand->right;
             Node<E> *child = parent->left;
             grand->right = child;
             parent->left = grand;
             afterRotate(grand, parent, child);
             
         }
         
         
//         右旋转
         /*               g                             p
                          /   \                         /    \
                        p      |                       n      g
                      /   \    |                      /  \   /  \
                    n      |   |    ---->             |   |  |   |
                 /    \    |   |                      |   |  |   |
                |     |    |   |                      |   |  |   |
           T0   |     |    |                          |   T1 |   |
                |     T1   T2  T3                     T0     T2  T3
           */
         void rotateRight(Node<E> *grand){
             //grand的左视图将会成为新的parent
             Node<E> *parent = grand->left;
             //parent 的right将会成为新的子节点
             Node<E> *child = parent->right;
             grand->left = child;
             grand->right = grand;
             //还需要维护的内容T2,p,g的parent
             afterRotate(grand, parent, child);
         }
         
         void afterRotate(Node<E> *grand,Node<E> *parent,Node<E> *child){
             //让parent成为根节点
             parent->parent = grand->parent;
             if (grand->isLeftChild()) {
                 grand->parent->left = parent;
             }else if (grand->isRightChild()){
                 grand->parent->right = parent;
             }else{//grand 是root节点
                 this->root = parent;
             }
             //更新child的parent
             if (child != nullptr) {
                 child->parent = grand;
             }
             //更新grand的parent
             grand->parent = parent;
             //更新高度
             updateHeight(grand);
             updateHeight(parent);
             
         }
         
         //是否是平衡因子
         bool isBalanced(Node<E> *node){
             return abs(((AVLNode)node)->balanceFactor()) <= 1;
         }
         
         //更新高度
         void updateHeight(Node<E> *node){
             ((AVLNode)node)->updateHeight();
         }
         
         void updateHeight(){
             int leftHeight = this->left == nullptr ? 0 : ((AVLNode)left)->height;
             int rightHeight = this->right == nullptr ? 0 : ((AVLNode)right)->height;
             height = 1 + max(leftHeight,rightHeight);
         }
         //寻找当前节点的最高者
         Node<E>* tallerChild(){
             int leftHeight = this->left == nullptr ? 0 : ((AVLNode)left)->height;
             int rightHeight = this->right == nullptr ? 0 : ((AVLNode)right)->height;
             if (leftHeight > rightHeight) return this->left;
             if (leftHeight < rightHeight) return this->right;
             return this->isLeftChild() ? this->left : this->right;
         }
         
    };
    
    Node<E> * createNode(E element,Node<E> *parent){
        return new AVLNode(element,parent);
    }
};

#endif /* AVLTree_hpp */
