#include "StdAfx.h"
#include "Explosion.h"
#include "resource.h"

CImageList CExplosion::m_Images;

CExplosion::CExplosion(int x,int y):CGameObject(x,y),m_nProcess(0)
{
}

CExplosion::~CExplosion(void)
{
}

BOOL CExplosion::Draw(CDC* pDC,BOOL bPause)
{
	//只有15张图片：判断帧数是否为最后一帧
	if(m_nProcess==18)
	{
		m_nProcess=0;
		return FALSE;
	}

	//用新位置绘制图像
	m_Images.Draw(pDC,m_nProcess,m_ptPos,ILD_TRANSPARENT);
	m_nProcess++;
	return TRUE;

}

BOOL CExplosion::LoadImage()
{
	//RGB(0,0,0)为透明色，图片大小为66x66，一共有8帧图片
	return CGameObject::LoadImage(m_Images,IDB_EXPLOSION,RGB(0,0,0),66,66,8);
}