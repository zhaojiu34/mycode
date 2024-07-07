#include "StdAfx.h"
#include "Bomb.h"
#include "resource.h"


CImageList CBomb::m_Images;


CBomb::CBomb(int x, int y, int t) 
	:CGameObject(x, y)
{
	if (t == -1)
		m = -1;
	else if (t == -2)
		m = -2;
	else if (t == 1)
		m = 0;
}


CBomb::~CBomb(void)
{
}


BOOL CBomb::Draw(CDC* pDC, BOOL bPause)
{
	//绘制三枚子弹的轨迹
	
	//上
	if (!bPause&&m == 0)
	{
		m_ptPos.y = m_ptPos.y - 10;
	}
	//左
	else if (!bPause && m == -1)
	{
		m_ptPos.y = m_ptPos.y - 10;
		m_ptPos.x = m_ptPos.x - 4;
	}
	//右
	else if (!bPause && m == -2)
	{
		m_ptPos.y = m_ptPos.y - 10;
		m_ptPos.x = m_ptPos.x + 4;
	}

	//判断边界
	if (m_ptPos.y < -BOMB_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);


	return TRUE;
}



BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP1,RGB(255,255,255),22,25,1);
}
