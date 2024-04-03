#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTreeNode.h"

void test()
{
	//ABD##E#H##CF##G##
	char s[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int i = 0;
	//创建树
	BTNode* root = BinaryTreeCreate(s, sizeof(s) / sizeof(char), &i);

	//前序遍历
	BinaryTreePrevOrder(root);
	printf("\n");

	//后序遍历
	BinaryTreePostOrder(root);
	printf("\n");

	//中序遍历
	BinaryTreeInOrder(root);
	printf("\n");

	//叶子节点的个数
	int leafsize = BinaryTreeLeafSize(root);
	printf("BinaryTreeLeafSize : %d\n", leafsize);

	//节点个数
	int size = BinaryTreeSize(root);
	printf("BinaryTreeSize : %d\n", size);

	//第k层节点个数
	int ksize = BinaryTreeLevelKSize(root, 3);
	printf("BinaryTreeLevelKSize : %d\n", ksize);


	BinaryTreeLevelOrder(root);
	int ret = BinaryTreeComplete(root);
	if (ret)
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");

	BinaryTreeDestory(&root);
}

int main()
{
	test();
	return 0;
}
