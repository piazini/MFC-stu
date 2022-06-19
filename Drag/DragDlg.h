// DragDlg.h : header file
//

#if !defined(AFX_DRAGDLG_H__4917E3B5_CC0E_4145_BB0C_C50882C02E4C__INCLUDED_)
#define AFX_DRAGDLG_H__4917E3B5_CC0E_4145_BB0C_C50882C02E4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDragDlg dialog

class CDragDlg : public CDialog
{
// Construction
public:
	CDragDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDragDlg)
	enum { IDD = IDD_DRAG_DIALOG };
	CButton	m_open;
	CString	m_filename;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDragDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnDropFiles( HDROP );			//֧�ֽ�����ק
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGDLG_H__4917E3B5_CC0E_4145_BB0C_C50882C02E4C__INCLUDED_)
