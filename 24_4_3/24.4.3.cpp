#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	char* a = (char*)calloc((m + 2) * (n + 2), sizeof(char));//�Ҿ�calloc������ ��Ϊ�Դ���ʼ��
	int i = 0;
	int j = 0;
	for (i = 1; i < m + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			scanf(" %c ", a + i * (n + 2) + j);//ע������Ķ�ȡһ��Ҫ����ǰ�������ո� �����ԶԻ��еĶ�ȡ 
			//�Ҿ�����������˰���
		}
	}
	int si = 0;
	int sj = 0;
	int num = 0;
	for (i = 1; i < m + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			if (*(a + i * (n + 2) + j) == '*')//���Ϊ * ��ֱ����� *
				printf("*");
			else//�����Ϊ * ˵����Ҫ���оŹ����ж�
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
				printf("%c", '0' + num);//��ʵ�����Ƕ���� ����ֱ�ӽ� num ���������
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
//����x�Ķ������е����һ��1��ֵ������100000100������100
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
