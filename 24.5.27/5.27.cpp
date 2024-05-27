#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//字符串最后一个单词的长度
//int main()
//{
//    string str;
//
//    while (getline(cin, str))//cin是无法读到空格和\0的，所以读取时要用getline
//    {
//        size_t pos = str.rfind(' ');
//        cout << str.size() - pos - 1 << endl;
//
//    }
//}


////区间部分翻转
//class Solution {
//public:
//    string reverseStr(string s, int k)
//    {
//        int len = s.size();
//        if (len < k)
//        {
//            reverse(s.begin(), s.end());
//            return s;
//        }
//
//        if (len < 2 * k)
//        {
//            reverse(s.begin(), s.begin() + k);
//            return s;
//        }
//
//        int end = 0;
//        while (end + 2 * k <= len)
//        {
//            reverse(s.begin() + end, s.begin() + end + k);
//
//            end += 2 * k;
//        }
//
//        if (len - end < k)
//        {
//            reverse(s.begin() + end, s.end());
//        }
//        else if (len - end >= k && len - end < 2 * k)
//        {
//            reverse(s.begin() + end, s.begin() + end + k);
//        }
//
//        return s;
//
//    }
//};


//翻转字符串中的单词
class Solution {
public:
    string reverseWords(string s)
    {
        int left = 0, right = 0, len = s.size();

        while (right < len)
        {
            while (right < len && s[right] != ' ')
                right++;

            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
            right++;
        }
        reverse(s.begin() + left, s.end());

        return s;
    }
};