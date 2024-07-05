#pragma once
#include "GameObject.h"


class Boss :public CGameObject
{
public:
	Boss();

	//����������
	//����������ʹ����ɾ��ָ���������Ļ���ָ��ʱ���Ե�����������������ﵽ�ͷ������ж��ڴ��Ŀ�ģ�����ֹ�ڴ�й¶��
	virtual ~Boss();

	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();

	//��������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSS_HEIGHT, m_ptPos.y + BOSS_HEIGHT));
	}

	//����
	int GetMontion() const
	{
		return m_nMotion;
	}

	//Ѫ��
	int getlife(int x);
	int getlife();

	int emblood;
	int x, y;//ˮƽ����ֱ�����˶�����

	//�Ƿ���Կ������ӵ�
	BOOL Fired();

private:
	//����
	static const int BOSS_HEIGHT = 100;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����

	//ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ
};

