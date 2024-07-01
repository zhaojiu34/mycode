#include "StdAfx.h"
#include "BossBall.h"
#include "resource.h"


CImageList BossBall::m_Images;


BossBall::BossBall(int x, int y, int nMotion) 
	:CGameObject(x, y)
	, m_nMotion(nMotion)
{

}

BossBall::~BossBall(void)
{
}

BOOL BossBall::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP9, RGB(0, 0, 0), 25, 25, 1);
}

BOOL BossBall::Draw(CDC* pDC, BOOL bPause)
{
	m_ptPos.y = m_ptPos.y + 15;
	m_ptPos.x = m_ptPos.x + 50 * cos(m_ptPos.y);

	if (m_ptPos.y < -BOMB_HEIGHT)
		return FALSE;

	m_ptPos_move.x = m_ptPos.x;
	m_ptPos_move.y = m_ptPos.y;
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}