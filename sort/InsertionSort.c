//
// Created by Administrator on 2017/11/12.
//

#include "InsertionSort.h"

/**
 * 插入排序
 * @param arr
 * @param length
 */
void insertionSort(int *arr, int length) {
    int temp;
    for (int i = 1; i < length; ++i) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }
}

/**
 * 优化插入排序
 * @param arr
 * @param length
 */
void insertionSort1(int *arr, int length) {
    for (int i = 1; i < length; ++i) {
        int e = arr[i], j;
        for (j = i; j > 0 && arr[j - 1] > e; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

/**
 * 优化插入排序
 * @param arr
 * @param length
 */
void insertionSort2(int *arr, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        int e = arr[i];
        int j;
        for (j = i; j > low && arr[j - 1] > e; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}
