//
//  BBST.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/9.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef BBST_hpp
#define BBST_hpp

#include <stdio.h>
#include "BinarySearchTree.hpp"

template<class E>

class BBST : public BinarySearchTree<E>{
     typedef int(*CompareElement)(int,int);
public:
    //函数指针
    CompareElement compareBlock;
    
    BBST<E>() {
        BBST(nullptr);
    }
    BBST<E>(CompareElement compareBlock):BinarySearchTree<E>(compareBlock){
        
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
        this->subAfterRotate(grand, parent, child);
        
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
        parent->right = grand;
        //还需要维护的内容T2,p,g的parent
        this->subAfterRotate(grand, parent, child);
    }
    
    virtual void subAfterRotate(Node<E> *grand,Node<E> *parent,Node<E> *child){
        
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
       
        
    }
};

#endif /* BBST_hpp */
