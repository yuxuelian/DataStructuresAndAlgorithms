//
// Created by Administrator on 2018/5/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

PLinkNode createLinkedNode(int data) {
    PLinkNode pLinkNode = malloc(sizeof(LinkNode));
    pLinkNode->data = data;
    pLinkNode->next = NULL;
    return pLinkNode;
}

PLinkedList createLinkedList() {
    PLinkedList pLinkedList = (PLinkedList) malloc(sizeof(LinkedList));
    pLinkedList->head = NULL;
    pLinkedList->size = 0;
    return pLinkedList;
}

/**
 * 向链表中插入一个元素,采用头部插入的方式
 * @param pLinkedList
 * @param pLinkNode
 */
void addElement(PLinkedList pLinkedList, PLinkNode pLinkNode) {
    //将头部指向下一个结点的值保存起来
    PLinkNode temp = pLinkedList->head;
    pLinkedList->head = pLinkNode;
    pLinkNode->next = temp;
    //链表大小加一
    pLinkedList->size++;
}

/**
 * 遍历
 * @param pLinkedList
 */
void traverseLinkedList(PLinkedList pLinkedList) {
    PLinkNode temp = pLinkedList->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/**
 * 指定  key  删除链表中的结点
 * @param pLinkedList
 * @param pLinkNode
 */
void removeElement(PLinkedList pLinkedList, int key) {
    if (pLinkedList->head == NULL) {
        return;
    }

    PLinkNode temp;
    //要移除的是第一个元素
    if (pLinkedList->head->data == key) {
        temp = pLinkedList->head;
        pLinkedList->head = pLinkedList->head->next;
        free(temp);
        pLinkedList->size--;
        return;
    }

    temp = pLinkedList->head;
    do {
        //在这儿可以直接跳过第一个元素  因为上面已经判断了第一号元素
        if (temp->next != NULL && temp->next->data == key) {
            PLinkNode _t = temp->next;
            temp->next = temp->next->next;
            free(_t);
            pLinkedList->size--;
            return;
        }
    } while ((temp = temp->next) != NULL);
}

/**
 * 真正反转链表的方法
 * 这里使用的是递归的方式
 * @param pLinkNode
 * @return
 */
//static PLinkNode inversion(PLinkNode head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//
//    PLinkNode newHead = reverse(head->next);
//    head->next->next = head;
//    head->next = NULL;
//    return newHead;
//}

/**
 * 非递归的方式反转链表
 * @param head
 * @return
 */
static PLinkNode inversion(PLinkNode head) {
    //newHead指向已经反转的新链表的头
    PLinkNode newHead = NULL;
    //指向当前还没有反转的链表的头
    PLinkNode curHead = head;

    while (curHead != NULL) {
        //取出当前还没有反转的链表的第一个结点中指向下一个结点的指针,并存储到临时变量中去
        PLinkNode next = curHead->next;
        //将新链表的头指针赋值给还没有反转的链表的头结点的next指针,即完成反转操作
        curHead->next = newHead;
        //newHead向前移动1
        newHead = curHead;
        //curHead也向前移动1
        curHead = next;
    }

    return newHead;
}

/**
 * 反转链表
 * @param pLinkedList
 */
void reverseLinkedList(PLinkedList pLinkedList) {
    pLinkedList->head = inversion(pLinkedList->head);
}


