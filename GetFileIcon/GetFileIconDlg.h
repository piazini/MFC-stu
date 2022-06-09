// GetFileIconDlg.h : header file
//

#if !defined(AFX_GETFILEICONDLG_H__EB2B77A0_CD6C_4742_8AAA_0B340FE1AD3A__INCLUDED_)
#define AFX_GETFILEICONDLG_H__EB2B77A0_CD6C_4742_8AAA_0B340FE1AD3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetFileIconDlg dialog

class CGetFileIconDlg : public CDialog
{
// Construction
public:
	CGetFileIconDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetFileIconDlg)
	enum { IDD = IDD_GETFILEICON_DIALOG };
	CButton	m_open;
	CString	m_filename;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFileIconDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetFileIconDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnGetion();
	afx_msg void OnExit();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETFILEICONDLG_H__EB2B77A0_CD6C_4742_8AAA_0B340FE1AD3A__INCLUDED_)
