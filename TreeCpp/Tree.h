#pragma once
#include <iostream>
using namespace std;

#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

typedef int TDataType;

typedef struct TreeNode
{
	TDataType val;
	struct TreeNode* left;
	struct TreeNode* right;
}TNode;

class Tree
{

public:
	//´´½¨Ê÷
	TNode* Creat(int* a,int* pi);

private :
	TNode* root;
};
