#include "StdAfx.h"
#include "Enemy.h"
#include "resource.h"

CImageList CEnemy::m_Images;

CEnemy::CEnemy(void)
{
	//随机确定X位置
	m_ptPos.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;

	//随机确定图像索引
	m_nImgIndex = rand()%2;

	//根据图像索引确定方向
	m_nMotion=1;
	m_ptPos.y=-ENEMY_HEIGHT;

	//产生从下面出现的飞机：加一个可以选择困难模式和简单模式：有没有从下面出来的飞机
	if (m_nImgIndex%2!=0)//如果是图像索引是偶数
	{
		m_nMotion=-1;
		m_ptPos.y = GAME_HEIGHT+ENEMY_HEIGHT;
	}

	//随机确定速度
	m_V = rand()%6+2;

	m_nWait=0;
}

CEnemy::~CEnemy(void)
{
}

BOOL CEnemy::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_ENEMY,RGB(0,0,0),35,35,2);
}


BOOL CEnemy::Draw(CDC* pDC,BOOL bPause)
{
	m_nWait++;
	if(m_nWait>20)
		m_nWait=0;

	if(!bPause)
	{
		m_ptPos.y = m_ptPos.y + m_nMotion * m_V;
	}

	if(m_ptPos.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC,m_nImgIndex,m_ptPos,ILD_TRANSPARENT);

	return TRUE;
}


BOOL CEnemy::Fired()
{
	if(m_nWait==0)
		return TRUE;
	else
		return FALSE;
}