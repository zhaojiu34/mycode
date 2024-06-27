
// PlanGameView.cpp : CPlanGameView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "PlanGame.h"
#endif

#include "PlanGameDoc.h"
#include "PlanGameView.h"

#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include <MMSYSTEM.H>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlanGameView

IMPLEMENT_DYNCREATE(CPlanGameView, CView)

BEGIN_MESSAGE_MAP(CPlanGameView, CView)
	/*��׼��ӡ����*/
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_UPDATEUISTATE()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_RESTART, &CPlanGameView::OnRestart)
	ON_COMMAND(ID_PAUSE , &CPlanGameView::OnPause)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPlanGameView ����/����
//ս������ֵ��ս���÷֡�ս����������ֵ�����ؿ����Ƿ���ء��Ƿ���ͣ
CPlanGameView::CPlanGameView():
myLifeTime(10), myScore(0), myLifeCount(1), myPass(1), is_pass(0), is_pause(0)
{
	// TODO:  �ڴ˴���ӹ������
	/*Ĭ��ս�������ٶ�*/
	myPlaneSpeed = 30;

	/*���ظ�����Ϸ�����ͼƬ*/
	MyPlane::LoadImageW();
	EnemyPlane::LoadImageW();
	MyBullet::LoadImageUp();
	MyBullet::LoadImageDown();
	EnemyBullet::LoadImageW();
	Explosion::LoadImageW();
}

CPlanGameView::~CPlanGameView()
{
}

BOOL CPlanGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPlanGameView ����

void CPlanGameView::OnDraw(CDC* /*pDC*/)
{
	CPlanGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

/*CPlaneGameView ��ӡ*/
BOOL CPlanGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	/*Ĭ��׼��*/
	return DoPreparePrinting(pInfo);
}

void CPlanGameView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPlanGameView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPlanGameView ���

#ifdef _DEBUG
void CPlanGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlanGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlanGameDoc* CPlanGameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlanGameDoc)));
	return (CPlanGameDoc*)m_pDocument;
}
#endif //_DEBUG

// CPlanGameView ��Ϣ�������
int CPlanGameView::OnCreate(LPCREATESTRUCT lpcs)
{
	/*��ͼ����ʧ��*/
	if (CView::OnCreate(lpcs) == -1)
	{
		return -1;
	}//if

	/*TODO: Ӧ�ó���ר�ô��� 2016/01/11*/
	//��1������ս������
	myPlane = new MyPlane;
	//��2������˵���Ի��� (����#define IDYES 6 #define IDNO 7)
	if (AfxMessageBox(L"�鿴��Ϸ˵���������ǡ�����ֱ�ӽ�����Ϸ�������񡱣�", MB_YESNO) == 6)
	{
		AfxMessageBox(L"���������ս�����򣬿ո������������ɿ��ơ���ʼ����ֵΪ10,����һ���л���1�֣���������ﵽҪ�󼴿ɽ�����һ�ء����Źؿ����࣬�л��ٶȺ����������ӣ�ͨ��3�ؼ���ͨ�أ�");
		/*����˯��ʱ�䣬��λ����*/
		Sleep(1000);
	}//if
	/*���������棬����ˢ�¶�ʱ*/
	SetTimer(1, TIME1, NULL);
	SetTimer(2, TIME2, NULL);
	SetTimer(3, TIME3, NULL);
	return 0;
}

