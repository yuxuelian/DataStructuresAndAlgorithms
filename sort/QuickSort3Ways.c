//
// Created by Administrator on 2017/11/18.
//

#include "QuickSort3Ways.h"
#include "InsertionSort.h"
#include <time.h>
#include <stdlib.h>

static void __QuickSort3Ways(int *arr, int low, int high) {

    //首先处理递归到底的情况
    // 优化2  当 high - low + 1
    // 即排序数组的长度小于等于16的时候使用插入排序
    if (high - low + 1 <= 16) {
        insertionSort2(arr, low, high);
        return;
    }

//    if (low >= high) {
//        return;
//    }

    //partition

    int v, temp;

    int index = rand() % (high - low + 1) + low;

    //swap(arr[low],arr[rand() % (high - low + 1) + low])
    temp = arr[index];
    arr[index] = arr[low];
    arr[low] = temp;

    v = arr[low];

    int lt = low;
    int gt = high + 1;
    int i = low + 1;

    while (i < gt) {
        if (arr[i] < v) {
            ++lt;

            //swap(arr[i],arr[lt])
            temp = arr[i];
            arr[i] = arr[lt];
            arr[lt] = temp;

            ++i;
        } else if (arr[i] > v) {
            //swap(arr[i],arr[gt-1])
            --gt;

            temp = arr[i];
            arr[i] = arr[gt];
            arr[gt] = temp;
        } else {
            //arr[i]==v
            i++;
        }
    }

    //swap(arr[low],arr[lt])
    temp = arr[low];
    arr[low] = arr[lt];
    arr[lt] = temp;

    __QuickSort3Ways(arr, low, lt - 1);
    __QuickSort3Ways(arr, gt, high);
}

void quickSort3Ways(int a[], int length) {
    //设置随机数种子
    srand(time(NULL));

    __QuickSort3Ways(a, 0, length - 1);
}
