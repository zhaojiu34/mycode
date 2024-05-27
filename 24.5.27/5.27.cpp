#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//�ַ������һ�����ʵĳ���
//int main()
//{
//    string str;
//
//    while (getline(cin, str))//cin���޷������ո��\0�ģ����Զ�ȡʱҪ��getline
//    {
//        size_t pos = str.rfind(' ');
//        cout << str.size() - pos - 1 << endl;
//
//    }
//}


////���䲿�ַ�ת
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


//��ת�ַ����еĵ���
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