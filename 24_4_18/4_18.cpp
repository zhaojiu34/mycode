#define _CRT_SECURE_NO_WARNINGS 1
#include <iosream>

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* left;//左孩子
	struct BinTreeNode* right;//右孩子
	BTDataType val;
}BTNode;

//建立节点
BTNode* CreatNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->left = newnode->right = NULL;
	newnode->val = x;
	return newnode;
}

//手搓一棵树
BTNode* CreatTree()
{
	BTNode* n1 = CreatNode(1);
	BTNode* n2 = CreatNode(2);
	BTNode* n3 = CreatNode(3);
	BTNode* n4 = CreatNode(4);
	BTNode* n5 = CreatNode(5);
	BTNode* n6 = CreatNode(6);

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	return n1;
}

//前序:根，左子树，右子树
void PerOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->val);
	PerOrder(root->left);
	PerOrder(root->right);
}

//中序：左子树，根，右子树
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);

}

//后序
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);

}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->right) + TreeSize(root->left) + 1;

}
int main()
{
	BTNode* root = CreatTree();
	PerOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n%d ", TreeSize(root));
	return 0;
}