/************************************************************************/
/*nIDEvent�������ϲ��� SetTimer����*/
void CPlanGameView::OnTimer(UINT nIDEvent)
{
	/*��ȡ��������*/
	CDC *pDC = GetDC();
	CRect cRect;
	GetClientRect(&cRect);

	/*�豸���������� ---- CDC��*/
	CDC cdc;
	/*�ڴ��г�����ʱͼλͼ*/
	CBitmap bitMap1;

	//�ú�������һ����ָ���豸���ݵ��ڴ��豸�����Ļ�����DC��
	cdc.CreateCompatibleDC(pDC);
	//�ú���������ָ�����豸������ص��豸���ݵ�λͼ
	bitMap1.CreateCompatibleBitmap(pDC, cRect.Width(), cRect.Height());
	//�ú���ѡ��һ����ָ�����豸�����Ļ����У����¶����滻��ǰ����ͬ���͵Ķ���
	CBitmap *pOldBit = cdc.SelectObject(&bitMap1);
	//�ù̶��Ĺ���ɫ����ı����ο�
	cdc.FillSolidRect(cRect, RGB(51, 255, 255));
	//��ӱ���ͼƬ
	CBitmap bgBitMap;
	bgBitMap.LoadBitmap(IDB_BACKGROUND);

	/*λͼ2*/
	BITMAP bitMap2;
	bgBitMap.GetBitmap(&bitMap2);

	/*����һ�����ݵ�CDC*/
	CDC bgCdc;
	bgCdc.CreateCompatibleDC(&cdc);

	CBitmap *old = bgCdc.SelectObject(&bgBitMap);
	cdc.StretchBlt(0, 0, cRect.Width(), cRect.Height(), &bgCdc, 0, 0, bitMap2.bmWidth, bitMap2.bmHeight, SRCCOPY);

	/*==================================���ս��,�����ֶ�����ս��======================================*/
	if (myPlane != NULL)
	{
		myPlane->Draw(&cdc, TRUE);
	}//if
	/*����û����µļ�����Ϣ��ս��λ��������Ӧ*/
	if ((GetKeyState(VK_UP) < 0 || GetKeyState('W') < 0) && is_pause == 0)
	{
		/*ս�����곬�����ϱ߽�*/
		if (myPlane->GetPoint().y < cRect.top)
			myPlane->SetPoint(myPlane->GetPoint().x, cRect.bottom);
		else
			myPlane->SetPoint(myPlane->GetPoint().x, myPlane->GetPoint().y - myPlaneSpeed);
	}//if
	if ((GetKeyState(VK_DOWN) < 0 || GetKeyState('S') < 0) && is_pause == 0)//�·����
	{
		if (myPlane->GetPoint().y>cRect.bottom)
			myPlane->SetPoint(myPlane->GetPoint().x, cRect.top);
		else
			myPlane->SetPoint(myPlane->GetPoint().x, (myPlane->GetPoint().y + myPlaneSpeed));
	}//if
	if ((GetKeyState(VK_LEFT) < 0 || GetKeyState('A') < 0) && is_pause == 0)//�����
	{
		if (myPlane->GetPoint().x < cRect.left)
			myPlane->SetPoint(cRect.right, myPlane->GetPoint().y);
		else
			myPlane->SetPoint((myPlane->GetPoint().x - myPlaneSpeed), myPlane->GetPoint().y);
	}//if
	if ((GetKeyState(VK_RIGHT) < 0 || GetKeyState('D') < 0) && is_pause == 0)//�ҷ����
	{
		if (myPlane->GetPoint().x > cRect.right)
			myPlane->SetPoint(cRect.left, myPlane->GetPoint().y);
		else
			myPlane->SetPoint((myPlane->GetPoint().x + myPlaneSpeed), myPlane->GetPoint().y);
	}//if
	/*�ո�������ӵ���ս������˫���ӵ���*/
	if (GetKeyState(VK_SPACE) < 0 && is_pause == 0)
	{
		MyBullet *bullet1 = new MyBullet(myPlane->GetPoint().x, myPlane->GetPoint().y, UP);
		myBulletList.AddTail(bullet1);
		MyBullet *bullet2 = new MyBullet(myPlane->GetPoint().x + 35, myPlane->GetPoint().y, UP);
		myBulletList.AddTail(bullet2);
		/*����ս�������ӵ�����*/
		PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	}//if

	/*Z��������ͣ*/
	if (GetKeyState('Z') < 0)
	{
		is_pause += 1;
		if (is_pause != 1)
			is_pause = 0;
	}//if

	/*=====�����ӵл�,�л��������ը������ʱ�л��ٶ��������͹ؿ��й� =======================*/
	if (myPlane != NULL && is_pause == 0)
	{
		switch (nIDEvent)
		{
		case 2:
			{
				  /*��ǰ���ڵ�һ�ؿ�*/
				  if (1 == myPass)
				  {
					  int dir = UP;
					  EnemyPlane *enemyPlane1 = new EnemyPlane(dir);
					  enemyPlaneList.AddTail(enemyPlane1);
				  }//if
				  /*��ǰ���ڵڶ����Ϲؿ����л���������������ɳ�*/
				  else if (2 <= myPass)
				  {
					  int dir1 = UP;
					  EnemyPlane *enemyPlane1 = new EnemyPlane(dir1);
					  /*�л��ķ����ٶȸ��ݹؿ���ͬ*/
					  enemyPlane1->SetSpeed((rand() % 5 + 1) * myPass);
					  enemyPlaneList.AddTail(enemyPlane1);

					  int dir2 = DOWN;
					  EnemyPlane *enemyPlane2 = new EnemyPlane(dir2);
					  enemyPlane2->SetSpeed((rand() % 5 + 1) * myPass);
					  enemyPlaneList.AddTail(enemyPlane2);
				  }//elif
			}//case
			break;

		default:
			break;
		}//switch

		/*ɾ������Ϸ����֮��ĵл�*/
		POSITION epPos = NULL, epPosTmp = NULL;
		epPos = enemyPlaneList.GetHeadPosition();
		while (epPos != NULL)
		{
			epPosTmp = epPos;
			enemyPlane = (EnemyPlane *)enemyPlaneList.GetNext(epPos);
			/*�жϵл��Ƿ����*/
			if (enemyPlane->GetPoint().x < cRect.left || enemyPlane->GetPoint().x > cRect.right ||
				enemyPlane->GetPoint().y < cRect.top || enemyPlane->GetPoint().y > cRect.bottom)
			{
				enemyPlaneList.RemoveAt(epPosTmp);
				delete enemyPlane;
			}//if
			else{
				enemyPlane->Draw(&cdc, TRUE);
				switch (nIDEvent)
				{
				//���ö�ʱ�������л�ը��
				case 3:
					{
						  EnemyBullet *eb = new EnemyBullet(enemyPlane->GetPoint().x + 17, enemyPlane->GetPoint().y + 30, enemyPlane->GetDirection());
						  enemyBulletList.AddTail(eb);
						  /*�л������ӵ�*/
						  PlaySound((LPCTSTR)IDR_WAVE3, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					}//case
					break;
				}//switch
			}//else
		}//while

		/*�жϸõл�������ӵ��Ƿ���磬��������ɾ��*/
		POSITION ebPos = NULL, ebPosTmp = NULL;
		ebPos = enemyBulletList.GetHeadPosition();
		while (ebPos != NULL)
		{
			ebPosTmp = ebPos;
			enemyBullet = (EnemyBullet *)enemyBulletList.GetNext(ebPos);
			if (enemyBullet->GetPoint().x <cRect.left || enemyBullet->GetPoint().x > cRect.right ||
				enemyBullet->GetPoint().y < cRect.top || enemyBullet->GetPoint().y >cRect.bottom)
			{
				enemyBulletList.RemoveAt(ebPosTmp);
				delete enemyBullet;
			}//if
			else{
				enemyBullet->Draw(&cdc, TRUE);
			}//else
		}//while
	}//if

	/*=============================����ս�������ӵ�======================================*/
	if (myPlane != NULL && is_pause == 0)
	{
		/*�����ӵ�λ��*/
		POSITION mbPos = NULL, mbPosTmp = NULL;
		mbPos = myBulletList.GetHeadPosition();
		while (mbPos != NULL)
		{
			mbPosTmp = mbPos;
			myBullet = (MyBullet *)myBulletList.GetNext(mbPos);
			/*ɾ��Խ����ӵ�*/
			if (myBullet->GetPoint().x < cRect.left || myBullet->GetPoint().x > cRect.right ||
				myBullet->GetPoint().y < cRect.top || myBullet->GetPoint().y > cRect.bottom)
			{
				myBulletList.RemoveAt(mbPosTmp);
				delete myBullet;
			}//if
			else
				myBullet->Draw(&cdc, TRUE);
		}//while
	}//if

	/*=================��1����ӱ�ըЧ����ս���ӵ����ел�================================*/
	if (myPlane != NULL && is_pause == 0)
	{
		POSITION explosionPos = NULL;
		explosionPos = explosionList.GetHeadPosition();
		/*��鱬ը�б��ǿ�ʱ��������λ����ʾ*/
		while (explosionPos != NULL)
		{
			explosion = (Explosion *)explosionList.GetNext(explosionPos);
			explosion->Draw(&cdc, TRUE);
		}//while
		POSITION mbPos, mbPosTmp, epPos, epPosTmp;
		for (mbPos = myBulletList.GetHeadPosition(); (mbPosTmp = mbPos) != NULL;)
		{
			/*ս���ӵ�*/
			myBullet = (MyBullet *)myBulletList.GetNext(mbPos);
			/*���ս���ӵ��ľ�������*/
			CRect myBulletRect = myBullet->GetRect();
			/*�������ел���������ս���ӵ���������ը�����ٵл�*/
			for (epPos = enemyPlaneList.GetHeadPosition(); (epPosTmp = epPos) != NULL;)
			{
				enemyPlane = (EnemyPlane *)enemyPlaneList.GetNext(epPos);
				/*��õл����ھ�������*/
				CRect enemyPlaneRect = enemyPlane->GetRect();
				/*�жϸõл���ս���ӵ���û�н���*/
				CRect tmpRect;
				if (tmpRect.IntersectRect(&myBulletRect, &enemyPlaneRect))
				{
					/*����ը������뱬ը�б�*/
					Explosion *explosion = new Explosion((enemyPlane->GetPoint().x + 17), (enemyPlane->GetPoint().y + 17));
					explosionList.AddTail(explosion);
					/*���ű�ը����*/
					PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					
					/*��ը��ɾ���ӵ�*/
					myBulletList.RemoveAt(mbPosTmp);
					delete myBullet;

					/*ɾ���л�*/
					enemyPlaneList.RemoveAt(epPosTmp);
					delete enemyPlane;

					/*����һ���л���ս����һ��*/
					++myScore;
					break;
				}//if
			}
		}//for
	}//if

	/*=================��2����ӱ�ըЧ�����л��ӵ�����ս��================================*/
	if (myPlane != NULL && is_pause == 0)
	{
		/*�л��ӵ�λ��*/
		POSITION ebPos, ebPosTmp;
		for (ebPos = enemyBulletList.GetHeadPosition(); (ebPosTmp = ebPos) != NULL;)
		{
			enemyBullet = (EnemyBullet *)enemyBulletList.GetNext(ebPos);
			/*��õл��ӵ��ľ�������*/
			CRect enemyBulletRect = enemyBullet->GetRect();
			/*���ս����������*/
			CRect myPlaneRect = myPlane->GetRect();
			/*�ж����޽���*/
			CRect tmpRect;
			if (tmpRect.IntersectRect(&enemyBulletRect, &myPlaneRect))
			{
				/*����ը������뱬ը�б�*/
				Explosion *explosion = new Explosion((enemyPlane->GetPoint().x + 17), (enemyPlane->GetPoint().y + 17));
				explosionList.AddTail(explosion);
				/*���ű�ը����*/
				PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				/*ɾ���л��ӵ�*/
				enemyBulletList.RemoveAt(ebPosTmp);
				delete enemyBullet;

				/*����ֵ��һ*/
				--myLifeTime;
				if (0 == myLifeTime)
				{
					/*ɾ��ս��*/
					delete myPlane;
					myPlane = NULL;
				}//if
				break;
			}//if
		}//for
	}//if
	/*=================��3����ӱ�ըЧ����ս����л���ײ================================*/
	if (myPlane != NULL && is_pause == 0)
	{
		POSITION epPos, epPosTmp;
		for (epPos = enemyPlaneList.GetHeadPosition(); (epPosTmp = epPos) != NULL;)
		{
			enemyPlane = (EnemyPlane *)enemyPlaneList.GetNext(epPos);
			/*��õл���������*/
			CRect enemyPlaneRect = enemyPlane->GetRect();
			/*���ս����������*/
			CRect myPlaneRect = myPlane->GetRect();

			CRect tmpRect;
			if (tmpRect.IntersectRect(&enemyPlaneRect, &myPlaneRect))
			{
				Explosion *explosion = new Explosion((enemyPlane->GetPoint().x + 18), (enemyPlane->GetPoint().y + 18));
				explosionList.AddTail(explosion);
				/*���ű�ը����*/
				PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				/*ɾ���л�*/
				enemyPlaneList.RemoveAt(epPosTmp);
				delete enemyPlane;

				/*ս������ֵ��һ*/
				--myLifeTime;
				if (0 == myLifeTime)
				{
					/*ɾ��ս������*/
					delete myPlane;
					myPlane = NULL;
				}//if
				break;
			}//if
		}//for
	}//if
	/*=================��4����ӱ�ըЧ����ս���ӵ���л��ӵ���ײ================================*/
	if (myPlane != NULL && is_pause == 0)
	{
		/*����ս���ӵ����л��ӵ�λ��*/
		POSITION mbPos, mbPosTmp, ebPos, ebPosTmp;
		for (mbPos = myBulletList.GetHeadPosition(); (mbPosTmp = mbPos) != NULL;)
		{
			myBullet = (MyBullet *)myBulletList.GetNext(mbPos);
			/*���ս���ӵ��ľ�������*/
			CRect myBulletRect = myBullet->GetRect();
			for (ebPos = enemyBulletList.GetHeadPosition(); (ebPosTmp = ebPos) != NULL;)
			{
				enemyBullet = (EnemyBullet *)enemyBulletList.GetNext(ebPos);
				/*��õл��ӵ��ľ�������*/
				CRect enemyBulletRect = enemyBullet->GetRect();
				/*�ж����޽���*/
				CRect tmpRect;
				if (tmpRect.IntersectRect(&myBulletRect, &enemyBulletRect))
				{
					//����ը������ӵ���ը������
					Explosion *explosion = new Explosion((enemyBullet->GetPoint().x + 17), (enemyBullet->GetPoint().y + 17));
					explosionList.AddTail(explosion);

					/*���ű�ը����*/
					PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					//��ը��ɾ��ս���ӵ�
					myBulletList.RemoveAt(mbPosTmp);
					delete myBullet;

					/*ɾ���л��ӵ�*/
					enemyBulletList.RemoveAt(ebPosTmp);
					delete enemyBullet;

					/*ս����һ��*/
					++myLifeTime;
					break;
				}//if
			}//for
		}//for
	}//if
	/*=================================��Ϸ�����������Ϸ��ǰ��Ϣ========================*/
	if (myPlane != NULL && is_pause == 0)
	{
		HFONT font;
		font = CreateFont(20, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 10, 0);
		cdc.SelectObject(font);
		CString str;
		cdc.SetTextColor(RGB(255, 0, 0));
		str.Format(_T("��ǰ�ؿ�:%d"), myPass);
		cdc.TextOutW(10, 20, str);
		str.Format(_T("��ǰ�÷�:%d"), myScore);
		cdc.TextOutW(10, 40, str);
		str.Format(_T("ʣ������:%d"), myLifeTime);
		cdc.TextOutW(10, 60, str);
	}//if
	/*��Ҫ������ս������ֵ*/
	if (myPlane != NULL && is_pause == 0)
	{
		if (myScore > 10 * myLifeCount * myPass)
		{
			myLifeTime++;
			myLifeCount++;
		}
	}//if
	/*=================================������һ�ؽ���========================*/
	if (myPlane != NULL && myScore > 50 * myPass && is_pause == 0)
	{
		delete myPlane;
		myPlane = NULL;
		/*��һ���Ѿ�ͨ��*/
		is_pass = 1;
	}//if
	/*������һ��*/
	if (is_pass == 1)
	{
		/*���˵����أ������Ϸս����ͨ��*/
		if (3 == myPass)
		{
			/*�رռ�ʱ��*/
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);
			if (AfxMessageBox(L"�ۣ���ϲ����ͨ�أ��Ƿ����¿�ʼ��", MB_YESNO) == 6)
			{
				/*���ս������*/
				myPlaneList.RemoveAll();
				/*��յл�����*/
				enemyPlaneList.RemoveAll();
				/*���ս���ӵ�����*/
				myBulletList.RemoveAll();
				/*��յл��ӵ�����*/
				enemyBulletList.RemoveAll();
				/*���ը������*/
				explosionList.RemoveAll();

				/*�����µ�ս��*/
				myPlane = new MyPlane;
				myScore = 0;
				myLifeCount = 1;
				myLifeTime = 10;
				myPass = 1;
				is_pass = 0;
				SetTimer(1, TIME1, NULL);
				SetTimer(2, TIME2, NULL);
				SetTimer(3, TIME3, NULL);
			}//if
			else
				exit(1);
		}//if
		else{
			/*�رռ�ʱ��*/
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);
			if (AfxMessageBox(L"�ۣ���ϲ����ͨ���˹أ��Ƿ������һ�أ�", MB_YESNO) == 6)
			{
				/*���ս������*/
				myPlaneList.RemoveAll();
				/*��յл�����*/
				enemyPlaneList.RemoveAll();
				/*���ս���ӵ�����*/
				myBulletList.RemoveAll();
				/*��յл��ӵ�����*/
				enemyBulletList.RemoveAll();
				/*���ը������*/
				explosionList.RemoveAll();
				/*�����µ�ս��*/
				myPlane = new MyPlane;
				myScore = 0;
				myLifeCount = 1;
				myLifeTime = 10;
				++myPass;
				is_pass = 0;
				SetTimer(1, TIME1, NULL);
				SetTimer(2, TIME2, NULL);
				SetTimer(3, TIME3, NULL);
			}//if
			else
				exit(1);
		}//else
	}//if
	/*=================================������Ϸ�Ľ���========================*/
	if (myPlane == NULL && is_pass == 0 && is_pause == 0)
	{
		KillTimer(1);
		KillTimer(2);
		KillTimer(3);
		if (AfxMessageBox(L"GAME OVER��COME ON �����¿�ʼ��", MB_YESNO) == 6)
		{
			/*���ս������*/
			myPlaneList.RemoveAll();
			/*��յл�����*/
			enemyPlaneList.RemoveAll();
			/*���ս���ӵ�����*/
			myBulletList.RemoveAll();
			/*��յл��ӵ�����*/
			enemyBulletList.RemoveAll();
			/*���ը������*/
			explosionList.RemoveAll();

			/*�����µ�ս��*/
			myPlane = new MyPlane;
			myScore = 0;
			myLifeCount = 1;
			myLifeTime = 10;
			myPass = 1;
			is_pass = 0;
			SetTimer(1, TIME1, NULL);
			SetTimer(2, TIME2, NULL);
			SetTimer(3, TIME3, NULL);
		}//if
		else
			exit(1);
	}//if

	/*�ú�����ָ����Դ�豸���������е����ؽ���λ�飨bit_block��ת�����Դ��͵�Ŀ���豸����*/
	pDC->BitBlt(0, 0, cRect.Width(), cRect.Height(), &cdc, 0, 0, SRCCOPY);
	cdc.DeleteDC();
	bitMap1.DeleteObject();
	ReleaseDC(pDC);
	CView::OnTimer(nIDEvent);
}//onTimer
/*===================================================================================*/
void CPlanGameView::OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ	
}

