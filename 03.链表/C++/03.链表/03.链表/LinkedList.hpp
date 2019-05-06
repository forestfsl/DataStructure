//
//  LinkedList.hpp
//  03.链表
//
//  Created by fengsl on 2019/4/21.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

static const int ELEMENT_NOT_FOUND = -1;

template <class E>
class LinkedList {
     class Node {
     public:
         E element;
         Node *next;
         
         Node():Node(NULL,NULL){
             
         }
         Node(E element,Node *node):element(element),next(node){
             
         }
         ~Node();
     };
    
public:
    int m_size = 0;
    int m_capacity = 0;
    
    Node *first;
    LinkedList();
    ~LinkedList();
    
    /**
     *销毁链表元素的引用
     */
    //采用Lamba的表达式
    void clear_element(void (*clearFunc)(E));
    /**
     * 清除所有元素
     */
    void clear();
    
    /**
     * 打印元素
     */
    void toString();
    
    /**
     * 获取元素
     */
   
    E get(int index);
    
    /**
     * 设置元素
     */
    E set(int index,E element);
    
    /**
     * 添加元素
     */
    void add(int index,E element);
    
    /**
     * 添加元素到尾部
     */
    void add(E element);
    
    /**
     *移除元素
     */
   
    E remove(int index);
    
    /**
     * 索引
     */
    int indexOf(E element);
    
    Node* fetchNode(int index){
        rangeCheck(index);
        Node *node = first;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }
    
    void rangeCheck(int index){
        if (index < 0 || index >= m_size) {
            outOfBounds(index);
        }
    }
    
    void outOfBounds(int index){
        throw "IndexOutOfBoundsException";
    }
};

template <class E>
LinkedList<E>::LinkedList(){
    cout<<"LinkedList<E>" << endl;
}
template <class E>
LinkedList<E>::~LinkedList(){
    cout<<"~LinkedList<E>" << endl;
}

template <class E>
E LinkedList<E>::get(int index){
    return fetchNode(index)->element;
}

template <class E>
void LinkedList<E>::add(int index, E element){
    if (index == 0) {
        first = new Node(element,first);
    }else{
        Node *prevNode = fetchNode(index - 1);
        prevNode->next = new Node(element,prevNode->next);
    }
    m_size++;
}

template <class E>
E LinkedList<E>::remove(int index){
    Node *node = first;
    if (index == 0) {
        first = first->next;
    }else{
        Node* prevNode = fetchNode(index - 1);
        node = prevNode->next;
        prevNode->next = node->next;
    }
    m_size--;
    return node->element;
}

template <class E>
E LinkedList<E>::set(int index, E element){
    Node *node = fetchNode(index);
    E old = node->element;
    node->element = element;
    return old;
}

template <class E>
void LinkedList<E>::clear_element(void (*clearFunc)(E)){
    if(m_size == 0) return;
    while (m_size > 0) {
        //获取元素提取数据
        E old = remove(m_size - 1);
        if (clearFunc != NULL) {
            (*clearFunc)(old);
        }
    }
}

template <class E>
void LinkedList<E>::clear(){
    m_size = 0;
    first = NULL;
}
template <class E>
int LinkedList<E>::indexOf(E element){
    if (element == NULL) {
        Node *node = first;
        for (int i = 0; i < m_size; i++) {
            if (node->element == NULL) return i;
            node = node->next;
        }
    }else{
        Node *node = first;
        for (int i = 0; i < m_size; i++) {
            if(element == node->element) return i;
            node = node->next;
        }
    }
    return ELEMENT_NOT_FOUND;
}

template <class E>
void LinkedList<E>::add(E element){
    add(m_size, element);
}

template <class E>
void LinkedList<E>::toString(){
    cout << "[";
    for (int i = 0; i < m_size; i++) {
        if (i != 0) {
            cout << ",";
        }
        E element = get(i);
        cout << element;
    }
    cout << " ]" << endl;
}

#endif /* LinkedList_hpp */
