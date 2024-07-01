#include "stdafx.h"
#include "Boss.h"
#include "resource.h"

CImageList Boss::m_Images;

Boss::Boss() 
	:emblood(50)
{
	//随机确定X位置
	m_ptPos.x = rand() % (GAME_WIDTH - BOSS_HEIGHT) + 1;

	//随机确定图像索引
	m_nImgIndex = 0;

	//根据图像索引确定方向
	m_nMotion = 1;

	m_ptPos.y = -BOSS_HEIGHT;
	//随机确定速度
	m_V = rand() % 2 + 1;

	m_nWait = 0;
}

int Boss::getlife(int x)
{
	return emblood = x;
}

int Boss::getlife()
{
	return emblood;
}

Boss::~Boss()
{

}

BOOL Boss::LoadImage()
{
	//图像资源ID(IDB_BITMAP4)、透明色(RGB(0, 0, 0))、图像的宽度和高度(40和59)，以及图像的索引(1)

	return CGameObject::LoadImage(m_Images, IDB_BITMAP4, RGB(0, 0, 0), 40, 59, 1);
}


BOOL Boss::Draw(CDC* pDC, BOOL bPause)
{
	//每16秒发射一次炮弹
	m_nWait++;
	if (m_nWait > 16)
		m_nWait = 0;

	//绘制大BOSS血条
	CBrush b1(RGB(255, 0, 0));
	CPen p1(PS_SOLID, 2, RGB(255, 0, 0));
	pDC->SelectObject(&p1);
	pDC->SelectObject(&b1);
	pDC->Rectangle(m_ptPos.x + 5, m_ptPos.y, m_ptPos.x + emblood, m_ptPos.y - 2);

	//让Boss对象在游戏进行时随着时间或操作移动
	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + y;
		m_ptPos.x = m_ptPos.x + x;

	}

	//保证BOSS不会越界，在屏幕中移动，不会出界面 
	if (m_ptPos.x <= 0)
	{
		m_ptPos.x = 0;
		x = 1;
	}
	if (m_ptPos.x >= 400)
	{
		m_ptPos.x = 400;
		x = -1;
	}
	if (m_ptPos.y <= 15)
	{
		m_ptPos.y = 15;
		y = 2;
	}
	if (m_ptPos.y >= 180)
	{
		m_ptPos.y = 180;
		y = -2;
	}

	//越界
	if (m_ptPos.y > GAME_HEIGHT + BOSS_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -BOSS_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

BOOL Boss::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}