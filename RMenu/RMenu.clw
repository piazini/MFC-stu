; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRMenuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RMenu.h"

ClassCount=3
Class1=CRMenuApp
Class2=CRMenuDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_RMENU_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:CRMenuApp]
Type=0
HeaderFile=RMenu.h
ImplementationFile=RMenu.cpp
Filter=N

[CLS:CRMenuDlg]
Type=0
HeaderFile=RMenuDlg.h
ImplementationFile=RMenuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEM32772

[CLS:CAboutDlg]
Type=0
HeaderFile=RMenuDlg.h
ImplementationFile=RMenuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RMENU_DIALOG]
Type=1
Class=CRMenuDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=CRMenuDlg
Command1=ID_MENUITEM32772
Command2=ID_MENUITEM32773
Command3=ID_MENUITEM32774
CommandCount=3

