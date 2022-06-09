// HideWndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HideWnd.h"
#include "HideWndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHideWndDlg dialog

CHideWndDlg::CHideWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHideWndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHideWndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHideWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHideWndDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHideWndDlg, CDialog)
	//{{AFX_MSG_MAP(CHideWndDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_MOVE()
	ON_WM_CANCELMODE()
	ON_WM_LBUTTONUP()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHideWndDlg message handlers

BOOL CHideWndDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetTimer(1, 100, NULL);



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHideWndDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHideWndDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHideWndDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHideWndDlg::OnTimer(UINT nIDEvent)
{
	CRect rc;
	CRect rect;
	GetWindowRect(&rect);
	rc.CopyRect(&rect);

	CPoint point;
	GetCursorPos(&point);	//获取光标位置，以屏幕坐标表示

	//上边
	if (rect.top < 0 && PtInRect(rect, point)) //PtInRect判断一个点是否在CRect中
	{
		rect.top = 0;
		MoveWindow(rect.left, rect.top, rc.Width(), rc.Height());
	}
	else if (rect.top > -3 && rect.top < 3 && !PtInRect(rect,point))
	{
		rect.top = 3 - rect.Height();		//贴边后保留3个像素，不能设置0，设置0就不能捕获鼠标l
		MoveWindow(rect.left, rect.top, rc.Width(), rc.Height());
	}


	//左
	if (rect.left < 0 && PtInRect(rect, point)) //PtInRect判断一个点是否在CRect中
	{
		rect.left = 0;
		MoveWindow(rect.left, rect.top, rc.Width(), rc.Height());
	}
	else if (rect.left > -3 && rect.left < 3 && !PtInRect(rect,point))
	{
		rect.left = 3 - rect.Width();
		MoveWindow(rect.left, rect.top, rc.Width(), rc.Height());
	}
	
	//右
	if (rect.right >1360 && PtInRect(rect, point)) //PtInRect判断一个点是否在CRect中
	{
		//MessageBox(_T("true"));
		//rect.left = 3;
		rect.right = 1360;
		//MoveWindow(rect.right, rect.top, rc.Width(), rc.Height());
		MoveWindow(rect.left+(rect.right-rect.left),rect.top, rect.right-rect.left, rect.bottom-rect.top);
	}
	else if (rect.right > -3 && rect.right < 3 && !PtInRect(rect,point))
	{
		//MessageBox(_T("false"));
		rect.left = 3 + rect.Width();
		MoveWindow(rect.left, rect.top, rc.Width(), rc.Height());
	}



	CDialog::OnTimer(nIDEvent);
}

void CHideWndDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	/*CRect rect;
	CString str;
	//str.Format(_T("left=%d, right=%d"),rect.left,rect.right);
	str.Format(_T("x=%d, y=%d"),x, y);
	MessageBox(str);*/
}

void CHideWndDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here

}


//鼠标左键弹起
void CHideWndDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	/*
	CRect rect;
	CString str;
	str.Format(_T("left=%d, right=%d"),rect.top,rect.right);
	MessageBox(str,_T("鼠标左键弹起"));*/

	CDialog::OnLButtonUp(nFlags, point);
}

void CHideWndDlg::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here



	CDialog::OnCaptureChanged(pWnd);
}
