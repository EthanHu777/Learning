// test2016View.h : interface of the CTest2016View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST2016VIEW_H__885FBA53_C3B1_4FD9_8F9D_71895181CFD2__INCLUDED_)
#define AFX_TEST2016VIEW_H__885FBA53_C3B1_4FD9_8F9D_71895181CFD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest2016View : public CView
{
protected: // create from serialization only
	CTest2016View();
	DECLARE_DYNCREATE(CTest2016View)

// Attributes
public:
	CTest2016Doc* GetDocument();

// Operations
public:
	//第一步：加入对应的成员变量和成员函数
	int steps;                   //确定线段实际长度
	void setLineBres(int xa, int ya, int xb, int yb);//在标准位置上进行bres画线
	void lineBres(int xa, int ya, int xb, int yb);// 实现任意斜率bres画线

    struct point2D
	{
		int x,y;
	} line[5000];         //直线上各个点的坐标 


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest2016View)
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
	virtual ~CTest2016View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest2016View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test2016View.cpp
inline CTest2016Doc* CTest2016View::GetDocument()
   { return (CTest2016Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST2016VIEW_H__885FBA53_C3B1_4FD9_8F9D_71895181CFD2__INCLUDED_)
