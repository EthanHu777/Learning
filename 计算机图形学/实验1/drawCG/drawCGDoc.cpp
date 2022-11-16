// drawCGDoc.cpp : implementation of the CDrawCGDoc class
//

#include "stdafx.h"
#include "drawCG.h"

#include "drawCGDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawCGDoc

IMPLEMENT_DYNCREATE(CDrawCGDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawCGDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawCGDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawCGDoc construction/destruction

CDrawCGDoc::CDrawCGDoc()
{
	// TODO: add one-time construction code here

}

CDrawCGDoc::~CDrawCGDoc()
{
}

BOOL CDrawCGDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawCGDoc serialization

void CDrawCGDoc::Serialize(CArchive& ar)
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
// CDrawCGDoc diagnostics

#ifdef _DEBUG
void CDrawCGDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawCGDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawCGDoc commands
