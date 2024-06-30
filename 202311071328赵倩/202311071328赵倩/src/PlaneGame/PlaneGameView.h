// PlaneGameView.h : CPlaneGameView 类的接口
//


#pragma once

//应用程序对象

class CMyPlane;
class CPlaneGameView : public CView
{

	enum ObjType{enEnemy, enEnemy1,enBomb, enBoss, enBoss1,enlife,enblue,enBall,enBossBall,enBigSkill,enExplosion};

protected: // 仅从序列化创建

	
	CPlaneGameView();
	DECLARE_DYNCREATE(CPlaneGameView)

// 属性
public:
	CPlaneGameDoc* GetDocument() const;
	int HP = 100;//经验值
	int level = 1;//关卡
	int Pattern = 1;//判断是否暂停

	int flag = 1;//是否重新开始
	int flag1 = 1;//第二关，弹窗口
	int flag2 = 1;//第三关，弹窗口
	int flag3 = 1;//最后，弹窗口

	int ff = 1;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPlaneGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//内存DC
	CDC*        m_pMemDC;
	//设备DC
	CClientDC*  m_pDC;
	//内存位图
	CBitmap*    m_pMemBitmap;


protected:
	//初始化游戏：欢迎窗口，窗口显示规则
	BOOL InitGame();
	//结束游戏
	void StopGame();

	//刷新游戏的帧画面：绘制战机，天空，背景，积分，血量情况
	void UpdateFrame(CDC* pMemDC);


	void AI();

	//获得键的状态1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}
	
	CMyPlane*  m_pMe;

	//链表
	////删除列表所有元素 RemoveAll()
	//从列表中删除指定位置的元素 RemoveAt(POSITION position)
	//返回链表尾元素的位置 GetNext(POSITION& rPosition);
	//在尾增加一个元素或者一个列表的元素 AddTail(void* newElement);

	CObList    m_ObjList[11];



// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	//加载图片显示
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // PlaneGameView.cpp 中的调试版本
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

