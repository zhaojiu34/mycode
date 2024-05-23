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
	printf("***** 0. exit *****\n");//0退出
	printf("***** 1. play *****\n");//1游戏
	printf("*******************\n");
}
void game()
{
	int num = rand() % 100 + 1;
	int guess = 0;
	while (1)
	{
		//printf("%d\n", num);
		printf("请输入您猜的数字：");
		scanf("%d", &guess);

		if (guess < num)
		{
			printf("您猜小了\n");
		}
		else if (guess > num)
		{
			printf("您猜大了\n");
		}
		else
		{
			printf("恭喜您，猜对了\n");
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
		printf("请输入您的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误，请重新输入");
		}

	} while (input);
}