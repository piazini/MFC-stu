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

	//��ʼ��,��ȡ��Ļ��С
	m_screenX=GetSystemMetrics(SM_CXSCREEN); 
	m_screenY=GetSystemMetrics(SM_CYSCREEN);

	//��ʾ��Ļ��С
	CString str1;
	str1.Format("��Ļ��С��m_screenX=%i, m_screenY=%i",m_screenX,m_screenY);
	GetDlgItem(IDC_STATIC2) -> SetWindowText(str1);
	//MessageBox(str1);


	//CRect default_rect;
	//ȡ�������������Ļ����������꣬�����ͻ����ͷǿͻ���
	GetWindowRect(&default_rect);
	//��ȡ�ͻ�����С���������������ķǿͻ���
	//GetClientRect(&default_rect);
	CString str;
	str.Format("����Ĭ�ϴ�С��\ndefault_rect.left=%d, \ndefault_rect.right=%d, \ndefault_rect.Height=%d, \ndefault_rect.Width=%d",default_rect.left,default_rect.right,default_rect.Height(),default_rect.Width());
	GetDlgItem(IDC_STATIC1) -> SetWindowText(str);
	//MessageBox(str);

	m_lastActiveTime=GetTickCount();

	//��ʼ����������ʾ������״̬ ��Ĭ��״̬���ڷ�����
	m_hidePosition = HidePosition::NO;

	//���ö�ʱ����100=nFlags 200=���ms
	SetTimer(100,200,NULL);
	GetDlgItem(IDC_STATIC) -> SetWindowText(_T("���Ի����϶�����Ļ������Ե���Ի�����Զ�����"));


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


//�����Ϣ������ƶ����ͻ���"��"����������Ϣ
void CDockedHideDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_lastActiveTime = GetTickCount();

	CDialog::OnMouseMove(nFlags, point);
}

//�����Ϣ,����ƶ����ͻ���"��"����������Ϣ
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

//��������Ƿ��ڴ����ں���
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

	//����ֵ�������λ��CRect�У��򷵻ط���ֵ�����򷵻�0��
	return rect.PtInRect(point);
}

//��ʱ������
void CDockedHideDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 100: 
		if(GetTickCount() - m_lastActiveTime < 300) { //չʾ
			DockedShow();
		}else{//����
			DockedHidden();
		}
	break;
	}

	CDialog::OnTimer(nIDEvent);
}


//ͣ������
void CDockedHideDlg::DockedHidden()
{
	CRect rect;
	CRect m_rect;
	GetWindowRect(&rect);

	if(m_hidePosition == HidePosition::NO && !isMouseInWindow()) {
		m_rect = rect;
		if(m_rect.top <= 0 ) { //����
			m_hidePosition = HidePosition::TOP;
			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(
				//NULL,		//ԭ�Ĵ��ڲ�������ǰ
				&wndTopMost,	//���ô�����ǰ
				m_rect.left,	//������ߵ���λ��
				0,	//���ڶ�������λ��
				m_rect.right - m_rect.left,		//���ڵ��¿��
				5,	//���غ󣬴��ڵ��¸߶ȣ���ʾ��������
				SWP_NOCOPYBITS
				);
			//����
			//���ƶ�
			m_rect.bottom -= m_rect.top;
			m_rect.top = 0;

		}else if( default_rect.left <= 0 ){ //����
			m_hidePosition = HidePosition::LEFT;
			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(&wndTopMost, 0, m_rect.top, 5, m_rect.bottom-m_rect.top, SWP_NOCOPYBITS);
			//���ƶ�
			m_rect.right -=m_rect.left;
			m_rect.left =0;
			
		}else if( m_rect.right >= m_screenX ){ //����
			m_hidePosition = HidePosition::RIGHT;
			MessageBox(_T("RIGHT"));

			ModifyStyle(WS_SYSMENU,NULL);
			this->SetWindowPos(
				&wndTopMost,	//���ô�����ǰ
				m_screenX-12,	//������ߵ���λ��
				m_rect.top,			//���ڶ�������λ��
				5,			//���ڵ��¿�ȡ�
				200,//m_rect.bottom-m_rect.top,		//ָ���˴��ڵ��¸߶�
				SWP_SHOWWINDOW
				);
			//���ƶ�
			m_rect.left = m_screenX-(m_rect.right - m_rect.left);
			//m_rect.left =m_rect.right - m_rect.left;
			m_rect.right =m_screenX;//m_rect.left; //ƫ����   m_rect.right - m_screenX
			
		}else{
			m_hidePosition =HidePosition::NO;
		}	
	}   // if(m_hidePosition End

} //DockedHidden() End

//ͣ��չʾ
void CDockedHideDlg::DockedShow()
{
	CRect rect;
	CRect m_rect;
	//ȡ�������������Ļ����������꣬�����ͻ����ͷǿͻ���
	GetWindowRect(&rect);

	if(m_hidePosition != HidePosition::NO && isMouseInWindow()) {  //�����أ���ʾ��ֵ

		m_rect = rect;

		//�ָ���ʽ
		ModifyStyle(NULL, WS_SYSMENU);

		// ��Ϣ����ʾĬ�ϴ��ڴ�С
		/*
		CString str;
		str.Format("default_rect.Height=%d, default_rect.Width=%d",default_rect.Height(),default_rect.Width());
		str.Format("%i,%i,%i",m_rect.bottom,m_rect.top);
		MessageBox(str);
		*/

		//��ԭ��С
		int seq = 0;
		switch(m_hidePosition) {
			case HidePosition::TOP:
				//MessageBox(_T("TOP"));
				while (++seq <= 5){
					this->SetWindowPos(
						&wndTopMost, //��֤��������ǰ
						m_rect.left,
						m_rect.top,
						m_rect.right - m_rect.left,
						//(m_rect.bottom - m_rect.top) * seq/5,   ԭ���ô���ֵ����Ҫ�ָ��Ĵ��ڴ�С������ȷ
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
// ԭ�����ӣ�https://blog.csdn.net/suifenghuidong/article/details/13614953
//
//////

