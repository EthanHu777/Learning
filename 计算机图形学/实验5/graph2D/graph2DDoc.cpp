// graph2DDoc.cpp : implementation of the CGraph2DDoc class
//

#include "stdafx.h"
#include "graph2D.h"

#include "graph2DDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraph2DDoc

IMPLEMENT_DYNCREATE(CGraph2DDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraph2DDoc, CDocument)
	//{{AFX_MSG_MAP(CGraph2DDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraph2DDoc construction/destruction

CGraph2DDoc::CGraph2DDoc()
{
	// TODO: add one-time construction code here

}

CGraph2DDoc::~CGraph2DDoc()
{
}

BOOL CGraph2DDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGraph2DDoc serialization

void CGraph2DDoc::Serialize(CArchive& ar)
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
// CGraph2DDoc diagnostics

#ifdef _DEBUG
void CGraph2DDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraph2DDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraph2DDoc commands
