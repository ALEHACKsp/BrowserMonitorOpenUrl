#pragma once
#include <Windows.h>

//
// �������ҳ�򿪼�ؽӿ�
// ������
//    hNotifyWnd����ȡ֪ͨ�¼��Ĵ��ڣ�ÿ����һ����ҳ��ʱ�����յ�һ�� WM_COPYDATA �¼�
//
// ��ע����������ֻ֧�ּ��32λ�������Chrome, 2345��QQ�������IE �ȵȣ����ҽ���ֻ������3���ӣ�3�����Ժ�����˳���ء�
//       �����Ҫ֧��64λ�����������������ʽ��ҵ��Ʒ������ϵ���� tankaishuai@126.com ������ʽ��Ȩ�汾��
//
//

//��ʼ���
extern "C" __declspec(dllexport)
HRESULT StartMonitorOpenUrlByNotifyWnd(HWND hNotifyWnd);

//��ȡ�������ǰ�򿪵�Url
extern "C" __declspec(dllexport)
LPCSTR GetOpendUrlByLParam(LPARAM lParam);

//��ȡ���������Id
extern "C" __declspec(dllexport)
DWORD GetOpendProcessIdByLParam(LPARAM lParam);