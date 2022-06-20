// OutlookBarDlg.h : header file
//

#if !defined(AFX_OUTLOOKBARDLG_H__3DF225A1_9D51_412D_ACD2_CB45B2E36C70__INCLUDED_)
#define AFX_OUTLOOKBARDLG_H__3DF225A1_9D51_412D_ACD2_CB45B2E36C70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "MySplitterWnd.h" // for CMySplitterWnd
#include "toolbar/XTOutBarCtrl.h"


/////////////////////////////////////////////////////////////////////////////
// COutlookBarDlg dialog

class COutlookBarDlg : public CDialog
{
// Construction
public:
	COutlookBarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COutlookBarDlg)
	enum { IDD = IDD_OUTLOOKBAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutlookBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Attributes
public:
	bool m_bInitialized;
	bool m_bShouldSetXColumn;
	//CMySplitterWnd m_wndSplitter;
	//CMySplitterWnd* m_pWndSplitter;
	CXTOutBarCtrl	m_wndOutlookBar;
	CImageList	m_ImageLarge;
	CImageList	m_ImageSmall;
	CImageList	m_ImageFolder;

	bool		m_bDestroy;
public:
	void InitializeOutlookBar();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COutlookBarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTLOOKBARDLG_H__3DF225A1_9D51_412D_ACD2_CB45B2E36C70__INCLUDED_)
