// graph2DDoc.h : interface of the CGraph2DDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPH2DDOC_H__21DBCF08_8A95_40E0_9D31_D2B586C17D71__INCLUDED_)
#define AFX_GRAPH2DDOC_H__21DBCF08_8A95_40E0_9D31_D2B586C17D71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraph2DDoc : public CDocument
{
protected: // create from serialization only
	CGraph2DDoc();
	DECLARE_DYNCREATE(CGraph2DDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraph2DDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGraph2DDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraph2DDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPH2DDOC_H__21DBCF08_8A95_40E0_9D31_D2B586C17D71__INCLUDED_)
