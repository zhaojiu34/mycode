#include "stdafx.h"
#include "bigb.h"
#include"resource.h"


CImageList bigb::m_Images;

bigb::bigb(int x, int y)
	:CGameObject(x, y)
{
}


bigb::~bigb()
{

}

BOOL bigb::Draw(CDC* pDC, BOOL bPause)
{

	m_ptPos.y = m_ptPos.y - 30;
	

	if (m_ptPos.y < -bBOMB_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}


BOOL bigb::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP9, RGB(255, 255, 255), 56, 39, 1);
}
