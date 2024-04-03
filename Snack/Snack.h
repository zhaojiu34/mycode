#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>
 
#define KEY_PRESS(VK) (( (GetAsyncKeyState(VK) )& 0x1) ? 1:0)
#define WALL L'��'
#define BODY L'��'
#define POS_X 24
#define POS_Y 5
#define FOOD L'��'

//̰������ڵ�Ķ���
typedef struct SnackNode
{
	int x;
	int y;
	struct SnackNode* next;
}SnackNode, *pSnackNode;

//����
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
//��Ϸ״̬
enum GAME_STATE
{
	OK,//��Ϸ��������
	KILL_BY_WALL,//ײǽ����
	KILL_BY_SELF,//ҧ���Լ�
	END_NOMAL//��������
};
//̰����
typedef struct Snack
{
	pSnackNode pSnack;//������
	pSnackNode pfood;//ʳ����ֵ�λ��
	enum DIRECTION Dir;//����һ�iҪ�ߵķ���
	enum GAME_STATE State;//��Ϸ״̬
	int Sore;//�ܷ���
	int foodWeight;//ÿһ��ʳ��ķ���
	int SleepTime;//˯��ʱ�䣨�ٶȣ�
}Snack,*pSnack;

void SetPos(short x, short y);
//��Ϸ��ʼ
void GameStart(pSnack ps);
//��ӡ��ӭ����
void WelcomToGame();
//��ӡ��ͼ
void CreatMap();
//��ʼ����
void InitSnack(pSnack ps);
//������һ��ʳ��
void CreatFood(pSnack ps);

//��Ϸ����
void GameRun(pSnack ps);
//�Ҳ������Ϣ
void PrintHelpInfo();
//��ͣ
void pause();
//�ж���һ���ǲ���ʳ��
int NextFood(pSnackNode psn, pSnack ps);
//��ʳ��
void EatFood(pSnackNode psn, pSnack ps);
//����ʳ��
void NoFood(pSnackNode psn, pSnack ps);
int  KillByWall(pSnack ps);
int  KillBySelf(pSnack ps);
//�ߵ��ƶ�
void SnackMove(pSnack ps);

//��Ϸ����
void GameEnd(pSnack ps);

