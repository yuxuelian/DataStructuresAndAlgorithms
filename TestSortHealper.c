//
// Created by Administrator on 2017/11/12.
//

#include "TestSortHealper.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>

/**
 * ����һ��ָ�����ȵ������,����ұյ�����
 * @param length
 * @param start
 * @param end
 * @return
 */
int *randomCreateArray(int length, int start, int end) {
    //�������������
    srand(time(NULL));
    assert(start < end);
    int *arr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % (end - start + 1) + start;
    }
    return arr;
}

/**
 * ��������
 * @param arr
 * @param length
 * @return
 */
int *copyArray(int *arr, int length) {
    int *a1 = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        a1[i] = arr[i];
    }
    return a1;
}

/**
 * ��������
 * @param arr
 * @param length
 */
void traverseArray(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}


/**
 * ����һ�������㷨
 * @param name
 * @param sort
 * @param arr
 * @param length
 */
void testSortTime(
        char *name,
        //����ĺ���ָ��
        void(*sort)(int *arr, int length),

        int *arr,
        int length) {

    clock_t startTime = clock();

    //ִ�к�������
    sort(arr, length);

    clock_t endTime = clock();

    assert(isSorted(arr, length));

    printf("%s����ִ��ʱ��:%lf\n", name, ((double) (endTime - startTime)) / CLOCKS_PER_SEC);
}

/**
 * �ж�һ�������Ƿ�����
 * @param arr
 * @param length
 * @return
 */
int isSorted(int *arr, int length) {
    for (int i = 0; i < length - 1; ++i) {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

/**
 * ����һ�����������
 * @param length
 * @return
 */
int *createOrderlyArray(int length) {
    int *arr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        arr[i] = i;
    }
    return arr;
}






