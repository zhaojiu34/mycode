#define _CRT_SECURE_NO_WARNINGS 1


#include "sort.h"
#include "stackQueue.h"
//升序

//打印数组
void PrintArry(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}

//交换
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//直接插入排序
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

//希尔排序
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

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	//每循环一次找到最大和最小
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			//找最小
			if (a[i] < a[mini])
				mini = i;
			//找最大
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);
		//如果最大值和begin重合了，那么经过一次交换后，原本maxi的位置的值跑到mini了
		if (maxi == begin)
			maxi = mini;
		Swap(&a[end], &a[maxi]);

		begin++;
		end--;
	}


}


// 堆排序
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
	//建堆:排升序建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	//排序
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}

}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 2; j++)
	{
		int flag = 0;
		//单趟
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

// 快速排序递归实现
// 快速排序hoare版本

//三数取中
int GetMid(int* a, int left, int right)
{
	int midi = (left + right) / 2;

	if (a[left] > a[midi])
	{
		if (a[midi] > a[right])
			return midi;

		//a[midi] 最小
		else if (a[left] < a[right])
			return left;

		else
			return right;
	}
	else//a[left] < a[midi]
	{
		if (a[midi] < a[right])
			return midi;

		//a[midi]最大
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
		//单趟
		int begin = left, end = right;

		////随机选取keyi
		//int randi = rand() % (right - left);
		//randi += left;
		//Swap(&a[randi], &a[left]);

		int midi = GetMid(a, left, right);
		Swap(&a[midi], &a[left]);

		int keyi = left;
		while (left < right)
		{
			//右边先走，找小
			//还要保证在数组范围内
			while (left < right && a[right] > a[keyi])
			{
				right--;
			}

			//左边找大
			while (left < right && a[left] < a[keyi])
			{
				left++;
			}

			//此时left所在的位置大于key，right所在的位置小于key
			Swap(&a[left], &a[right]);
		}
		//此时left和right相遇
		Swap(&a[keyi], &a[left]);
		keyi = left;

		//[begin,keyi -1] keyi [keyi+1,end]
		//递归
		PartSort1(a, begin, keyi - 1);
		PartSort1(a, keyi + 1, end);
	}
}
// 快速排序挖坑法
void PartSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	//三数取中
	int midi = GetMid(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int tmp = a[left];
	while (left < right)
	{
		//先走右边
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

		//左边
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
// 快速排序前后指针法
void  PartSort3(int* a, int left, int right)
{
	if (left >= right)
		return;


	int begin = left, end = right;

	int midi = GetMid(a, left, right);
	Swap(&a[midi], &a[left]);

	//单趟
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

// 快速排序 非递归实现
// 使用栈，先进后出
//出：左区间 右区间
//入：右区间，左区间
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		//左区间
		int begin = StackTop(&st);
		StackPop(&st);

		//右区间
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