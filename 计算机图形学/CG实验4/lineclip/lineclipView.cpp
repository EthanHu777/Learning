// lineclipView.cpp : implementation of the CLineclipView class
//

#include "stdafx.h"
#include "lineclip.h"

#include "lineclipDoc.h"
#include "lineclipView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define LEFT 1   /*二进制表示:0001*/
#define RIGHT 2  /*二进制表示:0010*/
#define BOTTOM 4 /*二进制表示:0100*/
#define  TOP 8   /*二进制表示:1000*/

#define XL 100
#define XR 300
#define YT 100
#define YB 250

/////////////////////////////////////////////////////////////////////////////
// CLineclipView

IMPLEMENT_DYNCREATE(CLineclipView, CView)

BEGIN_MESSAGE_MAP(CLineclipView, CView)
	//{{AFX_MSG_MAP(CLineclipView)
	ON_COMMAND(ID_LINE_CLIP, OnLineClip)
	ON_COMMAND(ID_LINE_INPUT, OnLineInput)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineclipView construction/destruction

CLineclipView::CLineclipView()
{
	// TODO: add construction code here

}

CLineclipView::~CLineclipView()
{
}

BOOL CLineclipView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLineclipView drawing

void CLineclipView::OnDraw(CDC* pDC)
{
	CLineclipDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->Rectangle(CRect(XL,YT,XR,YB));//剪切窗口
	pDC->TextOut(100,70,"剪切窗口");
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLineclipView printing

BOOL CLineclipView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLineclipView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLineclipView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLineclipView diagnostics

#ifdef _DEBUG
void CLineclipView::AssertValid() const
{
	CView::AssertValid();
}

void CLineclipView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLineclipDoc* CLineclipView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLineclipDoc)));
	return (CLineclipDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLineclipView message handlers

void CLineclipView::OnLineClip() 
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CDC* pDC=GetDC();
	CPen newpen(PS_SOLID,1,RGB(0,255,0));
	CPen *old=pDC->SelectObject(&newpen);
	float x,y;
	int i;
	int code1,code2;
	RedrawWindow();
	// 求两端点所在区号code
	for(i=0;i<N;i++,i++)
	{
		int c=0;
		if(ptset[i].x<XL) c=c|LEFT;
		else if (ptset[i].x>XR)c=c|RIGHT;
		if(ptset[i].y>YB) c=c|BOTTOM;
		else if(ptset[i].y<YT) c=c|TOP;
		code1=c;
		 c=0;
		if(ptset[i+1].x<XL) c=c|LEFT;
		else if(ptset[i+1].x>XR) c=c|RIGHT;
		if(ptset[i+1].y>YB) c=c|BOTTOM;
		else if(ptset[i+1].y<YT) c=c|TOP;
		code2=c;
	//线段与区域的相交情况
	if(code1!=0&&code2!=0&&(code1&code2)==0)
	{	
		if((LEFT&code1)!=0) 	        //线段与左边界相交
		{
		x=XL;
		y=(float)ptset[i].y+(ptset[i+1].y-ptset[i].y)*(XL-ptset[i].x)/(ptset[i+1].x-ptset[i].x);
		}
		else if((RIGHT&code1)!=0)          //线段与右边界相交
		{
		x=XR;
		y=(float)ptset[i].y+(ptset[i+1].y-ptset[i].y)*(XR-ptset[i].x)/(ptset[i+1].x-ptset[i].x);
		}
	
		else if((BOTTOM&code1)!=0)          //线段与下边界相交
		{
		y=YB;
		x=(float)ptset[i].x+(ptset[i+1].x-ptset[i].x)*(YB-ptset[i].y)/(ptset[i+1].y-ptset[i+1].y);
		}
		else if((TOP&code1)!=0)          //线段与上边界相交
		{
		y=YT;
		x=(float)ptset[i].x+(ptset[i+1].x-ptset[i].x)*(YT-ptset[i].y)/(ptset[i+1].y-ptset[i].y);
		}

		ptset[i].x=(long)x;
		ptset[i].y=(long)y;	
		if((LEFT&code2)!=0) 	        //线段与左边界相交
		{
		x=XL;
		y=(float)ptset[i].y+(ptset[i+1].y-ptset[i].y)*(XL-ptset[i].x)/(ptset[i+1].x-ptset[i].x);
		}
		else if((RIGHT&code2)!=0)          //线段与右边界相交
		{
		x=XR;
		y=(float)ptset[i].y+(ptset[i+1].y-ptset[i].y)*(XR-ptset[i].x)/(ptset[i+1].x-ptset[i].x);
		}
	
		else if((BOTTOM&code2)!=0)          //线段与下边界相交
		{
		y=YB;
		x=(float)ptset[i].x+(ptset[i+1].x-ptset[i].x)*(YB-ptset[i].y)/(ptset[i+1].y-ptset[i+1].y);
		}
		else if((TOP&code2)!=0)          //线段与上边界相交
		{
		y=YT;
		x=(float)ptset[i].x+(ptset[i+1].x-ptset[i].x)*(YT-ptset[i].y)/(ptset[i+1].y-ptset[i].y);
		}
		ptset[i+1].x=(long)x;
		ptset[i+1].y=(long)y;	
		pDC->MoveTo(ptset[i].x,ptset[i].y);
		pDC->LineTo(ptset[i+1].x,ptset[i+1].y);
	}	
	if(code1==0&&code2==0)
	{pDC->MoveTo(ptset[i].x,ptset[i].y);
		pDC->LineTo(ptset[i+1].x,ptset[i+1].y);
	}
	if(code1==0&&code2!=0)
	{
		pDC->MoveTo(ptset[0].x,ptset[0].y);	
		if((LEFT&code2)!=0) 	        //线段与左边界相交
		{
		x=XL;
		y=(float)ptset[i].y+(ptset[i+1].y-ptset[i].y)*(XL-ptset[i].x)/(ptset[i+1].x-ptset[i].x);
		}
		else if((RIGHT&code2)!=0)          //线段与右边界相交
		{
		x=XR;
		y=(float)ptset[i].y+(ptset[i+1].y-ptset[i].y)*(XR-ptset[i].x)/(ptset[i+1].x-ptset[i].x);
		}
	
		else if((BOTTOM&code2)!=0)          //线段与下边界相交
		{
		y=YB;
		x=(float)ptset[i].x+(ptset[i+1].x-ptset[i].x)*(YB-ptset[i].y)/(ptset[i+1].y-ptset[i+1].y);
		}
		else if((TOP&code2)!=0)          //线段与上边界相交
		{
		y=YT;
		x=(float)ptset[i].x+(ptset[i+1].x-ptset[i].x)*(YT-ptset[i].y)/(ptset[i+1].y-ptset[i].y);
		}
		
		ptset[i+1].x=(long)x;
		ptset[i+1].y=(long)y;
		
		pDC->LineTo(ptset[i+1].x,ptset[i+1].y);
	}
			
	if(code1!=0&&code2==0)
	{
		pDC->MoveTo(ptset[i+1].x,ptset[i+1].y);
		if((LEFT&code1)!=0) 	        //线段与左边界相交
		{
		x=XL;
		y=(float)ptset[i].y+(ptset[i+1].y-ptset[i].y)*(XL-ptset[i].x)/(ptset[i+1].x-ptset[i].x);
		}
		else if((RIGHT&code1)!=0)          //线段与右边界相交
		{
		x=XR;
		y=(float)ptset[i].y+(ptset[i+1].y-ptset[i].y)*(XR-ptset[i].x)/(ptset[i+1].x-ptset[i].x);
		}
	
		else if((BOTTOM&code1)!=0)          //线段与下边界相交
		{
		y=YB;
		x=(float)ptset[i].x+(ptset[i+1].x-ptset[i].x)*(YB-ptset[i].y)/(ptset[i+1].y-ptset[i+1].y);
		}
		else if((TOP&code1)!=0)          //线段与上边界相交
		{
		y=YT;
		x=(float)ptset[i].x+(ptset[i+1].x-ptset[i].x)*(YT-ptset[i].y)/(ptset[i+1].y-ptset[i].y);
		}
		
		ptset[i].x=(long)x;
		ptset[i].y=(long)y;
		pDC->LineTo(ptset[i].x,ptset[i].y);
	}
	
	}		
}

void CLineclipView::OnLineInput() 
{
	// TODO: Add your command handler code here
	ptset[0]=CPoint(120,150);
	ptset[1]=CPoint(170,110);
    ptset[2]=CPoint(0,190);
	ptset[3]=CPoint(350,150);
	ptset[4]=CPoint(0,250);
	ptset[5]=CPoint(150,230);
	ptset[6]=CPoint(200,50);
	ptset[7]=CPoint(120,150);
	CDC* pDC=GetDC();
	CPen newpen(PS_SOLID,1,RGB(255,0,0));
	CPen *old=pDC->SelectObject(&newpen);
	for(int i=0;i<N;i++)
	{
		pDC->MoveTo(ptset[i]);
	    pDC->LineTo(ptset[i+1]);
	    i++;
	}

}
