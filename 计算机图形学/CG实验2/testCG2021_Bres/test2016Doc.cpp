// test2016Doc.cpp : implementation of the CTest2016Doc class
//

#include "stdafx.h"
#include "test2016.h"

#include "test2016Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest2016Doc

IMPLEMENT_DYNCREATE(CTest2016Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest2016Doc, CDocument)
	//{{AFX_MSG_MAP(CTest2016Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest2016Doc construction/destruction

CTest2016Doc::CTest2016Doc()
{
	// TODO: add one-time construction code here

}

CTest2016Doc::~CTest2016Doc()
{
}

BOOL CTest2016Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest2016Doc serialization

void CTest2016Doc::Serialize(CArchive& ar)
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
// CTest2016Doc diagnostics

#ifdef _DEBUG
void CTest2016Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest2016Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest2016Doc commands
