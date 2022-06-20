// SDIViewSwitchDoc.h : interface of the CSDIViewSwitchDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDIVIEWSWITCHDOC_H__CB97F4C7_1752_11D2_B134_00C04FB9CA2B__INCLUDED_)
#define AFX_SDIVIEWSWITCHDOC_H__CB97F4C7_1752_11D2_B134_00C04FB9CA2B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


typedef struct tagDOC_RECORD
{
	char name[32];
	char address[40];
	char city[24];
	char state[4];
	char zipcode[8];
	char quote[400];
}DOC_RECORD;
///////////////////////////////////////////////////

class CSDIViewSwitchDoc : public CDocument
{

protected: // create from serialization only
	CSDIViewSwitchDoc();
	DECLARE_DYNCREATE(CSDIViewSwitchDoc)

public:
	CFile m_file;   // This file is kept open to do read/writes on a transaction basis.

	DOC_RECORD m_DocRecord;
	static double SWITCHSPLIT_FILE_SIGNATURE;
	UINT m_nHeaderSize;
	UINT m_nNumberOfRecords;
	UINT m_nRecordLength;

// Operations
public:
	void WriteHeader();
	BOOL ReadHeader();
	void FileSeekRecord(UINT nRecord);
	bool GetRecord(UINT nRecordIndex, void* pRecord);
	void UpdateRecord(UINT nRecordIndex, void* pRecord);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDIViewSwitchDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSDIViewSwitchDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSDIViewSwitchDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIVIEWSWITCHDOC_H__CB97F4C7_1752_11D2_B134_00C04FB9CA2B__INCLUDED_)
