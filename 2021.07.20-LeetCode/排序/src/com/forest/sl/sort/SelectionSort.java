package com.forest.sl.sort;

/**
 * Created by songlin on 2021/7/21.
 */
public class SelectionSort<T extends Comparable<T>> extends Sort<T> {
    @Override
    protected void sort() {
        for (int end = array.length - 1;end > 0; end--){
            //记录最大索引值
            int maxIndex = 0;
            for (int begin = 1;begin <= end;begin++){
                if (cmp(maxIndex,begin) < 0){
                    maxIndex = begin;
                }
            }
            swap(maxIndex,end);
        }
    }
}
