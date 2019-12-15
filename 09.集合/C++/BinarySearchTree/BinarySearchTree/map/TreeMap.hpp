//
//  TreeMap.hpp
//  BinarySearchTree
//
//  Created by fengsl on 2019/12/15.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef TreeMap_hpp
#define TreeMap_hpp

#include <stdio.h>

static bool isFinishVisitor = false;


template <class K,class V>
class TreeMap {
public:
     typedef int(*CompareElement)(K,V);
    //函数指针
       CompareElement compareBlock;
    typedef bool(*Visitor)(K,V);
    const static  bool RED = false;
      const static bool BLACK = true;
      int size;
    
    TreeMap(){
        TreeMap(nullptr);
    }
    
    TreeMap(CompareElement comparator){
        this->compareBlock = comparator;
    }
    
     class TreeMapNode{
        K key;
        V value;
        bool color = RED;
        TreeMapNode *left;
        TreeMapNode *right;
        TreeMapNode *parent;
        TreeMapNode(K key,V value,TreeMapNode *parent){
            this->key = key;
            this->value = value;
            this->parent = parent;
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
         TreeMapNode* sibling(){
             if (this->isLeftChild) {
                 return parent->right;
             }
             if (this->isRightChild()) {
                 return parent->left;
             }
             
             return nullptr;
         }
    };
    TreeMapNode *root;
    
    int fetchSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void clear(){
        root = nullptr;
        size = 0;
    }
    
    V put(K key, V value){
        keyNotNullCheck(key);
        //添加第一个节点
        if (root == nullptr) {
            root = new TreeMapNode(key,value,nullptr);
            size++;
            //新添加节点之后的处理
            afterPut(root);
            return  nullptr;
        }
        
        //添加的不是第一个节点
        //找到父节点
        TreeMapNode *parent = root;
        TreeMapNode *node = root;
        int cmp = 0;
        do {
            cmp = compare(key, node->key);
            parent = node;
            if (cmp > 0) {
                node = node->right;
            }else if (cmp < 0){
                node = node->left;
            }else{
                //相等
                node->key = key;
                V oldValue = node->value;
                node->value = value;
                return oldValue;
            }
        } while (node != nullptr);
        // 看看插入到父节点的哪个位置
        TreeMapNode *newNode = new TreeMapNode(key, value, parent);
        if (cmp > 0) {
            parent->right = newNode;
        } else {
            parent->left = newNode;
        }
        size++;
        
        // 新添加节点之后的处理
        afterPut(newNode);
        return nullptr;
    }
    
    //获取value
    V get(K key){
        TreeMapNode *node = node(key);
        return node != nullptr ? node->value : nullptr;
    }
    
    V remove(K key){
        return remove(node(key));
    }
    
    bool containsKey(K key){
        return node(key) != nullptr;
    }
    
