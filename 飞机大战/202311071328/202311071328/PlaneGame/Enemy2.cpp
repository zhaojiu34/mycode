#include "stdafx.h"
#include "Enemy2.h"
#include "resource.h"

CImageList Enemy2::m_Images;

Enemy2::Enemy2(void)
{
	//���ȷ��Xλ��
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMY_HEIGHT) + 1;

	//���ȷ��ͼ������
	m_nImgIndex = 0;

	//����ͼ������ȷ������
	m_nMotion = 1;
	m_ptPos.y = -ENEMY_HEIGHT;

	//���ȷ���ٶ�
	m_V = rand() % 3 + 2;

	m_nWait = 0;
}

Enemy2::~Enemy2(void)
{
}

BOOL Enemy2::LoadImage()
{

	return CGameObject::LoadImage(m_Images, IDB_BITMAP6, RGB(255, 255, 255), 49, 55, 2);

}

BOOL Enemy2::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;

	if (m_nWait>8)
		m_nWait = 0;

	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + m_nMotion * m_V;
	}

	if (m_ptPos.y > GAME_HEIGHT + ENEMY_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

BOOL Enemy2::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;

}