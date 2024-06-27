#pragma once
#include "GameObject.h"

/************************************************************************/
/*                         ս������
						  2016/01/18  yrr
*/
/************************************************************************/
class MyPlane :
	public GameObject
{
public:
	MyPlane();
	~MyPlane();

	BOOL Draw(CDC *pDC, BOOL bPause);

	static BOOL LoadImage();

	/*�õ�ս�����ڵľ�������*/
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + PLANE_WIDTH, m_ptPos.y + PLANE_HEIGHT));
	}

	/*ս���Ƿ���Է����ӵ�*/
	BOOL isFired();

public:
	/*����ս���ĳ��ȺͿ��*/
	static const int PLANE_WIDTH = 50;
	static const int PLANE_HEIGHT = 60;

private:
	static CImageList m_Images;/*�洢ս��ͼƬ*/
};

