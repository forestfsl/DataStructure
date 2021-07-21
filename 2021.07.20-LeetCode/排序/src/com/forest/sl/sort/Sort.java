package com.forest.sl.sort;

import java.text.DecimalFormat;
import java.util.Comparator;

/**
 * Created by songlin on 2021/7/21.
 */
public abstract class Sort<T extends Comparable<T>> implements Comparable<Sort<T>> {
    protected T[] array;//数组元素
    private int cmpCount;//比较次数
    private int swapCount;//交换次数
    private long time;
    private DecimalFormat fmt = new DecimalFormat("#.00");

    public void sort(T[] array){
        if (array == null || array.length < 2) return;

        this.array = array;

        long begin = System.currentTimeMillis();//当前时间
        sort();
        time = System.currentTimeMillis() - begin;//执行sort的时间差
    }

    //给子类去调用
    protected abstract void sort();

    @Override
    public int compareTo(Sort<T> o) {
        int result = (int)(time - o.time);
        if(result != 0) return result;
        result = cmpCount - o.cmpCount;
        if (result != 0) return result;

        return swapCount - o.swapCount;
    }

    /*
    返回值等于0，代表array[i1] == array[i2]
    返回值小于0，代表array[i1] < array[i2]
    返回值大于0，代表array[i1] > array[i2]
     */
    protected int cmp(int i1,int i2){
        cmpCount++;
        return array[i1].compareTo(array[i2]);
    }

    protected int cmp(T v1, T v2){
        cmpCount++;
        return v1.compareTo(v2);
    }

    protected void swap(int i1, int i2){
        swapCount++;
        T tmp = array[i1];
        array[i1] = array[i2];
        array[i2] = tmp;
    }

    @Override
    public String toString() {
        String timeStr = "耗时：" + (time / 1000.0) + "s(" + time + "ms)";
        String compareCountStr = "比较：" + numberString(cmpCount);
        String swapCountStr = "交换：" + numberString(swapCount);
//        String stableStr = "稳定性：" + isStable();
        return "【" + getClass().getSimpleName() + "】\n"
//                + stableStr + " \t"
                + timeStr + " \t"
                + compareCountStr + "\t "
                + swapCountStr + "\n"
                + "------------------------------------------------------------------";
    }

    private String numberString(int number){
        if (number < 10000) return "" + number;

        if (number < 100000000) return fmt.format(number / 1000.0) + "万";
        return fmt.format(number / 100000000.0) + "亿";
    }


}

