
// ChromiumLoadUrl_Demo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CChromiumLoadUrl_DemoApp:
// See ChromiumLoadUrl_Demo.cpp for the implementation of this class
//

class CChromiumLoadUrl_DemoApp : public CWinApp
{
public:
	CChromiumLoadUrl_DemoApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CChromiumLoadUrl_DemoApp theApp;