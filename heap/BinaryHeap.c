//
// Created by Administrator on 2017/11/18.
//

#include "BinaryHeap.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

static void shiftUp(PMaxHeap pMaxHeap, int k);

static void __shiftDown(PMaxHeap heap, int count);

/**
 * 创建最大堆
 * @param length
 * @return
 */
MaxHeap createMaxHeap(int length) {
    MaxHeap maxHeap;
    maxHeap.data = malloc(sizeof(int) * (length + 1));
    maxHeap.data[0] = 0;
    maxHeap.capacity = length;
    maxHeap.count = 0;
    return maxHeap;
}

/**
 * 将一个传入的数组堆化
 * @param arr
 * @param length
 * @return
 */
MaxHeap heapifyMaxHeap(int *arr, int length) {
    //首先创建一个最大堆
    MaxHeap maxHeap;

    maxHeap.data = malloc(sizeof(int) * (length + 1));
    maxHeap.data[0] = 0;
    maxHeap.capacity = length;

    for (int i = 0; i < length; ++i) {
        maxHeap.data[i + 1] = arr[i];
    }

    maxHeap.count = length;

    //heapify
    for (int j = maxHeap.count / 2; j >= 1; --j) {
        __shiftDown(&maxHeap, j);
    }

    return maxHeap;
}

/**
 * 返回当前元素的个数
 * @param pMaxHeap
 * @return
 */
int maxHeapCount(PMaxHeap pMaxHeap) {
    return pMaxHeap->count;
}

/**
 * 判断当前最大堆是否为空  为空返回1  不为空返回0
 * @param pMaxHeap
 * @return
 */
int maxHeapIsEmpty(PMaxHeap pMaxHeap) {
    return pMaxHeap->count == 0;
}

/**
 * 向最大堆插入一个元素 插入成功返回1  失败返回0
 * @param pMaxHeap
 * @param value
 * @return
 */
void insertMaxHeap(PMaxHeap pMaxHeap, int value) {
    //加入元素
    assert(pMaxHeap->count + 1 <= pMaxHeap->capacity);

    pMaxHeap->data[++pMaxHeap->count] = value;

    //维护最大堆的性质
    shiftUp(pMaxHeap, pMaxHeap->count);
}

/**
 * 取出一个最大堆的堆顶元素,即堆中的最大值
 * @param pMaxHeap
 * @param value
 */
int extractMaxHeap(PMaxHeap pMaxHeap) {
    //当堆中一个元素都没有的时候,不能出队
    assert(pMaxHeap->count > 0);

    int ret = pMaxHeap->data[1];

    //将堆中最后一个元素放置到堆的第一个元素的位置上去
    pMaxHeap->data[1] = pMaxHeap->data[pMaxHeap->count];

    pMaxHeap->count--;

    __shiftDown(pMaxHeap, 1);

    return ret;
}

/**
 * 维持堆的性质
 * @param heap
 * @param k
 */
void __shiftDown(PMaxHeap pMaxHeap, int k) {
    int temp;
    //有左孩子  2 * k <= pMaxHeap->count  才进行循环
    while (2 * k <= pMaxHeap->count) {
        //在此轮循环中 data[j]  和 data[k]  交换
        int j = 2 * k;

        //j + 1 <= pMaxHeap->count有右孩子
        //pMaxHeap->data[j + 1] > pMaxHeap->data[j]比较左右两个孩子  看谁大
        if (j + 1 <= pMaxHeap->count && pMaxHeap->data[j + 1] > pMaxHeap->data[j]) {
            j++;
        }

        //比较父节点与两个子孩子  看谁大   父节点大  那么  shiftDown  结束
        if (pMaxHeap->data[k] >= pMaxHeap->data[j]) {
            //父节点已经大于等于两个孩子了,无需在进行  __shiftDown
            break;
        }

        //否则交换位置 swap(pMaxHeap->data[k],pMaxHeap->data[j])
        temp = pMaxHeap->data[k];
        pMaxHeap->data[k] = pMaxHeap->data[j];
        pMaxHeap->data[j] = temp;

        //更新一下  k  继续  _shiftDown
        k = j;
    }
}

/**
 * 这个函数无需调用
 * @param pMaxHeap
 * @param k
 */
static void shiftUp(PMaxHeap pMaxHeap, int k) {
    int temp;

    while (k > 1 && pMaxHeap->data[k / 2] < pMaxHeap->data[k]) {
        //swap(pMaxHeap->data[k / 2],pMaxHeap->data[k])
        temp = pMaxHeap->data[k / 2];
        pMaxHeap->data[k / 2] = pMaxHeap->data[k];
        pMaxHeap->data[k] = temp;

        //更新一下k
        k /= 2;
    }
}

void traverseMaxHeap(PMaxHeap pMaxHeap) {
    for (int i = 1; i <= pMaxHeap->count; ++i) {
        printf("%d\t", pMaxHeap->data[i]);
    }
    printf("\n");
}


void printSpace(int num) {
    for (int i = 0; i < num; ++i) {
        printf(" ");
    }
}

/**
 * 以树的方式打印最大堆
 * @param pMaxHeap
 */
void printTreeMaxHeap(PMaxHeap pMaxHeap) {
    int tier = ceil(log2(pMaxHeap->count));

    //外层循环控制层
    for (int i = 0; i < tier; ++i) {
        //控制每一行的输出
        int start = pow(2, i);
        int end = i == tier - 1 ? (pMaxHeap->count) : (pow(2, i + 1) - 1);
        for (int j = start; j <= end; ++j) {
            printSpace(3 * (tier - i - 1));
            printf("%d   ", pMaxHeap->data[j]);
        }
        //打印树枝
        printf("\n");
    }
}




