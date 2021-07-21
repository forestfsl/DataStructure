package com.forest.sl.sort;

/**
 * Created by songlin on 2021/7/21.
 */

/*
这个算法还是具有可优化性的
测试1:耗时：0.111s(111ms) 	比较：49905.04万	 交换：0
这个案例我提供了一个排好序的数组了，外部for循环也还是需要跑array.length - 1 次，其实如果第一次没有交换，说明这个数组就是排序的了
 */
public class Bubble1Sort<T extends Comparable<T>> extends Sort<T> {

    @Override
    protected void sort() {
        //从父类已经继承了数组
        for (int end = array.length - 1;end > 0;end--){//外层循环，代表要遍历的次数
            for (int begin = 0;begin < end;begin++){//内循环代表要交换的情况
                if (cmp(begin,begin+1) > 0){
                    swap(begin,begin+1);
                };
            }
        }

    }
}
