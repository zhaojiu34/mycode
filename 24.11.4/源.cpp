#define _CRT_SECURE_NO_WARNINGS 1



class Solution {
public:
    // ���飬��ѡ����ʼλ�ã��ܺ�
    int dfs(vector<int>& nums, int idx, int sum = 0) {
        if (idx >= nums.size()) {
            return sum;
        }
        return max(
            dfs(nums, idx + 2, sum + nums[idx]), // ѡ��ǰ������Ҫ��һ��
            dfs(nums, idx + 1, sum) // ��ѡ��ǰ����һ����ѡλ�þ���idx+1
        );
    }
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param nums int����vector
     * @return int����
     */
    int rob(vector<int>& nums) {
        int ans = dfs(nums, 1); // ��һ��λ�ò�ѡ, ��ʣ�ಿ�ֵݹ�
        // ��һ��λ��ѡ���������һ��λ�ò�ѡ
        int first = nums[0];
        nums.pop_back();
        return max(ans, dfs(nums, 2, first));
    }
};
