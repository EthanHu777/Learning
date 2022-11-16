// drawCGView.h : interface of the CDrawCGView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWCGVIEW_H__E0C254D1_1AAC_4EC8_8691_C132BB865820__INCLUDED_)
#define AFX_DRAWCGVIEW_H__E0C254D1_1AAC_4EC8_8691_C132BB865820__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawCGView : public CView
{
protected: // create from serialization only
	CDrawCGView();
	DECLARE_DYNCREATE(CDrawCGView)

// Attributes
public:
	CDrawCGDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawCGView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:

	BOOL m_bCaptured;            //确定是否处于画线状态
	int steps;                   //确定迭代次数
	void lineDDA(int xa, int ya, int xb, int yb); //DDA画线
	CPoint pStart;               //直线的开始点
	CPoint pEnd;                 //直线的结束点
	int** line;                  //直线上各个点的坐标 

	virtual ~CDrawCGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawCGView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in drawCGView.cpp
inline CDrawCGDoc* CDrawCGView::GetDocument()
   { return (CDrawCGDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCGVIEW_H__E0C254D1_1AAC_4EC8_8691_C132BB865820__INCLUDED_)
