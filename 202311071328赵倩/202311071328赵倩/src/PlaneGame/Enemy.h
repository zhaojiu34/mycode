#pragma once
#include "gameobject.h"

//敌机1对象

class CEnemy :public CGameObject
{
public:
	CEnemy(void);
	~CEnemy(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	//敌机的位置矩形
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+ENEMY_HEIGHT,m_ptPos.y+ENEMY_HEIGHT));
	}

	//敌机的运行方向
	int GetMontion() const
	{
		return m_nMotion;
	}

	//是否可以开火发射子弹
	BOOL Fired();

private:
	static const int ENEMY_HEIGHT = 35;//敌机高度
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
	//图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时
};
