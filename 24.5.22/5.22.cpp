#define _CRT_SECURE_NO_WARNINGS 1


#include "sort.h"
#include "stackQueue.h"
//����

//��ӡ����
void PrintArry(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}

//����
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//ֱ�Ӳ�������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > a[end + 1])
			{
				Swap(&a[end], &a[end + 1]);
				end--;
			}
			else
			{
				break;
			}
		}
	}

}

//ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > a[end + gap])
				{
					Swap(&a[end], &a[end + gap]);
					end -= gap;
				}
				else
				{
					break;
				}
			}
		}
	}
}

// ѡ������
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	//ÿѭ��һ���ҵ�������С
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			//����С
			if (a[i] < a[mini])
				mini = i;
			//�����
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);
		//������ֵ��begin�غ��ˣ���ô����һ�ν�����ԭ��maxi��λ�õ�ֵ�ܵ�mini��
		if (maxi == begin)
			maxi = mini;
		Swap(&a[end], &a[maxi]);

		begin++;
		end--;
	}


}


// ������
void AdjustDwon(int* a, int n, int root)
{
	int child = root * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			++child;

		if (a[child] > a[root])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
void HeapSort(int* a, int n)
{
	//����:�����򽨴��
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	//����
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}

}

// ð������
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 2; j++)
	{
		int flag = 0;
		//����
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}

}

// ��������ݹ�ʵ��
// ��������hoare�汾

//����ȡ��
int GetMid(int* a, int left, int right)
{
	int midi = (left + right) / 2;

	if (a[left] > a[midi])
	{
		if (a[midi] > a[right])
			return midi;

		//a[midi] ��С
		else if (a[left] < a[right])
			return left;

		else
			return right;
	}
	else//a[left] < a[midi]
	{
		if (a[midi] < a[right])
			return midi;

		//a[midi]���
		else if (a[left] > a[right])
			return left;

		else
			return right;
	}
}
void  PartSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	if (right - left + 1 < 10)
	{
		InsertSort(a, right - left + 1);
	}
	else
	{
		//����
		int begin = left, end = right;

		////���ѡȡkeyi
		//int randi = rand() % (right - left);
		//randi += left;
		//Swap(&a[randi], &a[left]);

		int midi = GetMid(a, left, right);
		Swap(&a[midi], &a[left]);

		int keyi = left;
		while (left < right)
		{
			//�ұ����ߣ���С
			//��Ҫ��֤�����鷶Χ��
			while (left < right && a[right] > a[keyi])
			{
				right--;
			}

			//����Ҵ�
			while (left < right && a[left] < a[keyi])
			{
				left++;
			}

			//��ʱleft���ڵ�λ�ô���key��right���ڵ�λ��С��key
			Swap(&a[left], &a[right]);
		}
		//��ʱleft��right����
		Swap(&a[keyi], &a[left]);
		keyi = left;

		//[begin,keyi -1] keyi [keyi+1,end]
		//�ݹ�
		PartSort1(a, begin, keyi - 1);
		PartSort1(a, keyi + 1, end);
	}
}
// ���������ڿӷ�
void PartSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	//����ȡ��
	int midi = GetMid(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int tmp = a[left];
	while (left < right)
	{
		//�����ұ�
		while (left < right && a[right] > tmp)
		{
			right--;
		}
		while (left < right && a[right] < tmp)
		{
			a[keyi] = a[right];
			keyi = right;
			left++;
			break;
		}

		//���
		while (left < right && a[left] < tmp)
		{
			left++;
		}
		while (left < right && a[left] > tmp)
		{
			a[keyi] = a[left];
			keyi = left;
			right--;
			break;
		}
	}
	a[keyi] = tmp;
	//PrintArry(a+begin,end-begin+1);

	//[begin, keyi-1] keyi [keyi+1, end]
	PartSort2(a, begin, keyi - 1);
	PartSort2(a, keyi + 1, end);

}
// ��������ǰ��ָ�뷨
void  PartSort3(int* a, int left, int right)
{
	if (left >= right)
		return;


	int begin = left, end = right;

	int midi = GetMid(a, left, right);
	Swap(&a[midi], &a[left]);

	//����
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;

	//[begin, keyi-1] keyi [end, keyi+1]
	PartSort3(a, begin, keyi - 1);
	PartSort3(a, keyi + 1, end);
}

// �������� �ǵݹ�ʵ��
// ʹ��ջ���Ƚ����
//���������� ������
//�룺�����䣬������
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		//������
		int begin = StackTop(&st);
		StackPop(&st);

		//������
		int end = StackTop(&st);
		StackPop(&st);

		int midi = GetMid(a, begin, end);
		Swap(&a[midi], &a[begin]);

		int keyi = begin;
		int prev = begin;
		int cur = begin + 1;
		while (cur <= end)
		{
			if (a[cur] < a[keyi] && ++prev != cur)
				Swap(&a[cur], &a[prev]);

			cur++;
		}
		Swap(&a[keyi], &a[prev]);
		keyi = prev;

		//[begin, keyi-1] keyi [keyi+1, end]
		if (begin < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}

		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}
	}

	StackDestroy(&st);
}