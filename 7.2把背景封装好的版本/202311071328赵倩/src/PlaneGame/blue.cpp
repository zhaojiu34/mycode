#include "stdafx.h"
#include "blue.h"
#include "resource.h"

CImageList cblue::m_Images;

BOOL cblue::LoadImage()
{

	return CGameObject::LoadImage(m_Images, IDB_BITMAP8, RGB(0, 0, 0), 15, 30, 1);

}

BOOL cblue::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	if (m_nWait > 10)
		m_nWait = 0;

	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + m_nMotion * m_V;
	}

	if (m_ptPos.y > GAME_HEIGHT + _HEIGHT)
		return FALSE;
	if (m_ptPos.y < -_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

cblue::cblue()
{
	//随机确定X位置
	m_ptPos.x = rand() % (GAME_WIDTH - _HEIGHT) + 1;

	//随机确定图像索引
	m_nImgIndex = 0;

	//根据图像索引确定方向
	m_nMotion = 1;
	m_ptPos.y = -_HEIGHT;

	//随机确定速度
	m_V = rand() % 6 + 2;

	m_nWait = 0;
}


cblue::~cblue()
{
}