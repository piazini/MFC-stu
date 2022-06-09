// RMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RMenu.h"
#include "RMenuDlg.h"

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
// CRMenuDlg dialog

CRMenuDlg::CRMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRMenuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRMenuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

//注意是MAP里的参数是CRMenuDlg里填写，不是上面的CAboutDlg里填写
BEGIN_MESSAGE_MAP(CRMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CRMenuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP

	// 菜单栏代码需要手动添加
	//菜单栏
	ON_COMMAND(ID_MENUITEM32772, On_32772)  //右键-大家好
	ON_COMMAND(ID_MENUITEM32773, On_32773)  //右键-同学好
	ON_COMMAND(ID_MENUITEM32774, On_32774)  //右键-你好

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRMenuDlg message handlers

BOOL CRMenuDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRMenuDlg::OnPaint() 
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
HCURSOR CRMenuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


//鼠标右键弹起
void CRMenuDlg::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//载入菜单资源IDR_MENU1
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	
	//获取菜单项里的子菜单
	CMenu *pPopup = menu.GetSubMenu(NULL);

	//获取鼠标点击位置
	CPoint pointPos;
	GetCursorPos(&pointPos);

	//弹出菜单
	pPopup ->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pointPos.x, pointPos.y,this);


	CDialog::OnRButtonUp(nFlags, point);
}

//右键-大家好
void CRMenuDlg::On_32772() 
{
	MessageBox(_T("On_32772"));
}  

//右键-同学好 
void CRMenuDlg::On_32773()  
{
	MessageBox(_T("On_32773"));
}  

//右键-你好
void CRMenuDlg::On_32774() 
{
	MessageBox(_T("On_32774"));
}  
