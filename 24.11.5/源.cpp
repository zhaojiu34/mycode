#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s)
    {
        //双指针
        int left = 0, right = 0;
        int len = s.size();
        if (len == 1 || len == 0)
            return len;

        int ret = 0;

        while (left < len && right < len)
        {
            //判断[left,right]区间内有没有重复的，如果有就让left++,没有就让right--
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

        int hash[128] = { 0 };//哈希表
        while (right < len)
        {
            //进窗口
            hash[s[right]]++;

            //判断是否有重复字符
            while (hash[s[right]] > 1)
            {
                hash[s[left++]]--;//出窗口，然后left++
            }

            //更新结果
            ret = max(ret, right - left + 1);

            right++;//让right继续向后走
        }

        return ret;

    }
};

int main()
{
    Solution().lengthOfLongestSubstring("abcabcbb");

    return 0;
}