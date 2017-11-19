//
// Created by Administrator on 2017/11/12.
//

#ifndef TEST1_TESTSORTHEALPER_H
#define TEST1_TESTSORTHEALPER_H

/**
 * 随机生成数组
 * @param length
 * @param start
 * @param end
 * @return
 */
int *randomCreateArray(int length, int start, int end);

/**
 * 复制一个数组
 * @param length
 * @param start
 * @param end
 * @return
 */
int *copyArray(int *arr, int length);

/**
 * 遍历数组
 * @param arr
 * @param length
 */
void traverseArray(int *arr, int length);


/**
 * 测试排序时间
 * @param name
 * @param sort
 */
void testSortTime(char *name, void(*sort)(int *arr, int length), int *arr, int length);


/**
 * 验证一个数组是否是有序的
 * @param arr
 * @param length
 */
int isSorted(int *arr, int length);


/**
 * 创建一个有序的数组
 * @param length
 * @return
 */
int * createOrderlyArray(int length);

#endif //TEST1_TESTSORTHEALPER_H
