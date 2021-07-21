package com.forest.sl.sort;

/**
 * Created by songlin on 2021/7/21.
 */
/*
  Integer[] array = Integers.ascOrder(1,10000);
对Bubble1Sort 的进一步优化，针对如果是排序数组的情况下
【Bubble2Sort】
耗时：0.001s(1ms) 	比较：9999	 交换：0
针对排序数组，可以优化到这个地步

但是有没有办法减少交换次数呢？我们是否可以记录最终需要排序的索引值呢，那么最后的end，应该就是我们最终的索引值

 */
public class Bubble2Sort<T extends Comparable<T>> extends Sort<T> {
    @Override
    protected void sort() {
        for (int end = array.length - 1;end > 0; end--){
            boolean sort = true;
            for (int begin = 0;begin < end;begin++){
                if (cmp(begin,begin+1) > 0){
                    swap(begin,begin+1);
                    sort = false;
                }
            }
            if (sort) break;
        }
    }
}
