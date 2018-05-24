//
// Created by Administrator on 2017/11/11.
//

#ifndef TEST1_TREE_H
#define TEST1_TREE_H


typedef struct BTNode{
    int data;
    struct BTNode * pLchild;
    struct BTNode * pRchild;
} TNode,*PTNode;


/**
 * 创建一颗静态的二叉树
 * @return
 */
PTNode CreateStaticTree();

/**
 * 前序遍历二叉树
 * @param ptNode
 */
void PreTraverseTree(PTNode ptNode);

/**
 * 中序遍历二叉树
 * @param ptNode
 */
void InTraverseTree(PTNode ptNode);

/**
 * 后序遍历二叉树
 * @param ptNode
 */
void PostTraverseTree(PTNode ptNode);

#endif //TEST1_TREE_H
