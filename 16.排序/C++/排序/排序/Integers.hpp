//
//  Integers.hpp
//  排序
//
//  Created by fengsl on 2019/12/29.
//  Copyright © 2019 FLP. All rights reserved.
//

#ifndef Integers_hpp
#define Integers_hpp

#include <stdio.h>

//要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
//要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
//要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
class Integers {
public:
    int *localArray;
    
     int* randomArray(int count, int min,int max){
        //random 1
//        if (count <= 0 || min > max) return {};
//         int  array[count];
//        int delta = max - min + 1;
//        for (int i = 0; i < count; i++) {
//            array[i] = min + (int)(rand() * delta);
//        }
//        return array;
        
        //random2
         if (count <= 0 || min > max) return {};
         localArray = new int[count]{};
                
                for (int i = 0; i < count; i++) {
                    localArray[i] =  (int)((rand() % (max - min)) + min);
//                    cout << localArray[i] << endl;
                }
        return localArray;
    }
    
     int * combine(int array1[], int array2[]){
       
        if (array1 == nullptr || array2 == nullptr) return nullptr;
         int arrayLen1 = (sizeof(*array1) / sizeof(array1[0]));
        int arrayLen2 = (sizeof(*array2) / sizeof(array2[0]));
 
     
           localArray = new int[arrayLen1 + arrayLen2]{};
        for (int i = 0; i < arrayLen1; i++) {
            localArray[i] = array1[i];
        }
        for (int i = 0; i < arrayLen2; i++) {
            localArray[i + arrayLen1] = array2[i];
        }

        return localArray;
    }
    
     int *same(int count, int unsameCount){
        if (count <= 0 || unsameCount > count) return nullptr;
         localArray = new int[count]{};
        for (int i = 0; i < unsameCount; i++) {
            localArray[i] = unsameCount - i;
        }
        for (int i = unsameCount; i < count; i++) {
            localArray[i] = unsameCount + 1;
        }
       
        return localArray;
    }
    
     int *ascOrder(int min,int max){
          
        if (min > max) return nullptr;
        localArray = new int[max - min + 1]{};
        int len = max - min + 1;
        for (int i = 0; i < len ; i++) {
            localArray[i] = min++;
        }
       
        return localArray;
    }
    
    static void reverse(int array[],int begin,int end){
        int count = (end - begin) >> 1;
        int sum = begin + end - 1;
        for (int i = begin; i < begin + count; i++) {
            int j = sum - i;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    
    
    static bool isAscOrder(int array[]){
        int len = (sizeof(*array) / sizeof(array[0]));
        if (array == nullptr || len == 0) return false;
        for (int i = 1; i < len; i++) {
            if (array[i - 1] > array[i]) return false;
        }
        return true;
    }
    
    static int * copy(int array[]){
         int len = (sizeof(*array) / sizeof(array[0]));
         static int *g_array;
        for (int i = 0; i < len; i++) {
            g_array[i] = array[i];
        }
        return g_array;
    }
    
     int * headTailAscOrder(int min ,int max,int disorderCount){
        int* array = ascOrder(min, max);
         int len = (sizeof(*array) / sizeof(array[0]));
        
        if (disorderCount > len) return array;
        reverse(array,0,disorderCount);
        return array;
    }
    
     int * centerAscOrder(int min,int max,int disorderCount){
        int *array = ascOrder(min, max);
         int len = (sizeof(*array) / sizeof(array[0]));
        if (disorderCount > len) return array;
        int left = disorderCount >> 1;
        reverse(array, 0 , left);
        
        int right = disorderCount - left;
        reverse(array, len - right, len);
        return array;
    }
    
     int *headAscOrder(int min,int max,int disorderCount){
        int *array = ascOrder(min,max);
          int len = (sizeof(*array) / sizeof(array[0]));
        if (disorderCount > len) return array;
        reverse(array, len - disorderCount, len);
        return array;
    }
    
     int * tailAscOrder(int min,int max,int disorderCount){
        int *array = ascOrder(min, max);
         int len = (sizeof(*array) / sizeof(array[0]));
        if (disorderCount > len) return array;
        reverse(array, 0, disorderCount);
        return array;
    }
    
     void printlnStr(int array[]){
        if (array == nullptr) return;
        string content;
         int len = (sizeof(*array) / sizeof(array[0]));
        for (int i = 0; i < len; i++) {
            if (i != 0) content = content + "_";
            content = content + to_string(array[i]);
        }
        cout << content << endl;
    }
};


#endif /* Integers_hpp */
