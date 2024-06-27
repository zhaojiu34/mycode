#pragma once
#include "GameObject.h"

/************************************************************************/
/*                         �л�����
*/
/************************************************************************/

class EnemyPlane :
	public GameObject
{
public:
	EnemyPlane(int motion);
	~EnemyPlane();

	BOOL Draw(CDC *pDC, BOOL bPause);
	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYPLANE_HEIGHT, m_ptPos.y + ENEMYPLANE_HEIGHT));
	}

	int GetDirection()	const
	{
		return m_direction;
	}

	void SetDirection(int dir)
	{
		m_direction = dir;
	}

	void SetSpeed(int s)
	{
		m_speed = s;
	}

	BOOL isFired();
private:
	/*�л��Ŀ�ȡ��߶�*/
	static const int ENEMYPLANE_HEIGHT = 35;
	static CImageList m_Images;

	/*�л����з��� 1*/
	int m_direction;

	/*�л�ͼ������*/
	int m_nImgIdx;

	/*�л��ٶ�*/
	int m_speed;

	/*������ʱ*/
	int m_wait;
};

