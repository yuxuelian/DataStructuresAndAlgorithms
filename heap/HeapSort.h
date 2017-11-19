//
// Created by Administrator on 2017/11/18.
//

#ifndef TEST1_HEAPSORT_H
#define TEST1_HEAPSORT_H


/**
 * 使用堆进行排序
 * @param arr
 * @param length
 */
void heapSort(int *arr, int length);


/**
 * 使用heapify进行排序
 * @param arr
 * @param length
 */
void heapifySort(int *arr, int length);


/**
 * 原地堆排序
 * @param arr
 * @param length
 */
void heapifySort2(int *arr, int length);

#endif //TEST1_HEAPSORT_H
