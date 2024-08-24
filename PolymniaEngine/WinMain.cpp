#include <Windows.h>
#include "application.h"

// Program entrypoint at __stdcall

int WINAPI WinMain(
	_In_		HINSTANCE hInstance,
	_In_opt_	HINSTANCE hPrevInstance,
	_In_		LPSTR	lpCmdLine,
	_In_		int	nCmdShow
)
{
	Application application(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	
	return application.Run();
}