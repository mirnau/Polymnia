#pragma once

#include <iostream>
#include "Application.h"


#ifdef PL_PLATFORM_WINDOWS

extern std::unique_ptr<Polymnia::Application> Polymnia::CreateApplication();


int main(int argc, char** argv)
{

	printf("Polymnia Engine\n");

	std::unique_ptr<Polymnia::Application> app = Polymnia::CreateApplication();

	app->Run();
}

#endif