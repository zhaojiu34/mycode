#define _CRT_SECURE_NO_WARNINGS 1

#include "iostream"
using namespace std;
#include <iomanip> 


#include "iostream"
using namespace std;

int main() {

	int a = 16;

	cout << "八进制 : " << oct << a << endl;
	cout << "十进制 : " << dec << a << endl;
	cout << "十六进制 : " << hex << a << endl;

	// 控制台暂停 , 按任意键继续向后执行
	system("pause");

	return 0;
};




int main() {

	int a = 16;

	cout << showbase;

	cout << "八进制 : " << oct << a << endl;
	cout << "十进制 : " << dec << a << endl;
	cout << "十六进制 : " << hex << a << endl;

	// 控制台暂停 , 按任意键继续向后执行
	system("pause");

	return 0;
};





int main() {

	int a = 16;

	cout << showbase;

	cout << "八进制 : " << setbase(8) << a << endl;
	cout << "十进制 : " << setbase(10) << a << endl;
	cout << "十六进制 : " << setbase(16) << a << endl;

	// 控制台暂停 , 按任意键继续向后执行
	system("pause");

	return 0;
};
