// DockedHideDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DockedHide.h"
#include "DockedHideDlg.h"

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
// CDockedHideDlg dialog

CDockedHideDlg::CDockedHideDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDockedHideDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDockedHideDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDockedHideDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDockedHideDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDockedHideDlg, CDialog)
	//{{AFX_MSG_MAP(CDockedHideDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDockedHideDlg message handlers

BOOL CDockedHideDlg::OnInitDialog()
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



	//初始化
	m_screenX=GetSystemMetrics(SM_CXSCREEN);
	m_screenY=GetSystemMetrics(SM_CYSCREEN);
	m_lastActiveTime=GetTickCount();
	m_hidePosition = HidePosition::NO;
	
	//设置定时器，1=nFlags 100=间隔ms
	SetTimer(1,100,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDockedHideDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDockedHideDlg::OnPaint() 
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
HCURSOR CDockedHideDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDockedHideDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnMouseMove(nFlags, point);
}

void CDockedHideDlg::OnCancelMode(UINT nFlags, CPoint point) 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	m_lastActiveTime = GetTickCount();
	CDialog::OnMouseMove(nFlags, point);
}

BOOL CDockedHideDlg::isMouseInWindow()
{
	CRect rect;
	GetWindowRect(&rect);
	CPoint point;
	GetCursorPos(&point);
	return rect.PtInRect(point);
}

void CDockedHideDlg::OnTimer(UINT nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
		if(GetTickCount()-m_lastActiveTime < 300) {
			//显示
			DockedShow();
		}else{  
			//隐藏
			DockedHidden();
		}
		break;
	} //switch End

	CDialog::OnTimer(nIDEvent);
} // CDockedHideDlg::OnTimer End


//停靠隐藏
void CDockedHideDlg::DockedHidden()
{
	CRect rect;
	CRect m_rect;
	GetWindowRect(&rect);
	if(m_hidePosition == HidePosition::NO && !isMouseInWindow()) {
		m_rect = rect;
		if(m_rect.top <= 0 ) {
			//靠顶
			m_hidePosition = HidePosition::TOP;
			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(NULL,m_rect.left, 0,m_rect.right-m_rect.left,2,SWP_NOCOPYBITS);
			//下移
			//右移动
			m_rect.bottom -= m_rect.top;
			m_rect.top = 0;
		}else if(m_rect.left <= 0 ) {  //靠左
			m_hidePosition = HidePosition::LEFT;
			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(NULL,0,m_rect.top,2,m_rect.bottom-m_rect.top,SWP_NOCOPYBITS);
			//右移动
			m_rect.right -= m_rect.left;
			m_rect.left = 0;
		}else if( m_rect.right >= m_screenX ) { //靠右
			m_hidePosition = HidePosition::RIGHT;
			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(NULL,m_screenX-2,m_rect.top,2,m_rect.bottom-m_rect.top,SWP_NOCOPYBITS);
			//左移动
			m_rect.left = m_screenX-(m_rect.right - m_rect.left);
			m_rect.right = m_screenX;
		}else{
			m_hidePosition = HidePosition::NO;
		}

	}   // if(m_hidePosition End

} //DockedHidden() End


void CDockedHideDlg::DockedShow()
{
	CRect rect;
	CRect m_rect;
	GetWindowRect(&rect);

	if(m_hidePosition !=HidePosition::NO && isMouseInWindow()) {  //已隐藏，显示旧值
		//恢复样式
		ModifyStyle(NULL, WS_SYSMENU);
		//还原大小
		int seq = 0;
		switch(m_hidePosition) {
		case HidePosition::TOP:
			while (++seq <= 5){
				this->SetWindowPos(NULL,m_rect.left,m_rect.top,m_rect.right-m_rect.left,(m_rect.bottom-m_rect.top)*seq/5,SWP_NOCOPYBITS);
				Sleep(80);
			}
			break;
		case HidePosition::LEFT:
			while (++seq <= 5){
				this->SetWindowPos(NULL,m_rect.left,m_rect.top,(m_rect.right-m_rect.left)*seq/5,m_rect.bottom-m_rect.top,SWP_NOCOPYBITS);
				Sleep(80);
			}
			break;
		case HidePosition::RIGHT:
			while (++seq <= 5){
				this->SetWindowPos(NULL,m_rect.left+(m_rect.right-m_rect.left)*(5-seq)/5,m_rect.top,m_rect.right-m_rect.left,m_rect.bottom-m_rect.top,SWP_NOCOPYBITS);
				Sleep(80);
			}
			break;
		}  //switch End
	} // if End

	m_hidePosition = HidePosition::NO;
}  //DockedShow()  End
