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
#include <stack>

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
    
    void preorder1(Visitor visitor){
        if (visitor == nullptr || root == nullptr) return;
        stack<Node<E>*> *prestack = new stack<Node<E>*>();
        prestack->push(root);
        while (!prestack->empty()) {
            Node<E> *node = prestack->top();
            prestack->pop();
            //访问node节点
            visitor(node->element);
            if(node->right != nullptr){
                prestack->push(node->right);
            }
            if(node->left != nullptr){
                prestack->push(node->left);
            }
        }
    }
    
    void preorder2(Visitor visitor){
        if (visitor == nullptr || root == nullptr) return;
        stack<Node<E>*> *prestack = new stack<Node<E>*>();
        Node<E> *node = root;
        while (true) {
            if (node != nullptr) {
                //访问node节点
                visitor(node->element);
                //将右子节点入栈
                if (node->right != nullptr) {
                    prestack->push(node->right);
                }
                //向左走
                node = node->left;
            }else if (prestack->empty()){
                return;
            }else{
                //处理右边
                node = prestack->top();
                prestack->pop();
            }
        }
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
    
    void inorder1(Visitor visitor){
         if (this->root == nullptr || visitor == nullptr) return;
        Node<E> *node = root;
         stack<Node<E>*> *instack = new stack<Node<E>*>();
        while (true) {
            if (node != nullptr) {
                instack->push(node);
                //向左走
                node = node->left;
            }else if (instack->empty()){
                return;
            }else{
                node = instack->top();
                instack->pop();
                //访问node节点
                visitor(node->element);
                //让右节点进行中序遍历
                node = node->right;
            }
        }
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
    
    
    void postorder1(Visitor visitor){
         if (this->root == nullptr || visitor == nullptr) return;
       //记录上一次弹出访问的节点
        Node<E> *prev = nullptr;
        stack<Node<E>*> *poststack = new stack<Node<E>*>();
        poststack->push(root);
        while (!poststack->empty()) {
            Node<E> *top = poststack->top();
            if (top->isLeaf() || (prev != nullptr && prev->parent == top)) {
                prev = poststack->top();;
                poststack->pop();
                //访问节点
                visitor(prev->element);
            }else{
                if (top->right != nullptr){
                    poststack->push(top->right);
                }
                if (top->left != nullptr) {
                    poststack->push(top->left);
                }
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
    

};

#endif /* BinaryTree_hpp */
