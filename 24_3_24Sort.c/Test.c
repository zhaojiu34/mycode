#define _CRT_SECURE_NO_WARNINGS 1
#include "sorth.h"

void TestInsertSort()
{
	int a[] = { 5,6,7,9,8,3,4,2,1 };

	PrintArry(a, sizeof(a) / sizeof(int));

	InsertSort(a, sizeof(a) / sizeof(int));

	PrintArry(a, sizeof(a) / sizeof(int));

}

void TestShellSort()
{
	int a[] = { 5,6,7,9,8,3,4,2,1 };

	PrintArry(a, sizeof(a) / sizeof(int));

	ShellSort(a, sizeof(a) / sizeof(int));

	PrintArry(a, sizeof(a) / sizeof(int));

}

void TestSelectSort()
{
	int a[] = { 5,6,7,9,8,3,4,2,1 };

	PrintArry(a, sizeof(a) / sizeof(int));

	SelectSort(a, sizeof(a) / sizeof(int));

	PrintArry(a, sizeof(a) / sizeof(int));

}

void TestHeapSort()
{
	int a[] = { 5,6,7,9,8,3,4,2,1 };

	PrintArry(a, sizeof(a) / sizeof(int));

	HeapSort(a, sizeof(a) / sizeof(int));

	PrintArry(a, sizeof(a) / sizeof(int));

}

void TestBubbleSort()
{
	int a[] = { 5,6,7,9,8,3,4,2,1 };

	PrintArry(a, sizeof(a) / sizeof(int));

	BubbleSort(a, sizeof(a) / sizeof(int));

	PrintArry(a, sizeof(a) / sizeof(int));

}

void TestQuickSort()
{
	int a[] = { 5,6,7,9,8,3,4,2,1 };

	PrintArry(a, sizeof(a) / sizeof(int));

	QuickSort(a,0, sizeof(a) / sizeof(int)-1);

	PrintArry(a, sizeof(a) / sizeof(int));

}

void TestMargeSort()
{
	int a[] = { 1,9,6,7,5,8,4,3,15,20,49,64,2};

	PrintArry(a, sizeof(a) / sizeof(int));

	MergeSort(a, 0, sizeof(a) / sizeof(int) - 1, sizeof(a) / sizeof(int));

	PrintArry(a, sizeof(a) / sizeof(int));

}

void TestContSort()
{
	int a[] = { 5,6,7,9,8,3,4,2,1 };

	PrintArry(a, sizeof(a) / sizeof(int));

	CountSort(a, sizeof(a) / sizeof(int));

	PrintArry(a, sizeof(a) / sizeof(int));

}


void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		//a1[i] = i;

		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}


	int begin7 = clock();
	//CountSort(a7, N);
	int end7 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	//PrintArray(a4, N);

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("CountSort:%d\n", end7 - begin7);

	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}


int main()
{
	//TestInsertSort();
	//TestShellSort();

	//TestSelectSort();
	//TestHeapSort();
	
	//TestBubbleSort();
	//TestQuickSort();

	//TestMargeSort();
	//TestContSort();
	

	TestOP();
	return 0;
}