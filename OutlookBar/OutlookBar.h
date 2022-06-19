// OutlookBar.h : main header file for the OUTLOOKBAR application
//

#if !defined(AFX_OUTLOOKBAR_H__07290E47_C892_4F5D_A601_74599DA66CC4__INCLUDED_)
#define AFX_OUTLOOKBAR_H__07290E47_C892_4F5D_A601_74599DA66CC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COutlookBarApp:
// See OutlookBar.cpp for the implementation of this class
//

class COutlookBarApp : public CWinApp
{
public:
	COutlookBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutlookBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COutlookBarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTLOOKBAR_H__07290E47_C892_4F5D_A601_74599DA66CC4__INCLUDED_)
