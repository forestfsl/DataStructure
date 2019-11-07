//
//  SingleCircleLinkedList.hpp
//  03.链表
//
//  Created by songlin on 2019/11/4.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef SingleCircleLinkedList_hpp
#define SingleCircleLinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <class E>
class SingleCircleLinkedList {
    class Node {
    public:
        E element;
        Node *next;
        Node(E element,Node *next):element(element),next(next){
            
        }
        ~Node(){
            cout << "Node 销毁了" << endl;
        }
    };
public:
    void toString();
    int size;
    Node *first;
    void clearElement(void(*clearFunction)(E));
    void clear();
    E set(int index, E element);
    void add(int index,E element);
    void add(E element);
    E get(int index);
    E remove(int index);
    int indexOf(E element);
    Node* fetchNode(int index){
        Node *node = first;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }
    void rangeCheck(int index);
    void rangeCheckForAdd(int index);
    void outOfBounds(int index);
};

template <class E>
void SingleCircleLinkedList<E>::clearElement(void(*clearFunction)(E)){
    if (size == 0) return;
    while (size > 0) {
        E element = remove(size - 1);
        if (clearFunction != NULL) {
            clearFunction(element);
        }
    }
}

template <class E>
void SingleCircleLinkedList<E>::toString(){
    cout << "[";
    Node *node = first;
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            cout << "," << endl;
        }
        cout << node->element;
        node = node->next;
    }
    cout << " ]" << endl;
}

template <class E>
void SingleCircleLinkedList<E>::outOfBounds(int index){
    throw "IndexOutOfBoundsException";
}

template <class E>
void SingleCircleLinkedList<E>::rangeCheck(int index){
    if (index < 0 || index >= size) {
        outOfBounds(index);
    }
}

template <class E>
void SingleCircleLinkedList<E>::rangeCheckForAdd(int index){
    if (index < 0 || index > size) {
        outOfBounds(index);
    }
}



template <class E>
void SingleCircleLinkedList<E>::add(E element){
    add(size, element);
}

template <class E>
void SingleCircleLinkedList<E>::add(int index, E element){
    rangeCheckForAdd(index);
    if (index == 0) {
        Node *newFirst = new Node(element,first);
        //找出最后一个元素
        Node *lastNode = (size == 0 ? newFirst : fetchNode(size - 1));
        lastNode->next = newFirst;
        first = newFirst;
    }else{
        //找出添加元素的prev元素
        Node *prev = fetchNode(index - 1);
        Node *newNode = new Node(element,prev->next);
        prev->next = newNode;
    }
    size++;
}
template <class E>
E SingleCircleLinkedList<E>::remove(int index){
    rangeCheck(index);
    Node *node = first;
    if (index == 0) {
        if (size == 1) {
            first = NULL;
        }else{
            Node *lastNode = fetchNode(size - 1);
            first = first->next;
            lastNode->next = first;
        }
        
    }else{
        Node *prev = fetchNode(index - 1);
        //要删除的元素
        node = prev->next;
        prev->next = node->next;
    }
     size--;
    return node->element;
    
   
}


template <class E>
E SingleCircleLinkedList<E>::get(int index){
    Node *node = fetchNode(index);
    return node->element;
}

template <class E>
E SingleCircleLinkedList<E>::set(int index, E element){
    Node *oldNode = fetchNode(index);
    E oldElement = oldNode->element;
    oldNode->element = element;
    return oldElement;
}

template <class E>
int SingleCircleLinkedList<E>::indexOf(E element){
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
    return -1;
}

template <class E>
void SingleCircleLinkedList<E>::clear(){
    size = 0;
    first = NULL;
}


#endif /* SingleCircleLinkedList_hpp */
