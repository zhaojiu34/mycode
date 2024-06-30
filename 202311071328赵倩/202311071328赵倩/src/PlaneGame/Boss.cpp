#include "stdafx.h"
#include "Boss.h"
#include "resource.h"

CImageList Boss::m_Images;

Boss::Boss() 
	:emblood(50)
{
	//���ȷ��Xλ��
	m_ptPos.x = rand() % (GAME_WIDTH - BOSS_HEIGHT) + 1;

	//���ȷ��ͼ������
	m_nImgIndex = 0;

	//����ͼ������ȷ������
	m_nMotion = 1;

	m_ptPos.y = -BOSS_HEIGHT;
	//���ȷ���ٶ�
	m_V = rand() % 2 + 1;

	m_nWait = 0;
}

int Boss::getlife(int x)
{
	return emblood = x;
}

int Boss::getlife()
{
	return emblood;
}

Boss::~Boss()
{

}

BOOL Boss::LoadImage()
{
	//ͼ����ԴID(IDB_BITMAP4)��͸��ɫ(RGB(0, 0, 0))��ͼ��Ŀ�Ⱥ͸߶�(40��59)���Լ�ͼ�������(1)

	return CGameObject::LoadImage(m_Images, IDB_BITMAP4, RGB(0, 0, 0), 40, 59, 1);
}


BOOL Boss::Draw(CDC* pDC, BOOL bPause)
{
	//ÿ16�뷢��һ���ڵ�
	m_nWait++;
	if (m_nWait > 16)
		m_nWait = 0;

	//���ƴ�BOSSѪ��
	CBrush b1(RGB(255, 0, 0));
	CPen p1(PS_SOLID, 2, RGB(255, 0, 0));
	pDC->SelectObject(&p1);
	pDC->SelectObject(&b1);
	pDC->Rectangle(m_ptPos.x + 5, m_ptPos.y, m_ptPos.x + emblood, m_ptPos.y - 2);

	//��Boss��������Ϸ����ʱ����ʱ�������ƶ�
	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + y;
		m_ptPos.x = m_ptPos.x + x;

	}

	//��֤BOSS����Խ�磬����Ļ���ƶ������������ 
	if (m_ptPos.x <= 0)
	{
		m_ptPos.x = 0;
		x = 1;
	}
	if (m_ptPos.x >= 400)
	{
		m_ptPos.x = 400;
		x = -1;
	}
	if (m_ptPos.y <= 15)
	{
		m_ptPos.y = 15;
		y = 2;
	}
	if (m_ptPos.y >= 180)
	{
		m_ptPos.y = 180;
		y = -2;
	}

	//Խ��
	if (m_ptPos.y > GAME_HEIGHT + BOSS_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -BOSS_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

BOOL Boss::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}