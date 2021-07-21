package com.forest.sl;

import com.forest.sl.sort.*;
import com.forest.sl.tool.Asserts;
import com.forest.sl.tool.Integers;

import java.util.Arrays;

/**
 * Created by songlin on 2021/7/20.
 */
public class Main {
    public static void main(String[] args) {
        Integer[] array = Integers.random(1000,1,1000);//随机数组
//        Integer[] array = Integers.ascOrder(1,10000);
        testSorts(array,new Bubble1Sort(),new Bubble2Sort(),new Bubble3Sort(),new SelectionSort());
    }

    static void testSorts(Integer[] array,Sort...sorts){
        for (Sort sort: sorts){
            Integer[] newArray = Integers.copy(array);
            sort.sort(newArray);
            Asserts.test(Integers.isAscOrder(newArray));

            System.out.println(Arrays.toString(newArray));
        }

        //根据CompareTo的比较方式，排序输出
        Arrays.sort(sorts);
        for (Sort sort : sorts){
            System.out.println(sort);
        }
    }
}
