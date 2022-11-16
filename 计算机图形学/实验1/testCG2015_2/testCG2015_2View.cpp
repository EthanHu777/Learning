// testCG2015_2View.cpp : implementation of the CTestCG2015_2View class
//

#include "stdafx.h"
#include "testCG2015_2.h"

#include "testCG2015_2Doc.h"
#include "testCG2015_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2View

IMPLEMENT_DYNCREATE(CTestCG2015_2View, CView)

BEGIN_MESSAGE_MAP(CTestCG2015_2View, CView)
	//{{AFX_MSG_MAP(CTestCG2015_2View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2View construction/destruction

CTestCG2015_2View::CTestCG2015_2View()
{
	// TODO: add construction code here
	// 第四步: 在构造函数中对变量进行初始化
	m_bCaptured = FALSE;

}

CTestCG2015_2View::~CTestCG2015_2View()
{
}

BOOL CTestCG2015_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2View drawing

void CTestCG2015_2View::OnDraw(CDC* pDC)
{
	CTestCG2015_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	// 第五步: 画直线的起点和直线
	pDC->SetPixel(pStart.x,pStart.y,RGB(0,0,255));
	for(int i1=0; i1<steps; i1++)
			pDC->SetPixel(line[i1].x,line[i1].y,RGB(255,0,0));

}

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2View printing

BOOL CTestCG2015_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestCG2015_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestCG2015_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2View diagnostics

#ifdef _DEBUG
void CTestCG2015_2View::AssertValid() const
{
	CView::AssertValid();
}

void CTestCG2015_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestCG2015_2Doc* CTestCG2015_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestCG2015_2Doc)));
	return (CTestCG2015_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2View message handlers
//第二步：完成DDA算法对应的函数
void CTestCG2015_2View::lineDDA(int xa, int ya, int xb, int yb)
{
	int dx=xb-xa, dy=yb-ya;
	float xIncrement, yIncrement, x=(float)xa, y=(float)ya;
	if(abs(dx)>abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xIncrement = dx/(float)steps;
	yIncrement = dy/(float)steps;

	for(int k=0; k<steps; k++)
	{
		line[k].x=(int)(x+0.5);
		line[k].y=(int)(y+0.5);
		x+=xIncrement;
		y+=yIncrement;
	}

}

//第三步：完成鼠标消息响应函数
void CTestCG2015_2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bCaptured = TRUE;//确定是画线状态。

	pStart.x=point.x;
	pStart.y=point.y;	
	CView::OnLButtonDown(nFlags, point);
}

void CTestCG2015_2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    lineDDA(pStart.x, pStart.y, point.x, point.y);
    this->Invalidate(TRUE);
	m_bCaptured = FALSE;//可以尝试着去掉看一下效果
	CView::OnLButtonUp(nFlags, point);
}

void CTestCG2015_2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_bCaptured)
	{
	pEnd.x=point.x;
	pEnd.y=point.y;
    lineDDA(pStart.x, pStart.y, pEnd.x, pEnd.y);
    this->Invalidate(TRUE);//可以尝试着去掉看一下效果
	}

	CView::OnMouseMove(nFlags, point);
}
