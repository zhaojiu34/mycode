#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param nums int����vector
     * @param target int����
     * @return int����
     */
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            return -1;
        }
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
        // write code here
    }
};
