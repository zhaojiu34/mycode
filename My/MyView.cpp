
// MyView.cpp: CMyView 类的实现
//

#include "pch.h"
#include "framework.h"
 //SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
 //ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "My.h"
#endif

#include "MyDoc.h"
#include "MyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMyView::OnFilePrintPreview)
//	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONDBLCLK()
//	ON_WM_PAINT()
//ON_WM_PAINT()
//ON_WM_LBUTTONDBLCLK()
ON_WM_PAINT()
ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMyView 构造/析构

CMyView::CMyView() noexcept
{
	// TODO: 在此处添加构造代码
	n = 0;
	x = 0;
	y = 0;
}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyView 绘图

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDC->SelectStockObject(LTGRAY_BRUSH);

	for (int i = 0; i < n; i++)
		pDC->Rectangle(Rect[i]);

	// TODO: add draw code for native data here
}


// CMyView 打印


void CMyView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

//void CMyView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

//void CMyView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
//{
//#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
//#endif
//}


// CMyView 诊断

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyView 消息处理程序

void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (n < 1000)
	{
		int r = rand() % 50 + 10;
		CRect rect(point.x - r, point.y - r, point.x + r, point.y + r);
		Rect[n] = rect;
		n++;
		InvalidateRect(rect, FALSE);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMyView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen* oPen;
	CBrush* oBrush;
	CPen nPen(PS_DASH, 3, RGB(0, 255, 0));
	CBrush nBrush(1, RGB(255, 0, 0));
	oPen = dc.SelectObject(&nPen);
	oBrush = dc.SelectObject(&nBrush);
	dc.Rectangle(point.x, point.y, point.x + 100, point.y + 100);
	dc.SelectObject(&oPen);
	dc.SelectObject(&oBrush);
	CView::OnRButtonDown(nFlags, point);
}




void CMyView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	x = point.x;
	y = point.y;
	InvalidateRect(FALSE);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMyView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	LOGFONT font;
	font.lfHeight = 100;
	font.lfItalic = 0;
	font.lfEscapement = 0;
	font.lfCharSet = GB2312_CHARSET;
	font.lfUnderline = 0;
	font.lfStrikeOut = 0;
	CFont nFont, * oFont;
	nFont.CreateFontIndirect(&font);
	oFont = dc.SelectObject(&nFont);
	dc.TextOutW(x, y, L"海内存知己，天涯若比邻");
	dc.SelectObject(&oFont);
}


