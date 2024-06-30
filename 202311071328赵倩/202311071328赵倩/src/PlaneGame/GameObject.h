#pragma once


//将游戏的各种功能和性质在各自的类中定义成静态成员函数，
// 再由PlanGameView.cpp中的AI函数进行调用来实现各种功能。

//游戏对象
//各个游戏对象的抽象父类CGameObject类
//游戏对象的父类：其余类均继承了此类
class CGameObject : public CObject
{
public:

	CGameObject(int x=0,int y=0);

	//当父类的析构函数声明成虚析构函数的时候，当子类继承父类，父类的指针指向子类时
	//delete掉父类的指针，先调动子类的析构函数，再调动父类的析构函数。
	//虚析构函数
	virtual ~CGameObject();
	
	//绘制对象
	virtual BOOL Draw(CDC* pDC,BOOL bPause)=0;

	//获得矩形区域
	virtual CRect GetRect()=0;

	//获得左上角坐标
	CPoint GetPoint()
	{
		return m_ptPos;
	}

protected:
	//加载图像 静态成员函数
	static BOOL LoadImage(CImageList& imgList,UINT bmpID,COLORREF crMask,int cx,int cy,int nInitial);
protected:
	//物体的位置
	CPoint  m_ptPos;
	CPoint  m_ptPos_move;
};


