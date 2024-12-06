#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
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
