//
//  SkipList.hpp
//  25.SkipList
//
//  Created by fengsl on 2020/2/3.
//  Copyright © 2020 NeonChange. All rights reserved.
//

#ifndef SkipList_hpp
#define SkipList_hpp

#include <stdio.h>
using namespace std;
#include "SkipListNode.hpp"

/*
 跳表(SkipList)
 跳表：又叫做跳跃表，跳跃列表，在有序链表的基础上增加了跳跃的功能
 Redis中的SortedSet，LevelDB中的MemTable都用到了跳表
 对比平衡树，跳表的实现和维护会更加简单，跳表的搜索、删除、添加的平均时间复杂度是O(logn)
 
 跳表的搜索
 - 从顶层链表的首元素开始，从左往右搜索，直至找到一个大于或等于目标的元素，或者到达当前链表的尾部
 - 如果该元素等于目标元素，则表明该元素已经被找到了
 - 如果该元素大于目标元素或已达到链表的尾部，则退回到当前层的一个元素，然后转入下一层进行搜索
 
 添加的细节
 - 随机决定新添加元素的层数
 
 删除的细节
 - 删除一个元素后，整个跳表的层数可能会降低
 
 跳表的层数
 - 跳表是按层构造的，底层是一个普通的有序链表，高层相当于是底层的快速通道
 - 在第i层中的元素按某个固定的概率p（通常为1/2,或者1/4）出现在第i+1层中，产生越高的层数，概率越低
    - 元素层数恰好等于1的概率为1-p
    - 元素层数大于等于2的概率为p，而元素层数恰好等于2的概率为p*(1-p)
    - 元素层数大于等于3的概率为p^2,而元素层数恰好等于3的概率为p^2*(1-p)
    - 元素层数大于等于4的概率为p^3,而元素层数恰好等于4的概率为p^3*(1-p);
    - 一个元素的平均层数是1/(1-p)
 
 跳表的复杂度分析
 - 每一层的元素数量是
    - 第1层链表固定有n个元素
    - 第2层链表平均有n*p个元素
    - 第3层链表平均有n*p^2个元素
    - 第k层链表平均有n*p^k个元素
 */

template <class K,class V>

class SkipList{
public:
    int MAX_LEVEL = 32;
    double P = 0.25;
    int size;
    /*
     有效层数
     */
    int level;
    /*
     不存放任何K-V
     */
    SkipListNode<K, V> *first;
    SkipList(){
        first = new SkipListNode<K, V>(0,0,MAX_LEVEL);
    }
    
    int fetchSize(){
        return size;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    
    void keyCheck(K key){
        if (key < 0) {
            throw "key must not be less than zero";
        }
    }
    int compare(K k1,K k2){
        return k1 - k2;
    }
    int randomLevel(){
        int level = 1;
        while (rand() < P && level < MAX_LEVEL) {
            level++;
        }
        return level;
    }
    V put(K key,V value){
        keyCheck(key);
        SkipListNode<K, V> *node = first;
        SkipListNode<K, V> **prevs = new SkipListNode<K, V>*[level];
        for (int i = level - 1; i >= 0; i--) {
            int cmp = -1;
            while (node->nexts[i] != nullptr && (cmp = compare(key, node->nexts[i]->key)) > 0) {
                node = node->nexts[i];
            }
            if (cmp == 0) {//节点是存在的
                V oldV = node->nexts[i]->value;
                node->nexts[i]->value = value;
                return oldV;
            }
            prevs[i] = node;
        }
        //新节点的层数
        int newLevel = randomLevel();
        //添加新节点
        SkipListNode<K, V> *newNode = new SkipListNode<K, V>(key,value,newLevel);
        //设置前驱和后继
        for (int i = 0; i < newLevel; i++) {
            if (i >= level) {
                first->nexts[i] = newNode;
            }else{
                newNode->nexts[i] = prevs[i]->nexts[i];
                prevs[i]->nexts[i] = newNode;
            }
        }
        //节点数量增加
        size++;
        //计算跳表的最终层数
        level = max(level,newLevel);
        return -1;
    }
    
    V remove(K key){
        keyCheck(key);
        SkipListNode<K, V> *node = first;
        SkipListNode<K, V> *prevs = new SkipListNode<K, V>(level);
        bool exist = false;
        for (int i = level - 1; i >= 0; i--) {
            int cmp = -1;
            while (node->nexts[i] != nullptr && (cmp = compare(key, node->nexts[i]->key)) > 0) {
                node = node->nexts[i];
            }
            prevs[i] = node;
            if (cmp == 0) exist = true;
        }
        if (!exist) return nullptr;
        
        //需要被删除的节点
        SkipListNode<K, V> *removeNode = node->nexts[0];
        size--;
        int len = sizeof(removeNode->nexts) / sizeof(removeNode->nexts[0]);
        //设置后继
        for (int i = 0; i < len ; i++) {
            prevs[i]->nexts[i] = removeNode->nexts[i];
        }
        //更新跳表的层数
        int newLevel = level;//假设level = 6，但是层数是从0开始，所以一开始需要--newLevel,first->nexts[level] == nullptr是判断最高层元素是否为空，如果为空需要继续执行while
        while (--newLevel >= 0 && first->nexts[level] == nullptr) {
            level = newLevel;
        }
        return removeNode->value;
    }
    
};

#endif /* SkipList_hpp */
