#define _CRT_SECURE_NO_WARNINGS 1
#include "Snack.h"

//设置光标位置
void SetPos(short x, short y)
{
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	//获取标准输出的句柄
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置标准输出上光标的位置为pos
	SetConsoleCursorPosition(hOutput, pos);
}

//打印欢迎界面
void WelcomToGame()
{
	SetPos(40, 15);
	printf("欢迎来到贪吃蛇小游戏");
	SetPos(40, 25);
	system("pause");//暂停，按任意键继续
	system("cls");//清理屏幕信息
	SetPos(25, 12);
	printf("用↑，↓，←，→分别控制蛇的运动，F3为加速，F4为减速\n");
	SetPos(25, 13);
	printf("加速将获得更高的分数");
	SetPos(40, 25);
	system("pause");
	system("cls");
}
//打印地图
void CreatMap()
{
	int i = 0;
	//上（0，0）-（56，0）
	SetPos(0, 0);
	for (i = 0; i < 58; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//下（0，26）-（56，26）
	SetPos(0, 26);
	for (i = 0; i < 58; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//左
	//x是0，y是从1开始增长
	for (i = 1; i < 26; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//右
	for (i = 1; i < 26; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}
//初始化蛇
void InitSnack(pSnack ps)
{
	pSnackNode cur = NULL;
	int i = 0;
	//创建蛇身节点，并初始化坐标
	//头插
	for (i = 0; i < 5; i++)
	{
		//创建蛇身的节点
		cur = (pSnackNode)malloc(sizeof(SnackNode));
		if (cur == NULL)
		{
			perror("InitSnack()::fail");
			return;
		}
		//设置坐标
		cur->next = NULL;
		cur->x = POS_X + i * 2;
		cur->y = POS_Y;
		//头插法
		if (ps->pSnack == NULL)
		{
			ps->pSnack = cur;
		}
		else
		{
			cur->next = ps->pSnack;
			ps->pSnack = cur;
		}
	}
	//打印蛇身
	cur = ps->pSnack;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//初始化其他贪吃蛇数据
	ps->SleepTime = 200;
	ps->Sore = 0;
	ps->foodWeight = 10;
	ps->State = OK;
	ps->Dir = RIGHT;
	ps->pfood = NULL;
}
//创建第一个食物
void CreatFood(pSnack ps)
{
	int x = 0;
	int y = 0;
again:
	//产生的x坐标应该是2的倍数，这样蛇吃食物时，食物和蛇才可能对齐
	do
	{
		x = rand() % 53 + 2;//2~54
		y = rand() % 25 + 1;//1~25

	} while(x%2 != 0);
	//获取蛇头指针
	pSnackNode cur = ps->pSnack;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}

	pSnackNode pFood = (pSnackNode)malloc(sizeof(SnackNode));//创建食物
	if (pFood == NULL)
	{
		perror("malloc  failed");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	SetPos(x, y);
	wprintf(L"%lc", FOOD);
	ps->pfood = pFood;
}

void GameStart(pSnack ps)
{
	//设置控制台窗口大小，30行，100列
	//mod为DOS命令
	system("mode con cols=100 lines=30");
	//设置cmd窗口的名称
	system("title 贪吃蛇");

	//获取标准输出的句柄（用于标识不同设备的数值）
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	//隐藏光标
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false;//隐藏光标
	SetConsoleCursorInfo(hOutput, &CursorInfo);//设置控制台光标状态

	//打印欢迎界面
	WelcomToGame();
	//打印地图
	CreatMap();
	//初始化蛇
	InitSnack(ps);
	//创建第一个食物
	CreatFood(ps);

}


// 右侧帮助信息
void PrintHelpInfo()
{
	SetPos(64, 12);
	printf("不能穿墙，不能咬到自己");
	SetPos(64, 13);
	printf("用↑↓←→分别控制蛇的运动");
	SetPos(64, 14);
	printf("F3为加速，F4为减速");
	SetPos(64, 15);
	printf("ESC：退出游戏，Space：暂停游戏");
}
//暂停
void pause()
{
	while (1)
	{
		Sleep(300);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

//判断下一个是不是食物
int NextFood(pSnackNode psn, pSnack ps)
{
	//psn是下一个节点的地址
	//ps是维护蛇的指针
	return (psn->x == ps->pfood->x)&&(psn->y == ps->pfood->y);
}
//吃食物
void EatFood(pSnackNode psn, pSnack ps)
{
	//头插法
	psn->next = ps->pSnack;
	ps->pSnack = psn;
	pSnackNode cur = ps->pSnack;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->Sore += ps->foodWeight;
	//释放食物节点
	free(ps->pfood);
	//再建立新的食物
	CreatFood(ps);
}
//不吃食物
void NoFood(pSnackNode psn, pSnack ps)
{
	//头插法
	psn->next = ps->pSnack;
	ps->pSnack = psn;
	pSnackNode cur = ps->pSnack;
	//打印蛇
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//最后一个位置打印空格
	SetPos(cur->next->x, cur->next->y);
	printf("  ");//要打印两个空格
	free(cur->next);
	cur->next = NULL;
}
int  KillByWall(pSnack ps)
{
	if ((ps->pSnack->x == 0)
		|| (ps->pSnack->x == 56)
		|| (ps->pSnack->y == 0)
		|| (ps->pSnack->y == 26))
	{
		ps->State = KILL_BY_WALL;
		return 1;
	}
	return 0;
}
int  KillBySelf(pSnack ps)
{
	pSnackNode cur = ps->pSnack->next;
	while (cur)
	{
		if ((ps->pSnack->x == cur->x)
			&& (ps->pSnack->y == cur->y))
		{
			ps->State = KILL_BY_SELF;
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

//蛇的移动
void SnackMove(pSnack ps)
{
	//创建下一个节点
	pSnackNode pNextNode = (pSnackNode)malloc(sizeof(SnackNode));
	if (pNextNode == NULL)
	{
		perror("SnackMove malloc fail");
		return;
	}
	pNextNode->next = NULL;
	//确定下一个节点的坐标，蛇头的坐标和方向确定
	switch (ps->Dir)
	{
	case UP:
	{
		pNextNode->x = ps->pSnack->x;
		pNextNode->y = ps->pSnack->y - 1;
	}
	break;
	case DOWN:
	{
		pNextNode->x = ps->pSnack->x;
		pNextNode->y = ps->pSnack->y + 1;
	}
	break; 
	case LEFT:
	{
		pNextNode->x = ps->pSnack->x-2;
		pNextNode->y = ps->pSnack->y;
	}
	break;
	case RIGHT:
	{
		pNextNode->x = ps->pSnack->x+2;
		pNextNode->y = ps->pSnack->y;
	}
	break;
	}

	//如果下一个节点是食物
	if (NextFood(pNextNode, ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}
	KillByWall(ps);
	KillBySelf(ps);
}
//游戏运行
void GameRun(pSnack ps)
{
	//右侧打印信息
	PrintHelpInfo();
	do
	{
		SetPos(64, 10);
		printf("得分：%d ", ps->Sore);
		printf("每个食物的得分：%d", ps->foodWeight);
		//按键为向上，且蛇头不向下
		if (KEY_PRESS(VK_UP) && ps->Dir != DOWN)
		{
			ps->Dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->Dir != UP)
		{
			ps->Dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->Dir != RIGHT)
		{
			ps->Dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->Dir != LEFT)
		{
			ps->Dir = RIGHT;
		}
		//空格，暂停键
		else if (KEY_PRESS(VK_SPACE))
		{
			pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->State = END_NOMAL;
		}
		//加速，但是加速也不能一直加，要有一个最高值
		else if (KEY_PRESS(VK_F3))
		{
			if (ps->SleepTime >= 50)
			{
				ps->SleepTime -= 20;
				ps->foodWeight += 10;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			if (ps->SleepTime <350)
			{
				ps->SleepTime += 30;
				ps->foodWeight -= 10;
				if (ps->SleepTime == 350)
					ps->foodWeight = 1;
			}
		}
		//蛇每次一定要休眠，时间越短，移动速度越快
		Sleep(ps->SleepTime);
		SnackMove(ps);
	} while(ps->State == OK);
}

//游戏结束
void GameEnd(pSnack ps)
{
	pSnackNode cur = ps->pSnack->next;
	SetPos(24, 12);
	switch (ps->State)
	{
	case END_NOMAL:
		printf("您主动退出");
		break;
	case KILL_BY_SELF:
		printf("您撞到自己了，游戏结束");
		break;
	case KILL_BY_WALL:
		printf("您撞墙了，游戏介绍");
		break;
	}
	//释放蛇节点
	while (cur)
	{
		pSnackNode del = cur;
		cur = cur->next;
		free(del);
	}
	free(ps->pfood);
	ps->pfood = NULL;
}