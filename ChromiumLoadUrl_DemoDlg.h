
// ChromiumLoadUrl_DemoDlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CChromiumLoadUrl_DemoDlg dialog
class CChromiumLoadUrl_DemoDlg : public CDialogEx
{
// Construction
public:
	CChromiumLoadUrl_DemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHROMIUMLOADURL_DEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
 BOOL OnCopyData(CWnd*, COPYDATASTRUCT*);

// Implementation
protected:
	HICON m_hIcon;
 HRESULT m_hrInitRet;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  CListBox m_lstOutList;
  afx_msg void OnBnClickedBtnClear();
  afx_msg void OnBnClickedBtnStart();
  afx_msg void OnBnClickedBtnVisitDeveloper();
};