BOOL CPlanGameView::OnEraseBkgnd(CDC *pDC)
{
	return TRUE;
}
/*����Ӧ�ó���*/
void CPlanGameView::OnRestart()
{
	/*���ս������*/
	myPlaneList.RemoveAll();
	/*��յл�����*/
	enemyPlaneList.RemoveAll();
	/*���ս���ӵ�����*/
	myBulletList.RemoveAll();
	/*��յл��ӵ�����*/
	enemyBulletList.RemoveAll();
	/*���ը������*/
	explosionList.RemoveAll();

	/*�����µ�ս��*/
	myPlane = new MyPlane;
	myScore = 0;
	myLifeCount = 1;
	myLifeTime = 10;
	myPass = 1;
	is_pass = 0;

	SetTimer(1, TIME1, NULL);
	SetTimer(2, TIME2, NULL);
	SetTimer(3, TIME3, NULL);
}
/*��ͣӦ��*/
void CPlanGameView::OnPause()
{
	// TODO: �ڴ���������������
	Sleep(1000);
}
void CPlanGameView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnMouseMove(nFlags, point);
	if (is_pause == 0)
		myPlane->SetPoint(point.x, point.y);
}

void CPlanGameView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnLButtonDown(nFlags, point);
	if (is_pause == 0)
	{
		MyBullet *myBullet1 = new MyBullet(myPlane->GetPoint().x, myPlane->GetPoint().y, UP);
		/*�����ӵ�����*/
		PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		myBulletList.AddTail(myBullet1);
		MyBullet *myBullet2 = new MyBullet(myPlane->GetPoint().x + 35, myPlane->GetPoint().y, UP);
		myBulletList.AddTail(myBullet2);
	}//if
}