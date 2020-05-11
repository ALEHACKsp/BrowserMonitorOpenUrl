
// ChromiumLoadUrl_DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChromiumLoadUrl_Demo.h"
#include "ChromiumLoadUrl_DemoDlg.h"
#include "afxdialogex.h"
#include "SDK\ChromiumMonitorOpenUrl.h"

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


// CChromiumLoadUrl_DemoDlg dialog



CChromiumLoadUrl_DemoDlg::CChromiumLoadUrl_DemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHROMIUMLOADURL_DEMO_DIALOG, pParent)
{
  m_hrInitRet = E_NOTIMPL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChromiumLoadUrl_DemoDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_LST_URLS, m_lstOutList);
}

BOOL CChromiumLoadUrl_DemoDlg::OnCopyData(CWnd*, COPYDATASTRUCT*p)
{
  if (-1 != p->dwData)
  {
    LPARAM lParam = (LPARAM)p;
    CString strText;
    strText.Format(L"[%u] Open Url: %s",
      GetOpenedProcessIdByLParam(lParam),
      (LPCWSTR)ATL::CA2W(GetOpenedUrlByLParam(lParam), CP_UTF8)
    );
    m_lstOutList.InsertString(0, strText);
  }
  return TRUE;
}

BEGIN_MESSAGE_MAP(CChromiumLoadUrl_DemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_WM_COPYDATA()
  ON_BN_CLICKED(IDC_BTN_CLEAR, &CChromiumLoadUrl_DemoDlg::OnBnClickedBtnClear)
  ON_BN_CLICKED(IDC_BTN_START, &CChromiumLoadUrl_DemoDlg::OnBnClickedBtnStart)
  ON_BN_CLICKED(IDC_BTN_VISIT_DEVELOPER, &CChromiumLoadUrl_DemoDlg::OnBnClickedBtnVisitDeveloper)
END_MESSAGE_MAP()


// CChromiumLoadUrl_DemoDlg message handlers

BOOL CChromiumLoadUrl_DemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

void CChromiumLoadUrl_DemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChromiumLoadUrl_DemoDlg::OnPaint()
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
HCURSOR CChromiumLoadUrl_DemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChromiumLoadUrl_DemoDlg::OnBnClickedBtnClear()
{
  // TODO: Add your control notification handler code here
  m_lstOutList.ResetContent();
}


void CChromiumLoadUrl_DemoDlg::OnBnClickedBtnStart()
{
  // TODO: Add your control notification handler code here
  if (SUCCEEDED(m_hrInitRet))
    return;

  m_hrInitRet = StartMonitorOpenUrlByNotifyWnd(m_hWnd);

  if (SUCCEEDED(m_hrInitRet))
    MessageBoxW(L"监控成功！");
  else if (E_ABORT == m_hrInitRet)
    MessageBoxW(L"体验版3分钟试用期结束，请购买正式授权版本，或者重新启动系统尝试执行！");
  else
    MessageBoxW(L"监控失败！");
}


void CChromiumLoadUrl_DemoDlg::OnBnClickedBtnVisitDeveloper()
{
  // TODO: Add your control notification handler code here
  ShellExecute(nullptr, L"open", 
    L"https://blog.csdn.net/tan_kaishuai/article/details/105853208", 
    nullptr, nullptr, SW_SHOWNORMAL);
}
