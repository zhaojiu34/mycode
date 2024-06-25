
// Rect.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Rect.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



class CMyWnd :public CFrameWnd
{
	CRect RECT[1000];
	int n;
public:
	CMyWnd()
	{
		n = 0;
	}
protected:
	afx_msg void OnPaint();
	afx_msg	void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CMyWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (n < 1000)
	{
		int r = rand() % 50 + 10;
		CRect rect(point.x - r, point.y - r, point.x + r, point.y + r);
		RECT[n] = rect;
		n++;
		InvalidateRect(rect, FALSE);
	}
}

void CMyWnd::OnPaint()
{
	CPaintDC dc(this);
	dc.SelectStockObject(LTGRAY_BRUSH);
	for (int i = 0; i < n; i++)
		dc.Rectangle(RECT[i]);
}

class CMyApp :public CWinApp {

public:
	virtual	BOOL InitInstance();
};

BOOL CMyApp::InitInstance()
{
	CMyWnd* pMain = new CMyWnd;
	pMain->Create(0, L"画矩形！");
	pMain->ShowWindow(m_nCmdShow);
	this->m_pMainWnd = pMain;
	return TRUE;
}

CMyApp ThisApp;





