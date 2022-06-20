// SDIViewSwitchDoc.cpp : implementation of the CSDIViewSwitchDoc class

#include "stdafx.h"
#include "SDIViewSwitch.h"
#include "SDIViewSwitchDoc.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
double CSDIViewSwitchDoc::SWITCHSPLIT_FILE_SIGNATURE = 0x1234567890123; //static member variable

IMPLEMENT_DYNCREATE(CSDIViewSwitchDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDIViewSwitchDoc, CDocument)
	//{{AFX_MSG_MAP(CSDIViewSwitchDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
CSDIViewSwitchDoc::CSDIViewSwitchDoc()
{
	m_nNumberOfRecords = 0;
	m_nRecordLength = sizeof(tagDOC_RECORD);
	m_nHeaderSize = sizeof(m_nNumberOfRecords) + sizeof(SWITCHSPLIT_FILE_SIGNATURE);
}
/////////////////////////////////////////////////////////////////////////////
CSDIViewSwitchDoc::~CSDIViewSwitchDoc()
{
	TRACE("destructing CSDIViewSwitchDoc\n");	
}
/////////////////////////////////////////////////////////////////////////////
//a virtual member function of CDocument: 
BOOL CSDIViewSwitchDoc::OnNewDocument()
{ 
	if (!CDocument::OnNewDocument()) 
		return FALSE;

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
//This application uses a transaction method of reading and writing data from the document.
//If your app does not require this, it may be much easier to do just use the MFC framework's
//default way of doing this and implement the Serialize() function. 
void CSDIViewSwitchDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}
/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
void CSDIViewSwitchDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDIViewSwitchDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
BOOL CSDIViewSwitchDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	//The default CDocument::OnOpenDocument() opens the document, deserializes it, 
	//and then closes the document.	After calling this default function, we reopen 
	//the document's file and keep it open so that we can update the file on 
	//a transaction basis.
	if(!CDocument::OnOpenDocument(lpszPathName)) 
		return FALSE;
	ASSERT(m_file.m_hFile == CFile::hFileNull);
	if(!m_file.Open(lpszPathName, CFile::modeReadWrite|CFile::shareExclusive))
	{ 
		return FALSE;
	}

	//save a pointer to the document in the app object's member variable:
	((CSDIViewSwitchApp*)AfxGetApp())->m_pDoc = this;

	//If the file is empty, that is because the application has just created
	// a new file. In this case, we need to create a header for the new file.
	if (m_file.GetLength() == 0L)
	{
		WriteHeader();
	}
	else
	{   //Checks if it is a file of the correct type
		if( !ReadHeader() )
		{
			AfxMessageBox("This is not a proper switchsplit file");
			return FALSE;
		}
	}

	//When just starting program, AfxGetApp()->m_pMainWnd = 0, so the 
	//following code will not be run in that case:
	if(AfxGetApp()->m_pMainWnd) 
	{
		//Set a fake view ID so that when OnChooseView is called, it will force the view to 
		//update even if the current view is ID_VIEW_SPLITTER:
		((CMainFrame*)AfxGetMainWnd())->m_nCurrentView = 0; 
		//show the standard initial set of views which causes the data file to be read:
		((CMainFrame*)AfxGetMainWnd())->OnChooseView(ID_VIEW_SPLITTER); 
	}
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////////
void CSDIViewSwitchDoc::DeleteContents() 
{
	//The file was reopened in the override of CDocument::OnOpenDocument.
	//So, now the file should be closed when the framework wants to
	//clear out the CDocument object for potential reuse.

	if (m_file.m_hFile != CFile::hFileNull) //CFile::hFileNull = -1
		m_file.Close();

	((CSDIViewSwitchApp*)AfxGetApp())->m_pDoc = NULL;
	m_nNumberOfRecords = 0;
}
/////////////////////////////////////////////////////////////////////////////////
void CSDIViewSwitchDoc::WriteHeader()
{
	m_file.Seek(0L, CFile::begin);
	//writing of the signature only really needs to be done the first time the header is written:
	m_file.Write( &SWITCHSPLIT_FILE_SIGNATURE, sizeof(double) );
	//WriteHeader is called on other occassions to update the number of records:
	m_file.Write(&m_nNumberOfRecords, sizeof(m_nNumberOfRecords));
}
/////////////////////////////////////////////////////////////////////////////////
//Checks if it is a file of the correct type, and reads in the number of records:
BOOL CSDIViewSwitchDoc::ReadHeader()
{   
	m_file.Seek(0L, CFile::begin);
	double fileSignature;
	m_file.Read( &fileSignature, sizeof(double) ); 
	m_file.Read( &m_nNumberOfRecords, sizeof(UINT) ); 
	return( fileSignature == SWITCHSPLIT_FILE_SIGNATURE );
}
/////////////////////////////////////////////////////////////////////////////////
void CSDIViewSwitchDoc::FileSeekRecord(UINT nRecord)
{
	m_file.Seek( m_nHeaderSize + nRecord*m_nRecordLength, CFile::begin );
}
/////////////////////////////////////////////////////////////////////////////////
bool CSDIViewSwitchDoc::GetRecord(UINT nRecordIndex, void* pRecord)
{
	FileSeekRecord(nRecordIndex);
	if( m_file.Read(pRecord, m_nRecordLength) < m_nRecordLength )
	{
		AfxMessageBox("There is data corruption");
		return false;
	}
	return true;
}
/////////////////////////////////////////////////////////////////////////////////
void CSDIViewSwitchDoc::UpdateRecord(UINT nRecordIndex, void* pRecord)  
{
	FileSeekRecord(nRecordIndex);
	m_file.Write(pRecord, m_nRecordLength);
}
/////////////////////////////////////////////////////////////////////////////////
BOOL CSDIViewSwitchDoc::SaveModified() 
{   //It is needed to override this virtual CDocument function because if the document 
	//is modified, CDocument::SaveModified() will produce a sharing violation because 
	//the file is open already. Since we're saving data on a transaction basis, the 
	//data is already saved. All we need to do is close the file:
	DeleteContents(); 

	return TRUE; // keep going   
}
/////////////////////////////////////////////////////////////////////////////////
