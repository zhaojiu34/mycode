#define _CRT_SECURE_NO_WARNINGS 1
#include "Snack.h"

//���ù��λ��
void SetPos(short x, short y)
{
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	//��ȡ��׼����ľ��
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ñ�׼����Ϲ���λ��Ϊpos
	SetConsoleCursorPosition(hOutput, pos);
}

//��ӡ��ӭ����
void WelcomToGame()
{
	SetPos(40, 15);
	printf("��ӭ����̰����С��Ϸ");
	SetPos(40, 25);
	system("pause");//��ͣ�������������
	system("cls");//������Ļ��Ϣ
	SetPos(25, 12);
	printf("�á��������������ֱ�����ߵ��˶���F3Ϊ���٣�F4Ϊ����\n");
	SetPos(25, 13);
	printf("���ٽ���ø��ߵķ���");
	SetPos(40, 25);
	system("pause");
	system("cls");
}
//��ӡ��ͼ
void CreatMap()
{
	int i = 0;
	//�ϣ�0��0��-��56��0��
	SetPos(0, 0);
	for (i = 0; i < 58; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//�£�0��26��-��56��26��
	SetPos(0, 26);
	for (i = 0; i < 58; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//��
	//x��0��y�Ǵ�1��ʼ����
	for (i = 1; i < 26; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//��
	for (i = 1; i < 26; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}
//��ʼ����
void InitSnack(pSnack ps)
{
	pSnackNode cur = NULL;
	int i = 0;
	//��������ڵ㣬����ʼ������
	//ͷ��
	for (i = 0; i < 5; i++)
	{
		//��������Ľڵ�
		cur = (pSnackNode)malloc(sizeof(SnackNode));
		if (cur == NULL)
		{
			perror("InitSnack()::fail");
			return;
		}
		//��������
		cur->next = NULL;
		cur->x = POS_X + i * 2;
		cur->y = POS_Y;
		//ͷ�巨
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
	//��ӡ����
	cur = ps->pSnack;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//��ʼ������̰��������
	ps->SleepTime = 200;
	ps->Sore = 0;
	ps->foodWeight = 10;
	ps->State = OK;
	ps->Dir = RIGHT;
	ps->pfood = NULL;
}
//������һ��ʳ��
void CreatFood(pSnack ps)
{
	int x = 0;
	int y = 0;
again:
	//������x����Ӧ����2�ı����������߳�ʳ��ʱ��ʳ����߲ſ��ܶ���
	do
	{
		x = rand() % 53 + 2;//2~54
		y = rand() % 25 + 1;//1~25

	} while(x%2 != 0);
	//��ȡ��ͷָ��
	pSnackNode cur = ps->pSnack;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}

	pSnackNode pFood = (pSnackNode)malloc(sizeof(SnackNode));//����ʳ��
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
	//���ÿ���̨���ڴ�С��30�У�100��
	//modΪDOS����
	system("mode con cols=100 lines=30");
	//����cmd���ڵ�����
	system("title ̰����");

	//��ȡ��׼����ľ�������ڱ�ʶ��ͬ�豸����ֵ��
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	//���ع��
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false;//���ع��
	SetConsoleCursorInfo(hOutput, &CursorInfo);//���ÿ���̨���״̬

	//��ӡ��ӭ����
	WelcomToGame();
	//��ӡ��ͼ
	CreatMap();
	//��ʼ����
	InitSnack(ps);
	//������һ��ʳ��
	CreatFood(ps);

}


// �Ҳ������Ϣ
void PrintHelpInfo()
{
	SetPos(64, 12);
	printf("���ܴ�ǽ������ҧ���Լ�");
	SetPos(64, 13);
	printf("�á��������ֱ�����ߵ��˶�");
	SetPos(64, 14);
	printf("F3Ϊ���٣�F4Ϊ����");
	SetPos(64, 15);
	printf("ESC���˳���Ϸ��Space����ͣ��Ϸ");
}
//��ͣ
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

//�ж���һ���ǲ���ʳ��
int NextFood(pSnackNode psn, pSnack ps)
{
	//psn����һ���ڵ�ĵ�ַ
	//ps��ά���ߵ�ָ��
	return (psn->x == ps->pfood->x)&&(psn->y == ps->pfood->y);
}
//��ʳ��
void EatFood(pSnackNode psn, pSnack ps)
{
	//ͷ�巨
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
	//�ͷ�ʳ��ڵ�
	free(ps->pfood);
	//�ٽ����µ�ʳ��
	CreatFood(ps);
}
//����ʳ��
void NoFood(pSnackNode psn, pSnack ps)
{
	//ͷ�巨
	psn->next = ps->pSnack;
	ps->pSnack = psn;
	pSnackNode cur = ps->pSnack;
	//��ӡ��
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//���һ��λ�ô�ӡ�ո�
	SetPos(cur->next->x, cur->next->y);
	printf("  ");//Ҫ��ӡ�����ո�
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

//�ߵ��ƶ�
void SnackMove(pSnack ps)
{
	//������һ���ڵ�
	pSnackNode pNextNode = (pSnackNode)malloc(sizeof(SnackNode));
	if (pNextNode == NULL)
	{
		perror("SnackMove malloc fail");
		return;
	}
	pNextNode->next = NULL;
	//ȷ����һ���ڵ�����꣬��ͷ������ͷ���ȷ��
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

	//�����һ���ڵ���ʳ��
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
//��Ϸ����
void GameRun(pSnack ps)
{
	//�Ҳ��ӡ��Ϣ
	PrintHelpInfo();
	do
	{
		SetPos(64, 10);
		printf("�÷֣�%d ", ps->Sore);
		printf("ÿ��ʳ��ĵ÷֣�%d", ps->foodWeight);
		//����Ϊ���ϣ�����ͷ������
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
		//�ո���ͣ��
		else if (KEY_PRESS(VK_SPACE))
		{
			pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->State = END_NOMAL;
		}
		//���٣����Ǽ���Ҳ����һֱ�ӣ�Ҫ��һ�����ֵ
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
		//��ÿ��һ��Ҫ���ߣ�ʱ��Խ�̣��ƶ��ٶ�Խ��
		Sleep(ps->SleepTime);
		SnackMove(ps);
	} while(ps->State == OK);
}

//��Ϸ����
void GameEnd(pSnack ps)
{
	pSnackNode cur = ps->pSnack->next;
	SetPos(24, 12);
	switch (ps->State)
	{
	case END_NOMAL:
		printf("�������˳�");
		break;
	case KILL_BY_SELF:
		printf("��ײ���Լ��ˣ���Ϸ����");
		break;
	case KILL_BY_WALL:
		printf("��ײǽ�ˣ���Ϸ����");
		break;
	}
	//�ͷ��߽ڵ�
	while (cur)
	{
		pSnackNode del = cur;
		cur = cur->next;
		free(del);
	}
	free(ps->pfood);
	ps->pfood = NULL;
}