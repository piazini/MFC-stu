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
	ON_WM_NCMOUSEMOVE()
	//ON_WM_CANCELMODE()
	ON_WM_TIMER()
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

	//初始化,获取屏幕大小
	m_screenX=GetSystemMetrics(SM_CXSCREEN); 
	m_screenY=GetSystemMetrics(SM_CYSCREEN);

	//显示屏幕大小
	CString str1;
	str1.Format("屏幕大小：m_screenX=%i, m_screenY=%i",m_screenX,m_screenY);
	GetDlgItem(IDC_STATIC2) -> SetWindowText(str1);
	//MessageBox(str1);


	//CRect default_rect;
	//取得软件窗口在屏幕窗口里的坐标，包括客户区和非客户区
	GetWindowRect(&default_rect);
	//获取客户区大小，不包括标题栏的非客户区
	//GetClientRect(&default_rect);
	CString str;
	str.Format("窗口默认大小：\ndefault_rect.left=%d, \ndefault_rect.right=%d, \ndefault_rect.Height=%d, \ndefault_rect.Width=%d",default_rect.left,default_rect.right,default_rect.Height(),default_rect.Width());
	GetDlgItem(IDC_STATIC1) -> SetWindowText(str);
	//MessageBox(str);

	m_lastActiveTime=GetTickCount();

	//初始化，窗口显示或隐藏状态 ，默认状态窗口非隐藏
	m_hidePosition = HidePosition::NO;

	//设置定时器，100=nFlags 200=间隔ms
	SetTimer(100,200,NULL);
	GetDlgItem(IDC_STATIC) -> SetWindowText(_T("将对话框拖动到屏幕顶部边缘，对话框会自动隐藏"));


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


//鼠标消息，鼠标移动到客户区"内"，触发此消息
void CDockedHideDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_lastActiveTime = GetTickCount();

	CDialog::OnMouseMove(nFlags, point);
}

//鼠标消息,鼠标移动到客户区"外"，触发此消息
void CDockedHideDlg::OnNcMouseMove(UINT nFlags, CPoint point){
	m_lastActiveTime = GetTickCount();

	CDialog::OnNcMouseMove(nFlags, point);
}

/*
void CDockedHideDlg::OnCancelMode(UINT nFlags, CPoint point) 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	m_lastActiveTime = GetTickCount();
	CDialog::OnMouseMove(nFlags, point);
}
*/

//定义鼠标是否在窗体内函数
BOOL CDockedHideDlg::isMouseInWindow()
{
	CRect rect;
	GetWindowRect(&rect);

	CPoint point;
	GetCursorPos(&point);

	/*
	CString str;
	str = (CString)m_lastActiveTime;
	GetDlgItem(IDC_STATIC) -> SetWindowText(_T(str));
	*/

	//返回值：如果点位于CRect中，则返回非零值；否则返回0。
	return rect.PtInRect(point);
}

//定时器调用
void CDockedHideDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 100: 
		if(GetTickCount() - m_lastActiveTime < 300) { //展示
			DockedShow();
		}else{//隐藏
			DockedHidden();
		}
	break;
	}

	CDialog::OnTimer(nIDEvent);
}


//停靠隐藏
void CDockedHideDlg::DockedHidden()
{
	CRect rect;
	CRect m_rect;
	GetWindowRect(&rect);

	if(m_hidePosition == HidePosition::NO && !isMouseInWindow()) {
		m_rect = rect;
		if(m_rect.top <= 0 ) { //靠顶
			m_hidePosition = HidePosition::TOP;
			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(
				//NULL,		//原文窗口不设置最前
				&wndTopMost,	//设置窗口最前
				m_rect.left,	//窗口左边的新位置
				0,	//窗口顶部的新位置
				m_rect.right - m_rect.left,		//窗口的新宽度
				5,	//隐藏后，窗口的新高度，显示多少像素
				SWP_NOCOPYBITS
				);
			//下移
			//右移动
			m_rect.bottom -= m_rect.top;
			m_rect.top = 0;

		}else if( default_rect.left <= 0 ){ //靠左
			m_hidePosition = HidePosition::LEFT;
			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(&wndTopMost, 0, m_rect.top, 5, m_rect.bottom-m_rect.top, SWP_NOCOPYBITS);
			//右移动
			m_rect.right -=m_rect.left;
			m_rect.left =0;
			
		}else if( m_rect.right >= m_screenX ){ //靠右
			m_hidePosition = HidePosition::RIGHT;
			MessageBox(_T("RIGHT"));

			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(
				&wndTopMost,	//设置窗口最前
				m_screenX-12,	//窗口左边的新位置
				m_rect.top,			//窗口顶部的新位置
				5,			//窗口的新宽度。
				200,//m_rect.bottom-m_rect.top,		//指定了窗口的新高度
				SWP_SHOWWINDOW
				);
			//左移动
			m_rect.left = m_screenX-(m_rect.right - m_rect.left);
			//m_rect.left =m_rect.right - m_rect.left;
			m_rect.right =m_screenX;//m_rect.left; //偏移量   m_rect.right - m_screenX
			
		}else{
			m_hidePosition =HidePosition::NO;
		}	
	}   // if(m_hidePosition End

} //DockedHidden() End

//停靠展示
void CDockedHideDlg::DockedShow()
{
	CRect rect;
	CRect m_rect;
	//取得软件窗口在屏幕窗口里的坐标，包括客户区和非客户区
	GetWindowRect(&rect);

	if(m_hidePosition != HidePosition::NO && isMouseInWindow()) {  //已隐藏，显示旧值

		m_rect = rect;

		//恢复样式
		ModifyStyle(NULL, WS_SYSMENU);

		// 消息框提示默认窗口大小
		/*
		CString str;
		str.Format("default_rect.Height=%d, default_rect.Width=%d",default_rect.Height(),default_rect.Width());
		str.Format("%i,%i,%i",m_rect.bottom,m_rect.top);
		MessageBox(str);
		*/

		//还原大小
		int seq = 0;
		switch(m_hidePosition) {
			case HidePosition::TOP:
				//MessageBox(_T("TOP"));
				while (++seq <= 5){
					this->SetWindowPos(
						&wndTopMost, //保证窗口在最前
						m_rect.left,
						m_rect.top,
						m_rect.right - m_rect.left,
						//(m_rect.bottom - m_rect.top) * seq/5,   原文用此行值计算要恢复的窗口大小，不正确
						(default_rect.bottom - default_rect.top) * seq/5, 
						SWP_SHOWWINDOW
						);
					Sleep(20);
				}
			break;
			case HidePosition::LEFT:
				//MessageBox(_T("LEFT"));
				while (++seq <= 5){
					this->SetWindowPos(
						&wndTopMost,
						m_rect.left,
						m_rect.top,
						(default_rect.right-default_rect.left)*seq/5,
						m_rect.bottom-m_rect.top,
						SWP_NOCOPYBITS
						);
					Sleep(20);
				}
			break;
			case HidePosition::RIGHT:
				MessageBox(_T("RIGHT"));
				while (++seq <= 5){
					this->SetWindowPos(
						&wndTopMost,
						20,//default_rect.left+(default_rect.right-default_rect.left)*(5-seq)/5,
						30,//m_rect.top,
						300,//m_rect.right-m_rect.left,
						500,//m_rect.bottom-m_rect.top,
						SWP_SHOWWINDOW
						);
					Sleep(20);
				}
			break;
		}  //switch End
	} // if End

	m_hidePosition = HidePosition::NO;
}  //DockedShow()  End




//////
//
// 原文链接：https://blog.csdn.net/suifenghuidong/article/details/13614953
//
//////

