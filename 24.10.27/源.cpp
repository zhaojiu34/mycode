#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
    public int solve(string nums) {
        int[] codesNum = new int[nums.Length]; //状态数组，记录f(x)
        //初始条件：
        if (nums[0].ToString() != "0") {
            codesNum[0] = 1;
        }
        //从数组第2位枚举到最后一位：
        for (int i = 1; i < nums.Length; ++i) {
            //判断nums[i]是否不为0
            if (nums[i].ToString() != "0") {
                codesNum[i] += codesNum[i - 1];
            }
            //判断nums[i-1]与nums[i]的数字组合是否在[10,26]内
            int temp = int.Parse(nums[i - 1].ToString() + nums[i].ToString());
            if (temp >= 10 && temp <= 26) {
                if (i == 1) { //即f(2)，因为不存在f(0)，所以需要特殊处理：
                    codesNum[i] += 1;
                }
                else {
                    codesNum[i] += codesNum[i - 2];
                }
            }
        }
        return codesNum[nums.Length - 1];
    }
}
