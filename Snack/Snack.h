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
#define WALL L'■'
#define BODY L'●'
#define POS_X 24
#define POS_Y 5
#define FOOD L'★'

//贪吃蛇身节点的定义
typedef struct SnackNode
{
	int x;
	int y;
	struct SnackNode* next;
}SnackNode, *pSnackNode;

//方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
//游戏状态
enum GAME_STATE
{
	OK,//游戏正常运行
	KILL_BY_WALL,//撞墙死了
	KILL_BY_SELF,//咬到自己
	END_NOMAL//正常结束
};
//贪吃蛇
typedef struct Snack
{
	pSnackNode pSnack;//蛇身体
	pSnackNode pfood;//食物出现的位置
	enum DIRECTION Dir;//蛇下一歩要走的方向
	enum GAME_STATE State;//游戏状态
	int Sore;//总分数
	int foodWeight;//每一个食物的分数
	int SleepTime;//睡眠时间（速度）
}Snack,*pSnack;

void SetPos(short x, short y);
//游戏开始
void GameStart(pSnack ps);
//打印欢迎界面
void WelcomToGame();
//打印地图
void CreatMap();
//初始化蛇
void InitSnack(pSnack ps);
//创建第一个食物
void CreatFood(pSnack ps);

//游戏运行
void GameRun(pSnack ps);
//右侧帮助信息
void PrintHelpInfo();
//暂停
void pause();
//判断下一个是不是食物
int NextFood(pSnackNode psn, pSnack ps);
//吃食物
void EatFood(pSnackNode psn, pSnack ps);
//不吃食物
void NoFood(pSnackNode psn, pSnack ps);
int  KillByWall(pSnack ps);
int  KillBySelf(pSnack ps);
//蛇的移动
void SnackMove(pSnack ps);

//游戏结束
void GameEnd(pSnack ps);

