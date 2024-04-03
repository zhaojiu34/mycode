#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//���Ľṹ
typedef int BDataType;

typedef struct BinaryTreeNode
{
	BDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

}BTNode;

//ǰ�����
void PerOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);
//�������
void LevelOrder(BTNode* root);

//�������ڵ����
int BinaryTreeSize(BTNode* root);
//������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
//��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, int x);
//�������߶�
int BinaryTreeDepth(BTNode* root);

//������������
void BinaryTreeNodeDestroy(BTNode* root);
//�ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
//����������
BTNode* CreatTree(BDataType* a, int* pi);


