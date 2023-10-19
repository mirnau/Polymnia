#include <cstdint>
#include "Window.h"

int _stdcall WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	const wchar_t* className{ L"PolymniaEngine" };
	uint32_t width { 1280 };
	uint32_t height { 1280 };

	Window window(width, height, className);
	
	while (true)
	{
		if (const auto msgCode = Window::ProcessMessages())
			return msgCode;
	}
}