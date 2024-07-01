#include "stdafx.h"
#include "BigSkill.h"
#include"resource.h"


CImageList BigSkill::m_Images;


BigSkill::BigSkill(int x, int y) :CGameObject(x, y)
{
}

BigSkill::~BigSkill()
{
}


BOOL BigSkill::Draw(CDC* pDC, BOOL bPause)
{

	m_ptPos.y = m_ptPos.y - 15;


	if (m_ptPos.y < -bBOMB_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}



BOOL BigSkill::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP10, RGB(0, 0, 0), 200, 253, 1);
}
