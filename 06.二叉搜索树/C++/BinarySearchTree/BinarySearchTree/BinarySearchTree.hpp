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
#include <queue>

using namespace std;


static bool isFinish = false;

template<class E>
class BinarySearchTree {
    typedef int(*CompareElement)(int,int);
    typedef bool(*Visitor)(string);
public:
   
    int m_size;
    Node<E> *root;
    
//    int compare_element(CompareElement);
    //函数指针
    CompareElement compareBlock;
    Visitor visitor;
    
    BinarySearchTree<E>(){
        BinarySearchTree(NULL);
    }
    BinarySearchTree<E>(CompareElement compare){
        this->compareBlock = compare;
        root = nullptr;
        isFinish = false;
    }
    //前序遍历
     void preorder(Visitor visitor){
        preorder(root, visitor);
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
        inorder(root, visitor);
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
        postorder(root,visitor);
    }
    
    void postorder(Node<E> *node,Visitor visitor){
        if (node == nullptr || isFinish) return;
        postorder(node->left, visitor);
        postorder(node->right,visitor);
        if (isFinish) return;
        isFinish = visitor(node->element);
    }
    
    void levelorder(Visitor visitor){
        if (root == nullptr || visitor == nullptr) return;
        queue<Node<E> *> levelQueue;
        levelQueue.push(root);
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
    
    //判断是否是完全二叉树
    bool isCompleteTree(){
        if (root == nullptr) return false;
        queue<Node<E> *> completeQueue;
        completeQueue.push(rootNode());
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
        return heightRecursive(root);
    }
    
    int heightRecursive(Node<E> *node){
        if (node == nullptr) return 0;
        return 1 + max(heightRecursive(node->left),heightRecursive(node->right));
    }
    
    //二叉树高度遍历法
    int heightLevelOrder(){
        if (root == nullptr) return  0;
        //树的高度设置为0
        int height = 0;
        //存储每一层的元素数量
        int levelSize = 1;
        queue<Node<E> *> heightQueue;
        heightQueue.push(root);
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
    
    //添加
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
    
    Node<E> * fetchNode(E element){
        Node<E> *node = root;
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
        m_size--;
        //这里需要考虑三种情况：度为2的节点，度为1的节点，度为0的节点，为了精简代码，先从度为2的开始，其实就算是删除度为2的节点，最后也就变成为删除度为1或者度为0的元素，因为度为2的删除仅仅是用后继节点的值来覆盖要删除的几点，最后要删掉的是后继节点的值（注意：后继节点变成前继节点也成立）
        if (node->hasTwoChildren()) {
             Node<E> *s = successor(node);
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
                root = replacement;
            }else if (node == node->parent->left){
                node->parent->left = replacement;
            }else{//node == node->parent->right
                node->parent->right = replacement;
            }
        }else if (node->parent == nullptr){//node 是z叶子节点并且是根节点
            root = nullptr;
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




#endif /* BinarySearchTree_hpp */
