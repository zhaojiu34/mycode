#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>


using namespace std;


 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pRoot TreeNode��
     * @return TreeNode��
     */
    TreeNode* tmp;  //�ռ临�Ӷ�Ϊ1
    void recursion(TreeNode*& root)
    {
        if (root == NULL)
        {
            return;  //����������ǿս�㣬��ֱ�ӷ���
        }
        //���ҽڵ�ĵ�ַ���н���
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        //���еݹ�
            recursion(root->left);
        recursion(root->right);
    }
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        //�����ڵ���룬���շ��ص��Ǹ��ڵ�ĵ�ֵ���������ݵ�������
        recursion(pRoot);
        return pRoot;
    }
};