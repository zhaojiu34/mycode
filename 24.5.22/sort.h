#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//打印数组
void PrintArry(int* a, int n);
//交换
void Swap(int* px, int* py);

//直接插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

// 选择排序
void SelectSort(int* a, int n);

// 堆排序
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现
// 快速排序hoare版本
void  PartSort1(int* a, int left, int right);
// 快速排序挖坑法
void PartSort2(int* a, int left, int right);
// 快速排序前后指针法
void  PartSort3(int* a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);



