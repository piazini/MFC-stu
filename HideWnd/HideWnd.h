// HideWnd.h : main header file for the HIDEWND application
//

#if !defined(AFX_HIDEWND_H__8FF374EA_9E2D_4F8B_9CCD_0B931638E94B__INCLUDED_)
#define AFX_HIDEWND_H__8FF374EA_9E2D_4F8B_9CCD_0B931638E94B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHideWndApp:
// See HideWnd.cpp for the implementation of this class
//

class CHideWndApp : public CWinApp
{
public:
	CHideWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHideWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDEWND_H__8FF374EA_9E2D_4F8B_9CCD_0B931638E94B__INCLUDED_)
