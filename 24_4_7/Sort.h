#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//打印数组
void PrintArry(int* a, int n);
// 交换
void Swap(int* pa, int* pb);

//插入排序
//直接插入排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);

//选择排序
//选择排序
void SelectSort(int* a, int n);
//向下调整
void AdjustDown(int* a, int parent, int n);
//堆排序
void HeapSort(int* a, int n);

//交换排序
//冒泡排序
void BubbleSort(int* a, int n);
//三数取中
int GetMid(int* a, int left, int right);
//快速排序
void QuickSort(int* a, int left, int right);

//归并排序,递归版
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);

//非递归版
void MergeNonR(int* a, int left, int right, int n);

//非比较排序
//计数排序
void CountSort(int* a, int n);

