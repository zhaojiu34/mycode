// PlaneGameView.cpp : CPlaneGameView 类的实现
//

#include "stdafx.h"
#include "PlaneGame.h"

#include "PlaneGameDoc.h"
#include "PlaneGameView.h"
#include "MyPlane.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Bomb.h"
#include "Boss.h"
#include "Boss1.h"
#include "BossBall.h"
#include "Ball.h"
#include "Explosion.h"
#include <atlimage.h>
#include "life.h"
#include "blue.h"
#include "BigSkill.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneGameView

IMPLEMENT_DYNCREATE(CPlaneGameView, CView)

BEGIN_MESSAGE_MAP(CPlaneGameView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()

END_MESSAGE_MAP()

// CPlaneGameView 构造/析构

CPlaneGameView::CPlaneGameView():m_pMe(NULL)
{
	// TODO: 在此处添加构造代码
	
}

CPlaneGameView::~CPlaneGameView()
{
}

BOOL CPlaneGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPlaneGameView 绘制

void CPlaneGameView::OnDraw(CDC* /*pDC*/)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPlaneGameView 打印

BOOL CPlaneGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPlaneGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPlaneGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPlaneGameView 诊断

#ifdef _DEBUG
void CPlaneGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneGameDoc* CPlaneGameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneGameDoc)));
	return (CPlaneGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneGameView 消息处理程序
void CPlaneGameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	// TODO: 在此添加专用代码和/或调用基类
	//初始化游戏
	InitGame();
}
void CPlaneGameView::StopGame()
{
	delete m_pMe;
	delete m_pMemDC;
	delete m_pDC;
	delete m_pMemBitmap;
}

