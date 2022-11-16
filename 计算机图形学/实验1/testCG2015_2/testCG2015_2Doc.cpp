// testCG2015_2Doc.cpp : implementation of the CTestCG2015_2Doc class
//

#include "stdafx.h"
#include "testCG2015_2.h"

#include "testCG2015_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2Doc

IMPLEMENT_DYNCREATE(CTestCG2015_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CTestCG2015_2Doc, CDocument)
	//{{AFX_MSG_MAP(CTestCG2015_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2Doc construction/destruction

CTestCG2015_2Doc::CTestCG2015_2Doc()
{
	// TODO: add one-time construction code here

}

CTestCG2015_2Doc::~CTestCG2015_2Doc()
{
}

BOOL CTestCG2015_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2Doc serialization

void CTestCG2015_2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2Doc diagnostics

#ifdef _DEBUG
void CTestCG2015_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestCG2015_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2Doc commands
