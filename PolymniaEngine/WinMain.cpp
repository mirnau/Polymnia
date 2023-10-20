#include <cstdint>
#include "Window.h"
#include "WindowException.h"

int _stdcall WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	try
	{
		const wchar_t* className{ L"PolymniaEngine" };
		uint32_t width{ 1280 };
		uint32_t height{ 1280 };
		bool isRunning=true;

		Window window(width, height, className);

		while (isRunning)
		{
			if (const auto msgCode=Window::ProcessMessages())
				isRunning=false;
		}
	}
	catch (const WindowException& e)
	{
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
		return -1;
	}
	catch (const BaseEngineException& e)
	{
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
		return -1;
	}
	catch (...)
	{
		MessageBoxA(nullptr, "Error", "Unknown Error", MB_OK | MB_ICONEXCLAMATION);
		return -1;
	}

	return 0;
}