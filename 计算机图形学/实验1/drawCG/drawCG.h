// drawCG.h : main header file for the DRAWCG application
//

#if !defined(AFX_DRAWCG_H__7FC29DC6_7FA5_41B8_B185_41CFFDD0B9E3__INCLUDED_)
#define AFX_DRAWCG_H__7FC29DC6_7FA5_41B8_B185_41CFFDD0B9E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawCGApp:
// See drawCG.cpp for the implementation of this class
//

class CDrawCGApp : public CWinApp
{
public:
	CDrawCGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawCGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawCGApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCG_H__7FC29DC6_7FA5_41B8_B185_41CFFDD0B9E3__INCLUDED_)
