#pragma once
#include "GameObject.h"


class Boss 
	:public CGameObject
{
public:
	Boss();

	//虚析构函数
	//虚析构函数使得在删除指向子类对象的基类指针时可以调用子类的析构函数达到释放子类中堆内存的目的，而防止内存泄露的
	virtual ~Boss();

	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();

	//矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSS_HEIGHT, m_ptPos.y + BOSS_HEIGHT));
	}

	//方向
	int GetMontion() const
	{
		return m_nMotion;
	}

	//血量
	int getlife(int x);
	int getlife();

	int emblood;
	int x, y;//水平，垂直方向运动增量

	//是否可以开火发射子弹
	BOOL Fired();

private:
	//属性
	static const int BOSS_HEIGHT = 100;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上

	//图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时
};

