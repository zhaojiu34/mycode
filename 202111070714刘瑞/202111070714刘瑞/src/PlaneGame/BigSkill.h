#pragma once
#include "GameObject.h"
class BigSkill :
	public CGameObject
{
public:
	BigSkill(int x, int y);
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + bBOMB_HEIGHT));
	}
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	~BigSkill();
private:
	static const int bBOMB_HEIGHT = 20;
	static CImageList m_Images;
};