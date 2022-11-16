// testCG2015View.h : interface of the CTestCG2015View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTCG2015VIEW_H__B600B70B_6609_4BA9_B827_CC21762431DD__INCLUDED_)
#define AFX_TESTCG2015VIEW_H__B600B70B_6609_4BA9_B827_CC21762431DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestCG2015View : public CView
{
protected: // create from serialization only
	CTestCG2015View();
	DECLARE_DYNCREATE(CTestCG2015View)

// Attributes
public:
	CTestCG2015Doc* GetDocument();

// Operations
public:
	//第一步：加入对应的成员变量和成员函数
	int steps;                   //确定迭代次数
	void lineDDA(int xa, int ya, int xb, int yb); //DDA画线
    struct point2D
	{
		int x,y;
	} line[1000];         //直线上各个点的坐标 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCG2015View)
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
	virtual ~CTestCG2015View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestCG2015View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testCG2015View.cpp
inline CTestCG2015Doc* CTestCG2015View::GetDocument()
   { return (CTestCG2015Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCG2015VIEW_H__B600B70B_6609_4BA9_B827_CC21762431DD__INCLUDED_)
