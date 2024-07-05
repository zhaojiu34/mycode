// PlaneGameView.cpp : CPlaneGameView 类的实现
//

#include "stdafx.h"
#include "PlaneGame.h"
#include"resource.h"
#include "PlaneGameDoc.h"
#include "PlaneGameView.h"
#include "MyPlane.h"
#include "Enemy.h"
#include "Bomb.h"
#include "Ball.h"
#include "Explosion.h"
#include <atlimage.h>
#include"Boss.h"
#include "life.h"
#include "bigb.h"
#include "Enemy2.h"
#include "game_interface.h"

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

	ON_WM_DESTROY()
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
void CPlaneGameView::OnDraw(CDC* pDC)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	blood = 10;
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
	delete m_pMe;//飞机
	delete m_pMemDC;//内存
	delete m_pDC;//设备
	delete m_pMemBitmap;//内存位图
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

	//加载图片
	CMyPlane::LoadImage();
	CEnemy::LoadImage();
	CBomb::LoadImage();
	CBall::LoadImage();
	CExplosion::LoadImage();
	Boss::LoadImage();
	life::LoadImage();
	bigb::LoadImage();
	Enemy2::LoadImage();
  
	//启动游戏
	//AfxMessageBox弹出Windows窗口
	if (AfxMessageBox(L"要开始游戏吗", MB_YESNO) == 6)
	{
		AfxMessageBox(L"游戏基本操作:\n上下左右 控制飞机 \nP键 暂停\nC键 继续 \n空格键 发射大招并清屏（共五次机会）\nctrl键 转换三枚导弹\nshift键 无敌模式\nZ建 普通模式\n注：第五关不再有血包\n空格键 开始游戏", MB_OK);
		Sleep(1000);

      //产生主角(战机)
	     m_pMe = new CMyPlane;
	}

	else
	{
		exit(1);
	}

	//设置定时器，每一毫秒都要执行什么任务
	SetTimer(1,30,NULL);

	return TRUE;
}


