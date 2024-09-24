#define _CRT_SECURE_NO_WARNINGS 1

int minNumberInRotateArray(int* nums, int numsLen)
{
    // write code here
    int min = 10005;
    int i = 0;
    for (i = 0; i < numsLen; i++)
    {
        if (nums[i] < min)
            min = nums[i];
    }
    return min;
}