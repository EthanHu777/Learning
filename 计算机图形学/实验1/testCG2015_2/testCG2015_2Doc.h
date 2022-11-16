// testCG2015_2Doc.h : interface of the CTestCG2015_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTCG2015_2DOC_H__DBE859E8_CD02_4B51_A635_F109C68346A0__INCLUDED_)
#define AFX_TESTCG2015_2DOC_H__DBE859E8_CD02_4B51_A635_F109C68346A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestCG2015_2Doc : public CDocument
{
protected: // create from serialization only
	CTestCG2015_2Doc();
	DECLARE_DYNCREATE(CTestCG2015_2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCG2015_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestCG2015_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestCG2015_2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCG2015_2DOC_H__DBE859E8_CD02_4B51_A635_F109C68346A0__INCLUDED_)
