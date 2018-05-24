//
// Created by Administrator on 2017/11/11.
//
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

PTNode CreateStaticTree() {

    PTNode ptNodeA = (PTNode) malloc(sizeof(TNode));
    PTNode ptNodeB = (PTNode) malloc(sizeof(TNode));
    PTNode ptNodeC = (PTNode) malloc(sizeof(TNode));
    PTNode ptNodeD = (PTNode) malloc(sizeof(TNode));
    PTNode ptNodeE = (PTNode) malloc(sizeof(TNode));
    PTNode ptNodeF = (PTNode) malloc(sizeof(TNode));
    PTNode ptNodeG = (PTNode) malloc(sizeof(TNode));

    ptNodeA->data = 1;
    ptNodeA->pLchild = ptNodeB;
    ptNodeA->pRchild = ptNodeC;

    ptNodeB->data = 2;
    ptNodeB->pLchild = ptNodeD;
    ptNodeB->pRchild = ptNodeE;

    ptNodeC->data = 3;
    ptNodeC->pLchild = ptNodeF;
    ptNodeC->pRchild = ptNodeG;

    ptNodeD->data = 4;
    ptNodeE->data = 5;
    ptNodeF->data = 6;
    ptNodeG->data = 7;

    ptNodeD->pLchild = ptNodeD->pRchild = NULL;
    ptNodeE->pLchild = ptNodeE->pRchild = NULL;
    ptNodeF->pLchild = ptNodeF->pRchild = NULL;
    ptNodeG->pLchild = ptNodeG->pRchild = NULL;

    return ptNodeA;
}

void PreTraverseTree(PTNode ptNode) {
    if (ptNode != NULL) {
        printf("%c\t", ptNode->data);
        PreTraverseTree(ptNode->pLchild);
        PreTraverseTree(ptNode->pRchild);
    }
}

void InTraverseTree(PTNode ptNode) {
    if (ptNode != NULL) {
        PreTraverseTree(ptNode->pLchild);
        printf("%c\t", ptNode->data);
        PreTraverseTree(ptNode->pRchild);
    }
}

void PostTraverseTree(PTNode ptNode) {
    if (ptNode != NULL) {
        PreTraverseTree(ptNode->pLchild);
        PreTraverseTree(ptNode->pRchild);
        printf("%c\t", ptNode->data);
    }
}

/**
 * 对二叉树进行层序遍历
 * @param ptNode
 */
void levelTree(PTNode ptNode) {

//    LinkQUEUE linkQUEUE = createQueue();


}