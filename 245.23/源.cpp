#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//int main()
//{
//	srand((unsigned int)time(NULL));
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	return 0;
//}

void menu()
{
	printf("*******************\n");
	printf("***** 0. exit *****\n");//0�˳�
	printf("***** 1. play *****\n");//1��Ϸ
	printf("*******************\n");
}
void game()
{
	int num = rand() % 100 + 1;
	int guess = 0;
	while (1)
	{
		//printf("%d\n", num);
		printf("���������µ����֣�");
		scanf("%d", &guess);

		if (guess < num)
		{
			printf("����С��\n");
		}
		else if (guess > num)
		{
			printf("���´���\n");
		}
		else
		{
			printf("��ϲ�����¶���\n");
			break;
		}
	}

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("����������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("�����������������");
		}

	} while (input);
}