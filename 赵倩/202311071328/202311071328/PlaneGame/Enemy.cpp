#include "StdAfx.h"
#include "Enemy.h"
#include "resource.h"

CImageList CEnemy::m_Images;

CEnemy::CEnemy(void)
{
	//随机确定X位置
	m_ptPos.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;

	//随机确定图像索引
	m_nImgIndex =0;

	//根据图像索引确定方向
	m_nMotion=1;
	m_ptPos.y = -ENEMY_HEIGHT;
/*	if (m_nImgIndex%2!=0)//如果是图像索引是偶数
	{
		m_nMotion=-1;
		m_ptPos.y = GAME_HEIGHT+ENEMY_HEIGHT;
	}
*/
	//随机确定速度
	m_V = rand()%3+2;

	m_nWait=0;
}

CEnemy::~CEnemy(void)
{
}
BOOL CEnemy::LoadImage(int i)
{
	
//	if (m ==1)
		return CGameObject::LoadImage(m_Images,IDB_BITMAP3,RGB(255,255,255),68,60,2);
		//return CGameObject::LoadImage(m_Images, IDB_BITMAP6, RGB(255, 255, 255), 49, 55, 2);
	
}
BOOL CEnemy::Draw(CDC* pDC,BOOL bPause)
{
	m_nWait++;
	if(m_nWait>8)
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