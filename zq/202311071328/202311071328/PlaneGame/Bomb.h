#pragma once
#include "gameobject.h"

//我方战机子弹

class CBomb :
	public CGameObject
{
public:

	int m;//子弹发射方向

	CBomb(int x,int y,int M);
	~CBomb(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+10,m_ptPos.y+BOMB_HEIGHT));
	}

private:
	static const int BOMB_HEIGHT = 20;
	static CImageList m_Images;

};
