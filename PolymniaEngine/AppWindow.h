#pragma once
#include <Windows.h>
#include <tchar.h>

class AppWindow
{
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	HWND hWnd;
	LPSTR lpCmdLine;
	int	nCmdShow;

	const TCHAR szWindowClass[15] = _T("MyWindowClass");
	const TCHAR szTitle[50] = _T("Windows Desktop Guided Tour Application");

public:
	AppWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) :
		hInstance(hInstance),
		hPrevInstance(hPrevInstance),
		lpCmdLine(lpCmdLine),
		nCmdShow(nCmdShow) {}

	~AppWindow();

	int Init();
	int Run();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

