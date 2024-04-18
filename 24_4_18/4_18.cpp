#define _CRT_SECURE_NO_WARNINGS 1
#include <iosream>

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* left;//����
	struct BinTreeNode* right;//�Һ���
	BTDataType val;
}BTNode;

//�����ڵ�
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

//�ִ�һ����
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

//ǰ��:������������������
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

//����������������������
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

//����
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