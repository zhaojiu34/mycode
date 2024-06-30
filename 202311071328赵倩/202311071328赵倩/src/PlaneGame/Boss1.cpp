#include "stdafx.h"
#include "Boss1.h"
#include "resource.h"

CImageList Boss1::m_Images;

Boss1::Boss1() :emblood3(800)
{
	//随机确定X位置
	m_ptPos.x = rand() % (GAME_WIDTH - BOSS3_HEIGHT) + 1;

	//随机确定图像索引
	m_nImgIndex = 0;

	//根据图像索引确定方向：BOSS1只能从一个方向来
	m_nMotion = 1;
	m_ptPos.y = -BOSS3_HEIGHT;

	//如果加上这个代码，就上下两个方向都可以来
	/*	if (m_nImgIndex%2!=0)//如果是图像索引是偶数
	{
	m_nMotion=-1;
	m_ptPos.y = GAME_HEIGHT+ENEMY_HEIGHT;
	}
	*/

	//随机确定速度
	m_V = rand() % 2 + 1;

	m_nWait = 0;
}

Boss1::~Boss1()
{
}

BOOL Boss1::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP6, RGB(0, 0, 0), 400, 308, 1);
}


BOOL Boss1::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	if (m_nWait > 3)
		m_nWait = 0;

	CBrush b2(RGB(255, 255, 255));
	CPen p2(PS_SOLID, 2, RGB(255, 0, 0));
	pDC->SelectObject(&p2);
	pDC->SelectObject(&b2);
	pDC->Rectangle(m_ptPos.x + 30, m_ptPos.y, m_ptPos.x + 125 + 30, m_ptPos.y + 13);

	CBrush b1(RGB(0, 0, 0));
	CPen p1(PS_SOLID, 2, RGB(255, 0, 0));
	pDC->SelectObject(&p1);
	pDC->SelectObject(&b1);
	pDC->Rectangle(m_ptPos.x + 30, m_ptPos.y, m_ptPos.x + emblood3 / 4 + 30, m_ptPos.y + 13);
	
	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + y;
		m_ptPos.x = m_ptPos.x + x;

	}
	if (m_ptPos.x <= 0)
	{
		m_ptPos.x = 0;
		x = 2;
	}
	if (m_ptPos.x >= GAME_WIDTH - 146)
	{
		m_ptPos.x = GAME_WIDTH - 146;
		x = -2;
	}
	if (m_ptPos.y <= 15)
	{
		m_ptPos.y = 15;
		y = 1;
	}
	if (m_ptPos.y >= 150)
	{
		m_ptPos.y = 120;
		y = -1;
	}


	if (m_ptPos.y > GAME_HEIGHT + BOSS3_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -BOSS3_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}


BOOL Boss1::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}
