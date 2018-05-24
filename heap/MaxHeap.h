//
// Created by Administrator on 2017/11/18.
//

#ifndef MAX_HEAP_H
#define MAX_HEAP_H


typedef struct {
    //数据
    int *data;
    //当前元素个数
    int count;
    //容量
    int capacity;
} MaxHeap, *PMaxHeap;

/**
 * 创建一个最大堆  并返回
 * @param length
 * @return
 */
MaxHeap createMaxHeap(int length);

/**
 * 通过一个指定的数组,然后将数组进行堆化
 * @param arr
 * @param length
 * @return
 */
MaxHeap heapifyMaxHeap(int *arr,int length);

/**
 * 返回当前最大堆的元素个数
 * @param pMaxHeap
 * @return
 */
int maxHeapCount(PMaxHeap pMaxHeap);

/**
 * 是否为空
 * @param pMaxHeap
 * @return
 */
int maxHeapIsEmpty(PMaxHeap pMaxHeap);

/**
 * 向最大堆插入一个元素
 * @param pMaxHeap
 * @param value
 * @return
 */
void insertMaxHeap(PMaxHeap pMaxHeap, int value);

/**
 * 出队一个最大堆的堆顶元素,即堆中的最大值
 * @param pMaxHeap
 * @param value
 */
int extractMaxHeap(PMaxHeap pMaxHeap);

/**
 * 遍历最大堆
 * @param pMaxHeap
 */
void traverseMaxHeap(PMaxHeap pMaxHeap);

/**
 * 以树的方式这个最大堆
 * @param pMaxHeap
 */
void printTreeMaxHeap(PMaxHeap pMaxHeap);

#endif
