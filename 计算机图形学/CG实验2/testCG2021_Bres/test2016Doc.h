// test2016Doc.h : interface of the CTest2016Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST2016DOC_H__5F68C33D_7E58_46E9_A9BD_89538C0E6919__INCLUDED_)
#define AFX_TEST2016DOC_H__5F68C33D_7E58_46E9_A9BD_89538C0E6919__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest2016Doc : public CDocument
{
protected: // create from serialization only
	CTest2016Doc();
	DECLARE_DYNCREATE(CTest2016Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest2016Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest2016Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest2016Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST2016DOC_H__5F68C33D_7E58_46E9_A9BD_89538C0E6919__INCLUDED_)
