#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;


//复写零：思路：先将vector转换为list方便插入，然后再转化为vector
//void duplicateZeros1(vector<int>& arr)
//{
//    list<int> a(arr.begin(), arr.end());
//    auto it = a.begin();
//    while (it != a.end())
//    {
//        if (*it == 0)
//        {
//            it = a.insert(++it, 0);
//            it++;
//        }
//        else
//        {
//            it++;
//        }
//    }
//
//    int len = arr.size();
//    vector<int> ls(a.begin(), a.end());
//    for (size_t i = 0; i < len; i++)
//    {
//        arr[i] = ls[i];
//    }
//
//}



void duplicateZeros2(vector<int>& arr)
{
    int dest = -1, cur = 0;

    //找出最后一个要复写的数
    while (dest < (int)arr.size()-1)
    {
        //先判断cur位置，决定dest走几步
        if (arr[cur] != 0)
        {
            dest++;
        }
        else
        {
            dest += 2;
        }

        //然后判断dest是否越界，决定cur是否继续
        if (dest < arr.size()-1)
        {
            cur++;
        }
    }

    //从后往前遍历

    //处理越界问题
    if (dest >= arr.size())
    {
        arr[arr.size() - 1] = 0;
        dest -= 2;
        cur--;
    }

    //从后往前遍历数组
    while (cur >= 0)
    {
        if (arr[cur] == 0)
        {
            arr[dest] = 0;
            arr[dest - 1] = 0;
            dest -= 2;
            cur--;
        }
        else
        {
            arr[dest] = arr[cur];
            cur--;
            dest--;
        }
    }
}


void duplicateZeros3(vector<int>& arr)
{
    int dest = -1, cur = 0, n = arr.size();
    //1.找到要复写的最后一个数字
    while (cur < n)
    {
        if (arr[cur]) dest++;
        else dest += 2;

        if (dest >= n - 1)break;
        cur++;
    }

    //处理越界问题
    if (dest == n)
    {
        arr[n - 1] = 0;
        dest -= 2;
        cur--;
    }

    while (cur >= 0)
    {
        if (arr[cur])
        {
            arr[dest--] = arr[cur--];
        }

        else
        {
            arr[dest--] = 0;
            arr[dest--] = 0;
            cur--;
        }
    }

}
int main()
{
    vector<int> arr{ 0,1,7,6,0,2,0,7 };
    duplicateZeros2(arr);

	return 0;
}