#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//��ӡ����
void PrintArry(int* a, int n);
// ����
void Swap(int* pa, int* pb);

//��������
//ֱ�Ӳ�������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);

//ѡ������
//ѡ������
void SelectSort(int* a, int n);
//���µ���
void AdjustDown(int* a, int parent, int n);
//������
void HeapSort(int* a, int n);

//��������
//ð������
void BubbleSort(int* a, int n);
//����ȡ��
int GetMid(int* a, int left, int right);
//��������
void QuickSort(int* a, int left, int right);

//�鲢����,�ݹ��
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);

//�ǵݹ��
void MergeNonR(int* a, int left, int right,int n);

//�ǱȽ�����
//��������
void CountSort(int* a, int n);
