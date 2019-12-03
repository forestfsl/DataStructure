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
    
public:
    class AVLNode : public Node<E>{
    public:
        int height = 1;
        
        AVLNode(E element,Node<E> *parent) : Node<E>(element,parent) {
            this->height = 1;
//            cout << "height" << height << endl;
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
    
    AVLTree(CompareElement compareBlock) : BinarySearchTree<E>(compareBlock){
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
        //        while ((node = node->parent) != nullptr) {
        //            if (isBalanced(node)) {
        //                //更新高度
        //                updateHeight(node);
        //            }else{
        //                //恢复平衡
        //                rebalance(node);
        //            }
        //        }
    }
    
    //是否是平衡因子
    bool isBalanced(Node<E> *node){
        bool isBalance = abs(((AVLNode*)node)->balanceFactor()) <= 1;
        return isBalance;
    }
    
    
    
    
   
    
};

#endif /* AVLTree_hpp */
