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
	//飞机初始位置
	m_ptPos.x = 240;
	m_ptPos.y = 500;
}

//是否开火
BOOL CMyPlane::Fired()
{
	if(m_nWait==0)
		return TRUE;
	else
		return FALSE;

}

//加载图片
BOOL CMyPlane::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP4,RGB(255,255,255),68,77,1);
}


BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)
{
	//每刷新两次发射一枚子弹
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
		//飞机更新，运行速度
		m_ptPos.x = m_ptPos.x + m_nHorMotion*10;
		m_ptPos.y = m_ptPos.y - m_nVerMotion*10;
	}

	//判断边界
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