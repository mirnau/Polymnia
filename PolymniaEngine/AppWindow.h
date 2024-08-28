#pragma once
#include <Windows.h>
#include <tchar.h>

#include "Keyboard.h"

class AppWindow
{
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	HWND hWnd;
	LPSTR lpCmdLine;

	Keyboard keyboard;

	int	nCmdShow;

	const TCHAR szWindowClass[15] = _T("MyWindowClass");
	const TCHAR szTitle[50] = _T("Windows Desktop Guided Tour Application");

public:
	inline AppWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow, Keyboard &keyboard) :
		hInstance(hInstance),
		hPrevInstance(hPrevInstance),
		lpCmdLine(lpCmdLine),
		nCmdShow(nCmdShow),
		keyboard(keyboard)
	{}

	~AppWindow();

	int Init();
	int Run();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMessage(UINT message, WPARAM wParam, LPARAM lParam) noexcept;

};