#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s)
    {
        //˫ָ��
        int left = 0, right = 0;
        int len = s.size();
        if (len == 1 || len == 0)
            return len;

        int ret = 0;

        while (left < len && right < len)
        {
            //�ж�[left,right]��������û���ظ��ģ�����о���left++,û�о���right--
            int flag = 1;
            for (size_t i = left; i <= right; i++)
            {
                for (size_t j = i + 1; j <= right; j++)
                {
                    if (i != j && s[i] == s[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                {
                    break;
                }
            }

            if (flag == 1)
            {
                right++;
            }
            else
            {
                left++;
            }

            ret = max(ret, right - left);
        }

        return ret;

    }
};



class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0;
        int ret = 0;
        int len = s.size();

        int hash[128] = { 0 };//��ϣ��
        while (right < len)
        {
            //������
            hash[s[right]]++;

            //�ж��Ƿ����ظ��ַ�
            while (hash[s[right]] > 1)
            {
                hash[s[left++]]--;//�����ڣ�Ȼ��left++
            }

            //���½��
            ret = max(ret, right - left + 1);

            right++;//��right���������
        }

        return ret;

    }
};

int main()
{
    Solution().lengthOfLongestSubstring("abcabcbb");

    return 0;
}