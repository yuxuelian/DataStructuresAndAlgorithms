#include <stdio.h>
#include "tree/Tree.h"
#include "sort/QuickSort.h"
#include "sort/InsertionSort.h"
#include "TestSortHealper.h"
#include "BinarySearch.h"
#include "sort/IterMergeSort.h"
#include "sort/QuickSort3Ways.h"
#include "sort/MergeSort.h"
#include <stdlib.h>
#include "heap/MaxHeap.h"
#include <time.h>
#include "heap/HeapSort.h"
#include "sort/RadixSort.h"
#include <unistd.h>
#include "sort/BubbleSort.h"
#include "sort/SelectionSort.h"
#include "link/LinkedList.h"

void printCurrentTime();

//在给千万级别的数组排序的情况下：
//Quick > Merge > Shell > Insertion > Selection


void testHeap();

void sortTest() {
//    int capacity = 200000000;

    //随机生成
//    int *arr = randomCreateArray(capacity, 0, capacity - 1);

    //有大量的重复数值
//    int *arr = randomCreateArray(capacity, 0, 10);

    //数组本身就是有序的
//    int *arr = createOrderlyArray(capacity);

//    int *arr1 = copyArray(arr, capacity);
//    int *arr2 = copyArray(arr, capacity);
//    int *arr3 = copyArray(arr, capacity);
//    int *arr4 = copyArray(arr, capacity);
//    int *arr5 = copyArray(arr, capacity);
//    int *arr6 = copyArray(arr, capacity);
//    int *arr7 = copyArray(arr, capacity);
//    int *arr8 = copyArray(arr, capacity);
//    traverseArray(arr, capacity);

    //插入排序
//    testSortTime("insertionSort", insertionSort, arr, capacity);

    //优化后的插入排序
//    testSortTime("insertionSort1", insertionSort1, arr1, capacity);

    //快速排序
//    testSortTime("quickSort", quickSort, arr2, capacity);

    //三切快速排序
//    testSortTime("quickSort3Ways", quickSort3Ways, arr3, capacity);
//
//    //递归归并排序
//    testSortTime("mergeSort", mergeSort, arr4, capacity);
//
//    //迭代归并排序
//    testSortTime("iterMergeSort", iterMergeSort, arr5, capacity);
//
//    //堆排序
//    testSortTime("heapSort", heapSort, arr6, capacity);
//
//    //heapifySort  堆排序
//    testSortTime("heapifySort", heapifySort, arr7, capacity);
//
//    //原地堆排序
//    testSortTime("heapifySort2", heapifySort2, arr8, capacity);

//    printf("\n递归方式二分查找:%d\n", binarySearch(arr3, 0, capacity - 1, 5000));
    int floor = 0;
    int ceil = 0;
    int arr[8] = {5, 5, 5, 5, 5, 5, 5, 5};
    binarySearchScope(arr, 8, 5, &floor, &ceil);
//    printf("\n循环方式二分查找:%d\n", binarySearch2(arr3, capacity, 5000));

    printf("floor=%d,ceil=%d\n", floor, ceil);

//    free(arr);
}

void testLinkedList(){
    PLinkedList pLinkedList = createLinkedList();
    for (int i = 0; i < 16; ++i) {
        addElement(pLinkedList, createLinkedNode(i));
    }

    addElement(pLinkedList, createLinkedNode(20));

    //反转链表
    reverseLinkedList(pLinkedList);

    removeElement(pLinkedList, 5);

//    for (int j = 0; j < 10; ++j) {
//        removeElement(pLinkedList, j);
//    }

    traverseLinkedList(pLinkedList);

    printf("\n%d\n", pLinkedList->size);
}

int main() {
//    PTNode ptNode = CreateStaticTree();
//    PreTraverseTree(ptNode);
//    printf("\capacity");
//    InTraverseTree(ptNode);
//    printf("\capacity");
//    PostTraverseTree(ptNode);

//    printCurrentTime();

//    sortTest();

//    srand(time(NULL));
//    int capacity = 10;
    //随机生成
//    int *arr = randomCreateArray(capacity, 0, 99);

//    radixSort(arr, capacity, 2);

//    bubbleSort(arr, capacity);
//    selectionSort(arr, capacity);

//    for (int i = 0; i < capacity; ++i) {
//        printf("%d\t", arr[i]);
//    }

//    testHeap();

    //    printf("%d\n", maxHeapCount(&maxHeap));
//    printf("%d", maxHeapIsEmpty(&maxHeap));

    testLinkedList();

    return 0;
}


void testHeap() {
    srand(time(NULL));

    int length = 31;

    //创建一个最大堆
    MaxHeap maxHeap = createMaxHeap(length);

    for (int i = 0; i < length; ++i) {
        insertMaxHeap(&maxHeap, rand() % length);
    }

//    traverseMaxHeap(&maxHeap);
//    printf("%d\n",maxHeap.data[0]);

    printTreeMaxHeap(&maxHeap);

    while (maxHeapIsEmpty(&maxHeap)) {
        printf("%d  ", extractMaxHeap(&maxHeap));
    }
}

/**
 * 打印当前时间
 */
void printCurrentTime() {
    char tmpbuf[80];
    time_t time1;
    time(&time1);
    strftime(tmpbuf, 80, "%Y-%m-%d %H:%M:%S\n", localtime(&time1));
    printf("%s\n", tmpbuf);
}