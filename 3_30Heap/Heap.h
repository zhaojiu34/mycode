#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>


///�ѽṹ
//�ײ��߼�Ҳ������
typedef int HDataType;

typedef struct Heap
{
	HDataType* a;
	int size;
	int capacity;
}Heap;


//���µ���
void AdjustDown(HDataType* a, int parent, int n);
//���ϵ���
void AdjustUp(HDataType* a, int child);

//�ѵĹ���
void HeapCreat(Heap* hp, HDataType* a, int n);
//�ѵ�����
void HeapDestroy(Heap* hp);

//�ѵĲ���
void HeapInsert(Heap* hp, HDataType x);
//�ѵ�ɾ����ɾ���Ѷ�����
void HeapPop(Heap* hp);

//ȡ�Ѷ�����
HDataType HeapTop(Heap* hp);
//�ѵ����ݸ���
int HeapSize(Heap* hp);
//���Ƿ�Ϊ��
bool HeapEmpty(Heap* hp);

