#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"

//´´½¨Ê÷
TNode* Tree::Creat(int* a,int *pi)
{
	if (a[*pi] == 0)
	{
		*pi++;
		return NULL;
	}

	root->val = a[*pi]++;
	root->left = Creat(a, pi);
	root->right = Creat(a, pi);

	return root;
}

