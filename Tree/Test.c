#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTreeNode.h"

void test()
{
	//ABD##E#H##CF##G##
	char s[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int i = 0;
	//������
	BTNode* root = BinaryTreeCreate(s, sizeof(s) / sizeof(char), &i);

	//ǰ�����
	BinaryTreePrevOrder(root);
	printf("\n");

	//�������
	BinaryTreePostOrder(root);
	printf("\n");

	//�������
	BinaryTreeInOrder(root);
	printf("\n");

	//Ҷ�ӽڵ�ĸ���
	int leafsize = BinaryTreeLeafSize(root);
	printf("BinaryTreeLeafSize : %d\n", leafsize);

	//�ڵ����
	int size = BinaryTreeSize(root);
	printf("BinaryTreeSize : %d\n", size);

	//��k��ڵ����
	int ksize = BinaryTreeLevelKSize(root, 3);
	printf("BinaryTreeLevelKSize : %d\n", ksize);


	BinaryTreeLevelOrder(root);
	int ret = BinaryTreeComplete(root);
	if (ret)
		printf("����ȫ������\n");
	else
		printf("������ȫ������\n");

	BinaryTreeDestory(&root);
}

int main()
{
	test();
	return 0;
}
