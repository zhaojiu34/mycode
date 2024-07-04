// PlaneGameView.h : CPlaneGameView ��Ľӿ�
//


#pragma once

class CMyPlane;
class CPlaneGameView : public CView
{

	enum ObjType{ enEnemy, enBomb, enBall, enExplosion, enBoss, enlife, enbigb, enEnemy2};

protected: // �������л�����
	CPlaneGameView();
	DECLARE_DYNCREATE(CPlaneGameView)

// ����
public:
	int blood=10;
	int score = 0;
	int level = 1;
	int bigboll = 5;
	int mm=1;//ģʽ
	int Pattern = 1;
	int flag = 1;//�Ƿ����¿�ʼ
	int flag1 = 1;//�ڶ��أ�������
	int flag2 = 1;//�����أ�������
	int flag3 = 1;//���Ĺأ�������
	int flag4 = 1;//����أ�������
	int flag5 = 1;//��������
	int ff=1;
	CPlaneGameDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CPlaneGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//�ڴ�DC
	CDC*        m_pMemDC;
	//�豸DC
	CClientDC*  m_pDC;
	//�ڴ�λͼ
	CBitmap*    m_pMemBitmap;


protected:
	//��ʼ����Ϸ
	BOOL InitGame();
	//������Ϸ
	void StopGame();

	//ˢ����Ϸ��֡����
	void UpdateFrame(CDC* pMemDC);


	void AI();

	//��ü���״̬1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}
	
	CMyPlane*  m_pMe;
	CObList    m_ObjList[8];



// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // PlaneGameView.cpp �еĵ��԰汾
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

