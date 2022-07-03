// DockedHideDlg.h : header file
//

#if !defined(AFX_DOCKEDHIDEDLG_H__EDA27C2B_4BE4_4935_8470_7552EA3A09E2__INCLUDED_)
#define AFX_DOCKEDHIDEDLG_H__EDA27C2B_4BE4_4935_8470_7552EA3A09E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDockedHideDlg dialog

class CDockedHideDlg : public CDialog
{
// Construction
public:
	void DockedShow();
	void DockedHidden();
	void OnTimer(UINT nIDEvent);
	BOOL isMouseInWindow();
	CDockedHideDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	//{{AFX_DATA(CDockedHideDlg)
	enum { IDD = IDD_DOCKEDHIDE_DIALOG };
	// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	enum HidePosition{
	NO,  //非靠边
	LEFT, //靠左
	RIGHT,//靠右
	TOP	  //靠上
	};

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDockedHideDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	DWORD m_lastActiveTime;
	int m_screenX,m_screenY;
	HidePosition m_hidePosition; 

	CRect default_rect;		//存储对话框默认大小

	// Generated message map functions
	//{{AFX_MSG(CDockedHideDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcMouseMove(UINT nFlags, CPoint point);
//	afx_msg void OnCancelMode(UINT nFlags, CPoint point);
//	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCKEDHIDEDLG_H__EDA27C2B_4BE4_4935_8470_7552EA3A09E2__INCLUDED_)
