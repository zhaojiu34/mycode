#define _CRT_SECURE_NO_WARNINGS 1


 struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 };

class Solution {
public:
    /**
     *
     * @param t1 TreeNode��
     * @param t2 TreeNode��
     * @return TreeNode��
     */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // write code here
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        TreeNode* ret = new TreeNode(t1->val + t2->val);
        ret->left = mergeTrees(t1->left, t2->left);
        ret->right = mergeTrees(t1->right, t2->right);

        return ret;
    }
};
