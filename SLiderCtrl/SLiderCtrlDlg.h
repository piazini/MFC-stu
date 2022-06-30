// SLiderCtrlDlg.h : header file
//

#if !defined(AFX_SLIDERCTRLDLG_H__4D85371A_ACE7_47A3_BD7D_D2ACBBAF28AB__INCLUDED_)
#define AFX_SLIDERCTRLDLG_H__4D85371A_ACE7_47A3_BD7D_D2ACBBAF28AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSLiderCtrlDlg dialog

class CSLiderCtrlDlg : public CDialog
{
// Construction
public:
	CSLiderCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSLiderCtrlDlg)
	enum { IDD = IDD_SLIDERCTRL_DIALOG };
	CSliderCtrl	m_SilderCtrl;
	int		m_Number;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSLiderCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSLiderCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDERCTRLDLG_H__4D85371A_ACE7_47A3_BD7D_D2ACBBAF28AB__INCLUDED_)
