// graph2DView.h : interface of the CGraph2DView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPH2DVIEW_H__652D9089_2DF9_42D4_9ADA_4143C36E415E__INCLUDED_)
#define AFX_GRAPH2DVIEW_H__652D9089_2DF9_42D4_9ADA_4143C36E415E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraph2DView : public CView
{
protected: // create from serialization only
	CGraph2DView();
	DECLARE_DYNCREATE(CGraph2DView)

// Attributes
public:
	CGraph2DDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraph2DView)
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
	virtual ~CGraph2DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraph2DView)
	afx_msg void Oncenter();
	afx_msg void Onrot();
	afx_msg void Onscale();
	afx_msg void Ontran();
	afx_msg void OnXmir();
	afx_msg void OnYmir();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in graph2DView.cpp
inline CGraph2DDoc* CGraph2DView::GetDocument()
   { return (CGraph2DDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPH2DVIEW_H__652D9089_2DF9_42D4_9ADA_4143C36E415E__INCLUDED_)
