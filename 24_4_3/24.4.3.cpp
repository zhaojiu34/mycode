#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	char* a = (char*)calloc((m + 2) * (n + 2), sizeof(char));//我觉calloc更好用 因为自带初始化
	int i = 0;
	int j = 0;
	for (i = 1; i < m + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			scanf(" %c ", a + i * (n + 2) + j);//注意这里的读取一定要加上前后两个空格 来忽略对换行的读取 
			//我就是在这里调了半天
		}
	}
	int si = 0;
	int sj = 0;
	int num = 0;
	for (i = 1; i < m + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			if (*(a + i * (n + 2) + j) == '*')//如果为 * 则直接输出 *
				printf("*");
			else//如果不为 * 说明需要进行九宫格判断
			{
				num = 0;
				sj = j - 1;
				for (si = i - 1; si <= i + 1; si++)
				{
					for (sj = j - 1; sj <= j + 1; sj++)
					{
						if (*(a + si * (n + 2) + sj) == '*')
							num++;
					}
				}
				printf("%c", '0' + num);//其实这里是多余的 可以直接将 num 作整数输出
			}
		}
		printf("\n");
	}
	return 0;
}

#include<math.h>
int main() {
	int n, x;
	scanf("%d\n", &n);
	int a, max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		x = sqrt(a);
		if (a == pow(x, 2)) continue;
		else {
			if (a > max) max = a;
		}
	}
	printf("%d", max);
	return 0;
}


#include<iostream>
using namespace std;
#define ll long long
//返回x的二进制中的最后一个1的值，比如100000100，返回100
ll lowbit(ll x) {
	return x & (-x);
}


int main() {
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll res = 0;
		while (n) n -= lowbit(n), res++;
		cout << res << ' ';
		ll x = 1;
		while (res--) x *= 2;
		cout << x - 1 << endl;
	}

	return 0;
}