void CPlaneGameView::UpdateFrame(CDC* pMemDC)
{
	//绘制天空
	CRect rctClient;
	GetClientRect(rctClient);

	//滚动的背景图
	game_interface().BackGround(&pMemDC,level);	
	
	if(m_pMe!=NULL)
	{	
		//飞机相关信息界面
		game_interface().Myplane_interface(&pMemDC, level, blood, score, bigboll);

		if (mm == 0)
		{
 			CString st1 = _T("无敌模式（Z）");
			pMemDC->SetBkMode(TRANSPARENT);
			pMemDC->SetTextAlign(TA_CENTER);
			pMemDC->SetTextColor(RGB(90, 90, 90));
			pMemDC->TextOut(70, 110, st1);

		}
		else
		{
			CString st2 = _T("普通模式(Shift)");
			pMemDC->SetBkMode(TRANSPARENT);
			pMemDC->SetTextAlign(TA_CENTER);
			pMemDC->SetTextColor(RGB(90, 90, 90));
			pMemDC->TextOut(70, 110, st2);

		}

		//功能介绍界面
		game_interface().Function_interface(&pMemDC);

		CString str10 = _T("Esc键：退出");
		pMemDC->SetBkMode(TRANSPARENT);
		pMemDC->SetTextAlign(TA_CENTER);
		pMemDC->SetTextColor(RGB(90, 90, 90));
		pMemDC->TextOut(460, 100, str10);
		m_pMe->Draw(m_pMemDC,FALSE);
	
	}
	else
	{	
		exit(1);
	}


	//模式转换
	if (GetKey(VK_SHIFT) == 1&&mm==1)
	{
		mm = 0;
	}
	if (GetKey('Z') == 1&&mm==0)
	{
		mm = 1;
	}
	if (GetKey(VK_ESCAPE))
	{
		exit(1);
	}

	//绘制 导弹、爆炸、敌机、子弹
	for(int i=0;i<=7;i++)
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


void CPlaneGameView::AI()
{

	ff = 1;

	if (blood <= 0)
	{
		//这行代码用于销毁一个指定ID为1的定时器。
		//它会停止之前通过 SetTimer 函数设置的名为1的定时器，确保在血量小于等于0时停止相应的计时器
		//从而避免在游戏结束后继续运行定时器操作
		KillTimer(1);

		if (AfxMessageBox(L"血量不足，让我们重新来过吧！", MB_YESNO) == 6)
		{
			delete m_pMe;
			m_pMe = new CMyPlane;

			for (int i = 0; i < 8;i++)
				m_ObjList[i].RemoveAll();

			blood = 10;
			score = 0;
			bigboll = 5;
			level = 1;
			Pattern = 1;
			flag1 = 1;//第二关，弹窗口
			flag2 = 1;//第三关，弹窗口
			flag3 = 1;//第四关，弹窗口
			flag4 = 1;//第五关，弹窗口
			flag5 = 1;//第六关，弹窗口

		}
		else
		{
			delete m_pMe;
			m_pMe = NULL;
		}

		//设置一个新的定时器，ID为1，间隔时间为30毫秒。
		//它会在重置游戏状态的操作后重新激活定时器，确保游戏在重新开始后能够按照设定的时间间隔执行相应的任务。
		SetTimer(1, 30, NULL);
	}


	static int nCreator = rand() %5+10;
	static int nCreator4 = rand() % 5 + 10;
	static int nCreator2 = rand() % 5 + 10;
	static int nCreator3 = rand() % 5 + 10;

	//第一关，第三关，第四关有一发敌机
	//第二关，第三关，第五关有三发敌机
	//第四关，第五关有BOSS：10发子弹

	//随机产生敌机1：控制敌机产生的时机
	if (level == 1 || level == 3 || level == 4)
	{
		if (nCreator <= 0)
		{
			nCreator = rand() % 5 + 10;

			//在链表数组敌机部分中添加敌机
			m_ObjList[enEnemy].AddTail(new CEnemy);
		}
		nCreator--;
	}
	
	//随机产生敌机2
	if (level == 2  || level == 5)
	{
		if (nCreator4 <= 0)
		{
			nCreator4 = rand() % 10 + 10;
			m_ObjList[enEnemy2].AddTail(new Enemy2);
		}
		nCreator4--;
	}

	if (level == 3)
	{
		if (nCreator4 <= 0)
		{
			nCreator4 = rand() % 100 + 10;
			m_ObjList[enEnemy2].AddTail(new Enemy2);
		}
		nCreator4--;
	}

	//产生boss
	if (level == 4||level == 5)
	{
		
		if (nCreator2 <= 0)
		{
			nCreator2 = rand() % 900 + 10;

			m_ObjList[enBoss].AddTail(new Boss);
		}
		nCreator2--;
	}
	
	//产生小心心
	if (level < 5)
	{
     if (nCreator3 <= 0)
	{
		nCreator3 = rand() % 1000 + 10;
		m_ObjList[enlife].AddTail(new life);
	}
	nCreator3--;
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
	if (GetKey(VK_SPACE) == 1 && bigboll>0)//按下了空格键：导弹
	{
		if(m_pMe!=NULL && m_pMe->Fired())
		{
			CPoint pt = m_pMe->GetPoint();
			m_ObjList[enbigb].AddTail(new bigb(pt.x + 25, pt.y - 10));
			bigboll--;
		}
	}
	else
	{
		if (m_pMe != NULL && m_pMe->Fired())//发射一发子弹，按住CTRL以后发射三发子弹
		{
			CPoint pt = m_pMe->GetPoint();
			m_ObjList[enBomb].AddTail(new CBomb(pt.x + 25, pt.y - 10, 1));//上

			if (GetKey(VK_CONTROL) == 1)
			{
				m_ObjList[enBomb].AddTail(new CBomb(pt.x + 40, pt.y - 10, -2));//右
				m_ObjList[enBomb].AddTail(new CBomb(pt.x + 10, pt.y - 10, -1));//左

			}

		}
	}


	//敌机1发射子弹
	CPoint PlanePt = m_pMe->GetPoint();//获取飞机位置
	for(POSITION ePos=m_ObjList[enEnemy].GetHeadPosition();ePos!=NULL;)
	{
          CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos);

		  //如果不能开火，就不再继续走，判断下一个
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

		  //敌机位于战机的上方就可以发射子弹
		  if(by && ePt.x >= PlanePt.x && ePt.x<PlanePt.x+CMyPlane::PLANE_WIDTH)
		  {
              m_ObjList[enBall].AddTail(new CBall(ePt.x+10,ePt.y+10,pEnemy->GetMontion()));
		  }

	}

	//敌机2发射子弹
	for (POSITION ePos = m_ObjList[enEnemy2].GetHeadPosition(); ePos != NULL;)
	{
		Enemy2* pEnemy2= (Enemy2*)m_ObjList[enEnemy2].GetNext(ePos);

		if (!pEnemy2->Fired())
			continue;
		CPoint  ePt = pEnemy2->GetPoint();

		BOOL by = FALSE;

		//敌机在战机前面
		if (pEnemy2->GetMontion() == 1 && ePt.y<PlanePt.y)
			by = TRUE;
		//敌机在战机后面
		if (pEnemy2->GetMontion() == -1 && ePt.y>PlanePt.y)
			by = TRUE;

		if (by && ePt.x >= PlanePt.x && ePt.x<PlanePt.x + CMyPlane::PLANE_WIDTH)
		{
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 10, ePt.y + 15, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 20, ePt.y + 10, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x , ePt.y + 10, pEnemy2->GetMontion()));


		}
	}

	//boss发射子弹
	for (POSITION ePos = m_ObjList[enBoss].GetHeadPosition(); ePos != NULL;)
	{
		Boss* pEnemy2 = (Boss*)m_ObjList[enBoss].GetNext(ePos);

		if (!pEnemy2->Fired())
			continue;

		CPoint  ePt = pEnemy2->GetPoint();

		BOOL by = FALSE;

		//敌机在战机前
		if (pEnemy2->GetMontion() == 1 && ePt.y<PlanePt.y)
			by = TRUE;
		//敌机在战机后面
		if (pEnemy2->GetMontion() == -1 && ePt.y>PlanePt.y)
			by = TRUE;

		if (by && ePt.x >= PlanePt.x && ePt.x<PlanePt.x + CMyPlane::PLANE_WIDTH)
		{
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 10, ePt.y + 25, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 20, ePt.y + 20, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x, ePt.y + 20, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 30, ePt.y + 15, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x - 10, ePt.y + 15, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 15, ePt.y + 35, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 25, ePt.y + 30, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x, ePt.y + 30, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x + 35, ePt.y + 25, pEnemy2->GetMontion()));
			m_ObjList[enBall].AddTail(new CBall(ePt.x - 15, ePt.y + 25, pEnemy2->GetMontion()));
		}
	}


	//敌机子弹炸掉战机
	POSITION bPos1=NULL,//指示当前正在处理的敌机子弹对象的位置
			bPos2=NULL;//用于保存上一次处理的敌机子弹对象的位置

	CRect mRect = m_pMe->GetRect();//获取飞机所在的矩形区域

	for(bPos1=m_ObjList[enBall].GetHeadPosition();( bPos2 = bPos1 ) != NULL;)
	{
		CBall* pBall = (CBall*)m_ObjList[enBall].GetNext(bPos1);//bPos1已经移到下一个位置
		CRect bRect = pBall->GetRect();//获取子弹所在的矩形区域
		CRect tmpRect;

		if(tmpRect.IntersectRect(&bRect,mRect))//判断子弹和战机的位置是否重叠
		{
			//添加爆炸效果
			m_ObjList[enExplosion].AddTail(
				new CExplosion(mRect.left,mRect.top)
				);

			//删除子弹
			m_ObjList[enBall].RemoveAt(bPos2);
			delete pBall;
			

			if (mm == 1)
			{
				blood--;
			}
		
		}
	}


	//碰撞1减少血量
	POSITION bPos12 = NULL, bPos22 = NULL;
	                                                    //bPos22先赋值为bPos12
	for (bPos12 = m_ObjList[enEnemy].GetHeadPosition(); (bPos22 = bPos12) != NULL;)
	{
		//根据给定的位置返回下一个位置，并将当前位置指向下一个元素，bPos12指向下一个位置
		CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(bPos12);

		CRect bRect = pEnemy->GetRect();
		CRect tmpRect;
		if (tmpRect.IntersectRect(&bRect, mRect))
		{
			//添加爆炸效果
			m_ObjList[enExplosion].AddTail(new CExplosion(mRect.left, mRect.top));

			//删除敌机
			m_ObjList[enEnemy].RemoveAt(bPos22);
			delete pEnemy;

			if (mm == 1)
			{
				blood--;
			}
		}
	}

	//碰撞2减少血量
	for (bPos12 = m_ObjList[enEnemy2].GetHeadPosition(); (bPos22 = bPos12) != NULL;)
	{
		Enemy2* pEnemy = (Enemy2*)m_ObjList[enEnemy2].GetNext(bPos12);
		CRect bRect = pEnemy->GetRect();

		CRect tmpRect;
		if (tmpRect.IntersectRect(&bRect, mRect))
		{
			//添加爆炸效果
			m_ObjList[enExplosion].AddTail(new CExplosion(mRect.left, mRect.top));

			//删除敌机
			m_ObjList[enEnemy2].RemoveAt(bPos22);
			delete pEnemy;

			if (mm == 1)
			{
				blood--;
			}
			//删除战机
		}
	}


	//加血
	POSITION bPos13 = NULL, bPos23 = NULL;
	for (bPos13 = m_ObjList[enlife].GetHeadPosition(); (bPos23 = bPos13) != NULL;)
	{
		life* plife = (life*)m_ObjList[enlife].GetNext(bPos13);
		CRect bRect = plife->GetRect();
		CRect tmpRect;
		if (tmpRect.IntersectRect(&bRect, mRect))
		{
			
			if (m_pMe != NULL)
			{
				m_ObjList[enlife].RemoveAt(bPos23);
				delete plife;

				if (blood < 10)
				{
					blood++;
				}	

			}
		}
	}


	//战机导弹炸掉敌机
	POSITION mPos1=NULL,mPos2=NULL;

	//外层循环：获取每个导弹对象的位置和大小信息
	for(mPos1=m_ObjList[enBomb].GetHeadPosition();(mPos2=mPos1)!=NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos1);
		CRect bRect = pBomb->GetRect();

		POSITION ePos1=NULL,ePos2=NULL;
		//内层循环：获取每个敌机对象的位置和大小信息
		for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();
			CRect tmpRect;

			if (tmpRect.IntersectRect(&bRect, mRect) && ff == 1)//判断每个子弹是否与敌机发生碰撞
			{
				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left,mRect.top)
					);

				//删除导弹
				ff = 0;//ff的值用于判断当前的碰撞处理状态，以决定执行哪种操作

				m_ObjList[enBomb].RemoveAt(mPos2);
				delete pBomb;
				score += 10;

				//删除敌机
				m_ObjList[enEnemy].RemoveAt(ePos2);
				delete pEnemy;
				break;

			}
			
			if (GetKey(VK_SPACE) == 1 && bigboll>0)//按下了空格键(清屏)
			{
				
				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left,mRect.top)
					);

				m_ObjList[enEnemy].RemoveAt(ePos2);

				delete pEnemy;
				break;
			}
		}
	}


	//战机导弹炸掉敌机2
	for (mPos1 = m_ObjList[enBomb].GetHeadPosition(); (mPos2 = mPos1) != NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos1);
		CRect bRect = pBomb->GetRect();

		POSITION ePos1 = NULL, ePos2 = NULL;
		for (ePos1 = m_ObjList[enEnemy2].GetHeadPosition(); (ePos2 = ePos1) != NULL;)
		{
			Enemy2* pEnemy = (Enemy2*)m_ObjList[enEnemy2].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();
			CRect tmpRect;

			if (tmpRect.IntersectRect(&bRect, mRect) && ff == 1)
			{
				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left, mRect.top)
					);

				//删除导弹
				m_ObjList[enBomb].RemoveAt(mPos2);
				delete pBomb;
				score += 10;

				//删除敌机
				m_ObjList[enEnemy2].RemoveAt(ePos2);
				delete pEnemy;
				ff = 0;
				break;

			}

			if (GetKey(VK_SPACE) == 1 && bigboll>0)//按下了空格键(清屏)
			{

				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left, mRect.top)
					);
				m_ObjList[enEnemy2].RemoveAt(ePos2);
				delete pEnemy;
				break;
			}
		}
	}

	//炸boss
	POSITION mPos12 = NULL, mPos22 = NULL;
	for (mPos12 = m_ObjList[enBomb].GetHeadPosition(); (mPos22 = mPos12) != NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos12);
		CRect bRect = pBomb->GetRect();

		POSITION ePos12 = NULL, ePos22 = NULL;//以防敌机重叠delete两次
		for (ePos12 = m_ObjList[enBoss].GetHeadPosition(); (ePos22 = ePos12) != NULL;)
		{
			Boss* pEnemy2 = (Boss*)m_ObjList[enBoss].GetNext(ePos12);
			CRect mRect = pEnemy2->GetRect();
			CRect tmpRect;
			
			if (tmpRect.IntersectRect(&bRect, mRect)&&ff==1)
			{
				
				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left, mRect.top)
					);
				 //删除导弹
				m_ObjList[enBomb].RemoveAt(mPos22);
				delete pBomb;

				ff = 0;
				pEnemy2->emblood--;

				if (pEnemy2->emblood <= 0)
				{
			  
					score += 50;
					//删除敌机
					m_ObjList[enBoss].RemoveAt(ePos22);
					delete pEnemy2;
					bigboll++;//击毁一个BOSS可加一枚导弹
					break;
				}
			}
		
			if (GetKey(VK_SPACE) == 1 && bigboll>0)//按下了空格键(清屏)
			{

				//添加爆炸效果
				m_ObjList[enExplosion].AddTail(
					new CExplosion(mRect.left, mRect.top)
					);
				m_ObjList[enBoss].RemoveAt(ePos22);
				bigboll++;//击毁一个BOSS可加一枚导弹

				delete pEnemy2;
				break;
			}
		}

	}



	//显示关卡
	if (score >= 150 && flag1)
	{
		KillTimer(1);
		if (AfxMessageBox(L"要继续第二关吗", MB_YESNO) != 6)
		{
			delete m_pMe;
			m_pMe = NULL;
			
		}
		else
		{
			for (int i = 0; i < 8; i++)
				m_ObjList[i].RemoveAll();
			delete m_pMe;
			m_pMe = new CMyPlane;
			level = 2;
			AfxMessageBox(L"更强的敌人出现喽，小心呀");
		}
		
		SetTimer(1, 30, NULL);
		flag1 = 0;
	}
	if (score >= 300 && flag2)
	{
		KillTimer(1);
		if (AfxMessageBox(L"哇，要继续第三关吗", MB_YESNO) != 6)
		{
			delete m_pMe;
			m_pMe = NULL;
		}
		else
		{
			for (int i = 0; i < 8; i++)
				m_ObjList[i].RemoveAll();
			delete m_pMe;
			m_pMe = new CMyPlane;
			level = 3;
			AfxMessageBox(L"敌人的数量更多喽，加油加油");
		}
		
		SetTimer(1, 30, NULL);
		flag2 = 0;
	}
	if (score >= 450 && flag3)
	{
		KillTimer(1);
		if (AfxMessageBox(L"是不是要继续第四关呀", MB_YESNO) != 6)
		{
			delete m_pMe;
			m_pMe = NULL;
		}
		else
		{
			for (int i = 0; i < 8; i++)
				m_ObjList[i].RemoveAll();
			delete m_pMe;
			m_pMe = new CMyPlane;
			level = 4;
			AfxMessageBox(L"听说Boss要出现了");
		}
		
		SetTimer(1, 30, NULL);
		flag3 = 0;
	}
	if (score >= 600 && flag4)
	{
		KillTimer(1);
		if (AfxMessageBox(L"要不要试试第五关呀", MB_YESNO) != 6)
		{
			delete m_pMe;
			m_pMe = NULL;
		}
		else
		{
			for (int i = 0; i < 8; i++)
				m_ObjList[i].RemoveAll();
			delete m_pMe;
			m_pMe = new CMyPlane;
			level = 5;
		}
		
		SetTimer(1, 30, NULL);
		flag4 = 0;
	}
	if (score >= 750 && flag5)
	{
		KillTimer(1);
		if (AfxMessageBox(L"简直不敢相信，全部通过啦", MB_YESNO) == 6)
		{
			for (int i = 0; i < 8; i++)
				m_ObjList[i].RemoveAll();
			delete m_pMe;
			m_pMe = new CMyPlane;
			blood = 10;
			score = 0;
			bigboll = 5;
			level = 1;
			Pattern = 1;
			flag1 = 1;//第二关，弹窗口
			flag2 = 1;//第三关，弹窗口
			flag3 = 1;//第四关，弹窗口
			flag4 = 1;//第五关，弹窗口
			flag5 = 1;//第六关，弹窗口

		}
		else
		{
			delete m_pMe;
			m_pMe = NULL;
			flag5 = 0;
		}

		SetTimer(1, 30, NULL);
		
	}

	
}


void CPlaneGameView::OnTimer(UINT_PTR nIDEvent)
{
	//刷新游戏帧画面: 在内存DC上绘图

	if (GetKey('P') == 1)
	{
		Pattern = 0;
	}
	if (GetKey('C') == 1)
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
