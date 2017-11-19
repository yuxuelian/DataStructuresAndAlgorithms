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

#endif //TEST1_BINARYSEARCH_H
