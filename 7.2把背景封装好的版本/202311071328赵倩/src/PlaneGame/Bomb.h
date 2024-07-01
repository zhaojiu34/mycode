#pragma once
#include "gameobject.h"

//µºµØ∂‘œÛ

class CBomb :public CGameObject
{
public:
	CBomb(int x, int y, double tt, int vv);
	~CBomb(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + BOMB_HEIGHT));
	}
private:
	int t, fx, fy, flag, v;
	double jiao;
	static const int BOMB_HEIGHT = 20;
	static CImageList m_Images;
};
