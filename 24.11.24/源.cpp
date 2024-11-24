#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>


using namespace std;


 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode* tmp;  //空间复杂度为1
    void recursion(TreeNode*& root)
    {
        if (root == NULL)
        {
            return;  //如果遇到的是空结点，就直接返回
        }
        //左右节点的地址进行交换
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        //进行递归
            recursion(root->left);
        recursion(root->right);
    }
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        //将根节点带入，最终返回的是根节点的的值，函数传递的是引用
        recursion(pRoot);
        return pRoot;
    }
};