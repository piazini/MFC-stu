// RMenuDlg.h : header file
//

#if !defined(AFX_RMENUDLG_H__F64F1147_23BA_4629_B757_64C41FE4EB48__INCLUDED_)
#define AFX_RMENUDLG_H__F64F1147_23BA_4629_B757_64C41FE4EB48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRMenuDlg dialog

class CRMenuDlg : public CDialog
{
// Construction
public:
	CRMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRMenuDlg)
	enum { IDD = IDD_RMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//�Ҽ��˵�
	afx_msg void On_32772();  //�Ҽ�-��Һ�
	afx_msg void On_32773();  //�Ҽ�-ͬѧ��
	afx_msg void On_32774();  //�Ҽ�-���
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMENUDLG_H__F64F1147_23BA_4629_B757_64C41FE4EB48__INCLUDED_)
