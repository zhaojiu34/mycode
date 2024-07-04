#include "StdAfx.h"
#include "MyPlane.h"
#include "resource.h"

CImageList CMyPlane::m_Images;

CMyPlane::~CMyPlane(void)
{
}
CMyPlane::CMyPlane(void):m_nHorMotion(0),m_nVerMotion(0)
{
	m_nWait = 0;
	m_ptPos.x = 240;
	m_ptPos.y = 500;
}

BOOL CMyPlane::Fired()
{
	if(m_nWait==0)
		return TRUE;
	else
		return FALSE;

}
BOOL CMyPlane::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP4,RGB(255,255,255),68,77,1);
}
BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)
{
	if (VK_SPACE!=0)
	{
		m_nWait++;
		if (m_nWait>2)
			m_nWait = 0;
	}
	else
	{
		m_nWait = 0;
	}
	


	if(!bPause)
	{
		m_ptPos.x = m_ptPos.x + m_nHorMotion*10;
		m_ptPos.y = m_ptPos.y - m_nVerMotion*10;
	}

	if(m_ptPos.x>=GAME_WIDTH-PLANE_WIDTH)
		m_ptPos.x =GAME_WIDTH-PLANE_WIDTH;
	if(m_ptPos.x<=0)
		m_ptPos.x=0;

	if(m_ptPos.y<=0)
		m_ptPos.y =0;

	if(m_ptPos.y>=GAME_HEIGHT-PLANE_HEIGHT)
		m_ptPos.y=GAME_HEIGHT-PLANE_HEIGHT;


	m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}