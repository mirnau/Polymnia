#define WINDOW_EXCEPTION( hr ) WindowException(__LINE__,__FILE__, hr)
#define WINDOW_EXCEPTION() WindowException(__LINE__,__FILE__)

#pragma once

#include <cstdint>
#include "SlimWindows.h"

class Window
{

public:
	Window(uint32_t width, uint32_t height, const wchar_t* name) noexcept;
	~Window();

	Window(const Window&) = delete;
	Window(Window&&) = delete;
	Window& operator=(const Window&) = delete;
	Window& operator=(Window&&) = delete;

public:
	static uint32_t ProcessMessages();

private:
	static LRESULT _stdcall WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	HWND hwnd;
	HINSTANCE hInstance;
	uint32_t height;
	uint32_t width;
	const wchar_t* wndName;
};

