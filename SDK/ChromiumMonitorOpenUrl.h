#pragma once
#include <Windows.h>

//
// 浏览器网页打开监控接口
// 参数：
//    hNotifyWnd：获取通知事件的窗口，每当有一个网页打开时，会收到一个 WM_COPYDATA 事件
//
// 【注】体验版仅仅只支持监控32位浏览器（Chrome, 360, 2345，QQ浏览器，IE 等等），且仅仅只能试用3分钟，3分钟以后随机退出监控。
//       如果想要支持64位浏览器，或者用于正式商业产品，请联系作者 tankaishuai@126.com 购买正式授权版本。
//
//

//开始监控
extern "C" __declspec(dllexport)
HRESULT StartMonitorOpenUrlByNotifyWnd(HWND hNotifyWnd);

extern "C" __declspec(dllexport)
HRESULT StartMonitorOpenUrlByNotifyWnd_SB(HWND hNotifyWnd);

//获取浏览器当前打开的Url
extern "C" __declspec(dllexport)
LPCSTR GetOpenedUrlByLParam(LPARAM lParam);

//获取浏览器进程Id
extern "C" __declspec(dllexport)
DWORD GetOpenedProcessIdByLParam(LPARAM lParam);
