#define _CRT_SECURE_NO_WARNINGS 1

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        // write code here
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> Q;
        Q.push(root);
        int flag = 0;

        while (!Q.empty()) {
            int cur_size = Q.size();
            for (int i = 0; i < cur_size; i++) {
                auto node = Q.front();
                Q.pop();
                if (flag == 1 && node != nullptr) {
                    return false;
                }
                if (node == nullptr) {
                    flag = 1;
                }
                else {
                    Q.push(node->left);
                    Q.push(node->right);
                }
            }
        }
        return true;

    }

};
