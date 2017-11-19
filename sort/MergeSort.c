//
// Created by Administrator on 2017/11/12.
//

#include "MergeSort.h"
#include "InsertionSort.h"
#include <stdlib.h>


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
* 私有排序
* @param arr
* @param low
* @param high
*/
static void __mergeSort(int *arr, int low, int high) {

    // 优化  当 high - low + 1
    // 即排序数组的长度小于等于16的时候使用插入排序
    //加上这个判断  对于1亿的数据排序,归并排序用时41s
    //不加这个判断  对于1亿的数据排序,归并排序用时56s
    if (high - low + 1 <= 16) {
        insertionSort2(arr, low, high);
        return;
    }

    if (low >= high) {
        return;
    }

    int mid = (high - low) / 2 + low;

    //左边进行归并排序
    __mergeSort(arr, low, mid);

    //右边进行归并排序
    __mergeSort(arr, mid + 1, high);

    //归并排序的第一个优化 arr[mid] > arr[mid + 1]此时才进行归并
    //加上这个判断  对于1亿的数据排序,归并排序用时41s
    //不加这个判断  对于1亿的数据排序,归并排序用时56s
    if (arr[mid] > arr[mid + 1]) {
        //把 arr[low ... mid]  和 arr[mid+1 ... high] 进行归并排序
        __merge(arr, low, mid, high);
    }
}

/**
 * 归并排序
 * @param arr
 * @param length
 */
void mergeSort(int *arr, int length) {
    __mergeSort(arr, 0, length - 1);
}







