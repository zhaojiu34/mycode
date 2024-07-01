// PlaneGameView.h : CPlaneGameView ��Ľӿ�
//


#pragma once

//Ӧ�ó������

class CMyPlane;
class CPlaneGameView : public CView
{

	enum ObjType{enEnemy, enEnemy1,enBomb, enBoss, enBoss1,enlife,enblue,enBall,enBossBall,enBigSkill,enExplosion};

protected: // �������л�����

	
	CPlaneGameView();
	DECLARE_DYNCREATE(CPlaneGameView)

// ����
public:

	CPlaneGameDoc* GetDocument() const;

	int HP = 100;//����ֵ
	int level = 1;//�ؿ�
	int Pattern = 1;//�ж��Ƿ���ͣ

	int flag = 1;//�Ƿ����¿�ʼ
	int flag1 = 1;//�ڶ��أ�������
	int flag2 = 1;//�����أ�������
	int flag3 = 1;//��󣬵�����

	int ff = 1;
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
	//��ʼ����Ϸ����ӭ���ڣ�������ʾ����
	BOOL InitGame();
	//������Ϸ
	void StopGame();

	//ˢ����Ϸ��֡���棺����ս������գ����������֣�Ѫ�����
	void UpdateFrame(CDC* pMemDC);


	void AI();

	//��ü���״̬1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}
	
	CMyPlane*  m_pMe;

	//����
	////ɾ���б�����Ԫ�� RemoveAll()
	//���б���ɾ��ָ��λ�õ�Ԫ�� RemoveAt(POSITION position)
	//��������βԪ�ص�λ�� GetNext(POSITION& rPosition);
	//��β����һ��Ԫ�ػ���һ���б��Ԫ�� AddTail(void* newElement);

	CObList    m_ObjList[11];



// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	//����ͼƬ��ʾ
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // PlaneGameView.cpp �еĵ��԰汾
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

