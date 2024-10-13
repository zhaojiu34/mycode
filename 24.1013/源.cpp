#define _CRT_SECURE_NO_WARNINGS 1

int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    return helper(root, o1, o2)->val;
}

TreeNode* helper(TreeNode* root, int o1, int o2) {
    if (root == NULL) return NULL;           //递归边界
    if (root->val == o1 || root->val == o2) return root;

    //分解为求左子树的子问题和右子树的子问题,采用后序遍历
    TreeNode* left_have = helper(root->left, o1, o2);
    TreeNode* right_have = helper(root->right, o1, o2);
    if (left_have && right_have) return root;        //左右子树都有则返回root
    else return left_have ? left_have : right_have;     //如果左右子树中有一个子问题没得到结果，则返回得到结果的子问题.
}
