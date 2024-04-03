#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTreeNode.h"
#include "Queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[(*pi)] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("BinaryTreeCreate:malloc fail");
		return;
	}

	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);

	return root;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;

	////使用的是前序
	//(*root)->_data = 0;
	//BTNode* left = (*root)->_left;
	//BTNode* right = (*root)->_right;

	//(*root)->_left = (*root)->_right = NULL;

	//使用后序
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory((&(*root)->_right));
	free(*root);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->_left)
		+ BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	
	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) 
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->_data == x)
		return root;

	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left)
		return left;

	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right)
		return right;

	return NULL;
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode*  front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			printf("# ");
		//如果不是空，就把下一层带入
		else
		{
			printf("%c ", front->_data);
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		
	}
	printf("\n");
	QueueDestroy(&q);
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);

		if(front != NULL)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			break;
		}
		QueuePop(&q);
	}
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return 0;
		}
		else
		{
			QueuePop(&q);
		}
	}
	QueueDestroy(&q);
	return 1;
}