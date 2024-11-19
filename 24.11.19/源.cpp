#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
#include <string>

using namespace std;

class Solution {
public:
    int editDistance(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1, 0)); //dp[i][j]��ʾ��str1[i]��str2[j]Ϊֹ���Ӵ���Ҫ�ı༭����
        for (int i = 1; i <= n1; i++) //��ʼ���߽�
            dp[i][0] = dp[i - 1][0] + 1;
        for (int i = 1; i <= n2; i++)
            dp[0][i] = dp[0][i - 1] + 1;
        for (int i = 1; i <= n1; i++) //������һ���ַ�����ÿ��λ��
            for (int j = 1; j <= n2; j++) { //��Ӧ�ڶ����ַ���ÿ��λ��
                if (str1[i - 1] == str2[j - 1]) //�����ַ���ͬ���˴����ñ༭
                    dp[i][j] = dp[i - 1][j - 1]; //ֱ�ӵ��ڶ���ǰһ���ľ���
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; //ѡȡ��С�ľ�����ϴ˴��༭����1
            }
        return dp[n1][n2];
    }
};
