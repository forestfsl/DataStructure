package com.forest.sl.sort;

/**
 * Created by songlin on 2021/7/22.
 */
/*
二叉堆排序：
首先二叉堆的逻辑结构就是一颗完全二叉树，所以也叫完全二叉堆，鉴于完全二叉树的一些特征，

叶子节点个数n0 = floor((n+1)/2) = ceiling(n/2)
非叶子节点个数n1+n2 = floor(n/2) = ceiling((n-1)/2)


二叉堆的底层，一般用数组实现即可(只要第一个是叶子节点，后面的都是叶子节点)
索引i的规律(n是元素数量)
如果i = 0，它是根节点
如果i > 0,它的父节点的索引为floor((i-1)/2)
如果2i+1 小于等 (n -1),它的左子节点的索引为2i+1
如果2i+1 大于(n-1),它无左子节点
如果2i+2 小于等于(n-1),它的右子节点的索引为2i+2
如果2i+2 大于(n-1),它无右子节点
 */
public class HeapSort <T extends Comparable<T>> extends  Sort<T> {
    private int heapSize;
    @Override
    protected void sort() {
        //原地建堆也是需要是非叶子节点才可以，叶子节点-1等于非叶子节点
        heapSize = array.length;
        for (int i = (heapSize >> 1) - 1;i >= 0;i--){
            siftDown(i);
        }
        while (heapSize > 1){
            //交换堆顶元素和尾部元素
            swap(0,--heapSize);

            //对0位置进行siftDown(恢复堆的性质)
            siftDown(0);
        }
    }

    //下滤操作必须是非叶子节点，所以索引必须要小于叶子节点
    //从上面操作可以知道，叶子节点的索引half = heapSize >> 1;
    private void siftDown(int index){
        //找出要替交换的元素
        T element = array[index];
        int half = heapSize >> 1;
        while (index < half){
            //默认是左边跟父节点比(原因是存在的情况是只有左子节点，或者具有左右子节点，所以从左边开始比较)
            int childIndex = (index << 1) + 1;
            //取出左子节点的元素
            T child = array[childIndex];

            int rightIndex = childIndex + 1;
            //右子节点比左子节点大
            if (rightIndex < heapSize && cmp(array[rightIndex],child) > 0){
                child = array[childIndex = rightIndex];
            }

            //大于等于子节点
            if (cmp(element,child) >= 0) break;

            //来到这里说明小于子节点，需要替换

            array[index] = child;
            index = childIndex;
        }
        //跳出到循环外，说明element 是最后要替换的值
        array[index] = element;

    }
}
