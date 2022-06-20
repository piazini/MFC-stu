// OutlookBarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OutlookBar.h"
#include "OutlookBarDlg.h"

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
// COutlookBarDlg dialog

COutlookBarDlg::COutlookBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COutlookBarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutlookBarDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COutlookBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutlookBarDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COutlookBarDlg, CDialog)
	//{{AFX_MSG_MAP(COutlookBarDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutlookBarDlg message handlers

BOOL COutlookBarDlg::OnInitDialog()
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
	InitializeOutlookBar();



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COutlookBarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COutlookBarDlg::OnPaint() 
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
HCURSOR COutlookBarDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


//////////////////////////////////////////////////////////////////////
static UINT nIcons[] =
{
    IDI_ICON12, IDI_ICON23,  IDI_ICON15,  IDI_ICON16,
		IDI_ICON17, IDI_ICON18,  IDI_ICON19, IDI_ICON20,
		IDI_ICON21, IDI_ICON22, IDI_ICON11
};
void COutlookBarDlg::InitializeOutlookBar()
{
	m_ImageSmall.Create (32, 32, ILC_COLOR16|ILC_MASK, 2, 1);
	m_ImageLarge.Create (48, 48, ILC_COLOR16|ILC_MASK, 2, 1);
	m_ImageFolder.Create(16, 16, ILC_COLOR32|ILC_MASK, 2, 1);
	// initiailize the image lists.
	for (int i = 0; i < 11; ++i)
	{
		HICON hIcon = AfxGetApp()->LoadIcon(nIcons[i]);
		//ASSERT(hIcon);
		
		m_ImageSmall.Add(hIcon);
		m_ImageLarge.Add(hIcon);
		m_ImageFolder.Add(hIcon);
	}

	int iFolder; // index of the added folder
	// set the image lists for the outlook bar.
	m_wndOutlookBar.SetImageList(&m_ImageLarge, OBS_XT_LARGEICON);
	m_wndOutlookBar.SetImageList(&m_ImageSmall, OBS_XT_SMALLICON);
	m_wndOutlookBar.SetFolderImageList(&m_ImageFolder);

	// Add the first folder to the outlook bar.
	iFolder = m_wndOutlookBar.AddFolder(_T("电话产品"), 0);
	// Add items to the folder, syntax is folder, index, text, image, and item data.
	m_wndOutlookBar.InsertItem(iFolder, 1, _T("回款率计算"), 0, NULL);
	m_wndOutlookBar.InsertItem(iFolder, 2, _T("流失客户"), 1, NULL);
	m_wndOutlookBar.InsertItem(iFolder, 3, _T("账务预警"), 2, NULL);
	m_wndOutlookBar.InsertItem(iFolder, 4, _T("收入统计"), 3, NULL);
	m_wndOutlookBar.InsertItem(iFolder, 5, _T("收入统计"), 4, NULL);
	m_wndOutlookBar.InsertItem(iFolder, 6, _T("收入统计"), 5, NULL);

	// Add the second folder to the outlook bar.
	iFolder = m_wndOutlookBar.AddFolder(_T("Shortcuts 2"), 1);
	// Add items to the folder, syntax is folder, index, text, image, and item data.
	m_wndOutlookBar.InsertItem(iFolder, 7, _T("Item 7"), 7, 1);
	m_wndOutlookBar.InsertItem(iFolder, 8, _T("Item 8"), 8, 1);

	// Add the 3th folder to the outlook bar.
	iFolder = m_wndOutlookBar.AddFolder(_T("Shortcuts 3"), 2);
	// Add items to the folder, syntax is folder, index, text, image, and item data.
	m_wndOutlookBar.InsertItem(iFolder, 9, _T("Item 9"), 9, 1);
	m_wndOutlookBar.InsertItem(iFolder, 10, _T("Item 10"), 10, 1);

	// Add the tree control to the outlook bar.
	//xu	iFolder = m_wndOutlookBar.AddFolderBar(_T("Tree Control"), &m_wndTreeCtrl );

	// Set the default font used by the outlook bar.
	//xu	m_wndOutlookBar.SetFontX(&xtAfxData.font);

	// We want to receive notification messages.
	m_wndOutlookBar.SetOwner(this);
	//m_wndOutlookBar.SetSmallIconView(TRUE,0);

	// Select the first folder in the bar.
	m_wndOutlookBar.SetSelFolder(0);
	
	// Sizing for splitter
	//	m_wndSplitter1.SetSplitterStyle(XT_SPLIT_NOFULLDRAG);

}