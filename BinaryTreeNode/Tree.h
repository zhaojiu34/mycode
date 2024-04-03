#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//树的结构
typedef int BDataType;

typedef struct BinaryTreeNode
{
	BDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

}BTNode;

//前序遍历
void PerOrder(BTNode* root);
//中序遍历
void InOrder(BTNode* root);
//后序遍历
void PostOrder(BTNode* root);
//层序遍历
void LevelOrder(BTNode* root);

//二叉树节点个数
int BinaryTreeSize(BTNode* root);
//二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
//二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, int x);
//二叉树高度
int BinaryTreeDepth(BTNode* root);

//二叉树的销毁
void BinaryTreeNodeDestroy(BTNode* root);
//判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
//构建二叉树
BTNode* CreatTree(BDataType* a, int* pi);


