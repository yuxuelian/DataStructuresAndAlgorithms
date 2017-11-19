//
// Created by Administrator on 2017/11/11.
//

#include "QuickSort.h"
#include "InsertionSort.h"
#include <stdlib.h>
#include <time.h>

static int findPosition(int *arr, int low, int high);

static void __QuickSort(int arr[], int low, int high);

static int __partition(int *arr, int low, int high);


void quickSort(int a[], int length) {
    //设置随机数种子
    srand(time(NULL));

    __QuickSort(a, 0, length - 1);
}

void __QuickSort(int *arr, int low, int high) {

    // 优化2  当 high - low + 1
    // 即排序数组的长度小于等于16的时候使用插入排序
    if (high - low + 1 <= 16) {
        insertionSort2(arr, low, high);
        return;
    }

    //只有l小于r的时候才去处理,当l=r的时候,
    // 即a只有一个元素,无需排序了
    if (low < high) {
        //找数组中第一个元素在有序的情况下的位置,返回找到的位置
//        int position = findPosition(arr, low, high);
        int position = __partition(arr, low, high);
        //继续排序由position分割后左边的数组
        __QuickSort(arr, low, position - 1);
        //继续排序由position分隔后右边的数组
        __QuickSort(arr, position + 1, high);
    }
}


/**
 * 找数组中第一个元素的排序好的位置
 * 这个过程又可以叫作  partition
 * @param arr
 * @param low
 * @param high
 * @return
 */
int findPosition(int *arr, int low, int high) {

    // 快速排序的优化1
    // 随机选取数组中的一个数作为排序基准,防止数组有序情况下排序退化
    int index = rand() % (high - low + 1) + low;

    int temp;

    temp = arr[index];
    arr[index] = arr[low];
    arr[low] = temp;

    temp = arr[low];

    //开始移动下标
    while (low < high) {

        // 因为选取是左边第一个元素作为基准,那么开始移动的时候,
        // 第一次需要从右边开始移动,否则会出错

        //首先 low < high 这是肯定的
        //arr[high] 如果一直比val大, 执行 --high 否则退出循环
        while (low < high && arr[high] >= temp) {
            --high;
        }
        //将右边pInt[high](这个元素比val小)赋值个pInt[low]
        arr[low] = arr[high];


        //首先 low < high 这是肯定的
        //arr[low] 如果一直比val小, 执行 ++low 否则退出循环
        while (low < high && arr[low] <= temp) {
            ++low;
        }
        //将左边pInt[low](这个元素比val大)赋值给pInt[high]
        arr[high] = arr[low];
    }

    //找到了val的位置,赋值进去
    arr[low] = temp;

    return low;
}

/**
 * 快速排序的另外一种写法
 * @param arr
 * @param low
 * @param high
 * @return
 */
int __partition(int *arr, int low, int high) {

    int v, temp;

    int index = rand() % (high - low + 1) + low;

    int j = low;

    temp = arr[index];
    arr[index] = arr[low];
    arr[low] = temp;

    v = arr[low];

    for (int i = low + 1; i <= high; ++i) {
        if (arr[i] < v) {
            j++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}


