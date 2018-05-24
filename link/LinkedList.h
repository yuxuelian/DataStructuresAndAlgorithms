//
// Created by Administrator on 2018/5/23.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * 表示一个链表结点
 */
typedef struct _LNode {
    int data;
    struct _LNode *next;
} LinkNode, *PLinkNode;

/**
 * 创建结点
 * @param data
 * @return
 */
PLinkNode createLinkedNode(int data);

/**
 * 表示一个链表
 */
typedef struct _LinkedList {
    //链表的头指针
    PLinkNode head;
    //链表的大小
    int size;
} LinkedList, *PLinkedList;

/**
 * 创建List
 * @return
 */
PLinkedList createLinkedList();

/**
 * 添加指定结点
 * @param pLinkedList
 * @param pLinkNode
 */
void addElement(PLinkedList pLinkedList, PLinkNode pLinkNode);

/**
 * 删除指定结点
 * @param pLinkedList
 * @param pLinkNode
 */
void removeElement(PLinkedList pLinkedList, int key);

/**
 * 遍历
 * @param pLinkedList
 */
void traverseLinkedList(PLinkedList pLinkedList);

/**
 * 反转链表
 * @param pLinkedList
 */
void reverseLinkedList(PLinkedList pLinkedList);

#endif //C_TESTPROJECT_LINKEDLIST_H
