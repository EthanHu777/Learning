// testCG2015_2.h : main header file for the TESTCG2015_2 application
//

#if !defined(AFX_TESTCG2015_2_H__B957219F_0594_474A_8207_8883651981CC__INCLUDED_)
#define AFX_TESTCG2015_2_H__B957219F_0594_474A_8207_8883651981CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestCG2015_2App:
// See testCG2015_2.cpp for the implementation of this class
//

class CTestCG2015_2App : public CWinApp
{
public:
	CTestCG2015_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCG2015_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTestCG2015_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCG2015_2_H__B957219F_0594_474A_8207_8883651981CC__INCLUDED_)
