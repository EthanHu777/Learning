// testCG2015_2View.h : interface of the CTestCG2015_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTCG2015_2VIEW_H__03A93CC5_8295_46C6_9247_13F2C39C79E4__INCLUDED_)
#define AFX_TESTCG2015_2VIEW_H__03A93CC5_8295_46C6_9247_13F2C39C79E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestCG2015_2View : public CView
{
protected: // create from serialization only
	CTestCG2015_2View();
	DECLARE_DYNCREATE(CTestCG2015_2View)

// Attributes
public:
	CTestCG2015_2Doc* GetDocument();

// Operations
public:
	//第一步：加入对应的成员变量和成员函数
	int steps;                   //确定迭代次数
	void lineDDA(int xa, int ya, int xb, int yb); //DDA画线
    struct point2D
	{
		int x,y;
	} line[1000];         //直线上各个点的坐标 
	struct point2D pStart;               //直线的开始点
	struct point2D pEnd;                 //直线的结束点

	BOOL m_bCaptured;            //确定是否处于画线状态


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCG2015_2View)
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
	virtual ~CTestCG2015_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestCG2015_2View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testCG2015_2View.cpp
inline CTestCG2015_2Doc* CTestCG2015_2View::GetDocument()
   { return (CTestCG2015_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCG2015_2VIEW_H__03A93CC5_8295_46C6_9247_13F2C39C79E4__INCLUDED_)
