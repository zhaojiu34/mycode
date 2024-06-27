#pragma once
#include "afx.h"
#include "Resource.h"
/************************************************************************/
/*                         ��Ϸ����ĸ���
						 2016/01/18  yrr
*/
/************************************************************************/
/*��Ϸ������з���*/
enum Direction{
	STOP,
	UP,
	DOWN
};

/*����ͼ������*/
enum ImageIdx{
	UP_IDX,
	DOWN_IDX
};

class GameObject :
	public CObject
{
public:
	GameObject(int x = 0, int y = 0);
	/*��������������ȷ�ͷ����������Դ*/
	virtual ~GameObject();

	/*����ͼ��*/
	virtual BOOL Draw(CDC *pDC, BOOL bPause) = 0;
	/*��þ�������*/
	virtual CRect GetRect() = 0;

	/*�����Ϸ��������Ͻ�����*/
	CPoint GetPoint()
	{
		return m_ptPos;
	}

	/*������Ϸ��������*/
	void SetPoint(int x, int y)
	{
		m_ptPos.x = x;
		m_ptPos.y = y;
	}

protected:
	/*����ͼ��*/
	static BOOL LoadImage(CImageList &imgList, UINT bmpID, COLORREF crMask, int cx, int cy, int nInitial);

protected:
	/*��Ϸ���������λ��*/
	CPoint m_ptPos;
};
