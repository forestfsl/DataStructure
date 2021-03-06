
//
//  LinkedList2.cpp
//  03.链表
//
//  Created by fengsl on 2019/11/2.
//  Copyright © 2019 songlin. All rights reserved.
//


/**
 * 双向链表
 *
 */

#include <stdio.h>
#include <mm_malloc.h>
#include <iostream>
using namespace std;

static const int ELEMENT_NOT_FOUND2 = -1;

template <class E>
class LinkedList2 {
  
    class Node{
    public:
        E element;
        Node *prev;
        Node *next;
        
        
        Node(){
            element = NULL;
            prev = NULL;
            next = NULL;
             cout << "调动Node构造方法" << endl;
        }
        ~Node();

        Node(Node *prev,E element, Node *next):prev(prev),element(element),next(next){
            cout << "调动Node构造方法" << endl;
        }
     
    };
    
public:
    int size = 0;
    /**
     * 打印元素
     */
    void toString();
    Node *first;//指向第一个元素
    Node *last;//指向最后一个元素
    void clear();//清除元素
    void clearElement(void (*clearFunction)(E));
    LinkedList2();
    ~LinkedList2();
    E get(int index);
    E set(int index,E element);
    E remove(int index);
    void add(int index,E element);
    void add(E element);
    int indexOf(E element);
    
    Node * fetchNode(int index){
        rangeCheck(index);
        if (index < (size >> 1)) {
            Node *node = first;

            for (int i = 0; i < index; i++) {
                node = node->next;
            }
            return node;
        }else{
            Node *node = last;
            for (int i = size - 1; i > index; i--) {
                node = node->prev;
            }
               return node;
        }
     
    }
    
    void rangeCheck(int index){
        if (index <0 || index >= size) {
            outOfBounds(index);
        }
    }
    void rangeCheckForAdd(int index){
        if (index <0 || index > size) {
            outOfBounds(index);
        }
    }
    void outOfBounds(int index){
        throw "IndexOutOfBoundsException";
    }

};

template <class E>
void LinkedList2<E>::toString(){
    cout << "[";
    Node *node = first;
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            cout << ",";
        }
       
        cout << node->element;
        node = node->next;
    }
    cout << " ]" << endl;
}


template <class E>
int LinkedList2<E>::indexOf(E element){
    if (element == NULL) {
        Node *node = first;
        for (int i = 0; i < size; i++) {
            if (node->element == NULL) {
                return i;
            }
            node = node->next;
        }
    }else{
        Node *node = first;
        for (int i = 0; i < size; i++) {
            if (node->element == element) {
                return i;
            }
            node = node->next;
        }
    }
    return ELEMENT_NOT_FOUND;
}

template <class E>
E LinkedList2<E>:: set(int index,E element){
    Node *oldNode = fetchNode(index);
    E oldElement = oldNode->element;
    oldNode->element = element;
    return oldElement;
}

template <class E>
E LinkedList2<E>::get(int index){
    Node *current = fetchNode(index);
    return current->element;
}

template <class E>
E LinkedList2<E>::remove(int index){
    rangeCheck(index);
    Node *deleteNode = fetchNode(index);
    Node *prevNode = deleteNode->prev;
    Node *lastNode = deleteNode->next;
    if (index == 0) {
        //删除的是索引为0的节点
        first = lastNode;
    }else{
        prevNode->next = lastNode;
    }
    if (index == size - 1) {
        //删除的是最后一个节点
        last = prevNode;
    }else{
        lastNode->prev = prevNode;
    }
    size--;
    
    return deleteNode->element;
}

template <class E>
LinkedList2<E>::LinkedList2(){
    cout<<"LinkedLis2t<E>" << endl;

}

template <class E>
void LinkedList2<E>::clear(){
    size = 0;
    first = NULL;
    last = NULL;
}

template <class E>
void LinkedList2<E>::clearElement(void (*clearFunction)(E)){
    if (size == 0) return;
    while (size > 0) {
        E element = remove(size - 1);
        if (clearFunction != NULL) {
            clearFunction(element);
        }
    }
}

template <class E>
LinkedList2<E>::~LinkedList2(){
    cout<<"~LinkedList2<E>" << endl;
    
}
template <class E>
void LinkedList2<E>::add(E element){
    add(size,element);
}

template <class E>
void LinkedList2<E>::add(int index,E element){
    rangeCheckForAdd(index);


    //往最后一个索引添加元素
    if (index == size) {
        Node *oldLast = last;
        //构造新节点
        last = new Node(oldLast,element,NULL);
        if (index == 0) { //index == size == 0,往0元素插入元素,说明是第一个插入的元素
            first = last;
        }else{
            oldLast->next = last;
        }
    }else{
        //进入else，说明链表中已经有元素了
        Node *next = fetchNode(index);//往index添加元素，那么之前占用index的就成为next
        Node *prev = next->prev;//往index添加元素,那么index前的元素prev就会成功新元素的prev
        Node *current = new Node(prev,element,next);
        next->prev = current;
        if (index == 0) {
            //往元素为0的索引添加元素
            first = current;
        }else{
            prev->next = current;
        }
    }
    size++;
}
