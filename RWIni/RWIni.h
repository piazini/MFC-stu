// RWIni.h : main header file for the RWINI application
//

#if !defined(AFX_RWINI_H__E0E478FF_0BB2_4FE6_A8B9_7167EB0C10E5__INCLUDED_)
#define AFX_RWINI_H__E0E478FF_0BB2_4FE6_A8B9_7167EB0C10E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRWIniApp:
// See RWIni.cpp for the implementation of this class
//

class CRWIniApp : public CWinApp
{
public:
	CRWIniApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRWIniApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRWIniApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RWINI_H__E0E478FF_0BB2_4FE6_A8B9_7167EB0C10E5__INCLUDED_)
