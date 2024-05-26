#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <string>
#include<vector>

using namespace std;

////把字符串转为整数
//class Solution {
//public:
//    int myAtoi(string str) {
//        int len = str.size();
//
//        //空字符串
//        if (len == 0)
//            return 0;
//
//        int i = 0, flag = 1, bin = INT_MAX / 10;
//        int ret = 0, x = 0;
//
//        //读取空格
//        while (str[i] == ' ')
//        {
//            //字符串都为空格
//            if (i == len)
//                return 0;
//
//            i++;
//        }
//
//        //读正负号
//        if (str[i] == '-')
//        {
//            flag = -1;
//        }
//        if (str[i] == '+' || str[i] == '-')
//        {
//            i++;
//        }
//
//        //读完正负号以后，继续读下一位
//        for (int j = i; j <= len; j++)
//        {
//            //如果不是数字字符就停止读入
//            if (str[j] < '0' || str[j] >'9')
//            {
//                break;
//            }
//            else
//            {
//                x = str[j] - '0';
//
//                //越界
//                if (ret > bin || (ret == bin && str[j] > '7'))
//                    return flag == 1 ? INT_MAX : INT_MIN;
//
//                ret = ret * 10 + x;
//            }
//        }
//
//        return ret * flag;
//    }
//};


//字符串相加
//class Solution {
//public:
//    string addStrings(string num1, string num2)
//    {
//        int next = 0;//进制
//        int x = 0;
//
//        string str;
//
//        int len1 = num1.size() - 1, len2 = num2.size() - 1;
//        if (num1.size() == 0)
//            return num2;
//
//        if (num2.size() == 0)
//            return num1;
//
//        while (len1 >= 0 && len2 >= 0)
//        {
//            x = ((num1[len1] - '0') + (num2[len2] - '0') + next) % 10;
//
//            next = ((num1[len1] - '0') + (num2[len2] - '0') + next) / 10;
//            str += (x + '0');
//
//            len1--;
//            len2--;
//        }
//
//        while (len1 >= 0)
//        {
//            x = (num1[len1] - '0' + next) % 10;
//            next = (num1[len1] - '0' + next) / 10;
//            str += (x + '0');
//            len1--;
//        }
//        while (len2 >= 0)
//        {
//            x = (num2[len2] - '0' + next) % 10;
//            next = (num2[len2] - '0' + next) / 10;
//            str += (x + '0');
//            len2--;
//        }
//
//        if (next > 0)
//        {
//            str += (next + '0');
//        }
//
//        reverse(str.begin(), str.end());
//
//        return str;
//    }
//};

//翻转字符串
//class Solution {
//public:
//    void reverseString(vector<char>& s)
//    {
//        reverse(s.begin(), s.end());
//    }
//};

//找字符串中第一个唯一字符
//class Solution {
//public:
//    int firstUniqChar(string s)
//    {
//        int* hush = new int[26]{ 0 };
//
//        for (size_t i = 0; i < s.size(); i++)
//        {
//            hush[s[i] - 'a']++;
//        }
//
//        for (size_t i = 0; i < s.size(); i++)
//        {
//            if (hush[s[i] - 'a'] == 1)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};


//判断是不是回文字符串
//class Solution {
//public:
//    bool isPalindrome(string s)
//    {
//        if (s.size() == 0)
//            return true;
//
//        for (size_t i = 0; i < s.size(); i++)
//        {
//            if (s[i] >= 'A' && s[i] <= 'Z')
//                s[i] += 32;
//
//        }
//
//        int right = s.size() - 1, left = 0;
//
//        while (left <= right)
//        {
//            while (left < right && !isalnum(s[right]))
//                right--;
//            while (left < right && !isalnum(s[left]))
//                left++;
//
//            if (s[right] != s[left])
//                return false;
//            else
//            {
//                right--;
//                left++;
//            }
//        }
//
//
//        return true;
//    }
//};

//字符串相加
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int next = 0;//进制
        int x = 0;

        string str;

        int len1 = num1.size() - 1, len2 = num2.size() - 1;
        if (num1.size() == 0)
            return num2;

        if (num2.size() == 0)
            return num1;

        while (len1 >= 0 && len2 >= 0)
        {
            x = ((num1[len1] - '0') + (num2[len2] - '0') + next) % 10;

            next = ((num1[len1] - '0') + (num2[len2] - '0') + next) / 10;
            str += (x + '0');

            len1--;
            len2--;
        }

        while (len1 >= 0)
        {
            x = (num1[len1] - '0' + next) % 10;
            next = (num1[len1] - '0' + next) / 10;
            str += (x + '0');
            len1--;
        }
        while (len2 >= 0)
        {
            x = (num2[len2] - '0' + next) % 10;
            next = (num2[len2] - '0' + next) / 10;
            str += (x + '0');
            len2--;
        }

        if (next > 0)
        {
            str += (next + '0');
        }

        reverse(str.begin(), str.end());

        return str;
    }

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        string ret = "0";
        int len1 = num1.size(), len2 = num2.size();

        for (int i = len1 - 1; i >= 0; i--)
        {
            int a = num1[i] - '0';
            int next = 0;
            int x = 0;

            string s;

            for (int j = len1 - 1; j > i; j--)
            {
                s += '0';
            }

            for (int j = len2 - 1; j >= 0; j--)
            {
                x = ((num2[j] - '0') * a + next) % 10;

                next = ((num2[j] - '0') * a + next) / 10;

                s += (x + '0');
            }
            if (next > 0)
                s += (next + '0');

            reverse(s.begin(), s.end());

            ret = addStrings(ret, s);
        }

        return ret;
    }
};