#define _CRT_SECURE_NO_WARNINGS 1
#include "Snack.h"

void test()
{
	int ch = 0;
	srand((unsigned int)time(NULL));//����ʱ��������ֵ

	do
	{
		//����̰����
		Snack snack = { 0 };
		//��Ϸ���߼�
		GameStart(&snack);
		GameRun(&snack);
		GameEnd(&snack);

		SetPos(20, 15);
		printf("����һ���𣿣�Y/N��:");
		ch = getchar();
		getchar();//����'\n'
	} while (ch == 'Y' || ch == 'y');
	SetPos(0, 27);

}
int main()
{
	//�޸ĵ�ǰ����Ϊ����ģʽ��Ϊ��֧�����Ŀ��ַ��Ĵ�ӡ
	setlocale(LC_ALL, "");
	//�������
	test();
	return 0;
}