// RMenu.h : main header file for the RMENU application
//

#if !defined(AFX_RMENU_H__3F2B67F2_0E00_4FF3_AF97_CBAF5BA29C83__INCLUDED_)
#define AFX_RMENU_H__3F2B67F2_0E00_4FF3_AF97_CBAF5BA29C83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRMenuApp:
// See RMenu.cpp for the implementation of this class
//

class CRMenuApp : public CWinApp
{
public:
	CRMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMENU_H__3F2B67F2_0E00_4FF3_AF97_CBAF5BA29C83__INCLUDED_)
