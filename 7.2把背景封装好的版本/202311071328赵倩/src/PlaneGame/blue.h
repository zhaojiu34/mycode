#pragma once
#include "GameObject.h"

//蓝瓶对象：加经验值

class cblue :
	public CGameObject
{
public:
	cblue();
	~cblue();

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + _HEIGHT, m_ptPos.y + _HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}

private:
	static const int _HEIGHT = 35;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
	//图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时

};
