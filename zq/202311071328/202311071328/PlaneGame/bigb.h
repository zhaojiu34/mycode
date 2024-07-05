#pragma once
#include "GameObject.h"

//大招：导弹类

class bigb :
	public CGameObject
{
public:

	bigb(int x, int y);

	//获取导弹矩形框
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + bBOMB_HEIGHT));
	}

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	~bigb();

private:
	static const int bBOMB_HEIGHT = 20;
	static CImageList m_Images;
};

