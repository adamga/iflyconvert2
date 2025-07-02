
// 737MAX_SDKDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "737MAX_SDK.h"
#include "737MAX_SDKDlg.h"
#include "afxdialogex.h"
#include "sdk\SDK.h"
#include "sdk\key_command.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy737MAXSDKDlg dialog



CMy737MAXSDKDlg::CMy737MAXSDKDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY737MAX_SDK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy737MAXSDKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy737MAXSDKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1,&CMy737MAXSDKDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2,&CMy737MAXSDKDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMy737MAXSDKDlg message handlers

BOOL CMy737MAXSDKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

void CMy737MAXSDKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy737MAXSDKDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy737MAXSDKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy737MAXSDKDlg::OnBnClickedButton1()
{
	hMapFile737MAXSDK = OpenFileMapping(FILE_MAP_READ, FALSE, szName737MAXSDK);

	if(hMapFile737MAXSDK != NULL)
		pBuf737MAXSDK = (LPTSTR)MapViewOfFile(hMapFile737MAXSDK, FILE_MAP_READ, 0, 0, BUF_SIZE_737MAXSDK);

	if(pBuf737MAXSDK)
	{
		CopyMemory((PVOID)pShareMem737MAXSDK, pBuf737MAXSDK, sizeof(struct ShareMemory737MAXSDK));
		if(pShareMem737MAXSDK->iFly737MAX_STATE == iFly737MAX_RUNNING)
		{
			CString str;
			if (pShareMem737MAXSDK->FD_1_Switch_Status == 0)
				str.Format(TEXT("Left FD Switch: OFF"));
			else
				str.Format(TEXT("Left FD Switch: ON"));
			MessageBox(str, 0, 0);
		}
		else
			MessageBox("iFly737MAX is not running.", 0, 0);
	}
	else
		MessageBox("Can't connect to iFly737MAX. P3D is not running?", 0, 0);

	UnmapViewOfFile(pBuf737MAXSDK);
	pBuf737MAXSDK = NULL;
	CloseHandle(hMapFile737MAXSDK);
	hMapFile737MAXSDK = NULL;
}


void CMy737MAXSDKDlg::OnBnClickedButton2()
{
	iFly737MAX_Init_SendMessage(VER_MSFS2020);
	iFly737MAX_SendMessage(KEY_COMMAND_AUTOMATICFLIGHT_LEFT_FD, 1, 0, 0);

}


