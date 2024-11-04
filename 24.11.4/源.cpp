#define _CRT_SECURE_NO_WARNINGS 1



class Solution {
public:
    // 数组，可选的起始位置，总和
    int dfs(vector<int>& nums, int idx, int sum = 0) {
        if (idx >= nums.size()) {
            return sum;
        }
        return max(
            dfs(nums, idx + 2, sum + nums[idx]), // 选当前，则需要隔一个
            dfs(nums, idx + 1, sum) // 不选当前，下一个可选位置就是idx+1
        );
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int rob(vector<int>& nums) {
        int ans = dfs(nums, 1); // 第一个位置不选, 对剩余部分递归
        // 第一个位置选，但是最后一个位置不选
        int first = nums[0];
        nums.pop_back();
        return max(ans, dfs(nums, 2, first));
    }
};
