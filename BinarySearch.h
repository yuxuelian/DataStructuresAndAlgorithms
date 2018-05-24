//
// Created by Administrator on 2017/11/12.
//

#ifndef TEST1_BINARYSEARCH_H
#define TEST1_BINARYSEARCH_H

/**
 * 二分查找
 * @param a
 * @param lenth
 * @return 查找不存在返回-1,存在返回所在数组的索引
 */
int binarySearch(int a[], int start, int high, int key) {

    //int index = (high + start) / 2;

    //这种写法是防止在数据个数较多时，high + start 超出int范围的bug
    int index = (high - start) / 2 + start;

    //如果查找到
    if (a[index] == key) {
        return index;
    }

    if (start >= high) {
        return -1;
    } else if (a[index] < key) {
        // 说明要查找的元素在数组的右边
        return binarySearch(a, index + 1, high, key);
    } else if (a[index] > key) {
        //说明要查找的元素在数组的左边
        return binarySearch(a, start, index - 1, key);
    }
    return -1;
}

/**
 * 使用循环的方式实现二分查找
 * 找到返回找到的元素的索引,如果没有找到返回-1
 * @param arr
 * @param length
 * @param value
 * @return
 */
int binarySearch2(int arr[], int length, int value) {
    int l = 0, r = length - 1;

    while (l <= r) {
        int mid = (r - l) / 2 + l;

        if (arr[mid] > value) {
            //要查找的值在数组的左边
            r = mid - 1;
        } else if (arr[mid] < value) {
            //要查找的值在数组的右边
            l = mid + 1;
        } else {
            //如果找到,直接返回
            return mid;
        }
    }
    return -1;
}

#endif //TEST1_BINARYSEARCH_H
