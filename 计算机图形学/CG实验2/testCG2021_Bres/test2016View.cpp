// test2016View.cpp : implementation of the CTest2016View class
//

#include "stdafx.h"
#include "test2016.h"

#include "test2016Doc.h"
#include "test2016View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest2016View

IMPLEMENT_DYNCREATE(CTest2016View, CView)

BEGIN_MESSAGE_MAP(CTest2016View, CView)
	//{{AFX_MSG_MAP(CTest2016View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest2016View construction/destruction

CTest2016View::CTest2016View()
{
	// TODO: add construction code here

}

CTest2016View::~CTest2016View()
{
}

BOOL CTest2016View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest2016View drawing

void CTest2016View::OnDraw(CDC* pDC)
{
	CTest2016Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//第三步：函数调用及直线绘制
	lineBres(100,150,200,200);
	for(int i1=0; i1<steps; i1++)
			pDC->SetPixel(line[i1].x,line[i1].y,RGB(255,0,0));
	lineBres(300,500,100,200);
	for(int i2=0; i2<steps; i2++)
			pDC->SetPixel(line[i2].x,line[i2].y,RGB(255,0,0));

}

/////////////////////////////////////////////////////////////////////////////
// CTest2016View printing

BOOL CTest2016View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest2016View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest2016View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest2016View diagnostics

#ifdef _DEBUG
void CTest2016View::AssertValid() const
{
	CView::AssertValid();
}

void CTest2016View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest2016Doc* CTest2016View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest2016Doc)));
	return (CTest2016Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest2016View message handlers
//第二步：完成Bres算法对应的函数
void CTest2016View::lineBres(int xa, int ya, int xb, int yb)
{
	int dx=abs(xa-xb), dy=abs(ya-yb);
	if (dx<=dy)
	{
		setLineBres(ya, xa, yb, xb);
		int temp;
		for (int i = 0; i < dy; i++)
		{
            temp=line[i].x;
			line[i].x=line[i].y;
		    line[i].y=temp;
		}
   	}
	else
	{
	   setLineBres(xa, ya, xb, yb);
	}
}

void CTest2016View::setLineBres(int xa, int ya, int xb, int yb)
{
    int x, y,p,twoDy,twoDyDx;
	int dx=abs(xa-xb), dy=abs(ya-yb);

 	steps=dx;
	p = 2*dy-dx;
   	twoDy = 2*dy;
   	twoDyDx = 2*(dy-dx);

	if(xa>xb)
	{
		x=xb;
		y=yb;
 	}
	else
	{
		x=xa;
		y=ya;
	}
	line[0].x=x;
	line[0].y=y;
	for(int k=1; k<steps; k++)
	{
		if(p<0)
			p+=twoDy;
		else
		{
			if (((xb-xa)*(yb-ya))<=0) y--;
			else y++;
			p+=twoDyDx;
		}
		line[k].x=x+k;
		line[k].y=y;
	}
}
