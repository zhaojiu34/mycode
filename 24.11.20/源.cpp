#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * @param str string�ַ��� ���жϵ��ַ���
     * @return bool������
     */
     /* ʹ��˫ָ��O(n)��� */
    bool judge(string str) {
        int n = str.size();
        if (n <= 1) {
            return true;
        }
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (str[left] == str[right]) {
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
