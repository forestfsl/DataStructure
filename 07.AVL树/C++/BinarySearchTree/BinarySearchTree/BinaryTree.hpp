//
//  BinaryTree.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/1.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp
#include <stdio.h>
#include <iostream>
#include "Node.hpp"
#include <queue>

using namespace std;


static bool isFinish = false;

template<class E>
class BinaryTree {
    
public:
    
    typedef bool(*Visitor)(string);
    
    int m_size;
    Node<E> *root;
    int size(){
        return this->m_size;
    }
    bool isEmpty(){
        return this->m_size == 0;
    }
    void clear(){
        this->root = NULL;
        this->m_size = 0;
    }
    //前序遍历
    void preorder(Visitor visitor){
        preorder(this->root, visitor);
    }
    
    void preorder(Node<E> *node, Visitor visitor){
        if (node == nullptr || visitor == nullptr || isFinish) return;
        
        isFinish = visitor(node->element);
        preorder(node->left,visitor);
        preorder(node->right,visitor);
    }
    
    //中序遍历
    void inorder(Visitor visitor){
        isFinish = false;
        if (visitor == nullptr) return ;
        inorder(this->root, visitor);
    }
    
    void inorder(Node<E> *node, Visitor visitor){
        if (node == nullptr || visitor == nullptr || isFinish) return;
        inorder(node->left, visitor);
        if (isFinish) return;
        isFinish = visitor(node->element);
        inorder(node->right,visitor);
    }
    
    void postorder(Visitor visitor){
        isFinish = false;
        if (visitor == nullptr) return;
        postorder(this->root,visitor);
    }
    
    void postorder(Node<E> *node,Visitor visitor){
        if (node == nullptr || isFinish) return;
        postorder(node->left, visitor);
        postorder(node->right,visitor);
        if (isFinish) return;
        isFinish = visitor(node->element);
    }
    
    void levelorder(Visitor visitor){
        if (this->root == nullptr || visitor == nullptr) return;
        queue<Node<E> *> levelQueue;
        levelQueue.push(this->root);
        while (!levelQueue.empty()) {
            Node<E> *node = levelQueue.front();
            visitor(node->element);
            levelQueue.pop();
            
            if (node->left != nullptr) {
                levelQueue.push(node->left);
            }
            if (node->right != nullptr) {
                levelQueue.push(node->right);
            }
        }
        
    }
    
    Node<E>* predecessor(Node<E> *node){
        if (node == nullptr) return nullptr;
        //前驱节点在左子树当中(left.right.right.right.....)
        Node<E> *p = node->left;
        if (p != nullptr) {
            while (p != nullptr) {
                p = p->right;
            }
            return p;
        }
        //从父节点，祖父节点寻找前驱节点
        while (node->parent != nullptr && node == node->parent->left) {
            node = node->parent;
        }
        return node->parent;
    }
    
    Node<E>* successor(Node<E> *node){
        if (node == nullptr) return nullptr;
        // 后驱节点在左子树当中（right.left.left.left....）
        Node<E> *p = node->right;
        if (p != nullptr) {
            while (p->left != nullptr) {
                p = p->left;
            }
            return p;
        }
        //从父节点，祖父节点寻找前驱节点
        while (node->parent != nullptr && node == node->parent->right) {
            node = node->parent;
        }
        return node->parent;
    }
    
    //判断是否是完全二叉树
    bool isCompleteTree(){
        if (this->root == nullptr) return false;
        queue<Node<E> *> completeQueue;
        completeQueue.push(this->root);
        bool leaf = false;
        while (!completeQueue.empty()) {
            Node<E> *node = completeQueue.front();
            completeQueue.pop();
            //本来应该是叶子节点但是实际不是叶子节点，不符合实际
            if (leaf && !node->isLeaf()) return false;
            if (node->left != nullptr) {
                completeQueue.push(node->left);
            }else if (node->right != nullptr){
                //node->left == nullptr && node->right != nullptr
                return false;
            }
            if (node->right != nullptr) {
                completeQueue.push(node->right);
            }else{
                //               说明 node->right == nullptr
                leaf = true;
            }
        }
        return true;
    }
    
    //二叉树高度递归法
    int heightRecursive(){
        return heightRecursive(this->root);
    }
    
    int heightRecursive(Node<E> *node){
        if (node == nullptr) return 0;
        return 1 + max(heightRecursive(node->left),heightRecursive(node->right));
    }
    
    //二叉树高度遍历法
    int heightLevelOrder(){
        if (this->root == nullptr) return  0;
        //树的高度设置为0
        int height = 0;
        //存储每一层的元素数量
        int levelSize = 1;
        queue<Node<E> *> heightQueue;
        heightQueue.push(this->root);
        while (!heightQueue.empty()) {
            Node<E> *node = heightQueue.front();
            heightQueue.pop();
            levelSize--;
            if (node->left != nullptr) {
                heightQueue.push(node->left);
            }
            if (node->right != nullptr) {
                heightQueue.push(node->right);
            }
            if (levelSize == 0) {
                //意味着即将需要遍历下一层
                levelSize = (int)heightQueue.size();
                height++;
            }
        }
        return height;
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
    E nodeElement(Node<E> *node){
        return node->element;
        
    }
    
    Node<E>* createNode(E element,Node<E> *parent){
        return new Node<E>(element,parent);
    }

};

#endif /* BinaryTree_hpp */
