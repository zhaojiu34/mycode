#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void recursion(int left, int right, string temp, vector<string>& res, int n) {
        if (left == n && right == n) { //�������Ŷ������ˣ��ͼ�����
            res.push_back(temp);
            return;
        }
        if (left < n) //ʹ��һ��������
            recursion(left + 1, right, temp + "(", res, n);
        if (right < n && left > right) //ʹ�������Ÿ�����������������
            recursion(left, right + 1, temp + ")", res, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res; //��¼���
        string temp; //��¼ÿ����װ���ַ���
        recursion(0, 0, temp, res, n); //�ݹ�
        return res;
    }
};
