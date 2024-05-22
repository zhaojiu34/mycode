#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//��ӡ����
void PrintArry(int* a, int n);
//����
void Swap(int* px, int* py);

//ֱ�Ӳ�������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
void  PartSort1(int* a, int left, int right);
// ���������ڿӷ�
void PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
void  PartSort3(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);



