#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//����������
BTNode* CreatTree(BDataType* a, int* pi)
{

	if (a[(*pi)] == 0)
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	root->val = a[(*pi)++];
	root->left = CreatTree(a, pi);
	root->right = CreatTree(a, pi);

	return root;
}


//ǰ�����
void PerOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->val);
	PerOrder(root->left);
	PerOrder(root->right);

}

//�������
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);

}
//�������
void PostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);

}
//�������
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			printf("%d ", front->val);
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			printf("N ");
		}
	}

	printf("\n");

}
//�������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
//������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
//��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, int x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;

	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
		return right;

	return NULL;

}
//�������߶�
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int left = BinaryTreeDepth(root->left);
	int right = BinaryTreeDepth(root->right);

	return left > right ? left + 1 : right + 1;
}

//������������
void BinaryTreeNodeDestroy(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeNodeDestroy(root->left);
	BinaryTreeNodeDestroy(root->right);
	free(root);
}
//�ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(root))
	{
		BTNode* front = QueueFront(root);
		QueuePop(&q);

		if (front)
			break;

		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}

	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
			return 0;
	}
	return 1;
}






