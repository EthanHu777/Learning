// drawCGDoc.h : interface of the CDrawCGDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWCGDOC_H__14009C10_8BC0_4125_B78A_32BC05FEE783__INCLUDED_)
#define AFX_DRAWCGDOC_H__14009C10_8BC0_4125_B78A_32BC05FEE783__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawCGDoc : public CDocument
{
protected: // create from serialization only
	CDrawCGDoc();
	DECLARE_DYNCREATE(CDrawCGDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawCGDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawCGDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawCGDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCGDOC_H__14009C10_8BC0_4125_B78A_32BC05FEE783__INCLUDED_)
