#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    /**
     * ��֤IP��ַ
     * @param IP string�ַ��� һ��IP��ַ�ַ���
     * @return string�ַ���
     */
    vector<string> split(string s, char spliter) {
        vector<string> res;
        int i;
        while ((i = s.find(spliter)) && i != s.npos) {
            res.push_back(s.substr(0, i));
            s = s.substr(i + 1);
        }
        res.push_back(s);
        return res;
    }
    bool isIPv4(string IP) {
        vector<string> s = split(IP, '.');
        if (s.size() != 4) return false;
        for (int i = 0; i < 4; i++) {
            if (s[i].size() == 0) return false; //����ȱʡ
            else if (s[i].size() > 3 || s[i][0] == '0') return false;
            for (int j = 0; j < s[i].size(); j++) {
                if (s[i][j] < '0' || s[i][j] > '9') return false;
            }
            int num = stoi(s[i]);
            if (num < 0 || num > 255) return false;
        }
        return true;
    }
    bool isIPv6(string IP) {
        vector<string> s = split(IP, ':');
        if (s.size() != 8) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i].size() == 0 || s[i].size() > 4) return false; //����ȱʡ
            for (int j = 0; j < s[i].size(); j++) {
                if (!((s[i][j] >= 'a' && s[i][j] <= 'f') || ((s[i][j] >= 'A' && s[i][j] <= 'F')) || (s[i][j] >= '0' && s[i][j] <= '9'))) {
                    return false;
                }
            }
        }
        return true;
    }

    string solve(string IP) {
        // write code here
        if (isIPv4(IP)) return "IPv4";
        else if (isIPv6(IP)) return "IPv6";
        else return "Neither";
    }
};
