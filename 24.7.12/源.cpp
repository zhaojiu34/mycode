#define _CRT_SECURE_NO_WARNINGS 1

#include "iostream"
using namespace std;
#include <iomanip> 


#include "iostream"
using namespace std;

int main() {

	int a = 16;

	cout << "�˽��� : " << oct << a << endl;
	cout << "ʮ���� : " << dec << a << endl;
	cout << "ʮ������ : " << hex << a << endl;

	// ����̨��ͣ , ��������������ִ��
	system("pause");

	return 0;
};




int main() {

	int a = 16;

	cout << showbase;

	cout << "�˽��� : " << oct << a << endl;
	cout << "ʮ���� : " << dec << a << endl;
	cout << "ʮ������ : " << hex << a << endl;

	// ����̨��ͣ , ��������������ִ��
	system("pause");

	return 0;
};





int main() {

	int a = 16;

	cout << showbase;

	cout << "�˽��� : " << setbase(8) << a << endl;
	cout << "ʮ���� : " << setbase(10) << a << endl;
	cout << "ʮ������ : " << setbase(16) << a << endl;

	// ����̨��ͣ , ��������������ִ��
	system("pause");

	return 0;
};
