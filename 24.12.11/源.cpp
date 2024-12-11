#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    void inorder(vector<int>& res, TreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(res, root->left);//先遍历左边的节点
        res.push_back(root->val);//再遍历中间的节点
        inorder(res, root->right);//最后遍历右边的节点

    }
    vector<int> inorderTraversal(TreeNode* root) {
        // write code here
        vector<int>res;
        inorder(res, root);
        return res;

    }
};