#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"

void TestTree()
{
	int a[] = { 1,2,3,0,0,4,5,0,0,6,0,0 };
	int i = 0;
	Tree tree;
	tree.Creat(a,&i);

}

int main()
{
	TestTree();

	return 0;
}