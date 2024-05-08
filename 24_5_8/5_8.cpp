#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdbool.h>

using namespace std;

//左子树之和
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int sumOfLeftLeaves(struct TreeNode* root)
{
	// write code here
	if (root == NULL)
		return 0;
	if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
	{
		return root->left->val;
	}
	return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
}



//另一棵树的子树
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
bool isSameTree(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	if (left->val != right->val)
		return false;
	return isSameTree(left->left, right->left)
		&& isSameTree(left->right, right->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (root == NULL)
		return false;
	if (root->val == subRoot->val && isSameTree(root, subRoot))
		return true;
	else
		return isSubtree(root->left, subRoot)
		|| isSubtree(root->right, subRoot);
}



//链表的回味结构
struct ListNode {
 int val;
 struct ListNode *next;
};

typedef struct ListNode ListNode;
ListNode* GetMid(ListNode* A)
{
	ListNode* slow = A;
	ListNode* fast = A;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
ListNode* Reserve(ListNode* A)
{
	ListNode* n1 = NULL;
	ListNode* n2 = A;
	ListNode* n3 = A->next;
	while (n2 != NULL)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
			n3 = n3->next;
	}
	return n1;
}
bool chkPalindrome(struct ListNode* A)
{
	// write code here
	ListNode* mid = GetMid(A);
	ListNode* cur = Reserve(mid);
	while (A != NULL && cur != NULL && cur != A)
	{
		if (A->val != cur->val)
			return false;
		A = A->next;
		cur = cur->next;
	}
	return true;
}


//归并排序，非递归
void Sort(int n, int* a, int* tmp)
{
	int gap = 1;
	while (gap < n)
	{
		for (int j = 0; j < n; j += 2 * gap)
		{
			int begin1 = j, end1 = begin1 + gap - 1;
			int begin2 = begin1 + gap, end2 = begin2 + gap - 1;
			int i = j;
			if (end1 >= n || begin2 >= n)
				break;
			if (end2 >= n)
				end2 = n - 1;

				while (begin1 <= end1 && begin2 <= end2)
				{
					if (a[begin1] <= a[begin2])
					{
						tmp[i++] = a[begin1++];
					}
					else {
						tmp[i++] = a[begin2++];
					}
				}
			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}
			memcpy(a + j, tmp + j, sizeof(int) * (end2 - j + 1));
		}
		gap *= 2;
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return -1;
	}
	Sort(n, a, tmp);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	free(tmp);
	tmp = NULL;
	return 0;
}