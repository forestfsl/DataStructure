//
//  MinHeap.hpp
//  16.Graph
//
//  Created by fengsl on 2020/1/14.
//  Copyright © 2020 com.ktcwdxc.mical. All rights reserved.
//

#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <stdio.h>
#include <set>


using namespace std;
// set<Edge<V, E>*> outEdges
//Edge<V, E>*

template <class E>
class MinHeap {
   
public:
    int m_size;
    E *elements;
    typedef int(*Comparator)(E e1,E e2);
    Comparator compararor;
     static const int DEFAULT_CAPACITY = 10;
    MinHeap<E>(set<E> elements,Comparator comparator){
        this->compararor = comparator;
        
        m_size = (int)elements.size();
        if (m_size == 0) {
            this->elements = new E[DEFAULT_CAPACITY]{};
        }
        else{
            int capacity = max(m_size,10);
            this->elements = new E[capacity];
            int i = 0;
            for (E element: elements) {
                this->elements[i++] = element;
            }
//            批量建堆
            heapify();
        }
    }
    
    MinHeap<E>(){
        
    }
    MinHeap<E>(set<E> elements){
        m_size = (int)elements.size();
       if (m_size == 0) {
           this->elements = new E[DEFAULT_CAPACITY]{};
       }
       else{
           int capacity = max(m_size,10);
           this->elements = new E[capacity];
           int i = 0;
           for (E element: elements) {
               this->elements[i++] = element;
           }
//            批量建堆
           heapify();
       }
    }
    
    int size(){
        return m_size;
    }
    
    void clear(){
        for (int i = 0; i < m_size; i++) {
            elements[i] = nullptr;
        }
        m_size = 0;
    }
    
    void add(E element){
        elementNotNullCheck(element);
        ensureCapacity(m_size + 1);
        elements[m_size++] = element;
        siftUp(m_size - 1);
    }
    
    void addAll(set<E> elements){
        for(typename set<E>::iterator iter = elements.begin(); iter != elements.end(); iter++){
            add(iter);
        }
    }
    E get(){
        emptyCheck();
        return elements[0];
    }
    bool isEmpty(){
        return m_size == 0;
    }
    
    E remove(){
        emptyCheck();
        
        int lastIndex = --this->m_size;
        E root = elements[0];
        elements[0] = elements[lastIndex];
        elements[lastIndex] = nullptr;
        siftDown(0);
        
        return root;
    }
    
    
    E rplace(E element){
        elementNotNullCheck(element);
        E root = nullptr;
        if (this->m_size == 0) {
            if (this->m_size == 0) {
                elements[0] = element;
                elements[0] = element;
                this->m_size++;
            }else{
                root = elements[0];
                elements[0] = element;
                siftDown(0);
            }
           
        }
         return root;
    }
    
    //批量建堆
   void heapify(){
       //自上而下的上虑
//        for (int i = 1; i < this->m_size; i++) {
//            siftUp(i);
//        }
       
       //自下而上的下滤
       for (int i = (this->m_size >> 1) - 1; i >= 0; i--) {
           siftDown(i);
       }
       
   }
    //让index位置的元素上虑
void siftUp(int index){
    //method1
//        E e = elements[index];
//        while (index > 0) {//索引为0的元素不需要下滤，也就是根节点
//            int pindex = (index - 1) >> 1; //这个操作是公式，忘记了可以查看课件pdf
//            E p = elements[pindex];
//            //根据规则比较元素
//            if(compare(e, p) <= 0) return;
//            //交换index，pindex位置的内容
//            E tmp = elements[index];
//            elements[index] = elements[pindex];
//            elements[pindex] = tmp;
//        }
    
    //method2 相对method1的方法，减少了交换次数，比较到最后的时候才进行交换值
    E element = elements[index];
    while (index > 0) {
        int parentIndex = (index - 1) >> 1;
        E parent = elements[parentIndex];
        if(compare(element, parent) <= 0) break;
        
        //将父元素存储在index位置
        elements[index] = parent;
        //重新赋值index
        index = parentIndex;
    }
    elements[index] = element;
        }
    //让index位置的元素下滤
   void siftDown(int index){
       E element = elements[index];
       int half = this->m_size >> 1;
       //第一个叶子节点的索引 == 非叶子节点的数量 二叉堆是一个完美二叉树
       //index < 第一个叶子节点的索引
       //必须保证index位置是非叶子节点,换句话说就是叶子节点不需要下滤
       while (index < half) {
           //index 的节点有2中情况
           //1.只有叶子节点
           //2.同时有左右子节点
           
           //默认从左子节点跟它进行比较
           int childIndex = (index << 1) + 1;//课件中查看公式
           E child = elements[childIndex];
           //右子节点
           int rightIndex = childIndex + 1;
           //选出左右最节点最大的那个，这个根据添加可以知道最大节点不是在左边
           if (rightIndex < this->m_size && compare(elements[rightIndex], child) > 0) {
               child = elements[childIndex = rightIndex];
           }
           if (compare(element, child) >= 0) break;
           //将子节点存放到index位置
           elements[index] = child;
           //重新设置index
           index = childIndex;
       }
       elements[index] = element;
               
           }
    void ensureCapacity(int capacity){

        int oldCapacity = DEFAULT_CAPACITY;
        if (oldCapacity >= capacity) return;
        
        //新容量为就容量的1.5倍
        int newCapacity = oldCapacity + (oldCapacity >> 1);
        E *newElements = new E[newCapacity]{};
        for (int i = 0; i < this->m_size; i++) {
            newElements[i] = elements[i];
        }
        elements = newElements;
    }
    
    void emptyCheck(){
        if (m_size == 0) {
            throw "Heap is Empty";
        }
    }
    
    void elementNotNullCheck(E element){
        if (element == nullptr){
            throw "element must not be null";
        }
    }
    int compare(E e1,E e2){
        if (compararor != nullptr) {
               return compararor(e1,e2);
        }
        return 0;
    }
    
};

#endif /* MinHeap_hpp */
