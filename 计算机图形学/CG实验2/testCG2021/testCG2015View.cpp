// testCG2015View.cpp : implementation of the CTestCG2015View class
//

#include "stdafx.h"
#include "testCG2015.h"

#include "testCG2015Doc.h"
#include "testCG2015View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015View

IMPLEMENT_DYNCREATE(CTestCG2015View, CView)

BEGIN_MESSAGE_MAP(CTestCG2015View, CView)
	//{{AFX_MSG_MAP(CTestCG2015View)
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
// CTestCG2015View construction/destruction

//第六步：在构造函数中对m_bCaptured等变量初始化
CTestCG2015View::CTestCG2015View()
{
	// TODO: add construction code here
	m_bCaptured = FALSE;
	num = 0;
}

CTestCG2015View::~CTestCG2015View()
{
}

BOOL CTestCG2015View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015View drawing

void CTestCG2015View::OnDraw(CDC* pDC)
{
	CTestCG2015Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	//第三步：函数调用及直线绘制
    //	lineDDA(100,150,400,400);
	for (int j=0; j<=num;j++)
	   for(int i1=0; i1<steps[j]; i1++)
			pDC->SetPixel(line[j][i1].x,line[j][i1].y,RGB(20,01,39));

}

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015View printing

BOOL CTestCG2015View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestCG2015View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestCG2015View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015View diagnostics

#ifdef _DEBUG
void CTestCG2015View::AssertValid() const
{
	CView::AssertValid();
}

void CTestCG2015View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestCG2015Doc* CTestCG2015View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestCG2015Doc)));
	return (CTestCG2015Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015View message handlers
//第二步：完成DDA算法对应的函数
void CTestCG2015View::lineDDA(int xa, int ya, int xb, int yb)
{
	int dx=xb-xa, dy=yb-ya;
	float xIncrement, yIncrement, x=(float)xa, y=(float)ya;
	if(abs(dx)>abs(dy))
		steps[num] = abs(dx);
	else
		steps[num] = abs(dy);
	xIncrement = dx/(float)steps[num];
	yIncrement = dy/(float)steps[num];

	for(int k=0; k<steps[num]; k++)
	{
		line[num][k].x=(int)(x+0.5);
		line[num][k].y=(int)(y+0.5);
		x+=xIncrement;
		y+=yIncrement;
	}

}

//第五步：实现鼠标事件消息响应函数
void CTestCG2015View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	m_bCaptured = TRUE;
    num++;
    pStart[num].x=point.x;
    pStart[num].y=point.y;	
	
	CView::OnLButtonDown(nFlags, point);
}

void CTestCG2015View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    
    pEnd[num].x=point.x;
    pEnd[num].y=point.y;	
    lineDDA(pStart[num].x, pStart[num].y, pEnd[num].x, pEnd[num].y);	
    
    this->Invalidate(TRUE);//强制窗口重画
	m_bCaptured = FALSE;//可以尝试着去掉看一下效果


	CView::OnLButtonUp(nFlags, point);
}

void CTestCG2015View::OnMouseMove(UINT nFlags, CPoint point) 
{

	// TODO: Add your message handler code here and/or call default
	if (m_bCaptured)
	{
	pEnd[num].x=point.x;
	pEnd[num].y=point.y;
    lineDDA(pStart[num].x, pStart[num].y, pEnd[num].x, pEnd[num].y);
	}

    this->Invalidate(TRUE);//可以尝试着去掉看一下效果

	
	CView::OnMouseMove(nFlags, point);
}
