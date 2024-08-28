#pragma once
#include "SlimWindows.h"
#include <tchar.h>

#include "AppWindow.h"
#include "Keyboard.h"

class Application
{

public:
	inline Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) :
		appWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow, keyboard),
		keyboard() {}

	Application(Application& a) = delete;
	Application(Application&& a) = delete;

	~Application() {};

	int Run();

	AppWindow appWindow;
	Keyboard keyboard;
};