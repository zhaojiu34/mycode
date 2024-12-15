#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//�������ľ���
TreeNode* Mirror(TreeNode* pRoot) {
    if (pRoot == nullptr)
        return nullptr;

    TreeNode* left = pRoot->left;
    TreeNode* right = pRoot->right;

    pRoot->left = right;
    pRoot->right = left;

    Mirror(pRoot->right);
    Mirror(pRoot->left);

    return pRoot;
}

//��������������
int maxDepth(TreeNode* root)
{
    if (root == nullptr)
        return 0;


    int leftdepth = maxDepth(root->left);
    int rightdepth = maxDepth(root->right);

    return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
}

//�ж��ǲ���ƽ�������
bool IsBalanced_Solution(TreeNode* pRoot)
{
    if (pRoot == nullptr)
        return true;

    int left = maxDepth(pRoot->left);
    int right = maxDepth(pRoot->right);
    int num = abs(left - right);

    if (num > 1)
        return false;

    return IsBalanced_Solution(pRoot->left)
        && IsBalanced_Solution(pRoot->right);


}

//�������ĺ������
vector<int> postorderTraversal(TreeNode* root)
{
    static vector<int> vv;

    if (root == nullptr)
    {
        return vv;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    vv.push_back(root->val);

    return vv;
}

//��������ǰ�����
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        static vector<int> num;

        if (root == nullptr)
            return num;

        num.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return num;
    }
};


TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    //��������
    if (t1 == nullptr && t2 == nullptr)
        return nullptr;

    int num1 = 0, num2 = 0;
    TreeNode* root = nullptr;

    if (t1 != nullptr)
        num1 = t1->val;
    if (t2 != nullptr)
        num2 = t2->val;

    int num = num1 + num2;

    //��t1Ϊ���ص������ڴ˻��������t1�нڵ�͸ı�����ֵ�����û�о���ӽڵ�
    if (t1 == nullptr)
    {
        if (root != nullptr && root->left == nullptr)
        {
            TreeNode node(num);
            root->left = &node;
        }
        else if (root != nullptr && root->right == nullptr)
        {
            TreeNode node(num);
            root->right = &node;
        }
    }
    else {
        t1->val = num;
    }

    //����t1�ĸ��׽�
    root = t1;


    if (t1->left && t2->left)
        mergeTrees(t1->left, t2->left);
    else
    {
        if (t2->left)
        {
            t1->left = t2->left;
        }
    };


    if (t1->right && t2->right)
        mergeTrees(t1->right, t2->right);
    else
    {
        if (t2->right)
            t1->right = t2->right;
    };

    return t1;

}
int main()
{
    TreeNode node1(1);
    TreeNode node2(3);
    TreeNode node3(2);
    TreeNode node4(5);

    TreeNode node5(2);
    TreeNode node6(1);
    TreeNode node7(3);
    TreeNode node8(4);
    TreeNode node9(7);

    TreeNode* t1 = &node1;
    TreeNode* t2 = &node5;

    t1->right = &node3;
    t1->left = &node2;
    t1 = t1->right;
    t1->left = nullptr;
    t1->right = nullptr;
    t1 = &node2;
    t1->left = &node4;
    t1->right = nullptr;
    t1 = t1->left;
    t1->left = nullptr;
    t1->right = nullptr;

    t1 = &node1;
    mergeTrees(t1, t1);

    int a = 1;

	return 0;
}