    bool containsValue(V value){
        if (root == nullptr) return false;
        queue<TreeMapNode *> queue;
        queue.push(root);
        while (!queue.size()) {
            TreeMapNode *node = queue.front();
            queue.pop();
            if(valEquals(value,node->value)) return true;
            
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
    }
    
     void traversal1(Visitor visitor) {
        if (visitor == nullptr) return;
        traversal(root, visitor);
    }

     void traversal(TreeMapNode * node, Visitor visitor) {
        if (node == nullptr || isFinishVisitor) return;

        traversal(node->left, visitor);
        if (isFinishVisitor) return;
        visitor(node->key, node->value);
        traversal(node->right, visitor);
    }

    
     bool valEquals(V v1, V v2) {
         return v1 == nullptr ? v2 == nullptr : v1.equals(v2);
    }
    
     V remove(TreeMapNode * node) {
        if (node == nullptr) return nullptr;
        
        size--;
        
        V oldValue = node->value;
        
        if (node->hasTwoChildren()) { // 度为2的节点
            // 找到后继节点
           TreeMapNode *s = successor(node);
            // 用后继节点的值覆盖度为2的节点的值
            node->key = s->key;
            node->value = s->value;
            // 删除后继节点
            node = s;
        }
        
        // 删除node节点（node的度必然是1或者0）
        TreeMapNode * replacement = node->left != nullptr ? node->left : node->right;
        
        if (replacement != nullptr) { // node是度为1的节点
            // 更改parent
            replacement->parent = node->parent;
            // 更改parent的left、right的指向
            if (node->parent == nullptr) { // node是度为1的节点并且是根节点
                root = replacement;
            } else if (node == node->parent->left) {
                node->parent->left = replacement;
            } else { // node == node.parent.right
                node->parent->right = replacement;
            }
            
            // 删除节点之后的处理
            afterRemove(replacement);
        } else if (node->parent == nullptr) { // node是叶子节点并且是根节点
            root = nullptr;
        } else { // node是叶子节点，但不是根节点
            if (node == node->parent->left) {
                node->parent->left = nullptr;
            } else { // node == node.parent.right
                node->parent->right = nullptr;
            }
            
            // 删除节点之后的处理
            afterRemove(node);
        }
        
        return oldValue;
    }
    
     void afterRemove(TreeMapNode* node) {
        // 如果删除的节点是红色
        // 或者 用以取代删除节点的子节点是红色
        if (isRed(node)) {
            black(node);
            return;
        }
        
          TreeMapNode* parent = node->parent;
        if (parent == nullptr) return;
        
        // 删除的是黑色叶子节点【下溢】
        // 判断被删除的node是左还是右
        bool left = parent->left == nullptr || node->isLeftChild();
          TreeMapNode* sibling = left ? parent->right : parent->left;
        if (left) { // 被删除的节点在左边，兄弟节点在右边
            if (isRed(sibling)) { // 兄弟节点是红色
                black(sibling);
                red(parent);
                rotateLeft(parent);
                // 更换兄弟
                sibling = parent->right;
            }
            
            // 兄弟节点必然是黑色
            if (isBlack(sibling->left) && isBlack(sibling->right)) {
                // 兄弟节点没有1个红色子节点，父节点要向下跟兄弟节点合并
                bool parentBlack = isBlack(parent);
                black(parent);
                red(sibling);
                if (parentBlack) {
                    afterRemove(parent);
                }
            } else { // 兄弟节点至少有1个红色子节点，向兄弟节点借元素
                // 兄弟节点的左边是黑色，兄弟要先旋转
                if (isBlack(sibling->right)) {
                    rotateRight(sibling);
                    sibling = parent->right;
                }
                
                color(sibling, colorOf(parent));
                black(sibling->right);
                black(parent);
                rotateLeft(parent);
            }
        } else { // 被删除的节点在右边，兄弟节点在左边
            if (isRed(sibling)) { // 兄弟节点是红色
                black(sibling);
                red(parent);
                rotateRight(parent);
                // 更换兄弟
                sibling = parent->left;
            }
            
            // 兄弟节点必然是黑色
            if (isBlack(sibling->left) && isBlack(sibling->right)) {
                // 兄弟节点没有1个红色子节点，父节点要向下跟兄弟节点合并
                bool parentBlack = isBlack(parent);
                black(parent);
                red(sibling);
                if (parentBlack) {
                    afterRemove(parent);
                }
            } else { // 兄弟节点至少有1个红色子节点，向兄弟节点借元素
                // 兄弟节点的左边是黑色，兄弟要先旋转
                if (isBlack(sibling->left)) {
                    rotateLeft(sibling);
                    sibling = parent->left;
                }
                
                color(sibling, colorOf(parent));
                black(sibling->left);
                black(parent);
                rotateRight(parent);
            }
        }
    }
    
   TreeMapNode* predecessor(TreeMapNode* node) {
           if (node == nullptr) return nullptr;
           
           // 前驱节点在左子树当中（left.right.right.right....）
           TreeMapNode* p = node->left;
           if (p != nullptr) {
               while (p->right != nullptr) {
                   p = p->right;
               }
               return p;
           }
           
           // 从父节点、祖父节点中寻找前驱节点
           while (node->parent != nullptr && node == node->parent->left) {
               node = node->parent;
           }

           // node.parent == null
           // node == node.parent.right
           return node->parent;
       }
    
    TreeMapNode* successor(TreeMapNode* node) {
        if (node == nullptr) return nullptr;
        
        // 前驱节点在左子树当中（right.left.left.left....）
        TreeMapNode* p = node->right;
        if (p != nullptr) {
            while (p->left != nullptr) {
                p = p->left;
            }
            return p;
        }
        
        // 从父节点、祖父节点中寻找前驱节点
        while (node->parent != nullptr && node == node->parent->right) {
            node = node->parent;
        }

        return node->parent;
    }
    
    TreeMapNode *node(K key){
        TreeMapNode *node = root;
        while (node != nullptr) {
            int cmp = compare(key, node->key);
            if (cmp == 0) return node;
            if (cmp > 0) {
                node = node->right;
            }else{//cmp < 0
                node = node->left;
            }
        }
        return nullptr;
    }
    
    void afterPut(TreeMapNode *node){
        TreeMapNode *parent = node->parent;
        //添加的是根节点，或者上溢到达了根节点
        if (parent == nullptr) {
            black(node);
            return;
        }
        //如果父节点是黑色，直接返回
        if (isBlack(parent)) return;
        
        //叔父节点
        TreeMapNode *uncle = parent->sibling();
        //祖父节点
        TreeMapNode *grand = red(parent->parent);
        if (isRed(uncle)) {// 叔父节点是红色【B树节点上溢】
            black(parent);
            black(uncle);
            // 把祖父节点当做是新添加的节点
            afterPut(grand);
        }
        // 叔父节点不是红色
        if (parent->isLeftChild()) { // L
            if (node->isLeftChild()) { // LL
                black(parent);
            } else { // LR
                black(node);
                rotateLeft(parent);
            }
            rotateRight(grand);
        } else { // R
            if (node->isLeftChild()) { // RL
                black(node);
                rotateRight(parent);
            } else { // RR
                black(parent);
            }
            rotateLeft(grand);
        }
    }
    
    void rotateLeft(TreeMapNode *grand){
        TreeMapNode *parent = grand->right;
        TreeMapNode *child = parent->left;
        grand->right = child;
        parent->left = grand;
        afterRotate(grand, parent, child);
    }
    
    void rotateRight(TreeMapNode *grand){
        TreeMapNode *parent = grand->left;
        TreeMapNode *child = parent->right;
        grand->left = child;
        parent->right = grand;
        afterRotate(grand, parent, child);
    }
    
    void afterRotate(TreeMapNode *grand,TreeMapNode *parent,TreeMapNode *child){
        parent->parent = grand->parent;
        if (grand->isLeftChild()) {
            grand->parent->left = parent;
        }else if (grand->isRightChild()){
            grand->parent->right = parent;
        }else{//grand 是root节点
            this->root = parent;
        }
        //更新child 的parent
        if (child == nullptr) {
            child->parent = grand;
        }
        //更新grand的parent
        grand->parent = parent;
    }
  
    TreeMapNode * color(TreeMapNode *node,bool color){
        if (node == nullptr) return node;
        node->color = color;
        return node;
    }
    
    TreeMapNode * red(TreeMapNode *node){
        return color(node, RED);
    }
    TreeMapNode * black(TreeMapNode *node){
        return color(node, BLACK);
    }
    bool colorOf(TreeMapNode *node){
        return node == nullptr ? BLACK : node->color;
    }
    
    bool isBlack(TreeMapNode *node){
        return colorOf(node) == BLACK;
    }
    
    bool isRed(TreeMapNode *node){
        return colorOf(node) = RED;
    }
    
    void keyNotNullCheck(K key){
        if (key == nullptr) {
            cout << "key must not be null" << endl;
        }
    }
    
    int compare(K e1,K e2){
        if (compareBlock != nullptr) {
            compareBlock(e1, e2);
        }
        return e1 - e2;
    }
    
};

#endif /* TreeMap_hpp */
