// DockedHide.h : main header file for the DOCKEDHIDE application
//

#if !defined(AFX_DOCKEDHIDE_H__08780E4D_815B_419D_8914_D63BE6A397A4__INCLUDED_)
#define AFX_DOCKEDHIDE_H__08780E4D_815B_419D_8914_D63BE6A397A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDockedHideApp:
// See DockedHide.cpp for the implementation of this class
//

class CDockedHideApp : public CWinApp
{
public:
	CDockedHideApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDockedHideApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDockedHideApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCKEDHIDE_H__08780E4D_815B_419D_8914_D63BE6A397A4__INCLUDED_)
