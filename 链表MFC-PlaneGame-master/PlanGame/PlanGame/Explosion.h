#pragma once
#include "GameObject.h"

/************************************************************************/
/*                       ��ըЧ��������
						2016/01/18  yrr
*/
/************************************************************************/


class Explosion :
	public GameObject
{
public:
	Explosion(int x , int y);
	~Explosion();
	BOOL Draw(CDC *pDC, BOOL bPause);
	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + EXPLOSION_WIDTH, m_ptPos.y + EXPLOSION_WIDTH));
	}
private:
	static CImageList m_Images;
	/*ͼ�������Ĳ�������*/
	int m_nProcess;
public:
	static const int EXPLOSION_WIDTH = 66;
};

