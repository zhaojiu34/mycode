#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//BTNode* CreatNode(int x)
//{
//	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//	if (root == NULL)
//	{
//		perror("malloc fail");
//		return NULL;
//	}
//
//	root->val = x;
//	root->left = root->right = NULL;
//	return root;
//}
//
//BTNode* Tree()
//{
//	BTNode* n1 = CreatNode(1);
//	BTNode* n2 = CreatNode(2);
//	BTNode* n3 = CreatNode(3);
//	BTNode* n4 = CreatNode(4);
//	BTNode* n5 = CreatNode(5);
//	BTNode* n6 = CreatNode(6);
//	BTNode* n7 = CreatNode(7);
//
//	n1->left = n2;
//	n2->right = n4;
//	n2->left = n3;
//	n4->left = n5;
//	n4->right = n6;
//	n6->left = n7;
//
//	return n1;
//}
//void TestTree()
//{
//	int a[] = { 1,2,3,0,0,4,5,0,0,6,7,0,0,0,0 };
//	int i = 0;
//
//	BTNode* root = CreatTree(a, &i);
//	PerOrder(root);
//	printf("\n");
//
//	InOrder(root);
//	printf("\n");
//
//	PostOrder(root);
//	printf("\n");
//
//	int Size = BinaryTreeSize(root);
//	printf("BinaryTreeSize(叶子节点) : %d\n", Size);
//
//	int ksize = BinaryTreeLevelKSize(root,3);
//	printf("BinaryTreeLevelKSize（第k层节点） : %d\n", ksize);
//
//	int n0 = BinaryTreeLeafSize(root);
//	printf("BinaryTreeLeafSize（叶子节点） : %d\n", n0);
//
//	int height = BinaryTreeDepth(root);
//	printf("BinaryTreeDepth（树的高度） : %d\n", height);
//
//	BTNode* ret = BinaryTreeFind(root, 3);
//	if (ret)
//		printf("找到了，值是: %d\n", ret->val);
//	else
//		printf("没找到\n");
//
//	BinaryTreeNodeDestroy(root);
//
//}

void Test()
{
	int a[] = { 1,2,3,0,0,4,5,0,0,6,7,0,0,0,0 };
	int i = 0;

	BTNode* root = CreatTree(a, &i);

	LevelOrder(root);
	printf("\n");

	if (BinaryTreeComplete(root))
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");

}

int main()
{
	//TestTree();

	Test();
	return 0;
}