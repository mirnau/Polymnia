#pragma once
#include "SlimWindows.h"
#include <tchar.h>

#include "AppWindow.h"

class Application
{

public:
	Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) : 
		appWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow) {}

	Application(Application& a) = delete;
	Application(Application&& a) = delete;

	~Application() {};

	int Run();

	AppWindow appWindow;
};