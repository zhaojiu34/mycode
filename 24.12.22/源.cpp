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
        //当前序或者中序遍历为空的情况
        if (pre.empty() || vin.empty()) {
            return nullptr;
        }
        //建立根节点
        int root = pre[0];
        TreeNode* tree = new TreeNode(root);
        int length = pre.size();
        //如果长度为1，直接返回根节点
        if (length == 1) {
            return tree;
        }
        auto posi = find(vin.begin(), vin.end(), root);
        //如果在中序中没有检测到根节点
        if (posi == vin.end()) {
            return nullptr;
        }
        //计算左右子树的长度
        int num_left = posi - vin.begin();
        int num_right = vin.end() - posi - 1;
        vector<int> left_pre;
        vector<int> left_vin;
        vector<int> right_pre;
        vector<int> right_vin;
        //找左右子树对应的先序和中序遍历
        left_pre.assign(pre.begin() + 1, pre.begin() + 1 + num_left);
        right_pre.assign(pre.end() - num_right, pre.end());
        left_vin.assign(vin.begin(), vin.begin() + num_left);
        right_vin.assign(vin.end() - num_right, vin.end());
        //递归的建立左右子树
        tree->left = reConstructBinaryTree(left_pre, left_vin);
        tree->right = reConstructBinaryTree(right_pre, right_vin);
        return tree;
    }
};
