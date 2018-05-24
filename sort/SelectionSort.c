//
// Created by Administrator on 2017/11/18.
//

#include "SelectionSort.h"


void selectionSort(int a[], int length) {
    int temp, minIndex;

    for (int i = 0; i < length - 1; ++i) {

        //假设  a[i]  是当前最小值
        minIndex = i;

        //找数组后面是否还有  比 min更小的数
        for (int j = i + 1; j < length; ++j) {

            //如果  当前考察位置(a[j])  小于  a[minIndex]   则更新  索引
            if (a[j] < a[minIndex]) {
                //更新索引
                minIndex = j;
            }
        }

        //交换
        if (minIndex != i) {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}
