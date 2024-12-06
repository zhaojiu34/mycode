#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < array.size(); i++) {
            mp[array[i]]++;
        }
        for (int i = 0; i < array.size(); i++) {
            if (mp[array[i]] == 1) {
                ans.push_back(array[i]);
            }
        }
        if (ans[0] > ans[1]) {
            swap(ans[0], ans[1]);
        }
        return ans;
    }
};
