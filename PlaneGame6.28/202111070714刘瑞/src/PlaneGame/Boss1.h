#pragma once
#include "GameObject.h"
class Boss1 :
	public CGameObject
{
public:
	Boss1();
	virtual ~Boss1();
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSS3_HEIGHT, m_ptPos.y + BOSS3_HEIGHT - 50));
	}
	int GetMontion() const
	{
		return m_nMotion;
	}
	int emblood3;
	int x, y;
	//是否可以开火发射子弹
	BOOL Fired();
private:

	static const int BOSS3_HEIGHT = 150;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
					 //图像索引
	int m_nImgIndex;
	//速度
	int m_V;

	int    m_nWait;//发射延时
};
