//
//  HashMapV0.hpp
//  BinarySearchTree
//
//  Created by songlin on 2019/12/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef HashMapV0_hpp
#define HashMapV0_hpp



#include <stdio.h>
#include "HashNode.hpp"
#include "BinarySearchTree.hpp"




template<class K,class V>

class HashMapV0{
public:
    int size;
   
     typedef bool(*Visitor)(K,V);
    static const int DEFAULT_LOAD_CAPACITY = 1 << 4;
    constexpr static const float DEFAULT_LOAD_FACTOR = 0.75f;
    //TODO wait for fix
    HashNode<K, V>** table;
    HashMapV0(){
        table = new HashNode<K, V> *[DEFAULT_LOAD_CAPACITY]{};
    }

   
    
    int fetchSize(){
        return size;
    }
    
    int fetchTableLength(){
        int len = sizeof(**table) / sizeof(table[0]);
        return len;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    
     void clear(){
        if (size == 0) return; //防止size等于0的时候还需要q循环清空table
        size = 0;
        int len = sizeof(table) / sizeof(table[0]);
//        cout << "哈希数组的长度:" << len << endl;
        for (int i = 0; i < len; i++) {
            table[i] = nullptr;
        }
    }
    virtual HashNode<K, V> * createNode(K key,V value,HashNode<K, V> *parent){
        return new HashNode<K, V>(key,value,parent);
    }
    
    V put(K key,V value){
        resize();
        int indexPath = fetchindex(key);
        //取出index位置的红黑树根节点
        HashNode<K,V> *root = table[indexPath];
        if (root == nullptr) {
            root = createNode(key,value,nullptr);
            table[indexPath] = root;
            size++;
            fixAfterPut(root);
            return 0;
        }
        
        //添加新的节点到红黑树上面
        HashNode<K,V> *parent = root;
        HashNode<K,V> *node =  root;
        int cmp = 0;
        K k1 = key;
        int h1 = 0;
        if (hash(k1) != 0) {
            h1 = hash(k1);
        }
        HashNode<K,V> *result = nullptr;
        bool searched = false;//是否已经搜过这个key
       do {
//           cout << "类名:" << typeid(k1).name() << endl;
           parent = node;
           K k2 = node->key;
           int h2 = node->hash;
           if (h1 > h2) {
               cmp = 1;
           }else if(h1 < h2){
               cmp = -1;
           }else if (k1 == k2){
               cmp = 0;
           }else if(typeid(k1).name() == typeid(k2).name() && k1.identifier == "test" && k2.identifier == "test" && k1 == k2){
               cout << "k1 k2 name 相同" << endl;
            }
           else if(searched){
               //内存地址对比
               //todo
               cmp = int(&k1 - &k2);
           }else{
               // searched == false; 还没有扫描，然后再根据内存地址大小决定左右
               if ((node->left != nullptr && (result = fetchNodeWithK(node->left,k1)) != nullptr) || (node->right != nullptr && (result = fetchNodeWithK(node->right,k1)) != nullptr)) {
                   //已经存在这个key
                   node = result;
                   cmp = 0;
               }else {
                   //不存在这个key
                   searched = true;
                   //内存地址对比
                   //todo
                   cmp = int(&k1 - &k2);
               }
           }
            if (cmp > 0) {
                node = node->right;
            } else if (cmp < 0) {
                node = node->left;
            } else { // 哈希值相等之后，找到对应的key相等
                V oldValue = node->value;
                node->key = key;
                node->value = value;
                node->hash = h1;
                return oldValue;
            }
        } while (node != nullptr);
                   
           // 看看插入到父节点的哪个位置
           HashNode<K, V> *newNode = createNode(key,value,parent);
           if (cmp > 0) {
               parent->right = newNode;
           } else {
               parent->left = newNode;
           }
           size++;
           
           // 新添加节点之后的处理
           fixAfterPut(newNode);
           return 0;
        
    }
    
    
    V get(K key){
        HashNode<K, V> *node = fetchNode(key);
        if (node != nullptr) {
            return node->value;
        }
        return 0;
        
    }
    
    V remove(K key){
        return remove(fetchNode(key));
    }
    
    V remove(HashNode<K, V> *node){
        if (node == nullptr) return 0;
        HashNode<K, V> *willNode = node;
        size--;
        V oldValue = node->value;
        
        if (node->hasTwoChildren()) {//度为2的节点
            //找到后继节点
            HashNode<K, V> *s = successor(node);
            //用后继节点的值覆盖度为2的节点的值
            node->key = s->key;
            node->value = s->value;
            node->hash = s->hash;
            //删除后继节点
            node = s;
        }
        //删除node节点(node 的度必然是1或者0)
        HashNode<K, V> *replacement = node->left != nullptr ? node->left : node->right;
        int indexPath = index(node);
        if (replacement != nullptr) { //node 是度为1 的节点
            //更改parent
            replacement->parent = node->parent;
            //更改parent的left，right的指向
            if (node->parent == nullptr) {//node 是度为1的节点并且是根节点
                table[indexPath] = replacement;
            }else if (node == node->parent->left){
                node->parent->left = replacement;
            }else{
                node->parent->right = replacement;
            }
            //删除节点之后的处理
            fixAfterRemove(replacement);
        }else if (node->parent == nullptr){
            //node 是叶子节点并且是根节点
            table[indexPath] = nullptr;
        }else{//node 是叶子节点但不是根节点
            if (node == node->parent->left) {
                node->parent->left = nullptr;
            }else{//node == node->parent->right
                node->parent->right = nullptr;
            }
            //删除节点之后的处理
            fixAfterRemove(node);
        }
        
        //交给子类去扩展的方法
        afterRemove(willNode,node);
        return oldValue;
    }
    
    virtual void afterRemove(HashNode<K, V>*willNode, HashNode<K, V>*removeNode){};
    
    bool containsKey(K key){
        return node(key) != nullptr;
    }
    
    bool containsValue(V value){
        if (size == 0) return false;
        queue<HashNode<K, V> *> hashQueue;
         int len = sizeof(table) / sizeof(table[0]);
        for (int i = 0; i < len; i++) {
            if (table[i] == nullptr) continue;
            hashQueue.push(table[i]);
            while (!hashQueue.empty()) {
                HashNode<K, V> *node = hashQueue.front();
                hashQueue.pop();
                if (value == node->value) return true;
                
                if (node->left != nullptr) {
                    hashQueue.push(node->left);
                }
                if (node->right != nullptr) {
                    hashQueue.push(node->right);
                }
            }
        }
    }
    void resize(){
           int len = sizeof(**table) / sizeof(table[0]);
           if (size / len <= DEFAULT_LOAD_FACTOR) return;
        HashNode<K, V>* oldTable[DEFAULT_LOAD_CAPACITY];
        for (int i = 0; i < len; i++) {
            oldTable[i] = table[i];
        }
        
          
        table =  new HashNode<K, V> *[len << 1]{};
           queue<HashNode<K, V> *> hashQueue;
           for (int i = 0; i < len; i++) {
               if (oldTable[i] == nullptr) continue;
               
               hashQueue.push(oldTable[i]);
               while (!hashQueue.empty()) {
                   HashNode<K, V> *node = hashQueue.front();
                   hashQueue.pop();
                   if (node->left != nullptr) {
                       hashQueue.push(node->left);
                   }
                   if (node->right != nullptr) {
                       hashQueue.push(node->right);
                   }
                   //挪动代码放到最后面
                   moveNode(node);
               }
           }
       }
       
       void moveNode(HashNode<K, V> *newNode){
           //重置
           newNode->parent = nullptr;
           newNode->left = nullptr;
           newNode->right = nullptr;
           newNode->color = RED;
           int indexPath = index(newNode);
           //取出index位置的红黑树根节点
           HashNode<K, V> *root = table[indexPath];
           if (root == nullptr) {
               root = newNode;
               table[indexPath] = root;
               fixAfterPut(root);
               return;
           }
           
           //添加新的节点到红黑树节点
           HashNode<K, V> *parent = root;
           HashNode<K, V> *node = root;
           int cmp = 0;
           K k1 = newNode->key;
           int h1 = newNode->hash;
           do {
               parent = node;
               K k2 = node->key;
               int h2 = node->hash;
               if (h1 > h2) {
                   cmp = 1;
               }else if (h1 < h2){
                   cmp = -1;
               }else{
                   cmp = (int)(&k1 - &k2);
               }
               
               if (cmp > 0) {
                   node = node->right;
               }else if (cmp < 0){
                   node = node->left;
               }
           } while (node != nullptr);
           
           //看看插入到父节点的哪个位置
           newNode->parent = parent;
           if (cmp > 0) {
               parent->right = newNode;
           }else{
               parent->left = newNode;
           }
           //新添加节点之后的处理
           fixAfterPut(newNode);
       }
           
    
    void traversal(Visitor visitor){
        if (size == 0 || visitor == nullptr) return;
        queue<HashNode<K, V> *>hashQueue;
         int len = sizeof(table) / sizeof(table[0]);
        for (int i = 0; i < len ; i++) {
            if (table[i] == nullptr) continue;
            
            hashQueue.push(table[i]);
            while (!hashQueue.empty()) {
                HashNode<K, V> *node = hashQueue.front();
                hashQueue.pop();
                isFinish = visitor(node->key,node->value);
                if (isFinish) return;
                if (node->left != nullptr) {
                    hashQueue.push(node->left);
                }
                if (node->right != nullptr) {
                    hashQueue.push(node->right);
                }
            }
        }
    }
    
    HashNode<K, V>* successor(HashNode<K, V> *node){
        if (node == nullptr) return nullptr;
        
        //前驱节点在左子树当中(right->left->left->left......)
        HashNode<K, V> *p = node->right;
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
    
    HashNode<K, V>* fetchNode(K key){
        HashNode<K, V> *root = table[fetchindex(key)];
        return root == nullptr ? nullptr : fetchNodeWithK(root,key);
    }
    
    
    HashNode<K, V> *fetchNodeWithK(HashNode<K, V>*node,K k1){
        int h1 = 0;
        //存储查找结果
        HashNode<K,V> *result = nullptr;
        if (hash(k1) != 0) {
            h1 = hash(k1);
        }
        int cmp = 0;
       
        while (node != nullptr) {
            K k2 = node->key;
            int h2 = node->hash;
            //先比较哈希值
            if (h1 > h2) {
                node = node->right;
            }else if(h1 < h2){
                node = node->left;
            }else if(k1 == k2){
                return node;
            }else if(typeid(k1).name() == typeid(k2).name() && k1.identifier == "test" && k2.identifier == "test" && k1 == k2){
                //todo
                node = cmp > 0 ? node->right : node->left;
                
            }else if(node->right != nullptr && (result = fetchNodeWithK(node->right,k1)) != nullptr){
                return result;
            }else{ //只能往左边找
                node = node->left;
            }
        }
        return nullptr;
                   
    }
    
    int fetchindex(K key){
        int len = sizeof(table) / sizeof(table[0]);
//        int index = hash(key) & (len - 1);
//        cout <<"index"<< index << endl;
        return hash(key) & (len - 1);
    }
    
    
    int hash(K key){
       
        int hash = Key::hashName(key);
        return int(hash ^ (hash >> 16));
    }
    
    
    int index(HashNode<K,V> *node){
        int len = sizeof(table) / sizeof(table[0]);
           return node->hash & (len - 1);
       }
       
       HashNode<K,V> * hashColor(HashNode<K,V> *node ,bool color){
           if (node == nullptr) return node;
           node->color = color;
           return node;
       }
       
       HashNode<K,V> *red(HashNode<K,V> *node){
           return hashColor(node,RED);
       }
       
       HashNode<K,V>* black(HashNode<K,V> *node){
           return hashColor(node,BLACK);
       }
       
       bool colorOf(HashNode<K,V> *node){
           return node == nullptr ? BLACK : node->color;
       }
       
       bool isBlack(HashNode<K,V> *node){
           return colorOf(node) == BLACK;
       }
       
       bool isRed(HashNode<K,V> *node){
           return colorOf(node) == RED;
       }
    
    void fixAfterRemove(HashNode<K, V> *node){
        //如果删除的节点是红色
        //或者用以取代删除节点的子节点是红色
        if (isRed(node)) {
            black(node);
            return;
        }
        
        HashNode<K, V> *parent = node->parent;
        if (parent == nullptr) return;
        
        //删除的是黑色叶子节点(下溢)
        //判断被删除的node是左还是右
        bool left = parent->left == nullptr || node->isLeftChild();
        HashNode<K, V> *sibling = left ? parent->right : parent->left;
        if (left) { //被删除的节点在左边，兄弟节点在右边
            if (isRed(sibling)) {//兄弟节点是红色
                black(sibling);
                red(parent);
                rotateLeft(parent);
                //更换兄弟
                sibling = parent->right;
            }
            
            //兄弟节点必然是黑色
            if (isBlack(sibling->left) && isBlack(sibling->right)) {
                //兄弟节点没有一个红色子节点，父节点要向下跟兄弟节点合并
                bool parentBlack = isBlack(parent);
                black(parent);
                red(sibling);
                if (parentBlack) {
                    fixAfterRemove(parent);
                }
            }else{//兄弟节点至少有一个红色子节点，向兄弟节点借元素
                //兄弟节点的左边是黑色，兄弟要先旋转
                if (isBlack(sibling->right)) {
                    rotateRight(sibling);
                    sibling = parent->right;
                }
                hashColor(sibling, colorOf(parent));
                black(sibling->right);
                black(parent);
                rotateLeft(parent);
            }
        }else{//被删除的节点在右边，兄弟节点在左边
            if (isRed(sibling)) {//兄弟节点是红色
                black(sibling);
                red(parent);
                rotateRight(parent);
                //更换兄弟
                sibling = parent->left;
            }
            
            //让兄弟节点必然是黑色
            if (isBlack(sibling->left) && isBlack(sibling->right)) {
                //兄弟节点没有1个红色子节点，父节点要向下跟兄弟节点合并
                bool parentBlack = isBlack(parent);
                black(parent);
                red(sibling);
                if (parentBlack) {
                    fixAfterRemove(parent);
                }
            }else{//兄弟节点至少有一个红色子节点，向兄弟节点借元素
                //兄弟节点的左边是黑色，兄弟要先旋转
                if (isBlack(sibling->left)) {
                    rotateLeft(sibling);
                    sibling = parent->left;
                }
                hashColor(sibling, colorOf(parent));
                black(sibling->left);
                black(parent);
                rotateRight(parent);
            }
            
        }
    }
    
    void afterRotate(HashNode<K,V> *grand,HashNode<K,V>*parent,HashNode<K,V>*child){
        //让parent称为子树的根节点
        parent->parent = grand->parent;
        if(grand->isLeftChild()){
            grand->parent->left = parent;
        }else if (grand->isRightChild()){
            grand->parent->right = parent;
        }else{//grand 是root节点
            table[index(grand)] = parent;
        }
        //更新child的parent
        if (child != nullptr) {
            child->parent = grand;
        }
        
        //更新grand的parent
        grand->parent = parent;
    }
    
    void rotateRight(HashNode<K,V> *grand){
        HashNode<K,V> *parent = grand->left;
        HashNode<K, V> *child = parent->right;
        grand->left = child;
        parent->right = grand;
        afterRotate(grand, parent, child);
    }
    
    void rotateLeft(HashNode<K,V> *grand){
        HashNode<K,V> *parent = grand->right;
        HashNode<K,V> *child = parent->left;
        grand->right = child;
        parent->left = grand;
        afterRotate(grand, parent, child);
    }
    
    void fixAfterPut(HashNode<K,V>*node){
        HashNode<K,V> *parent = node->parent;
        //添加的是根节点或者上溢到达了根节点
        if (parent == nullptr) {
            black(node);
            return;
        }
        //如果父节点是黑色，直接返回
        if (isBlack(parent)) return;
        
        //叔父节点
        HashNode<K,V> *uncle = parent->sibling();
        //祖父节点
        HashNode<K,V> *grand = red(parent->parent);
        
        if (isRed(uncle)) { //叔父节点是红色(B树节点上溢)
            black(parent);
            black(uncle);
            //把父节点当做是新添加的节点
            fixAfterPut(grand);
            return;
        }
        //叔父节点不是红色
        if (parent->isLeftChild()) {//L
            if (node->isLeftChild()){//LL
                black(parent);
            }else{//LR
                black(node);
                rotateRight(grand);
            }
        }else{//R
            if (node->isLeftChild()) {//RL
                black(node);
                rotateRight(parent);
            }else{//RR
                black(parent);
            }
            rotateLeft(grand);
        }
    }
};

#endif /* HashMapV0_hpp */
