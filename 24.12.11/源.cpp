#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    void inorder(vector<int>& res, TreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(res, root->left);//�ȱ�����ߵĽڵ�
        res.push_back(root->val);//�ٱ����м�Ľڵ�
        inorder(res, root->right);//�������ұߵĽڵ�

    }
    vector<int> inorderTraversal(TreeNode* root) {
        // write code here
        vector<int>res;
        inorder(res, root);
        return res;

    }
};