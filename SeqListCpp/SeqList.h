#pragma once
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

typedef int SDataType;

class SqeList
{
public:
	//��ʼ��
	void Init(int n = 4);
	//����
	void Destroy();
	//��ӡ
	void Print();
	//����
	void CheckCapacity();

	//ͷ���Ĳ���ɾ�� β���Ĳ����ɾ��
	void PushBack(SDataType x);
	void PopBack();
	void PushFront(SDataType x);
	void PopFront();

	//ָ��λ�ò���ɾ��
	void Insert(int pos, SDataType x);
	void Erase(int pos);

	//����
	int Find(SDataType x);

private:
	SDataType* _a;
	int _capacity;
	int _size;
};