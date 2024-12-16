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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param p int整型
     * @param q int整型
     * @return int整型
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
