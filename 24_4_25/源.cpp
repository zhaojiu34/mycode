#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include <iosream>

#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ʼ��
void SqeList::Init(int n)
{
	_a = (SDataType*)malloc(sizeof(SDataType) * n);

	if (_a == nullptr)
	{
		perror("malloc fail");
		return;
	}

	_size = 0;
	_capacity = n;
}

//����
void SqeList::Destroy()
{

	if (_a)
	{
		free(_a);
		_a = nullptr;
	}

	_size = _capacity = 0;

}

//��ӡ
void SqeList::Print()
{
	for (int i = 0; i < _size; i++)
	{
		printf("%d ", _a[i]);
	}
	printf("\n");
}

//����
void SqeList::CheckCapacity()
{
	if (_size == _capacity)
	{
		int newCapacity = _capacity * 2;
		SDataType* tmp = (SDataType*)realloc(_a, sizeof(SDataType) * newCapacity);

		if (tmp == nullptr)
		{
			perror("realloc  fail");
			return;
		}

		_a = tmp;
		_capacity = newCapacity;
	}
}

//ͷ���Ĳ���ɾ�� β���Ĳ����ɾ��
void SqeList::PushBack(SDataType x)
{
	//����ռ䲻��������
	if (_size == _capacity)
	{
		CheckCapacity();
	}

	_a[_size++] = x;
}
void SqeList::PopBack()
{
	assert(_size != 0);
	_size--;
}

void SqeList::PushFront(SDataType x)
{
	//����ռ䲻��������
	if (_size == _capacity)
	{
		CheckCapacity();
	}

	//���Ųһλ
	for (int i = _size - 1; i >= 0; i--)
	{
		_a[i + 1] = _a[i];
	}
	_a[0] = x;
	_size++;

}
void SqeList::PopFront()
{
	assert(_size != 0);

	for (int i = 0; i < _size - 1; i++)
	{
		_a[i] = _a[i + 1];
	}

	_size--;
}

//ָ��λ��֮ǰ����/ɾ��
void SqeList::Insert(int pos, SDataType x)
{
	//����ռ䲻��������
	if (_size == _capacity)
	{
		CheckCapacity();
	}

	for (int i = _size - 1; i >= pos; i--)
	{
		_a[i + 1] = _a[i];
	}

	_a[pos] = x;
	_size++;
}
void SqeList::Erase(int pos)
{
	for (int i = pos; i < _size - 1; i++)
	{
		_a[i] = _a[i + 1];
	}
	_size--;
}

//����:�ҵ��˷����±꣬û�ҵ�����-1
int SqeList::Find(SDataType x)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		if (_a[i] == x)
		{
			return i;
		}
	}

	return -1;
}