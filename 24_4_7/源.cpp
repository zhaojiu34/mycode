#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"


//��ӡ����
void PrintArry(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// ����
void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}


//��������
//ֱ�Ӳ�������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//����,[0,end]Ϊ�������飬��a[end+1]��������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;
	}

}

//ϣ������
//Ԥ���򣺽ӽ�����
//ֱ������gap == 1����������
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;//���һ����1
		//����ÿһ��ĵ�һ���������Ժ���������
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}

}

//ѡ������
//ѡ������
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
				mini = i;

			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);

		//���maxi��bgein�غϣ�ǰ��begin��mini����ֵ�Ժ�������Ӧ����mini�±�
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		end--;
		begin++;
	}

}
//���µ���
void AdjustDown(int* a, int parent, int n)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//������
void HeapSort(int* a, int n)
{
	//����:��������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}

	//����
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		AdjustDown(a, 0, end);
		end--;
	}
}

//��������
//ð������
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
	}

}
//����ȡ��
int GetMid(int* a, int left, int right)
{
	int midi = (left + right) / 2;

	if (a[left] > a[midi])
	{
		if (a[midi] > a[right])
			return midi;

		//a[midi] < a[right],a[midi]ֵ��С
		else if (a[left] > a[right])
			return right;

		else
			return left;
	}
	else//a[left] < a[midi]
	{
		if (a[midi] < a[right])
			return midi;
		//a[midi] > a[right] ,a[midi]���
		else if (a[right] > a[left])
			return right;

		else
			return left;
	}

}
//��������
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	int midi = GetMid(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	int prev = left;
	int cur = left + 1;

	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		cur++;
	}

	Swap(&a[keyi], &a[prev]);
	keyi = prev;

	//[beign , keyi-1] keyi [keyi+1, end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);

}

//�鲢����:�ݹ��
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
		return;

	int mid = (left + right) / 2;

	//�ֽ�
	//[begin, mid] [mid+1,end]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	//�����������飬����С�Ľ���β��
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//left��һ���Ǵ�0��ʼ�����Կ���ʱ��ע�⿽��λ��
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));

}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);
}

//�ǵݹ�
void MergeNonR(int* a, int left, int right, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	int gap = 1;

	while (gap < n)
	{
		//����������
		for (int j = 0; j < n; j += gap * 2)
		{
			//printf("gap:%d -> ", gap);
			//����
			int begin1 = j, end1 = begin1 + gap - 1;
			int begin2 = begin1 + gap, end2 = begin2 + gap - 1;
			int i = j;
			//ע��end1,begin2,end2�Ƿ��Խ�磬begin1 == j�϶�����Խ��

			if (end1 >= n || begin2 >= n)
				break;

			if (end2 >= n)
				end2 = n - 1;
			//printf("[%d ,%d] [%d ,%d]\n", begin1, end1, begin2, end2);

			//�����������飬���бȽϣ�С��β��
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
					tmp[i++] = a[begin1++];
				else
					tmp[i++] = a[begin2++];
			}

			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}

			//�����������ʼλ�úͿ�������
			memcpy(a + j, tmp + j, sizeof(int) * (end2 - j + 1));
		}

		gap *= 2;
	}


}

//��������
void CountSort(int* a, int n)
{
	int i = 0;
	int min = a[0], max = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	int* cont = (int*)malloc(sizeof(int) * (max - min + 1));
	if (cont == NULL)
	{
		perror("malloc malloc");
		return;
	}

	memset(cont, 0, (max - min + 1) * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		cont[a[i] - min]++;
	}

	int range = max - min + 1;
	int j = 0;
	for (i = 0; i < range; i++)
	{
		while (cont[i]--)
		{
			a[j++] = i + min;
		}
	}

}

