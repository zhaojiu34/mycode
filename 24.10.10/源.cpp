#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    vector solve(vector& xianxu, vector& zhongxu) {
        // write code here
        vector res = viewRight(xianxu, zhongxu, 0, zhongxu.size() - 1, 0);
        return res;
    }
    /**
     * 最开始的想法是：重构二叉树+层序遍历
     * 再仔细一想发现不用, 解法如下：
     *   使用递归找到左右子树的右视图，遍历右子树的右视图添加到结果中，
     *   之后使用相同的索引，若此时左子树还有值则继续添加至结果
     *
     * 需要注意的是如何寻找右子树的根节点，根据前序遍历结果，可知xianxu[0]必然是根节点，
     * 那么之后的右子树根节点如何寻找呢？右子树的根节点index = 此时的根节点index+做左子树的节点个数,
     * 这样皆可以在前序中找到右子树的根节点了。
     *
     * 这道题与LC199 Binary Tree Right Side View很像。
     *
     *
     */
    vector viewRight(vector& xianxu, vector& zhongxu, int start, int end, int ridx)
    {
        if (start > end) return vector();
        int root = xianxu[ridx];
        vector res;
        res.push_back(root);
        int idx = find(
            zhongxu.begin() + start, zhongxu.begin() + end, root) - zhongxu.begin();
        vector left;
        if (idx > start)
            left = viewRight(xianxu, zhongxu, start, idx - 1, ridx + 1);
        vector right;
        if (idx < end)
            right = viewRight(xianxu, zhongxu, idx + 1, end, ridx + idx - start + 1);
        int i = 0;
        while (i < right.size())
        {
            res.push_back(right[i]);
            i++;
        }
        while (i < left.size())
        {
            res.push_back(left[i]);
            i++;
        }
        return res;
    }
};