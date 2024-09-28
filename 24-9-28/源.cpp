#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* Node) {
        if (Node == nullptr) return;
        res.push_back(Node->val);
        dfs(Node->left);
        dfs(Node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        dfs(root);
        return res;
    }
};

