//
// Created by Administrator on 2017/11/18.
//

#include "HeapSort.h"
#include "BinaryHeap.h"

static void __shiftDown(int *pInt, int i);

/**
 * 使用堆进行排序
 * @param arr
 * @param length
 */
void heapSort(int *arr, int length) {
    MaxHeap maxHeap = createMaxHeap(length);

    for (int i = 0; i < length; ++i) {
        insertMaxHeap(&maxHeap, arr[i]);
    }


    for (int j = length - 1; j >= 0; --j) {
        arr[j] = extractMaxHeap(&maxHeap);
    }
}


/**
 * 使用heapify进行排序
 * @param arr
 * @param length
 */
void heapifySort(int *arr, int length) {
    MaxHeap maxHeap = heapifyMaxHeap(arr, length);

    for (int i = length - 1; i >= 0; --i) {
        arr[i] = extractMaxHeap(&maxHeap);
    }
}


/**
 * 原地堆排序
 * @param arr
 * @param length
 */
void heapifySort2(int *arr, int length) {

    int temp;

    //heapify
    for (int i = (length - 1) / 2; i >= 0; --i) {
        __shiftDown0(arr, length, i);
    }

    for (int i = length - 1; i > 0; --i) {
        //swap(arr[0],arr[i])
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        //对arr第0个元素的位置进行__shiftDown0操作 切堆中的元素个数要减一
        __shiftDown0(arr, i, 0);
    }
}

void __shiftDown0(int *arr, int length, int k) {
    int temp;
    //有左孩子  2 * k <= count  才进行循环
    while (2 * k + 1 < length) {
        //在此轮循环中 arr[j]  和 arr[k]  交换
        int j = 2 * k + 1;

        //j + 1 < count有右孩子
        //arr[j + 1] > arr[j]比较左右两个孩子  看谁大
        if (j + 1 < length && arr[j + 1] > arr[j]) {
            j++;
        }

        //比较父节点与两个子孩子  看谁大   父节点大  那么  shiftDown  结束
        if (arr[k] >= arr[j]) {
            //父节点已经大于等于两个孩子了,无需再进行  __shiftDown
            break;
        }

        //否则交换位置 swap(pMaxHeap->arr[k],pMaxHeap->arr[j])
        temp = arr[k];
        arr[k] = arr[j];
        arr[j] = temp;

        //更新一下  k  继续  _shiftDown
        k = j;
    }
}

