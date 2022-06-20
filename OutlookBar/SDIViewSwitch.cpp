// SDIViewSwitch.cpp : Defines the class behaviors for the application.

#include "stdafx.h"
#include "SDIViewSwitch.h"
//#include "MainFrm.h"
#include "SDIViewSwitchDoc.h"
//#include "SplitterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSDIViewSwitchApp

BEGIN_MESSAGE_MAP(CSDIViewSwitchApp, CWinApp)
	//{{AFX_MSG_MAP(CSDIViewSwitchApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, OnMyFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
CSDIViewSwitchApp::CSDIViewSwitchApp()
{
	m_nNumberOfInitialRecords = 7;
	m_pDoc = NULL;
}
/////////////////////////////////////////////////////////////////////////////
CSDIViewSwitchApp::~CSDIViewSwitchApp()
{
}
/////////////////////////////////////////////////////////////////////////////
// The one and only CSDIViewSwitchApp object
CSDIViewSwitchApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSDIViewSwitchApp initialization
BOOL CSDIViewSwitchApp::InitInstance()
{
	SetDialogBkColor(RGB(45,235,255), RGB(0,0,255));

	//Set the    GdiplusStartupInput m_gdiplusStartupInput;
    GdiplusStartup(&m_pGdiToken,&m_gdiplusStartupInput,NULL);
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  //Load standard INI file options (including MRU)

	// Register document templates
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSDIViewSwitchDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CSplitterView) );
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////
//When this function is called, either the app is just starting and it is called from 
//ProcessShellCommand(), or the user has selected File|New. By default, the MFC framework
//does not create a file for a new document until the user saves the document. Since  
//this app updates the file on a transaction basis, a file is required at the start:
void CSDIViewSwitchApp::OnMyFileNew()
{
    CString strFileToOpen;

	if(m_pDoc) 
	{   //If m_pDoc != 0 then there is an existing document open and we want to close it
		//and create a new one. We create a File Open dialog for the use to open a new file
		//We use the barely documented CWinApp::DoPromptFileName that CWinApp::OnFileOpen calls.
		//But we replace the OFN_FILEMUSTEXIST flag with OFN_CREATEPROMPT.
		//CWinApp::DoPromptFileName is mentioned in TN022.

		CFile file;
		CFileStatus status;

		while(1)
		{
			if (!(DoPromptFileName(strFileToOpen, IDS_NEW_SWITCH_SPLIT_FILE,
				OFN_HIDEREADONLY | OFN_CREATEPROMPT, TRUE, NULL)))
				return;

			if(file.GetStatus(strFileToOpen, status))
			{   //file exists
				int nRet = AfxMessageBox("This file already exists,	do you want to open it?",
					MB_YESNO);
				if(nRet == IDYES)
					break;
			}
			else 
			{   //file doesn't exist
				break;
			}
		}

		if(!file.Open(strFileToOpen, CFile::modeCreate))
		{
			CString strMessage;
			AfxFormatString1(strMessage, IDS_CANNOT_CREATE_NEW_SWITCHSPLIT,	strFileToOpen);
			AfxMessageBox(strMessage);
			return;
		}
		//We will reopen the file later, so close it now:
		file.Close(); 

	}
	else //We are just starting application, and there is no open document:
	{
		//Check to see if there is a File in the MRU list stored in the registry:
		strFileToOpen = GetProfileString("Recent File List", "File1");
		if(strFileToOpen == "")  //no string was found:
		{
			strFileToOpen = "FirstSwitchSplit.sws";
			CreateFirstFile(strFileToOpen);
		}
		else  //a string was found in the MRU registry key:
		{
			CDocument* pDoc = OpenDocumentFile(strFileToOpen);
			if(!pDoc) //If we can't open file, then maybe no file exists for the  
			{	//registry entry. So, give up and delete "Recent File List" registry key:	
				HKEY hKeyToApp = 0;
				LPCTSTR lpszAppRegKey = "Software\\Local AppWizard-Generated Applications\\SwitchSplit";
				LONG lreturnOpen = RegOpenKeyEx(HKEY_CURRENT_USER, lpszAppRegKey, 0, KEY_ALL_ACCESS, 
					&hKeyToApp);
				LPCTSTR lpszTextProblem = "Problem with app's registry key."
						"You may want to delete the key: HKEY_CURRENT_USER\\Software\\"
						"Local AppWizard-Generated Applications\\SwitchSplit before "
						"running this app again";
				if(lreturnOpen == ERROR_SUCCESS)
				{
					LPCTSTR lpSubKey = "Recent File List";  
					LONG lreturnDelKey = RegDeleteKey(hKeyToApp, lpSubKey);
					if(lreturnDelKey != ERROR_SUCCESS)
						AfxMessageBox(lpszTextProblem);
				}
				else
				{	//could use FormatMessage() to get an accurate error
					AfxMessageBox(lpszTextProblem);
				}

				//The app may not work perfectly at this point, but if the registry key was 
				//deleted, it should restart fine. Try to create a starting file anyway:
				strFileToOpen = "FirstSwitchSplit.sws";
				CreateFirstFile(strFileToOpen);
			}
			else
				return;
		}

	}

	//Open the file now that it has been created.
	OpenDocumentFile(strFileToOpen);
}
/////////////////////////////////////////////////////////////////////////////
void CSDIViewSwitchApp::CreateFirstFile(CString strFirstFileName)
{
	CFile file;
	CFileStatus status;
	//The file name is not stored in the registry at this point.
	//The file shouldn't exist, but if it does, then don't recreate it.
	//If file doesn't already exist, then create it now:
	if(!file.GetStatus(strFirstFileName, status))
	{
		if(!file.Open(strFirstFileName, CFile::modeCreate|CFile::modeWrite))
		{
			CString strMessage;
			AfxFormatString1(strMessage, IDS_CANNOT_CREATE_NEW_SWITCHSPLIT, strFirstFileName);
			AfxMessageBox(strMessage);
			return;
		}

		//Write file header:
		file.Seek(0L, CFile::begin);
		file.Write( &(CSDIViewSwitchDoc::SWITCHSPLIT_FILE_SIGNATURE), sizeof(double) );
		file.Write(&m_nNumberOfInitialRecords, sizeof(UINT)); //UINT is type for CSDIViewSwitchDoc::m_nNumberOfRecords

		//Write file data:
		WriteDataToFirstFile(&file);

		file.Close();
	}
}
//////////////////////////////////////////////////////////////////////////////
void CSDIViewSwitchApp::WriteDataToFirstFile(CFile* pFile)
{
	DOC_RECORD* pArrayOfDocRecords = new DOC_RECORD[m_nNumberOfInitialRecords]; 

	strncpy(pArrayOfDocRecords[0].name    , "Phil Spory", 32);
	strncpy(pArrayOfDocRecords[0].address , "31 Oak Ave", 40);
	strncpy(pArrayOfDocRecords[0].city    , "Issaquah"  , 24);
	strncpy(pArrayOfDocRecords[0].state   , "NY"        ,  4); //4 instead of 2 because want it aligned on an int boundary, might also consider setting /Zp or  #pragma pack
	strncpy(pArrayOfDocRecords[0].zipcode , "11798"     ,  8); //8 instead of 5 for the same reason mentioned above
	strncpy(pArrayOfDocRecords[0].quote   , 
		"Love is a smoke made with the fume of sighs,\r\n"
		"Being purged, a fire sparkling in lovers' eyes,\r\n"
		"Being vexed, a sea nourished with lovers' tears.\r\n"
		"What is it else? A madness most discreet,\r\n"
		"A choking gall and a preserving sweet.\r\n\r\n"
		"William Shakespeare. Romeo and Juliet, act 1, sc. 1.", 400);

	strncpy(pArrayOfDocRecords[1].name    , "Isaac Varon"       , 32);
	strncpy(pArrayOfDocRecords[1].address , "52 Pleasant Pl, #2", 40);
	strncpy(pArrayOfDocRecords[1].city    , "Smithtown"         , 24);
	strncpy(pArrayOfDocRecords[1].state   , "WI"                ,  4);
	strncpy(pArrayOfDocRecords[1].zipcode , "34908"             ,  8);
	strncpy(pArrayOfDocRecords[1].quote   , 
		"How like a winter hath my absence been\r\n"
		"From thee, the pleasure of the fleeting year!\r\n"
		"What freezings have I felt, what dark days seen,\r\n"
		"What old December's bareness everywhere!\r\n\r\n"
		"William Shakespeare. Sonnet 97.", 400);

	strncpy(pArrayOfDocRecords[2].name    , "Adam Kim" , 32);
	strncpy(pArrayOfDocRecords[2].address , "12 Elm St", 40);
	strncpy(pArrayOfDocRecords[2].city    , "Seattle"  , 24);
	strncpy(pArrayOfDocRecords[2].state   , "WA"       ,  4);
	strncpy(pArrayOfDocRecords[2].zipcode , "98105"    ,  8);
	strncpy(pArrayOfDocRecords[2].quote   , 
		"The man that hath no music in himself,\r\n"
		"Nor is not moved with concord of sweet sounds,\r\n"
		"Is fit for treasons, stratagems, and spoils.\r\n"
		"The motions of his spirit are dull as night,\r\n"
		"And his affections dark as Erebus.\r\n"
		"Let no such man be trusted.\r\n\r\n"
		"William Shakespeare. The Merchant of Venice, act 5, sc. 1", 400);		

 	strncpy(pArrayOfDocRecords[3].name    , "Miguel Fernandez"	, 32);
	strncpy(pArrayOfDocRecords[3].address , "27 Park Pl, Apt E.", 40);
	strncpy(pArrayOfDocRecords[3].city    , "Bellevue"			, 24);
	strncpy(pArrayOfDocRecords[3].state   , "WA"				,  4);
	strncpy(pArrayOfDocRecords[3].zipcode , "98125"				,  8);
	strncpy(pArrayOfDocRecords[3].quote   , 
		"O comfort-killing night, image of hell,\r\n"
		"Dim register and notary of shame,\r\n"
		"Black stage for tragedies and murders fell,\r\n"
		"Vast sin-concealing chaos, nurse of blame!\r\n\r\n"
		"William Shakespeare. The Rape of Lucrece.", 400);

  	strncpy(pArrayOfDocRecords[4].name    , "Donald Weed", 32);
	strncpy(pArrayOfDocRecords[4].address , "3 Rodeo Ave", 40);
	strncpy(pArrayOfDocRecords[4].city    , "Dallas"	 , 24);
	strncpy(pArrayOfDocRecords[4].state   , "TX"		 ,  4);
	strncpy(pArrayOfDocRecords[4].zipcode , "65789"      ,  8);
	strncpy(pArrayOfDocRecords[4].quote   , 
		"O mischief, thou art swift\r\n"
		"To enter in the thoughts of desperate men!\r\n\r\n"
		"William Shakespeare. Romeo and Juliet, act 5, sc. 1.", 400);

 	strncpy(pArrayOfDocRecords[5].name    , "Sal Coco"       , 32);
	strncpy(pArrayOfDocRecords[5].address , "1 Microsoft Way", 40);
	strncpy(pArrayOfDocRecords[5].city    , "Redmond"        , 24);
	strncpy(pArrayOfDocRecords[5].state   , "WA"             ,  4);
	strncpy(pArrayOfDocRecords[5].zipcode , "98305"          ,  8);
	strncpy(pArrayOfDocRecords[5].quote   , 
		"Fear no more the heat o' th' sun,\r\n"
		"Nor the furious winter's rages.\r\n"
		"Thou thy worldly task hast done,\r\n"
		"Home art gone and ta'en thy wages.\r\n\r\n"
		"William Shakespeare. Song from Cymbeline, act 4, sc. 2.", 400);

	strncpy(pArrayOfDocRecords[6].name,     "Shawn Karr"  , 32);
	strncpy(pArrayOfDocRecords[6].address , "7789 Main St", 40);
	strncpy(pArrayOfDocRecords[6].city    , "Springfield" , 24);
	strncpy(pArrayOfDocRecords[6].state   , "CA"          ,  4);
	strncpy(pArrayOfDocRecords[6].zipcode , "54298"       ,  8);
	strncpy(pArrayOfDocRecords[6].quote   , 
		"Sure, he, that made us with such large discourse,\r\n"
		"Looking before and after, gave us not\r\n"
		"That capability and god-like reason,\r\n"
		"To fust in us unused.\r\n\r\n"
		"William Shakespeare. Hamlet, act 4, sc. 4.", 400);

	pFile->Write(pArrayOfDocRecords, m_nNumberOfInitialRecords*sizeof(DOC_RECORD));

	delete [] pArrayOfDocRecords;
}
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
		// No message handlers
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

// App command to run the dialog
void CSDIViewSwitchApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
/////////////////////////////////////////////////////////////////////////////

int CSDIViewSwitchApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	GdiplusShutdown(m_pGdiToken);
	return CWinApp::ExitInstance();
}
