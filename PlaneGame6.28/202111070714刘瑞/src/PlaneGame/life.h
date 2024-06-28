#pragma once
#include "GameObject.h"
class life :
	public CGameObject
{
public:
	life();
	~life();

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
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
	//ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ
};
