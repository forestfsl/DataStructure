package com.forest.sl.sort;

import java.util.Comparator;

/**
 * Created by songlin on 2021/7/21.
 */
public class Bubble3Sort<T extends Comparable<T>> extends Sort<T> {
    @Override
    protected void sort() {
        for (int end = array.length - 1;end > 0;end--){
            //定义变量记录最终的元素的交换位置的索引，这样就不用每次都是end-1操作
            int sortIndex = 0;
            for (int begin =0;begin < end;begin++){
               if (cmp(begin,begin+1) > 0){
                   swap(begin,begin+1);
                   sortIndex = (begin + 1);
               }
            }
            end = sortIndex;
        }
    }
}
