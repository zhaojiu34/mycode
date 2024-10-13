#define _CRT_SECURE_NO_WARNINGS 1

int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    return helper(root, o1, o2)->val;
}

TreeNode* helper(TreeNode* root, int o1, int o2) {
    if (root == NULL) return NULL;           //�ݹ�߽�
    if (root->val == o1 || root->val == o2) return root;

    //�ֽ�Ϊ�������������������������������,���ú������
    TreeNode* left_have = helper(root->left, o1, o2);
    TreeNode* right_have = helper(root->right, o1, o2);
    if (left_have && right_have) return root;        //�������������򷵻�root
    else return left_have ? left_have : right_have;     //���������������һ��������û�õ�������򷵻صõ������������.
}
