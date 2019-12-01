//
//  Node.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/11/16.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>


template<class E>
class Node{
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
    bool isLeaf(){
        return left == nullptr && right == nullptr;
    }
    bool hasTwoChildren(){
        return left != nullptr && right != nullptr;
    }
    bool isLeftChild(){
        return parent != nullptr && this == parent->left;
    }
    bool isRightChild(){
        return parent != nullptr && this == parent->right;
    }
    
    Node<E> * sibling(){
        if (isLeftChild()) {
            return parent->right;
        }
        if (isRightChild()) {
            return parent->left;
        }
        return nullptr;
    }
};

#endif /* Node_hpp */
