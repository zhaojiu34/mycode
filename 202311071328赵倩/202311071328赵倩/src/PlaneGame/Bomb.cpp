#include "StdAfx.h"
#include "Bomb.h"
#include "resource.h"


CImageList CBomb::m_Images;


CBomb::CBomb(int x, int y, double tt, int vv) :CGameObject(x, y)
{
	v = vv;
	fx = x;
	fy = y;
	t = 0;
	jiao = tt;
	flag = 0;
}

CBomb::~CBomb(void)
{
}
BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMB, RGB(0, 0, 0), 10, 20, 1);
}
BOOL CBomb::Draw(CDC* pDC, BOOL bPause)
{
	t++;
	if (!bPause)
	{
		m_ptPos.y = fy - t * cos(jiao) * v;
		m_ptPos.x = fx + t * sin(jiao) * v;
	}

	if (m_ptPos.y < -BOMB_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}