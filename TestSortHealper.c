//
// Created by Administrator on 2017/11/12.
//

#include "TestSortHealper.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>

/**
 * 生成一个指定长度的随机数,左闭右闭的数组
 * @param length
 * @param start
 * @param end
 * @return
 */
int *randomCreateArray(int length, int start, int end) {
    //设置随机数种子
    srand(time(NULL));
    assert(start < end);
    int *arr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % (end - start + 1) + start;
    }
    return arr;
}

/**
 * 复制数组
 * @param arr
 * @param length
 * @return
 */
int *copyArray(int *arr, int length) {
    int *a1 = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        a1[i] = arr[i];
    }
    return a1;
}

/**
 * 遍历数组
 * @param arr
 * @param length
 */
void traverseArray(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}


/**
 * 测试一个排序算法
 * @param name
 * @param sort
 * @param arr
 * @param length
 */
void testSortTime(
        char *name,
        //排序的函数指针
        void(*sort)(int *arr, int length),

        int *arr,
        int length) {

    clock_t startTime = clock();

    //执行函数排序
    sort(arr, length);

    clock_t endTime = clock();

    assert(isSorted(arr, length));

    printf("%s排序执行时间:%lf\n", name, ((double) (endTime - startTime)) / CLOCKS_PER_SEC);
}

/**
 * 判断一个数组是否有序
 * @param arr
 * @param length
 * @return
 */
int isSorted(int *arr, int length) {
    for (int i = 0; i < length - 1; ++i) {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

/**
 * 创建一个有序的数组
 * @param length
 * @return
 */
int *createOrderlyArray(int length) {
    int *arr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        arr[i] = i;
    }
    return arr;
}






