// drawCGView.cpp : implementation of the CDrawCGView class
//

#include "stdafx.h"
#include "drawCG.h"

#include "drawCGDoc.h"
#include "drawCGView.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawCGView

IMPLEMENT_DYNCREATE(CDrawCGView, CView)

BEGIN_MESSAGE_MAP(CDrawCGView, CView)
	//{{AFX_MSG_MAP(CDrawCGView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawCGView construction/destruction

CDrawCGView::CDrawCGView()
{
	line = NULL;
	m_bCaptured = FALSE;
	// TODO: add construction code here

}

CDrawCGView::~CDrawCGView()
{
	if (line!=NULL)
	{
	   	for (int i1=0; i1<steps;i1++)
		{
	  	    delete line[i1];
		} 
	   	delete [] line;
	}


}

BOOL CDrawCGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawCGView drawing

void CDrawCGView::OnDraw(CDC* pDC)
{
	CDrawCGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->SetPixel(pStart,255);
	for(int i1=0; i1<steps; i1++)
			pDC->SetPixel(line[i1][0],line[i1][1],255);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawCGView printing

BOOL CDrawCGView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawCGView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawCGView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawCGView diagnostics

#ifdef _DEBUG
void CDrawCGView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawCGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawCGDoc* CDrawCGView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawCGDoc)));
	return (CDrawCGDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawCGView message handlers

void CDrawCGView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CDrawCGView::lineDDA(int xa, int ya, int xb, int yb)
{
	int dx=xb-xa, dy=yb-ya;
	float xIncrement, yIncrement, x=(float)xa, y=(float)ya;
	if(abs(dx)>abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xIncrement = dx/(float)steps;
	yIncrement = dy/(float)steps;

	line = new int*[steps];
	for (int i = 0; i< steps; i++)
		line[i]= new int[2];

	for(int k=0; k<steps; k++)
	{
		line[k][0]=(int)(x+0.5);
		line[k][1]=(int)(y+0.5);
		x+=xIncrement;
		y+=yIncrement;
	}

}

void CDrawCGView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	pEnd=point;
    lineDDA(pStart.x, pStart.y, pEnd.x, pEnd.y);
//	this->Invalidate(TRUE);
	m_bCaptured = FALSE;

	CView::OnLButtonUp(nFlags, point);

}

void CDrawCGView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	pStart=point;
	m_bCaptured = TRUE;

	CView::OnLButtonDown(nFlags, point);
}

void CDrawCGView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    if(m_bCaptured)
	{
	    lineDDA(pStart.x, pStart.y, point.x, point.y);
   	    this->Invalidate(TRUE);
	}

	CView::OnMouseMove(nFlags, point);

}
