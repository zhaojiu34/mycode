#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"


//打印数组
void PrintArry(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// 交换
void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}


//插入排序
//直接插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//单趟,[0,end]为有序数组，将a[end+1]插入数组
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

//希尔排序
//预排序：接近有序
//直接排序：gap == 1，插入排序
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;//最后一次是1
		//先排每一组的第一个，排完以后依次类推
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

//选择排序
//选择排序
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

		//如果maxi和bgein重合，前面begin和mini换了值以后，最大的数应该在mini下标
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		end--;
		begin++;
	}

}
//向下调整
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

//堆排序
void HeapSort(int* a, int n)
{
	//建堆:升序见大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}

	//排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		AdjustDown(a, 0, end);
		end--;
	}
}

//交换排序
//冒泡排序
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
//三数取中
int GetMid(int* a, int left, int right)
{
	int midi = (left + right) / 2;

	if (a[left] > a[midi])
	{
		if (a[midi] > a[right])
			return midi;

		//a[midi] < a[right],a[midi]值最小
		else if (a[left] > a[right])
			return right;

		else
			return left;
	}
	else//a[left] < a[midi]
	{
		if (a[midi] < a[right])
			return midi;
		//a[midi] > a[right] ,a[midi]最大
		else if (a[right] > a[left])
			return right;

		else
			return left;
	}

}
//快速排序
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

//归并排序:递归版
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
		return;

	int mid = (left + right) / 2;

	//分解
	//[begin, mid] [mid+1,end]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	//两组有序数组，数字小的进行尾插
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

	//left不一定是从0开始，所以拷贝时，注意拷贝位置
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

//非递归
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
		//排完所有组
		for (int j = 0; j < n; j += gap * 2)
		{
			//printf("gap:%d -> ", gap);
			//单趟
			int begin1 = j, end1 = begin1 + gap - 1;
			int begin2 = begin1 + gap, end2 = begin2 + gap - 1;
			int i = j;
			//注意end1,begin2,end2是否会越界，begin1 == j肯定不会越界

			if (end1 >= n || begin2 >= n)
				break;

			if (end2 >= n)
				end2 = n - 1;
			//printf("[%d ,%d] [%d ,%d]\n", begin1, end1, begin2, end2);

			//两组有序数组，进行比较，小的尾插
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

			//拷贝数组的起始位置和拷贝长度
			memcpy(a + j, tmp + j, sizeof(int) * (end2 - j + 1));
		}

		gap *= 2;
	}


}

//计数排序
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

