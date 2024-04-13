#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqList()
{
	SqeList list;
	list.Init();

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.Print();
	///*list.PushFront(2);
	//list.PushFront(4);
	//list.PushFront(3);
	//list.Print();
	//list.PopFront();
	//list.PopFront();
	//list.Print();
	//list.PopBack();
	//list.PopBack();
	//list.Print();*/
	list.Insert(1, 10);
	list.Insert(3, 10);
	list.Insert(2, 10);
	list.Print();
	list.Erase(2);
	list.Erase(3);
	list.Erase(4);
	list.Print();

	cout << list.Find(10) << endl;
	cout << list.Find(100) << endl;
	cout << list.Find(5) << endl;

	list.Destroy();
}

int main()
{
	TestSeqList();

	return 0;
}