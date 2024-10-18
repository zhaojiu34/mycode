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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param root TreeNode��
     * @return bool������
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
