// testCG2015Doc.h : interface of the CTestCG2015Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTCG2015DOC_H__0C8469DF_E87F_4CF3_AC02_7267538AADC0__INCLUDED_)
#define AFX_TESTCG2015DOC_H__0C8469DF_E87F_4CF3_AC02_7267538AADC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestCG2015Doc : public CDocument
{
protected: // create from serialization only
	CTestCG2015Doc();
	DECLARE_DYNCREATE(CTestCG2015Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCG2015Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestCG2015Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestCG2015Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCG2015DOC_H__0C8469DF_E87F_4CF3_AC02_7267538AADC0__INCLUDED_)
