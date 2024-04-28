#include "Date.h"

void Test()
{
	Date d1(2024, 4, 28);
	Date d2(2022, 5, 1);

	//cout << (d1 < d2) << endl;
	/*d1 -= 2000;
	cout << d1;*/

	int n = d1 - d2;
	cout << n;
}

int main()
{
	Test();

	return 0;
}