// HideWndDlg.h : header file
//

#if !defined(AFX_HIDEWNDDLG_H__9994AE24_712D_4BA6_AFE7_CF5220153A4F__INCLUDED_)
#define AFX_HIDEWNDDLG_H__9994AE24_712D_4BA6_AFE7_CF5220153A4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHideWndDlg dialog

class CHideWndDlg : public CDialog
{
// Construction
public:
	void OnTimer(INT nIDEvent);
	CHideWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHideWndDlg)
	enum { IDD = IDD_HIDEWND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHideWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer( UINT nIDEvent );
	afx_msg void OnMove(int x, int y);
	afx_msg void OnCancelMode();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDEWNDDLG_H__9994AE24_712D_4BA6_AFE7_CF5220153A4F__INCLUDED_)