BOOL CPlaneGameView::InitGame()
{
	CRect rc;
	GetClientRect(rc);

	//产生随机数种子
	srand( (unsigned)time( NULL ) );

	//建立设备DC
	m_pDC = new CClientDC(this);

	//建立内存DC
	m_pMemDC = new CDC;
	m_pMemDC->CreateCompatibleDC(m_pDC);

	//建立内存位图
	m_pMemBitmap = new CBitmap;
	m_pMemBitmap->CreateCompatibleBitmap(m_pDC,GAME_WIDTH,GAME_HEIGHT);

	//将位图选入内存DC
	m_pMemDC->SelectObject(m_pMemBitmap);

	CMyPlane::LoadImage();
	CEnemy::LoadImage();
	CEnemy1::LoadImage();
	CBomb::LoadImage();
	CBall::LoadImage();
	CExplosion::LoadImage();
	Boss::LoadImage();
	Boss1::LoadImage();
	life::LoadImage();
	cblue::LoadImage();
	BossBall::LoadImage();
	BigSkill::LoadImage();

	//开始游戏
		//产生主角(战机)
	if (AfxMessageBox(L"欢迎来到飞机大战", MB_YESNO) == 6)
	{
		m_pMe = new CMyPlane;
		AfxMessageBox(L"游戏基本操作:\n上下左右 控制飞机 \nEsc键 退出\nX键 技能1 \nC键 技能2 \nP键 暂停\nO键 继续\n空格键 发射导弹\nctrl键 转换导弹\n空格键 开始游戏", MB_OK);
	}
	else
	{
		exit(1);
	}
	SetTimer(1, 30, NULL);
	return TRUE;
}
int score = 0;
int blood = 300;
int blue = 300;
int m=1;
void CPlaneGameView::UpdateFrame(CDC* pMemDC)
{
	//绘制天空
	CRect rect_Client;
	GetClientRect(&rect_Client);
	//滚动背景
	if (level == 1)
	{
		static int ImageLocation = 0;//背景图片截取位置初始位置
		CDC m_CDC;//缓冲区
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BITMAP1);//创建位图
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//设置动态背景
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}
	if (level == 2)
	{
		static int ImageLocation = 0;//背景图片截取位置初始位置
		CDC m_CDC;//缓冲区
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BITMAP2);//创建位图
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//设置动态背景
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}
	if (level == 3)
	{
		static int ImageLocation = 0;//背景图片截取位置初始位置
		CDC m_CDC;//缓冲区
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BITMAP3);//创建位图
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//设置动态背景
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}

	//绘制我方战机
	if (m_pMe != NULL)
	{
		m_pMe->Draw(m_pMemDC, FALSE);
	}
	else
	{   
		//Game Over
		/*
		CString str = _T("Game Over!");
		pMemDC->SetBkMode(TRANSPARENT);
		pMemDC->SetTextAlign(TA_CENTER);
		pMemDC->SetTextColor(RGB(255, 0, 0));
		pMemDC->TextOut(GAME_WIDTH / 2, GAME_HEIGHT / 2, str);
		*/
			exit(1);
	}
	//绘制血条
	pMemDC->FillSolidRect(30, 655, 300, 20, RGB(256, 0, 0));
	pMemDC->FillSolidRect(30, 655, blood, 20, RGB(255, 0, 0));
	CString str;
	CString str1 = _T("HP：");
	pMemDC->SetBkMode(TRANSPARENT);
	pMemDC->SetTextAlign(TA_CENTER);
	pMemDC->SetTextColor(RGB(255, 0, 0));
	pMemDC->TextOut(20, 655, str1);
	//绘制蓝量
	pMemDC->FillSolidRect(30, 700, 300, 20, RGB(256, 0, 0));
	pMemDC->FillSolidRect(30, 700, blue, 20, RGB(0, 0, 255));
	CString str2;
	CString str3 = _T("MP：");
	pMemDC->SetBkMode(TRANSPARENT);
	pMemDC->SetTextAlign(TA_CENTER);
	pMemDC->SetTextColor(RGB(255, 0, 0));
	pMemDC->TextOut(20, 704, str3);
	//积分情况
	CString grade = _T("得分：");
	CString grade1 = _T("");
	grade1.Format(_T("%d"), score);
	pMemDC->SetBkMode(TRANSPARENT);
	pMemDC->SetTextAlign(TA_CENTER);
	pMemDC->SetTextColor(RGB(255, 0, 0));
	pMemDC->TextOut(50, 20, grade + grade1);
	//退出
	if (GetKey(VK_ESCAPE))
	{
		exit(1);
	}
	//绘制 导弹、爆炸、敌机、子弹
	for(int i=0;i<11;i++)
	{
		POSITION pos1,pos2;
		for( pos1 = m_ObjList[i].GetHeadPosition(); ( pos2 = pos1 ) != NULL; )
		{
			CGameObject* pObj = (CGameObject*)m_ObjList[i].GetNext( pos1 );
			if(!pObj->Draw(pMemDC,FALSE))
			{
				m_ObjList[i].RemoveAt(pos2);
				delete pObj;
			}
		}
	}
	//复制内存DC到设备DC
	m_pDC->BitBlt(0,0,GAME_WIDTH,GAME_HEIGHT,m_pMemDC,0,0,SRCCOPY);
}
int k = 1;
int n = 1;
void CPlaneGameView::AI()
{
	if (GetKey('C') == 1 && n==1)
	{
		delete m_pMe;
		m_pMe=NULL;
		m_pMe = new CMyPlane;
		blue = 300;
		blood = 300;
		n = 0;
	}
	ff = 1;
	if (blood <= 0)
	{
		KillTimer(1);
		if (AfxMessageBox(L"血量不足，让我们重新开始吧！", MB_YESNO) == 6)
		{
			delete m_pMe;
			m_pMe = new CMyPlane;
			for (int i = 0; i < 11; i++)
				m_ObjList[i].RemoveAll();
			blood = 300;
			score = 0;
			blue = 300;
			level = 1;
			k = 1;
			m = 1;
			flag1 = 1;//第二关，弹窗口
			flag2 = 1;//第三关，弹窗口
			flag3 = 1;//弹窗口

		}
		else
		{
			delete m_pMe;
			m_pMe = NULL;
		}
		SetTimer(1, 30, NULL);
	}

	//随机产生敌机1
	static int nCreator = rand() %5+10;
	if (level <=3)
	{
		if(nCreator<=0)
	{
		nCreator = rand()%5+20;
		m_ObjList[enEnemy].AddTail(new CEnemy);
	}
		nCreator--;
	}
	//随机产生敌机2
	static int nCreator1 = rand() % 5 + 10;
	if (level == 2||level==3)
	{
		if (nCreator1 <= 0)
		{
			nCreator1 = rand() % 5 + 10;
			m_ObjList[enEnemy1].AddTail(new CEnemy1);
		}
		nCreator1--;
	}
	//随机产生小boss
	static int nCreator2 = rand() % 5 + 10;
	if (level ==1 &&m==1)
	{
		if (nCreator2 <= 0)
		{
			m_ObjList[enBoss].AddTail(new Boss);
			m = 0;
		}
		nCreator2--;
	}
	//随机产生boss1
	static int nCreator3 = rand() % 5 + 10;
	if (level == 3 && k == 1)
	{
		if (nCreator3 <= 0)
		{
			m_ObjList[enBoss1].AddTail(new Boss1);
			k = 0;
		}
		nCreator3--;
	}
	//产生小心心
	static int nCreator4 = rand() % 5 + 10;
	if (level < 4)
	{
		if (nCreator4 <= 0)
		{
			nCreator4 = rand() % 1000 + 10;
			m_ObjList[enlife].AddTail(new life);
		}
		nCreator4--;
	}
	//产生小蓝瓶
	static int nCreator5 = rand() % 5 + 10;
	if (level < 4)
	{
		if (nCreator5 <= 0)
		{
			nCreator5 = rand() % 500 + 10;
			m_ObjList[enblue].AddTail(new cblue);
		}
		nCreator5--;
	}

	if(m_pMe==NULL)
		return;

	//检测四个方向键，移动战机
	for(int i=0;i<4;i++)
	{
		int nMeMotion=0;
		m_pMe->SetVerMotion(0);
		m_pMe->SetHorMotion(0);

		nMeMotion = GetKey(VK_UP);
		if(nMeMotion==1)
			m_pMe->SetVerMotion(1);
		    
		nMeMotion = GetKey(VK_DOWN);
		if(nMeMotion==1)
			m_pMe->SetVerMotion(-1);

		nMeMotion = GetKey(VK_RIGHT);
		if(nMeMotion==1)
			m_pMe->SetHorMotion(1);

		nMeMotion = GetKey(VK_LEFT);
		if(nMeMotion==1)
			m_pMe->SetHorMotion(-1);
	}
	
	//产生战机导弹
	if (GetKey(VK_SPACE) == 1)//按下了空格键
	{
		CPoint pt = m_pMe->GetPoint();
		if (m_pMe != NULL && m_pMe->Fired())
		{
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 20, pt.y + 10, 0, 10));
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 40, pt.y + 10, 0, 10));

		}
	}
	if (GetKey(VK_CONTROL) == 1)//按下了ctrl键
	{
		blue -= 0.5;
		if (blue > 0)
		{
			CPoint pt = m_pMe->GetPoint();
		if (m_pMe != NULL && m_pMe->Fired())
		{
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 20, pt.y + 10, 0, 10));
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 40, pt.y + 10, 0, 10));
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 20, pt.y + 10, -0.5, 10));
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 40, pt.y + 10, 0.5, 10));
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 20, pt.y + 10, -1, 10));
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 40, pt.y + 10, 1, 10));

		}
		}
		
	}
	//产生大招
	if (GetKey('X') == 1 &&blue>=50)//按下了X键
	{
		if (m_pMe != NULL && m_pMe->Fired())
		{
			CPoint pt = m_pMe->GetPoint();
			m_ObjList[enBigSkill].AddTail(new BigSkill(pt.x + 25, pt.y - 10));
			blue-=50;
		}
	}


	//敌机1发射子弹

	CPoint PlanePt = m_pMe->GetPoint();
	for(POSITION ePos=m_ObjList[enEnemy].GetHeadPosition();ePos!=NULL;)
	{
          CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos);
		  if(!pEnemy->Fired())
			  continue;
		  CPoint  ePt = pEnemy->GetPoint();

		  BOOL by=FALSE;

		  //敌机在战机前面
		  if(pEnemy->GetMontion()==1 && ePt.y<PlanePt.y)
		         by=  TRUE;
		  //敌机在战机后面
		  if(pEnemy->GetMontion()==-1 && ePt.y>PlanePt.y)
				 by=  TRUE;	

		  if(by && ePt.x >= PlanePt.x && ePt.x<PlanePt.x+CMyPlane::PLANE_WIDTH)
		  {
              m_ObjList[enBall].AddTail(new CBall(ePt.x+10,ePt.y+10,pEnemy->GetMontion()));
		  }
	}
	//敌机2发射子弹
	for (POSITION ePos = m_ObjList[enEnemy1].GetHeadPosition(); ePos != NULL;)
	{
		CEnemy1* pEnemy1 = (CEnemy1*)m_ObjList[enEnemy1].GetNext(ePos);
		if (!pEnemy1->Fired())
			continue;
		CPoint  ePt = pEnemy1->GetPoint();

		BOOL by = FALSE;

		//敌机在战机前面
		if (pEnemy1->GetMontion() == 1 && ePt.y < PlanePt.y)
			by = TRUE;

		if (by && ePt.x >= PlanePt.x && ePt.x < PlanePt.x + CMyPlane::PLANE_WIDTH)
		{
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 10, ePt.y + 10, pEnemy1->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 20, ePt.y + 10, pEnemy1->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 30, ePt.y + 10, pEnemy1->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 40, ePt.y + 10, pEnemy1->GetMontion()));
		}
	}
	//小boss发射子弹
	for (POSITION ePos = m_ObjList[enBoss].GetHeadPosition(); ePos != NULL;)
	{
		Boss* pBoss = (Boss*)m_ObjList[enBoss].GetNext(ePos);
		if (!pBoss->Fired())
			continue;
		CPoint  ePt = pBoss->GetPoint();

		BOOL by = FALSE;

		//敌机在战机前面
		if (pBoss->GetMontion() == 1 && ePt.y < PlanePt.y)
			by = TRUE;

		if (by && ePt.x >= PlanePt.x && ePt.x < PlanePt.x + CMyPlane::PLANE_WIDTH)
		{
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 10, ePt.y + 10, pBoss->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 20, ePt.y + 20, pBoss->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 30, ePt.y + 20, pBoss->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 40, ePt.y + 10, pBoss->GetMontion()));
		}
	}
	//boss1发射子弹
	PlanePt = m_pMe->GetPoint();
	for (POSITION ePos = m_ObjList[enBoss1].GetHeadPosition(); ePos != NULL;)
	{
		Boss1* pBoss1 = (Boss1*)m_ObjList[enBoss1].GetNext(ePos);
		if (!pBoss1->Fired())
			continue;
		CPoint  ePt = pBoss1->GetPoint();

		BOOL by = FALSE;

		//敌机在战机前面
		if (pBoss1->GetMontion() == 1 && ePt.y < PlanePt.y)
			by = TRUE;
		if (by && rand() % 6 == 1)
		{
			m_ObjList[enBossBall].AddTail(new BossBall(ePt.x + 50, ePt.y + 10, -1500));
			m_ObjList[enBossBall].AddTail(new BossBall(ePt.x + 100, ePt.y + 10, 1500));
		}
		if (by && rand() % 5 == 1)
		{
			m_ObjList[enBossBall].AddTail(new BossBall(ePt.x + 75, ePt.y - 10, 0));
		}
	}
	//敌机子弹炸掉战机
	POSITION bPos1=NULL,bPos2=NULL;
	CRect mRect = m_pMe->GetRect();
	for(bPos1=m_ObjList[enBall].GetHeadPosition();( bPos2 = bPos1 ) != NULL;)
	{
		CBall* pBall = (CBall*)m_ObjList[enBall].GetNext(bPos1);
		CRect bRect = pBall->GetRect();
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,mRect))
		{
			//添加爆炸效果
			m_ObjList[enExplosion].AddTail(
				new CExplosion(mRect.left,mRect.top)
				);

			//删除子弹
			m_ObjList[enBall].RemoveAt(bPos2);
			delete pBall;

			//删除战机
			blood -= 15;
		}
	}
	//Boss1子弹击中战机
	if (blood > 0)
		mRect = m_pMe->GetRect();
	for (bPos1 = m_ObjList[enBossBall].GetHeadPosition(); (bPos2 = bPos1) != NULL;)
	{
		BossBall* plaser = (BossBall*)m_ObjList[enBossBall].GetNext(bPos1);
		CRect bRect = plaser->GetRect();
		CRect tmpRect;
		if (tmpRect.IntersectRect(&bRect, mRect))
		{
			//添加爆炸效果
			m_ObjList[enExplosion].AddTail(
				new CExplosion(mRect.left, mRect.top)
			);
			//删除子弹
			m_ObjList[enBossBall].RemoveAt(bPos2);
			delete plaser;
			//删除战机
			blood -= 20;
		}
	}
	//加血
	POSITION bPos5 = NULL, bPos6 = NULL;
	//CRect mRect = m_pMe->GetRect();
	for (bPos5 = m_ObjList[enlife].GetHeadPosition(); (bPos6 = bPos5) != NULL;)
	{
		life* plife = (life*)m_ObjList[enlife].GetNext(bPos5);
		CRect bRect = plife->GetRect();
		CRect tmpRect;
		if (tmpRect.IntersectRect(&bRect, mRect))
		{

			if (m_pMe != NULL)
			{
				m_ObjList[enlife].RemoveAt(bPos6);
				delete plife;
				if (blood < 300)
				{
					blood+=10;
				}
			}
		}
	}
	//加蓝
	for (bPos5 = m_ObjList[enblue].GetHeadPosition(); (bPos6 = bPos5) != NULL;)
	{
		cblue* pblue = (cblue*)m_ObjList[enblue].GetNext(bPos5);
		CRect bRect = pblue->GetRect();
		CRect tmpRect;
		if (tmpRect.IntersectRect(&bRect, mRect))
		{

			if (m_pMe != NULL)
			{
				m_ObjList[enblue].RemoveAt(bPos6);
				delete pblue;
				if (blue < 300)
				{
					blue += 30;
				}
			}
		}
	}
	//战机导弹炸掉敌机1
	POSITION mPos1=NULL,mPos2=NULL;
	for(mPos1=m_ObjList[enBomb].GetHeadPosition();(mPos2=mPos1)!=NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos1);
		CRect bRect = pBomb->GetRect();

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();
			CRect tmpRect;
			if (tmpRect.IntersectRect(&bRect, mRect))
			{
				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left, mRect.top)
				);
				//删除导弹
				m_ObjList[enBomb].RemoveAt(mPos2);
				delete pBomb;

				//删除敌机
				score += 10;
				m_ObjList[enEnemy].RemoveAt(ePos2);
				delete pEnemy;
				break;
			}
		}
	}
	//战机导弹炸毁敌机2
	mPos1 = NULL; mPos2 = NULL;
	for (mPos1 = m_ObjList[enBomb].GetHeadPosition(); (mPos2 = mPos1) != NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos1);
		CRect bRect = pBomb->GetRect();

		POSITION ePos1 = NULL, ePos2 = NULL;
		for (ePos1 = m_ObjList[enEnemy1].GetHeadPosition(); (ePos2 = ePos1) != NULL;)
		{
			CEnemy1* pEnemy1 = (CEnemy1*)m_ObjList[enEnemy1].GetNext(ePos1);
			CRect mRect = pEnemy1->GetRect();
			CRect tmpRect;
			if (tmpRect.IntersectRect(&bRect, mRect))
			{
				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left, mRect.top)
				);
				//删除导弹
				m_ObjList[enBomb].RemoveAt(mPos2);
				//delete pBomb;

				//删除敌机
				pEnemy1->life--;
				if (pEnemy1->life == 0)
				{
					score += 10;
					m_ObjList[enEnemy1].RemoveAt(ePos2);
					delete pEnemy1;
					break;
				}

			}
		}
	}
	//战机导弹炸毁小boss
	mPos1 = NULL; mPos2 = NULL;
	for (mPos1 = m_ObjList[enBomb].GetHeadPosition(); (mPos2 = mPos1) != NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos1);
		CRect bRect = pBomb->GetRect();
		POSITION ePos1 = NULL, ePos2 = NULL;
		for (ePos1 = m_ObjList[enBoss].GetHeadPosition(); (ePos2 = ePos1) != NULL;)
		{
			Boss* Boss1 = (Boss*)m_ObjList[enBoss].GetNext(ePos1);
			CRect mRect = Boss1->GetRect();
			CRect tmpRect;
			if (tmpRect.IntersectRect(&bRect, mRect))
			{
				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left, mRect.top)
				);
				//删除导弹
				
				m_ObjList[enBomb].RemoveAt(mPos2);
				delete pBomb;
				pBomb = NULL;
				//删除敌机
				
				Boss1->emblood--;
				if (Boss1->emblood == 0)
				{
					ff = 0;
					score += 30;
					m_ObjList[enBoss].RemoveAt(ePos2);
					delete Boss1;
					m = 1;
					break;
				}
				
			}
		}
	}
	//大招清屏
	POSITION ePos1 = NULL, ePos2 = NULL;
	for (ePos1 = m_ObjList[enEnemy].GetHeadPosition(); (ePos2 = ePos1) != NULL;)
	{
		CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
		CRect mRect = pEnemy->GetRect();
		CRect tmpRect;
		if (GetKey('X') == 1 && blue >= 50)//按下了X键(清屏)
		{

			//添加爆炸效果
			m_ObjList[enExplosion].AddTail(
				new CExplosion(mRect.left, mRect.top)
			);
			m_ObjList[0].RemoveAll();
			score += 10;
			break;
		}
	}
	for (ePos1 = m_ObjList[enEnemy1].GetHeadPosition(); (ePos2 = ePos1) != NULL;)
	{
		CEnemy1* pEnemy1 = (CEnemy1*)m_ObjList[enEnemy1].GetNext(ePos1);
		CRect mRect = pEnemy1->GetRect();
		CRect tmpRect;
		if (GetKey('X') == 1 && blue >= 50)//按下了X键(清屏)
		{

			//添加爆炸效果
			m_ObjList[enExplosion].AddTail(
				new CExplosion(mRect.left, mRect.top)
			);
			m_ObjList[1].RemoveAll();
			score += 10;
			break;
		}
	}
	for (ePos1 = m_ObjList[enBoss].GetHeadPosition(); (ePos2 = ePos1) != NULL;)
	{
		Boss* Boss1 = (Boss*)m_ObjList[enBoss].GetNext(ePos1);
		CRect mRect = Boss1->GetRect();
		CRect tmpRect;
		if (GetKey('X') == 1 && blue >= 50)//按下了X键(清屏)
		{

			//添加爆炸效果
			m_ObjList[enExplosion].AddTail(
				new CExplosion(mRect.left, mRect.top)
			);
			m_ObjList[3].RemoveAll();
			m = 1;
			score += 30;
			break;
		}
	}

	//子弹击中boss1
	mPos1 = NULL, mPos2 = NULL;
	for (mPos1 = m_ObjList[enBomb].GetHeadPosition(); (mPos2 = mPos1) != NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos1);
		CRect bRect = pBomb->GetRect();
		POSITION ePos1 = NULL, ePos2 = NULL;
		for (ePos1 = m_ObjList[enBoss1].GetHeadPosition(); (ePos2 = ePos1) != NULL;)
		{
			Boss1* pBoss1 = (Boss1*)m_ObjList[enBoss1].GetNext(ePos1);
			CRect pRect = pBoss1->GetRect();
			CRect tmpRect;
			if (tmpRect.IntersectRect(&bRect, pRect))
			{
				//添加爆炸效果
				for (int i = 0; i < 11; i++)
					m_ObjList[enExplosion].AddTail(new CExplosion(pRect.left + i * 30, pRect.top + i * 30));
				//删除导弹
				m_ObjList[enBomb].RemoveAt(mPos2); delete pBomb;
				//boss 减血
				if (pBoss1->emblood3 > 0)
				{
					pBoss1->emblood3 -= 10;
				}
				if (pBoss1->emblood3 <= 0)
				{
					score += 400;
					m_ObjList[enBoss1].RemoveAt(ePos2);
					delete pBoss1;
				}

				break;

			}
		}
	}
	//显示关卡
	if (score >= 500 && flag1==1)
	{
		KillTimer(1);
		if (AfxMessageBox(L"厉害呢~\(≧▽≦)/~，要继续第二关吗", MB_YESNO) != 6)
		{
			delete m_pMe;
			m_pMe = NULL;
			exit(1);
		}
		else
		{
			for (int i = 0; i < 11; i++)
				m_ObjList[i].RemoveAll();
			delete m_pMe;
			m_pMe = new CMyPlane;
			level = 2;
			blue = 300;
			AfxMessageBox(L"更强的敌人出现喽::>_<::，请小心");
		}

		SetTimer(1, 30, NULL);
		flag1 = 0;
	}
	if (score >= 1200 && flag2==1)
	{
		KillTimer(1);
		if (AfxMessageBox(L"哇好棒，要继续第三关吗", MB_YESNO) != 6)
		{
			delete m_pMe;
			m_pMe = NULL;
		}
		else
		{
			for (int i = 0; i < 11; i++)
				m_ObjList[i].RemoveAll();
			delete m_pMe;
			m_pMe = new CMyPlane;
			level = 3;
			blue = 300;
			AfxMessageBox(L"听说Boss要出现了(ง•_•)ง");
		}

		SetTimer(1, 30, NULL);
		flag2 = 0;
	}
	if (score >= 2000 && flag3==1)
	{
		KillTimer(1);
		if (AfxMessageBox(L"简直不敢相信，全部通过啦，还要再来一次吗(>^ω^<)", MB_YESNO) == 6)
		{
			for (int i = 0; i < 11; i++)
				m_ObjList[i].RemoveAll();
			delete m_pMe;
			m_pMe = new CMyPlane;
			blood = 300;
			blue = 300;
			score = 0;
			k = 1;
			m = 1;
			level = 1;
			flag1 = 1;//第二关，弹窗口
			flag2 = 1;//第三关，弹窗口
			flag3 = 1;//弹窗口
		}
		else
		{
			delete m_pMe;
			m_pMe = NULL;
		}
		SetTimer(1, 30, NULL);
		flag3 = 1;
	}
}
void CPlaneGameView::OnTimer(UINT_PTR nIDEvent)
{
	//刷新游戏帧画面: 在内存DC上绘图
	  if (GetKey('P') == 1)
		{
			Pattern = 0;
		}
		if (GetKey('O') == 1)
		{
			Pattern = 1;
		}
		if (Pattern != 0)
		{
			UpdateFrame(m_pMemDC);
			AI();
		}
	
	CView::OnTimer(nIDEvent);
}

void CPlaneGameView::OnDestroy()
{
	CView::OnDestroy();
	this->StopGame();
	// TODO: 在此处添加消息处理程序代码
}

