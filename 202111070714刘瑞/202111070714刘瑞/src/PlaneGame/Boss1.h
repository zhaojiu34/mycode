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
	//�Ƿ���Կ������ӵ�
	BOOL Fired();
private:

	static const int BOSS3_HEIGHT = 150;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
					 //ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;

	int    m_nWait;//������ʱ
};
