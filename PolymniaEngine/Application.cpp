#include "application.h"
#include "AppWindow.h"

int Application::Run()
{
	if (!appWindow.Init())
		return 1;

	return appWindow.Run();
}





