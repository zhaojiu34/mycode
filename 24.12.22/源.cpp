#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        //��ǰ������������Ϊ�յ����
        if (pre.empty() || vin.empty()) {
            return nullptr;
        }
        //�������ڵ�
        int root = pre[0];
        TreeNode* tree = new TreeNode(root);
        int length = pre.size();
        //�������Ϊ1��ֱ�ӷ��ظ��ڵ�
        if (length == 1) {
            return tree;
        }
        auto posi = find(vin.begin(), vin.end(), root);
        //�����������û�м�⵽���ڵ�
        if (posi == vin.end()) {
            return nullptr;
        }
        //�������������ĳ���
        int num_left = posi - vin.begin();
        int num_right = vin.end() - posi - 1;
        vector<int> left_pre;
        vector<int> left_vin;
        vector<int> right_pre;
        vector<int> right_vin;
        //������������Ӧ��������������
        left_pre.assign(pre.begin() + 1, pre.begin() + 1 + num_left);
        right_pre.assign(pre.end() - num_right, pre.end());
        left_vin.assign(vin.begin(), vin.begin() + num_left);
        right_vin.assign(vin.end() - num_right, vin.end());
        //�ݹ�Ľ�����������
        tree->left = reConstructBinaryTree(left_pre, left_vin);
        tree->right = reConstructBinaryTree(right_pre, right_vin);
        return tree;
    }
};
