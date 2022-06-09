// RWIniDlg.h : header file
//

#if !defined(AFX_RWINIDLG_H__5E26F214_9FB9_4708_B80E_2BEC7C60B78B__INCLUDED_)
#define AFX_RWINIDLG_H__5E26F214_9FB9_4708_B80E_2BEC7C60B78B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRWIniDlg dialog

class CRWIniDlg : public CDialog
{
// Construction
public:
	CRWIniDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRWIniDlg)
	enum { IDD = IDD_RWINI_DIALOG };
	//CListBox	m_list;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRWIniDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRWIniDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RWINIDLG_H__5E26F214_9FB9_4708_B80E_2BEC7C60B78B__INCLUDED_)
