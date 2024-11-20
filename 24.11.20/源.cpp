#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param str string字符串 待判断的字符串
     * @return bool布尔型
     */
     /* 使用双指针O(n)解决 */
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
