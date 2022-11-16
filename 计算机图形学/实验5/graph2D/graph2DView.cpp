// graph2DView.cpp : implementation of the CGraph2DView class
//

#include "stdafx.h"
#include "graph2D.h"

#include "graph2DDoc.h"
#include "graph2DView.h"

#include "Myclass.h"
#include "math.h"
#define PI  0.1745329252  /*    Pi/180     */

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraph2DView

IMPLEMENT_DYNCREATE(CGraph2DView, CView)

BEGIN_MESSAGE_MAP(CGraph2DView, CView)
	//{{AFX_MSG_MAP(CGraph2DView)
	ON_COMMAND(ID_center, Oncenter)
	ON_COMMAND(ID_rot, Onrot)
	ON_COMMAND(ID_scale, Onscale)
	ON_COMMAND(ID_tran, Ontran)
	ON_COMMAND(ID_X_mir, OnXmir)
	ON_COMMAND(ID_Y_mir, OnYmir)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraph2DView construction/destruction

CGraph2DView::CGraph2DView()
{
	// TODO: add construction code here

}

CGraph2DView::~CGraph2DView()
{
}

BOOL CGraph2DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraph2DView drawing

void CGraph2DView::OnDraw(CDC* pDC)
{
	CGraph2DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	// TODO: add draw code for native data here/  绘制字符原图形
 	int i,j;
		CMyClass my1;  //构造新的CMyClass对象
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A1[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A1[1][1]=1;
		my1.A1[2][2]=1;
		my1.A1[3][3]=1;
				
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		my1. Display ();
}

/////////////////////////////////////////////////////////////////////////////
// CGraph2DView printing

BOOL CGraph2DView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraph2DView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraph2DView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraph2DView diagnostics

#ifdef _DEBUG
void CGraph2DView::AssertValid() const
{
	CView::AssertValid();
}

void CGraph2DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraph2DDoc* CGraph2DView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraph2DDoc)));
	return (CGraph2DDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraph2DView message handlers

void CGraph2DView::Oncenter() 
{
	// TODO: Add your command handler code here
        int i,j;
		CMyClass my1;  //构造新的CMyClass对象

		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}

		//给图形变换矩阵赋值
		my1.A[1][1]=-1;
		my1.A[2][2]=-1;
		my1.A[3][3]=1;
	    RedrawWindow();
		my1. Display ();	
}

void CGraph2DView::Onrot() 
{
	// TODO: Add your command handler code here
	    int i,j;
		CMyClass my1;  //构造新的CMyClass对象
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=cos(PI*60);//旋转60度
		my1.A[1][2]=sin(PI*60);
		my1.A[2][1]=-sin(PI*60);
		my1.A[2][2]=cos(PI*60);
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}

void CGraph2DView::Onscale() 
{
	// TODO: Add your command handler code here
		int i,j;
		CMyClass my1;  //构造新的CMyClass对象
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=5;
		my1.A[2][2]=2;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}

void CGraph2DView::Ontran() 
{
	// TODO: Add your command handler code here
		int i,j;
		CMyClass my1;  //构造新的CMyClass对象
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=1;
		my1.A[2][2]=1;
		my1.A[3][1]=15;
		my1.A[3][2]=45;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}

void CGraph2DView::OnXmir() 
{
	// TODO: Add your command handler code here
        int i,j;
		CMyClass my1;  //构造新的CMyClass对象

		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=1;
		my1.A[2][2]=-1;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}

void CGraph2DView::OnYmir() 
{
	// TODO: Add your command handler code here
		int i,j;
		CMyClass my1;  //构造新的CMyClass对象

		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=-1;
		my1.A[2][2]=1;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}
