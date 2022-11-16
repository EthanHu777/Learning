// lineclipView.h : interface of the CLineclipView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINECLIPVIEW_H__27764733_BDF0_4BA7_A5F7_409CA6776FBA__INCLUDED_)
#define AFX_LINECLIPVIEW_H__27764733_BDF0_4BA7_A5F7_409CA6776FBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define N 9

class CLineclipView : public CView
{
protected: // create from serialization only
	CLineclipView();
	DECLARE_DYNCREATE(CLineclipView)

// Attributes
public:
	CLineclipDoc* GetDocument();

// Operations
public:
	CPoint ptset[N];//存放多条直线段

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineclipView)
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
	virtual ~CLineclipView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLineclipView)
	afx_msg void OnLineClip();
	afx_msg void OnLineInput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lineclipView.cpp
inline CLineclipDoc* CLineclipView::GetDocument()
   { return (CLineclipDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINECLIPVIEW_H__27764733_BDF0_4BA7_A5F7_409CA6776FBA__INCLUDED_)
