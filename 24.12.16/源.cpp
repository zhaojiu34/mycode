#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
};

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param root TreeNode��
     * @param p int����
     * @param q int����
     * @return int����
     */
    int ret = 0;
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        TreeNode* cur = root;
        while (1) {
            if (p < cur->val && q < cur->val)
                cur = cur->left;
            else if (p > cur->val && q > cur->val)
                cur = cur->right;
            else break;
        }
        return cur->val;
    }
};
