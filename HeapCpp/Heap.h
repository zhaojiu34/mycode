#pragma once
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

typedef int HDataType;

class Heap
{
public:
	//����
	void Swap(int* px, int* py);

	//���µ���
	void AdjustDown(int parent, int n);

	//���ϵ���
	void AdjustUp(int child);

	//������
	void Creat(HDataType* a, int n);

	//���ٶ�
	void Destroy();

	//����в�������
	void Push(HDataType x);

	//ɾ������
	void Pop();

	//���Ѷ�������
	HDataType top();
	//�ѵ����ݸ���
	int Size();

	//���Ƿ�Ϊ��
	bool Empty();

private:
	HDataType* _a;
	int _size;
	int _capacity;
};
