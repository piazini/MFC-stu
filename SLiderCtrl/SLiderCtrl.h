// SLiderCtrl.h : main header file for the SLIDERCTRL application
//

#if !defined(AFX_SLIDERCTRL_H__0B7A7934_F2D0_4251_943B_C63123742A0D__INCLUDED_)
#define AFX_SLIDERCTRL_H__0B7A7934_F2D0_4251_943B_C63123742A0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSLiderCtrlApp:
// See SLiderCtrl.cpp for the implementation of this class
//

class CSLiderCtrlApp : public CWinApp
{
public:
	CSLiderCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSLiderCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSLiderCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDERCTRL_H__0B7A7934_F2D0_4251_943B_C63123742A0D__INCLUDED_)
