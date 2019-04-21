//
//  ArrayList.hpp
//  02.动态数组
//  刚开始的时候我将ArrayList的声明和实现实现函数分离的，但是发现编译过程之后会报错，是因为模板函数
//在编译的过程之后，只是copy的声明过去，而没有将实现也拷贝过去，这样就会因为找不到对应的类型而报错，这个是模板函数的特性
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


template <class Item>
class ArrayList {
    int m_size = 0;
    int m_capcity = 0;
    Item *m_data = nullptr;
    friend ostream &operator<<(ostream &, const ArrayList<Item> &);
    static const int DEFAULT_CAPACITY = 2;
    static const int ELEMENT_NOT_FOUND = -1;
    //检查是否在范围内
    void rangeCheck(int index);
    void rangeCheckForAdd(int index);
    //检查是否越界
    void outOfBounds(int index);
    //扩容量
    void ensureCapacity(int capacity);

public:
    ArrayList();
    ArrayList(int capacity);
    ~ArrayList();
    void add(Item value);
    void add(int index,Item value);
    int size();
    Item get(int index);
    Item set(int index, Item value);
    Item operator[](int index);
    void display();
    void clear();
    bool isEmpty();
    bool contains(Item element);
    int indexOf(Item element);
    Item remove(int index);
};

template<class Item>
//语法糖
ArrayList<Item>::ArrayList():ArrayList(DEFAULT_CAPACITY){
    cout << "无参调用有参函数ArrayList()" << endl;
}

template<class Item>
ArrayList<Item>::ArrayList(int capacity){
    cout << "调用有参构造函数ArrayList(int capacity)" << endl;
    m_capcity = (capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : capacity;
    m_data = new Item[m_capcity]{};
 }

template<class Item>
ArrayList<Item>::~ArrayList<Item>(){
    cout << "调用析构函数 ~ArrayList()" << endl;
    if (m_data != nullptr) {
        //delete 代表内存可以回收了，但是内存中还是有值的，怕之后数据错乱，所以要将m_data 指向的值清空
        delete [] m_data;
        m_data = NULL;
    }
    m_size = 0;
   
}

/*
 * 清楚所有元素
 */
template<class Item>
void ArrayList<Item>::clear(){
    for (int i = 0; i < m_size; i++) {
       
        delete m_data[i];
         m_data[i] = NULL;
    }
    m_size = 0;
}

/**
 * 元素的数量
 */
template<class Item>
int ArrayList<Item>::size(){
    return m_size;
}

/**
 * 是否为空
 */
template<class Item>
bool ArrayList<Item>::isEmpty(){
    return m_size == 0;
}

/**
 * 获取index位置的元素
 */

template<class Item>
Item ArrayList<Item>::get(int index){
    rangeCheck(index);
    return m_data[index];
}

/**
 * 设置index位置的元素
 */
template<class Item>
Item ArrayList<Item>::set(int index,Item value){
    rangeCheck(index);
    //取出旧值
    Item oldValue = m_data[index];
    //获取新值
    m_data[index] = value;
    //返回旧值
    return oldValue;
}


/**
 * 是否包含某个元素
 */
template<class Item>
bool ArrayList<Item>::contains(Item element){
    return indexOf(element) != ELEMENT_NOT_FOUND;
}

/**
 * 查看元素的索引
 */
template<class Item>
int ArrayList<Item>::indexOf(Item element){
    if (element == NULL) {
        for (int i = 0; i < m_size; i++) {
            if(m_data[i] == NULL) return i;
        }
    }else{
        for (int i = 0; i < m_size; i++) {
            if(m_data[i] == element) return i;
        }
    }
}

/*
 * 添加元素到尾部
 */
template<class Item>
void ArrayList<Item>::add(Item value){
    add(m_size, value);
}

/*
 * 在index位置插入一个元素
 */
template<class Item>
void ArrayList<Item>::add(int index, Item value){
    rangeCheckForAdd(index);
    ensureCapacity(m_size + 1);
    for (int i = m_size; i > index; i--) {
        m_data[i] = m_data[i-1];
    }
    m_data[index] = value;
    m_size++;
}
/**
 * 删除index位置的元素
 */
template<class Item>
Item ArrayList<Item>::remove(int index){
    rangeCheck(index);
    Item oldItem = m_data[index];
    for (int i = index + 1; i < m_size; i++) {
        m_data[i - 1] = m_data[index];
    }
    //移除最后一个对象内存
    m_data[--m_size] = NULL;
    return oldItem;
}

/**
 * 扩容
 */
template<class Item>
void ArrayList<Item>::ensureCapacity(int capacity){
    //容量足够的话，直接返回
    int oldCapacity = m_capcity;
    if (oldCapacity >= capacity) return;
    //容量不够，开始扩容1.5
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    Item *newElements =  new Item[newCapacity]{};
    //赋值
    for (int i = 0; i < m_size; i++) {
        newElements[i] = m_data[i];
    }
    //赋值回去原来的m_data
    m_data = newElements;
    m_capcity = newCapacity;
    cout << oldCapacity << "扩容为" << newCapacity << endl;
}

/*
 * 检查index是否在范围
 */

template<class Item>
void ArrayList<Item>::rangeCheck(int index){
    if (index < 0 || index >= m_size) {
        outOfBounds(index);
    }
}


//抛出异常
template<class Item>
void ArrayList<Item>::outOfBounds(int index){
    throw "IndexOutOfBoundsException";
}

template<class Item>
void ArrayList<Item>::rangeCheckForAdd(int index){
    if (index < 0 || index > m_size) {
        outOfBounds(index);
    }
}


//打印数组
template<class Item>
void ArrayList<Item>::display(){
    cout << "[";
    for (int i = 0; i < m_size; i++) {
        if (i != 0) {
            cout << ", ";
        }
        //上面这种效率高一点，因为不用执行多一次减法
        //        if (i != m_size - 1) {
        //            cout << ", ";
        //        }
        cout <<m_data[i];
    }
    cout << "]" << endl;
}

template<class Item>
ostream &operator<<(ostream &cout, const ArrayList<Item> &arrayList){
    cout << "[";
    for (int i = 0; i < arrayList.m_size ; i++) {
        if (i != 0) {
            cout << arrayList.m_data[i];
        }
        //        if (i != arrayList.m_size - 1) {
        //            cout << ", ";
        //        }
    }
    return cout << "]";
}



#endif /* ArrayList_hpp */
