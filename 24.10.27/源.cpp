#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
    public int solve(string nums) {
        int[] codesNum = new int[nums.Length]; //״̬���飬��¼f(x)
        //��ʼ������
        if (nums[0].ToString() != "0") {
            codesNum[0] = 1;
        }
        //�������2λö�ٵ����һλ��
        for (int i = 1; i < nums.Length; ++i) {
            //�ж�nums[i]�Ƿ�Ϊ0
            if (nums[i].ToString() != "0") {
                codesNum[i] += codesNum[i - 1];
            }
            //�ж�nums[i-1]��nums[i]����������Ƿ���[10,26]��
            int temp = int.Parse(nums[i - 1].ToString() + nums[i].ToString());
            if (temp >= 10 && temp <= 26) {
                if (i == 1) { //��f(2)����Ϊ������f(0)��������Ҫ���⴦��
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
