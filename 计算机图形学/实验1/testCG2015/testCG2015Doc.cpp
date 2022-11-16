// testCG2015Doc.cpp : implementation of the CTestCG2015Doc class
//

#include "stdafx.h"
#include "testCG2015.h"

#include "testCG2015Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015Doc

IMPLEMENT_DYNCREATE(CTestCG2015Doc, CDocument)

BEGIN_MESSAGE_MAP(CTestCG2015Doc, CDocument)
	//{{AFX_MSG_MAP(CTestCG2015Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015Doc construction/destruction

CTestCG2015Doc::CTestCG2015Doc()
{
	// TODO: add one-time construction code here

}

CTestCG2015Doc::~CTestCG2015Doc()
{
}

BOOL CTestCG2015Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestCG2015Doc serialization

void CTestCG2015Doc::Serialize(CArchive& ar)
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
// CTestCG2015Doc diagnostics

#ifdef _DEBUG
void CTestCG2015Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestCG2015Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015Doc commands
