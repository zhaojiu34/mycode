#define _CRT_SECURE_NO_WARNINGS 1
#include "Snack.h"

void test()
{
	int ch = 0;
	srand((unsigned int)time(NULL));//根据时间产生随机值

	do
	{
		//创建贪吃蛇
		Snack snack = { 0 };
		//游戏主逻辑
		GameStart(&snack);
		GameRun(&snack);
		GameEnd(&snack);

		SetPos(20, 15);
		printf("再来一局吗？（Y/N）:");
		ch = getchar();
		getchar();//清理'\n'
	} while (ch == 'Y' || ch == 'y');
	SetPos(0, 27);

}
int main()
{
	//修改当前地区为本地模式，为了支持中文宽字符的打印
	setlocale(LC_ALL, "");
	//代码测试
	test();
	return 0;
}