//
//  ArrayList.cpp
//  02.动态数组
//
//  Created by fengsl on 2019/4/17.
//  Copyright © 2019 songlin. All rights reserved.
//

#include "ArrayList.hpp"

template<class Item>

//语法糖
ArrayList<Item>::ArrayList():ArrayList(DEFAULT_CAPACITY){
    cout << "无参调用有参函数" << endl;
}

template<class Item>
ArrayList<Item>::ArrayList(int capacity){
    cout << "调用有参构造函数" << endl;
    m_capcity = (capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : capacity;
    m_data = new Item[m_capcity]{};
}

template<class Item>
ArrayList<Item>::~ArrayList<Item>(){
    cout << "调用析构函数" << endl;
    if (!m_data) {
        return;
    }
    //delete 代表内存可以回收了，但是内存中还是有值的，怕之后数据错乱，所以要将m_data 指向的值清空
    delete [] m_data;
    m_data = NULL;
}

/*
* 清楚所有元素
*/
template<class Item>
void ArrayList<Item>::clear(){
    for (int i = 0; i < m_size; i++) {
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
    for (int i = m_size - 1; i >= index; i--) {
        m_data[i + 1] = m_data[i];
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
    for (int i = index + 1; i < m_size - 1; i++) {
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
     Item *newElements =  new Item[newCapacity]{0};
    //赋值
    for (int i = 0; i < m_size; i++) {
        newElements[i] = m_data[i];
    }
    //赋值回去原来的m_data
    m_data = newElements;
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
        cout << m_data[i];
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

