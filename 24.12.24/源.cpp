#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//顺序表区间元素删除
//int main()
//{
//	int n = 0;
//	int a[1000];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//
//	int x = 0, y = 0;
//	scanf("%d %d", &x, &y);
//
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] < x || a[i] > y)
//		{
//			printf("%d ", a[i]);
//		}
//	}
//
//	return 0;
//}

//一元多项式的求导
int main()
{
	int a = 0, b = 0;
	int flag = 0;

	//scanf成功读取到两个数，返回值为二
	while (scanf("%d %d", &a, &b) == 2 && a * b)
	{
		if (flag)
			printf(" ");
		else
			flag = 1;

		printf("%d %d", a * b, b - 1);
	}
	
	//没有输入
	if (!flag)
		printf("0 0");

	return 0;
}