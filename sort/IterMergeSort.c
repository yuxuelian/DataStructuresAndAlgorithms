//
// Created by Administrator on 2017/11/18.
//

#include "IterMergeSort.h"
#include <math.h>
#include <stdlib.h>
#include "InsertionSort.h"

static void __merge(int *arr, int low, int mid, int high) {

    //复制一个空间出来
    int length = high - low + 1;
    int *aux = malloc(sizeof(int) * length);

    //复制一份待归并的数组
    for (int i = low; i <= high; ++i) {
        aux[i - low] = arr[i];
    }

    //i 左边待归并的数组的索引
    int i = low;

    //j 右边待归并数组的索引
    int j = mid + 1;

    //k 归并后数组的索引
    for (int k = low; k <= high; ++k) {
        if (i > mid) {
            //这个同理  将右边剩余数组全部赋值到arr
            arr[k] = aux[j - low];
            ++j;
        } else if (j > high) {
            //右边的索引已经超出 最右边数组的最后一个元素的位置了
            //此时只需要将左边数组剩下的所有元素全部赋值到arr数组后面的位置
            // 因为左边剩下的数组肯定是有序的且都比右边数组最后一个元素大
            arr[k] = aux[i - low];
            ++i;
        } else {
            //正常归并
            if (aux[i - low] < aux[j - low]) {
                arr[k] = aux[i - low];
                ++i;
            } else {
                arr[k] = aux[j - low];
                ++j;
            }
        }
    }
    //释放申请的空间
    free(aux);
}


/**
 * 这种排序可以用于对链表进行NlogN的时间进行排序
 * 这个自低向上的归并排序相对于自顶向下的归并排序要稍微慢一些
 * 一千万的数据进行排序
 * mergeSort排序执行时间:2.726000
 * iterMergeSort排序执行时间:2.987000
 * @param arr
 * @param length
 */
void iterMergeSort(int *arr, int length) {
    for (int sz = 1; sz <= length; sz += sz) {
        //跨过两个sz的大小进行归并
        for (int i = 0; i + sz < length; i += sz + sz) {

            int low = i;
            int mid = i + sz - 1;
            int high = __min(i + sz + sz - 1, length - 1);

            //优化1
            if (high - low + 1 <= 16) {
                insertionSort2(arr, low, high);
                continue;
            }

//            //优化2
            if (arr[mid] > arr[mid + 1]) {
                __merge(arr, low, mid, high);
            }

//            __merge(arr, low, mid, high);
        }
    }
}

