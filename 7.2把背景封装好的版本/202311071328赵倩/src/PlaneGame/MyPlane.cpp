#include "StdAfx.h"
#include "MyPlane.h"
#include "resource.h"

CImageList CMyPlane::m_Images;

CMyPlane::~CMyPlane(void)
{
}


CMyPlane::CMyPlane(void)
	:m_nHorMotion(0)
	,m_nVerMotion(0)
{
	m_nWait = 0;
	m_ptPos.x = 150;
	m_ptPos.y = 200;
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
	return CGameObject::LoadImage(m_Images,IDB_ME,RGB(0,0,0),70,45,1);
}

BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)
{
	//发射延迟
	m_nWait++;
	if(m_nWait>3)
		m_nWait=0;

	//没有暂停，根据飞机的水平和垂直运动方向来更新飞机的位置m_ptPos
	//水平方向每次移动6个像素，垂直方向每次移动6个像素
	if(!bPause)
	{
		m_ptPos.x = m_ptPos.x + m_nHorMotion*6;
		m_ptPos.y = m_ptPos.y - m_nVerMotion*6;
	}

	//边界检测
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