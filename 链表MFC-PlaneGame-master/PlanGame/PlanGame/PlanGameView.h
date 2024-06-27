
// PlanGameView.h : CPlanGameView ��Ľӿ�
//

#pragma once
#include "GameObject.h"
#include "MyPlane.h"
#include "EnemyPlane.h"
#include "MyBullet.h"
#include "EnemyBullet.h"
#include "Explosion.h"

#define TIME1 30
#define TIME2 300
#define TIME3 600

class CPlanGameView : public CView
{
protected: // �������л�����
	CPlanGameView();
	DECLARE_DYNCREATE(CPlanGameView)

// ����
public:
	CPlanGameDoc* GetDocument() const;

	/*����������Ϸ����*/
	MyPlane *myPlane;
	EnemyPlane *enemyPlane;
	MyBullet *myBullet;
	EnemyBullet *enemyBullet;
	Explosion *explosion;

	/*������Ϸ����洢����*/
	CObList myPlaneList;
	CObList enemyPlaneList;
	CObList myBulletList;
	CObList enemyBulletList;
	CObList explosionList;

	/*ս���ٶ�*/
	int myPlaneSpeed;	/*ս�������ٶ�*/
	int myLifeTime;		/*ս������ֵ*/
	int myScore;	/*ս���÷�*/
	int myLifeCount;	/*����ֵ�仯ֵ*/
	int myPass;		/*��ǰ�ؿ�*/
	int is_pass;	/*�Ƿ�ͨ��*/
	int is_pause;	/*�Ƿ���ͣ*/

// ����
public:
	int GetSpeed()	const{
		return myPlaneSpeed;
	}

	void SetSpeed(int s)
	{
		myPlaneSpeed = s;
	}

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	/*���ƻ���*/
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
// ʵ��
public:
	virtual ~CPlanGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/);
	afx_msg BOOL OnEraseBkgnd(CDC *pDC);
	/*����Ӧ�ó���*/
	afx_msg void OnRestart();
	/*��ͣӦ��*/
	afx_msg void OnPause();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // PlanGameView.cpp �еĵ��԰汾
inline CPlanGameDoc* CPlanGameView::GetDocument() const
   { return reinterpret_cast<CPlanGameDoc*>(m_pDocument); }
#endif

