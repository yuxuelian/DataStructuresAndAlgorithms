//
// Created by Administrator on 2017/12/13.
//

#include "RadixSort.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXK 10

int countSort(int *array, int n, int d);

int getValue(int a, int d);

void radixSort(int *a, int n, int d) {
    for (int i = 0; i <= d; i++) {
        countSort(a, n, i);
    }
}

int countSort(int *array, int n, int d) {
    printf("%d\n", d);
    int k[MAXK] = {0};
    int *temp, *b;
    int i;

    //储存自己数组下标数值在目标数组对应的位置sizeof(int) * n);
    b = malloc(sizeof(int) * n);
    temp = malloc(sizeof(int) * n);

    if (NULL == temp) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        b[i] = getValue(array[i], d);
    }

    //显示b数组
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        //记录与数组下标相等的数值的个数
        k[b[i]]++;
    }

    //显示k数组
    for (i = 0; i < 10; i++) {
        printf("%d ", k[i]);
    }

    printf("\n");

    for (i = 1; i < 10; i++) {
        k[i] += k[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        //将原数组按大小顺序储存到另一个数组
        temp[--k[b[i]]] = array[i];
    }

    //显示temp数组
    for (i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    printf("\n");

    //赋值回原数组
    for (i = 0; i < n; i++) {
        array[i] = temp[i];
    }

    //释放空间
    free(b);
    free(temp);

    return 1;
}

int getValue(int a, int d) {
    int b;
    for (b = a; d > 0 && a > 0; d--) {
        b /= MAXK;
    }
    return b % MAXK;
}

