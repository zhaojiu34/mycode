#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//�¶�ת��
//class Solution {
//public:
//    vector<double> convertTemperature(double celsius)
//    {
//        vector<double> vv;
//
//        vv.push_back(celsius + 273.15);
//        vv.push_back(celsius * 1.80 + 32);
//
//        return vv;
//    }
//};

////��Сż����
//class Solution {
//public:
//    int smallestEvenMultiple(int n)
//    {
//        if (n % 2 == 0)
//            return n;
//
//        else
//            return n * 2;
//
//    }
//};


////�жϸ��ڵ��Ƿ������������֮��
//struct TreeNode 
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//    
//};
//
//class Solution {
//public:
//    bool checkTree(TreeNode* root)
//    {
//        if (root->val == root->left->val + root->right->val)
//            return true;
//
//        else
//            return false;
//    }
//};

//����������
class Solution {
public:
    int xorOperation(int n, int start)
    {
        int* nums = new int[n] {0};

        for (size_t i = 0; i < n; i++)
        {
            nums[i] = start + i * 2;
        }

        int next = 0;
        for (size_t i = 0; i < n; i++)
        {
            next ^= nums[i];
        }

        delete[] nums;

        return next;
    }
};

int main()
{

}