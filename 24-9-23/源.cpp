#define _CRT_SECURE_NO_WARNINGS 1

int findPeakElement(int* nums, int numsLen)
{
    int i = 0;
    if (nums[0] > nums[1])
        return 0;
    for (i = 1; i < numsLen - 1; i++)
    {
        if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
            return i;
    }
    if (nums[numsLen - 1] > nums[numsLen - 2])
        return (numsLen - 1);
    return 0;
}