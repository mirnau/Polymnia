#pragma once

#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <iostream>
#include "Application.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#ifdef PL_PLATFORM_WINDOWS

extern std::unique_ptr<Polymnia::Application> Polymnia::CreateApplication();

int main(int argc, char** argv)
{
	#if PL_DEBUG

		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
		_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
		_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	#endif

	// To prevent registering a memory leak I have scoped the unique pointer
	// It expires anyway, but it looks nicer in the terminal.

	// ************************
	//char* leak = new char[100]; //Intentional leak
	// ************************

	{
		std::unique_ptr<Polymnia::Application> app = Polymnia::CreateApplication();
		app->Run();
	}

	#if PL_DEBUG

		LOG_MESSAGE(LoggerTool::Level::Info, "MEMORY LEAKS:\n");
		_CrtDumpMemoryLeaks();

	#endif
}

#endif