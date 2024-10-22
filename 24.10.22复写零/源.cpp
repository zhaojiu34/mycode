#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;


//��д�㣺˼·���Ƚ�vectorת��Ϊlist������룬Ȼ����ת��Ϊvector
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

    //�ҳ����һ��Ҫ��д����
    while (dest < (int)arr.size()-1)
    {
        //���ж�curλ�ã�����dest�߼���
        if (arr[cur] != 0)
        {
            dest++;
        }
        else
        {
            dest += 2;
        }

        //Ȼ���ж�dest�Ƿ�Խ�磬����cur�Ƿ����
        if (dest < arr.size()-1)
        {
            cur++;
        }
    }

    //�Ӻ���ǰ����

    //����Խ������
    if (dest >= arr.size())
    {
        arr[arr.size() - 1] = 0;
        dest -= 2;
        cur--;
    }

    //�Ӻ���ǰ��������
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
    //1.�ҵ�Ҫ��д�����һ������
    while (cur < n)
    {
        if (arr[cur]) dest++;
        else dest += 2;

        if (dest >= n - 1)break;
        cur++;
    }

    //����Խ������
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