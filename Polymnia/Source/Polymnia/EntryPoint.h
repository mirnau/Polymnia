#pragma once
#include <iostream>
#include "Application.h"

using app = Polymnia::Application; 

#ifdef PL_PLATFORM_WINDOWS

extern app* Polymnia::CreateApplication();

int main(int argc, char** argv)
{
	printf("Polymnia Engine\n");
	app* app = Polymnia::CreateApplication();
	app->Run();
	delete app;
}

#endif
