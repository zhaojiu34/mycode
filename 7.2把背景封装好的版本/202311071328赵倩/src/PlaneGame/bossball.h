#pragma once
#include "gameobject.h"

//BOSSµºµØ∂‘œÛ

class BossBall :
	public CGameObject
{
public:
	BossBall(int x, int y, int m_nMotion);
	~BossBall(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMB_WIDTH, m_ptPos.y + BOMB_HEIGHT));
	}

private:
	static const int BOMB_HEIGHT = 26;
	static const int BOMB_WIDTH = 20;
	static CImageList m_Images;
	int    m_nMotion;

};
